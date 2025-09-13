
const { execSync } = require('child_process');
const express = require('express');
const multer = require('multer');
const cors = require('cors');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = 3000;

// --- Directory Setup ---
// Create a 'storage' directory outside of 'frontend'
const storageDir = path.join(__dirname, '..', 'storage');
const uploadsDir = path.join(storageDir, 'uploads');
const resultsDir = path.join(storageDir, 'results');

// Ensure these directories exist
[storageDir, uploadsDir, resultsDir].forEach(dir => {
    if (!fs.existsSync(dir)) {
        fs.mkdirSync(dir, { recursive: true });
        console.log(`Created directory: ${dir}`);
    }
});

// --- Middleware ---
app.use(cors());
app.use(express.json());
// Serve the results directory statically to allow downloads
app.use('/results', express.static(resultsDir));


// --- File Upload Configuration (Multer) ---
const upload = multer({ dest: uploadsDir });


// --- API Endpoints ---

// 1. File Upload Endpoint
app.post('/upload', upload.single('uploadedFile'), (req, res) => {
    if (!req.file) {
        return res.status(400).json({ message: 'No file uploaded.' });
    }
    console.log('File uploaded:', req.file);
    res.json({
        message: 'File uploaded successfully!',
        fileName: req.file.filename // Send back the generated filename
    });
});

// 2. Analysis Trigger Endpoint
app.post('/analyze', (req, res) => {
    const { fileName } = req.body;
    if (!fileName) {
        return res.status(400).json({ message: 'Missing fileName to analyze.' });
    }

    const filePath = path.join(uploadsDir, fileName);

    if (!fs.existsSync(filePath)) {
        return res.status(404).json({ message: 'File to analyze not found.' });
    }
    execSync("cd .. && python ./backend/main.py");
    console.log(`Analysis started for: ${fileName}`);

    // ===================================================================
    // TODO: TRIGGER YOUR GHIDRA ANALYSIS SCRIPT HERE
    // The command should take the input file path and the output directory.
    // This part of the code should execute your command-line script.
    //
    // For example, using Node.js's child_process:
    //
    // const { execSync } = require('child_process');
    // try {
    //     // This is a blocking call, the server will wait until the script is done.
    //     // Replace this with your actual command.
    //     const command = `your_ghidra_command --inputFile "${filePath}" --outputDir "${resultsDir}"`;
    //     console.log(`Executing: ${command}`);
    //     execSync(command, { stdio: 'inherit' }); // stdio: 'inherit' will show script output in the server console
    // } catch (error) {
    //     console.error(`Analysis script failed for ${fileName}:`, error);
    //     return res.status(500).json({ message: `Analysis script failed: ${error.message}` });
    // }
    //
    // For testing without a real script, you can manually place files
    // in the 'storage/results' directory before clicking 'Analyze'.
    // ===================================================================


    // After the script is finished, read the results directory for any generated files.
    try {
        const resultFiles = fs.readdirSync(resultsDir);
        console.log(`Analysis finished for: ${fileName}. Found ${resultFiles.length} result files.`);
        res.json({
            message: `Analysis complete for ${fileName}`,
            results: resultFiles
        });
    } catch (error) {
        console.error('Error reading results directory:', error);
        res.status(500).json({ message: 'Could not read analysis results directory.' });
    }
});

// 3. Get Code Results Endpoint
app.get('/code-results', (req, res) => {
    try {
        const files = fs.readdirSync(resultsDir);
        const cFiles = files.filter(file => path.extname(file).toLowerCase() === '.c');
        
        const codeData = cFiles.map(fileName => {
            const content = fs.readFileSync(path.join(resultsDir, fileName), 'utf-8');
            return { fileName, content };
        });

        res.json(codeData);
    } catch (error) {
        console.error('Error reading code results:', error);
        res.status(500).json({ message: 'Could not retrieve code files.' });
    }
});

// 4. Cleanup Endpoint
app.post('/cleanup', (req, res) => {
    const cleanupDirectory = (directory) => {
        try {
            if (!fs.existsSync(directory)) return;
            const files = fs.readdirSync(directory);
            for (const file of files) {
                fs.unlinkSync(path.join(directory, file));
            }
            console.log(`Successfully cleaned up directory: ${directory}`);
        } catch (err) {
            console.error(`Error cleaning up directory ${directory}:`, err);
        }
    };

    cleanupDirectory(uploadsDir);
    cleanupDirectory(resultsDir);

    res.json({ message: 'Server directories cleaned up successfully.' });
});


// --- Server Start ---
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
    console.log('Storage directories are set up at:', storageDir);
});


	

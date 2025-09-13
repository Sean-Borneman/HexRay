const express = require('express');
const multer = require('multer');
const cors = require('cors');
const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process')
const app = express();
const PORT = 3000;

// --- Directory Setup ---
const storageDir = path.join(__dirname, '..', 'storage');
const uploadsDir = path.join(storageDir, 'uploads');
const decomp_out = path.join(__dirname, '..', 'decompiled_output');
const resultsDir = path.join(storageDir, 'results');


// Ensure all directories exist on startup
[storageDir, uploadsDir, resultsDir, decomp_out].forEach(dir => {
    if (!fs.existsSync(dir)) {
        fs.mkdirSync(dir, { recursive: true });
        console.log(`Created directory: ${dir}`);
    }
});

// --- Middleware ---
app.use(cors());
app.use(express.json());
app.use('/results', express.static(resultsDir));
app.use('/decompiled', express.static(decomp_out)); // Serve decompiled files too

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
        fileName: req.file.filename
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

    try {
        // We can check both directories for a combined list of downloadable files
        const decompFiles = fs.readdirSync(decomp_out);
        const resultFiles = fs.readdirSync(resultsDir);
        const allFiles = [...decompFiles, ...resultFiles];
        
        console.log(`Analysis finished for: ${fileName}. Found ${allFiles.length} result files.`);
        res.json({
            message: `Analysis complete for ${fileName}`,
            results: allFiles
        });
    } catch (error) {
        console.error('Error reading results directories:', error);
        res.status(500).json({ message: 'Could not read analysis results directories.' });
    }
});

// 3. Get Viewable Files Endpoint
app.get('/code-results', (req, res) => {
    try {
        const cFiles = [];
        const txtFiles = [];

        // Read C files from decompiled_output
        const decompFiles = fs.readdirSync(decomp_out);
        decompFiles.forEach(fileName => {
            if (path.extname(fileName).toLowerCase() === '.c') {
                const content = fs.readFileSync(path.join(decomp_out, fileName), 'utf-8');
                cFiles.push({ fileName, content });
            }
        });

        // Read TXT files from storage/results
        const resultFiles = fs.readdirSync(resultsDir);
        resultFiles.forEach(fileName => {
            if (path.extname(fileName).toLowerCase() === '.txt') {
                const content = fs.readFileSync(path.join(resultsDir, fileName), 'utf-8');
                txtFiles.push({ fileName, content });
            }
        });

        res.json({ cFiles, txtFiles });

    } catch (error) {
        console.error('Error reading viewable files:', error);
        res.status(500).json({ message: 'Could not retrieve viewable files.' });
    }
});

// 4. Verification Endpoint
app.post('/verify', (req, res) => {
    console.log('Verification process triggered...');
    try {
        execSync("cd .. && python ./backend/verify.py");
        const verificationResultPath = path.join(resultsDir, 'verification_result.txt');
        const verificationContent = fs.readFileSync(verificationResultPath, 'utf-8');
        res.json({
            message: 'Verification complete.',
            result: verificationContent
        });
    } catch (error) {
        console.error('An error occurred during verification:', error);
        res.status(500).json({ message: `Verification failed: ${error.message}` });
    }
});

// 5. Cleanup Endpoint
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
    cleanupDirectory(decomp_out); // Also clean verification results
    res.json({ message: 'Server directories cleaned up successfully.' });
});

// --- Server Start ---
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
    console.log('Storage directories are set up at:', storageDir);
});


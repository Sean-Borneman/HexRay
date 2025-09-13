const express = require('express');
const multer = require('multer');
const cors = require('cors');
const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');


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

    execSync("cd ../backend && python main.py");
    console.log(`Analysis started for: ${fileName}`);

    // --- Backend Simulation ---
    // In a real application, this is where you would trigger your Ghidra script.
    // We'll simulate it by creating some dummy result files after a delay.
    setTimeout(() => {
        const baseName = path.parse(fileName).name;
        
        // --- Create dummy C files for the code viewer ---
        const cFileContent1 = `// Decompiled from: ${fileName}
#include <stdio.h>

int main() {
    printf("Hello from main function!\\n");
    return 0;
}`;
        const cFileContent2 = `// Helper functions for: ${fileName}
#include <stdlib.h>

void helper_function() {
    // This is a simulated helper function.
    int* ptr = malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 100;
        free(ptr);
    }
}`;
        fs.writeFileSync(path.join(resultsDir, `${baseName}_main.c`), cFileContent1);
        fs.writeFileSync(path.join(resultsDir, `${baseName}_helpers.c`), cFileContent2);


        const resultFiles = [
            `${baseName}_analysis_report.txt`,
            `${baseName}_strings.json`,
            `${baseName}_functions.csv`,
            `${baseName}_main.c`,
            `${baseName}_helpers.c`,
        ];

        resultFiles.slice(0, 3).forEach(resultFile => {
            const resultPath = path.join(resultsDir, resultFile);
            fs.writeFileSync(resultPath, `This is a simulated analysis result for ${fileName}.\nGenerated on: ${new Date().toISOString()}`);
            console.log(`Generated result file: ${resultPath}`);
        });

        console.log(`Analysis finished for: ${fileName}`);
        res.json({
            message: `Analysis complete for ${fileName}`,
            results: resultFiles
        });
    }, 3000); // Simulate a 3-second analysis time
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


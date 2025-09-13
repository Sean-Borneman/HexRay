@echo off
.\venv\Scripts\activate
cd frontend
start npm start
timeout /t 1
start index.html
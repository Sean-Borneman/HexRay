@echo off
cd frontend
start npm start
timeout /t 1
start index.html
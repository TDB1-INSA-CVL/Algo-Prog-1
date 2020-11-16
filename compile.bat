@echo off

set /p c_file_name="Enter source code file name : " 

:start
gcc %c_file_name% -o output.exe
output.exe
PAUSE
goto start
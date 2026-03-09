@echo off
gcc %1 -o %~n1.exe -lws2_32
echo Compilation finished!
pause
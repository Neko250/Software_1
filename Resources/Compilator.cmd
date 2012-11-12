@echo off
color 0A
title MinGW Compiler.
 
:start
echo Welcome, Neko250
echo What would you like to do?
echo.
echo 1. Compile Cpp
echo 2. Inject Icon
echo. 
echo 0. Quit
echo.
 
set /p choice="Enter your choice: "
if "%choice%"=="1" goto compile
if "%choice%"=="2" goto icon
if "%choice%"=="0" exit
echo Invalid choice: %choice%
echo.
pause
cls
goto start
 
:compile
cls
g++ work.cpp -o RenameMe.exe
echo Compilation Done !
echo.
pause
cls
goto start

:icon
cls
RCEDIT.exe /I RenameMe.exe cpp.ico
echo Icon Injected !
echo.
pause
cls
goto start
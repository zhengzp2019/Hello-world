@echo off
:again
makedata#.exe > input
my.exe < input > output_my
other.exe < input > output_other
fc output_my output_other 
if not errorlevel 1 goto again
pause
@echo on

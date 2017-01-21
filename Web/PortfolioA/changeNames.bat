@echo off
echo Welcome to nameChanger v1.0
set /a n=1
set /a m=2

setlocal ENABLEDELAYEDEXPANSION

FOR %%G IN (*.jpg) DO (
	set var=_A.jpg
	set temp=!n!!var!
	echo !var!
	echo !temp!
	ren %%G !temp!
	set /a n+=1
	rem pause
)
set /a n-=1
echo !n!
endlocal
rem pause


set MATLAB=E:\Programs\matlab

cd .

if "%1"=="" ("E:\Programs\matlab\bin\win64\gmake"  -f BLDC_Control_Logic.mk all) else ("E:\Programs\matlab\bin\win64\gmake"  -f BLDC_Control_Logic.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make

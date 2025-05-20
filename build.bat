@echo off
echo Building Banking System...

gcc main.c createAcc.c deposit.c withdraw.c accDetails.c deleteAcc.c loan.c updatePin.c -o bank.exe

if %errorlevel%==0 (
    echo Build successful! Run bank.exe to start the program.
) else (
    echo Build failed. Please check for errors.
)

pause

@echo off
cl -c -TC test.c
link -OUT:bin\MSVC\app.exe test.obj user32.lib
gcc -o bin\GCC\app.exe test.c
del test.obj -y
@echo on
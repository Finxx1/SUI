@echo off
if "%1"=="examples" goto examples
goto end

:examples
cl -c example\KeyboardTest.c
cl -c example\MouseTest.c
link -OUT:example\KeyboardTest.exe KeyboardTest.obj user32.lib
link -OUT:example\MouseTest.exe MouseTest.obj user32.lib
del KeyboardTest.obj -y
del MouseTest.obj -y
cl -c example\KeyboardTest.cpp
cl -c example\MouseTest.cpp
link -OUT:example\CppKeyboardTest.exe KeyboardTest.obj user32.lib
link -OUT:example\CppMouseTest.exe MouseTest.obj user32.lib
del KeyboardTest.obj -y
del MouseTest.obj -y

:end
@echo on
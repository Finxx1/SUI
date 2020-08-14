@echo off
cl -c -TC example\KeyboardTest.c
link -OUT:example\KeyboardTest.exe KeyboardTest.obj user32.lib
cl -c -TC example\MouseTest.c
link -OUT:example\MouseTest.exe MouseTest.obj user32.lib
del KeyboardTest.obj -y
del MouseTest.obj -y
@echo on
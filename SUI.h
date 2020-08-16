// Single-Header Library for Simulating user input
// Putting it on GitHub so i can always download 
// it if I get a new computer

#pragma once

// Defines so you dont have to remember left and right click are 1 and 2
#define MOUSE_LEFT_CLICK 1
#define MOUSE_RIGHT_CLICK 2

// Include Windows.h, wont work on unix systems ¯\_(ツ)_/¯
#ifndef _WINDOWS_
    #include <Windows.h>
#endif

#ifdef __cplusplus
class SUI {
    private:
        // Input variable, private so nobody changes it without Init().
        INPUT _input;
    public:
        // Function for initializing SUI
        void Init(int mode) {
            if(mode>1) {
                return;
            }
            _input.type = mode;
            if(mode == 0) {
                _input.mi.time = 0;
                _input.mi.mouseData = 0;
                _input.mi.dwExtraInfo = 0;
            }

            if(mode == 1) {
                _input.ki.wScan = 0;
                _input.ki.time = 0;
                _input.ki.dwExtraInfo = 0;
            }
        }

        // Moving cursor pos. its just SetCursorPos, but it would have been weird if we didnt have something for this ¯\_(ツ)_/¯
        void MoveCursor(int x, int y) {
            SetCursorPos(x, y);
        }

        // Click mouse button
        void ClickMouse(int button) {
            if(button == 1) {
                _input.mi.dwFlags = 2;
                    SendInput(1, &_input, sizeof(INPUT));
                    _input.mi.dwFlags = 4;
                    SendInput(1, &_input, sizeof(INPUT));
            }
            else
            if(button == 2) {
                _input.mi.dwFlags = 8;
                    SendInput(1, &_input, sizeof(INPUT));
                    _input.mi.dwFlags = 10;
                    SendInput(1, &_input, sizeof(INPUT));
            } else {
                return;
            }
        }

        // Keyboard input
        void PressKey(int keycode) {
            if(_input.type == 0) {
                return;
            }
            _input.ki.wVk = keycode;
            _input.ki.dwFlags = 0;
            SendInput(1, &_input, sizeof(INPUT));

            _input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &_input, sizeof(INPUT));
        }
};
#else

// Input variable
INPUT _input;

// Function for initializing SUI
void SUIInit(int mode) {
    if(mode>1) {
        return;
    }
    _input.type = mode;
    if(mode == 0) {
        _input.mi.time = 0;
        _input.mi.mouseData = 0;
        _input.mi.dwExtraInfo = 0;
    }

    if(mode == 1) {
        _input.ki.wScan = 0;
        _input.ki.time = 0;
        _input.ki.dwExtraInfo = 0;
    }
}

// Moving cursor pos. its just SetCursorPos, but it would have been weird if we didnt have something for this ¯\_(ツ)_/¯
void SUIMoveCursor(int x, int y) {
    SetCursorPos(x, y);
}

// Click mouse button
void SUIClickMouse(int button) {
    if(button == 1) {
           _input.mi.dwFlags = 2;
            SendInput(1, &_input, sizeof(INPUT));
            _input.mi.dwFlags = 4;
            SendInput(1, &_input, sizeof(INPUT));
    }
    else
    if(button == 2) {
        _input.mi.dwFlags = 8;
            SendInput(1, &_input, sizeof(INPUT));
            _input.mi.dwFlags = 10;
            SendInput(1, &_input, sizeof(INPUT));
    } else {
        return;
    }
}

// Keyboard input
void SUIPressKey(int keycode) {
    if(_input.type == 0) {
        return;
    }
    _input.ki.wVk = keycode;
    _input.ki.dwFlags = 0;
    SendInput(1, &_input, sizeof(INPUT));

    _input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &_input, sizeof(INPUT));
}

#endif

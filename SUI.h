// Single-Header Library for Simulating user input
// Putting it on GitHub so i can always download it if I get a new computer

#pragma once

#ifndef _WINDOWS_
    #include <Windows.h>
#endif

INPUT _input;

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

void SUIMoveCursor(int x, int y) {
    _input.mi.dx = x;
	_input.mi.dy = y;
    _input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
		SendInput(1, &_input, sizeof(INPUT));
}

void SUIClickMouse(int button) {
    if(button == 1) {
           _input.mi.dwFlags = 2;
	    SendInput(1, &_input, sizeof(INPUT));
	    _input.mi.dwFlags = 4;
	    SendInput(1, &_input, sizeof(INPUT));
    } else
    if(button == 2) {
        _input.mi.dwFlags = 8;
	    SendInput(1, &_input, sizeof(INPUT));
	    _input.mi.dwFlags = 10;
	    SendInput(1, &_input, sizeof(INPUT));
    }
}

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

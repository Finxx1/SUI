// Single-Header Library for Simulating user input
// Putting it on GitHub so i can always download it if I get a new computer

#pragma once

#ifndef _WINDOWS_
    #include <windows.h>
#endif

INPUT ip;

void SUIInit(int mode) {
    if(mode == 0) {
        ip.type = INPUT_KEYBOARD;
    } else if(mode == 1) {
        ip.type = INPUT_MOUSE;
    } else {
        return;
    }
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
}

void SUIPressKey(int keycode) {
    if(ip.type == INPUT_MOUSE) {
        return;
    }
    ip.ki.wVk = keycode;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

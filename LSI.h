// Single-Header Library for Simulating user input
// Putting it on GitHub so i can always download it if I get a new computer

#pragma once

#ifndef _WINDOWS_
    #include <windows.h>
#endif

INPUT ip;

void SKPInit() {
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
}

void SKPPressKey(int keycode) {
    ip.ki.wVk = keycode;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

#include "SUI.hpp" // Include library

int main() {
    SUI sui; // Create an instance of SUI
    sui.Init(INPUT_KEYBOARD); // Initialize the library for keyboard input
    sui.PressKey(13); // Press keycode 13 (Keycode for ENTER, https://keycode.info has a list of keycodes)
    return 0;
}
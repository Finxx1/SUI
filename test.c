#include "SUI.h" // Include library

int main() {
    SUIInit(INPUT_KEYBOARD); // Initialize the library for keyboard input
    SUIPressKey(13); // Press keycode 13 (Keycode for ENTER, https://keycode.info has a list of keycodes)
    return 0;
}
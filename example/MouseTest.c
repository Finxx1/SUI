#include "SUI.h" // Include library

int main() {
    SUIInit(INPUT_MOUSE); // Initialize the library for mouse input
    SUIMoveCursor(1920/2, 1080/2); // Move cursor to middle of screen
    SUIClickMouse(MOUSE_LEFT_CLICK); // Click mouse
    return 0;
}
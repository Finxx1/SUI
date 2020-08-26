#include "..\SUI.h" // Include library

int main() {
    SUIInit(INPUT_MOUSE); // Initialize the library for mouse input
    SUIMoveCursor(1920/2, 1080/2); // Move cursor to middle of a 1920 by 1080 screen
    SUIClickMouse(MOUSE_LEFT_CLICK); // Click the left mouse button
    return 0;
}
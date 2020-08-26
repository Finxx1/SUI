#include "..\SUI.h" // Include library

int main() {
    SUI sui; // Create an instance of SUI
    sui.Init(INPUT_MOUSE); // Initialize the library for mouse input
    sui.MoveCursor(1920/2, 1080/2); // Move cursor to middle of a 1920 by 1080 screen
    sui.ClickMouse(MOUSE_LEFT_CLICK); // Click the left mouse button
    return 0;
}
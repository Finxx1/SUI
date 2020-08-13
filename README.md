# SUI

**SUI** is a Single-Header Library that simulates user input

---

## Example

```c
#include "SUI.h" // Include library

int main() {
    SUIInit(INPUT_KEYBOARD); // Initialize the library for keyboard input
    SUIPressKey(13); // Press keycode 13 (Keycode for ENTER, [KeyCodes](https://keycode.info) has a list of keycodes)
    return 0;
}
```

---

## Function Guide

---

```c
void SUIInit(int mode)
```

Initializes SUI

mode = 0 means mouse input

mode = 1 means keyboard input

You can also use the macros INPUT_MOUSE and INPUT_KEYBOARD

---

```c
void SUIPressKey(int keycode)
```

Presses a key

keycode is the keycode of the key you want to press

You can find keycodes [here](https://keycode.info)

---

```c
void SUIMoveCursor(int x, int y)
```

Moves the cursor

x is the x position you want the mouse to be in
y is the y position you want the mouse to be in

NOTE: This is functionally identical to SetCursorPos

---

```c
void SUIClickMouse(int button)
```

Clicks the mouse

button is the mouse button you want to click

1 = left

2 = right

You can also use the macros MOUSE_LEFT_CLICK and MOUSE_RIGHT_CLICK

---

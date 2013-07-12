#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "GlobbyMouse.h"

using namespace std;

int mouseX = 0;
int mouseY = 0;
POINT p;

void setMousePos() {
    if (GetCursorPos(&p)) {
        mouseX = p.x;
        mouseY = p.y;
    } else {
        cout << "Could not set mouse variables..." << endl;
    }
}

JNIEXPORT jint JNICALL Java_ghostclickerredux_GlobbyMouse_whatButton
(JNIEnv *, jobject) {
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
        return 0;
    } else
        if (GetAsyncKeyState(VK_MBUTTON) & 0x8000) {
        return 1;
    } else
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
        return 2;
    } else
        if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) {
        return 3;
    } else
        if (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) {
        return 4;
    } else {
        return -1;
    }
}

JNIEXPORT jint JNICALL Java_ghostclickerredux_GlobbyMouse_getMouseX
(JNIEnv *, jobject) {
    setMousePos();
    return mouseX;
}

JNIEXPORT jint JNICALL Java_ghostclickerredux_GlobbyMouse_getMouseY
(JNIEnv *, jobject) {
    setMousePos();
    return mouseY;
}

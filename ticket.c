
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


#define X 123
#define Y -123
#define SCREEN_WIDTH 2560
#define SCREEN_HEIGHT 1440


void MouseMoveRelative(INPUT *buffer, int x, int y) {
    buffer->type = INPUT_MOUSE;
    buffer->mi.mouseData = 0;
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
    buffer->mi.dx = x;
    buffer->mi.dy = y;
    buffer->mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(1, buffer, sizeof(INPUT));
}

void MouseMoveAbsolute(INPUT *buffer, int x, int y) {
    buffer->type = INPUT_MOUSE;
    buffer->mi.mouseData = 0;
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
    buffer->mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);

    SendInput(1, buffer, sizeof(INPUT));
}

void MouseClick(INPUT *buffer) {
    buffer->type = INPUT_MOUSE;
    buffer->mi.mouseData = 0;
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, buffer, sizeof(INPUT));

    Sleep(10);

    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, buffer, sizeof(INPUT));
}

void KeyDown(INPUT *buffer, WORD key) {
    buffer->type = INPUT_KEYBOARD;
    buffer->ki.wVk = key;
    buffer->ki.dwFlags = 0;
    SendInput(1, buffer, sizeof(INPUT));
}

void KeyUp(INPUT *buffer, WORD key) {
    buffer->type = INPUT_KEYBOARD;
    buffer->ki.wVk = key;
    buffer->ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, buffer, sizeof(INPUT));
}

void KeyPress(INPUT *buffer, WORD key) {
    KeyDown(buffer, key);
    KeyUp(buffer, key);
}


int main(int argc, char *argv[]) {

    INPUT buffer;           //x: 1386 y: 582 Guide, x: 1172 y: 553 chicken wheeel




    /*
    while(1) {
        POINT position;
        GetCursorPos(&position);
        printf("x: %d y: %d\n", position.x, position.y);
        Sleep(2000);
    }    */
    
   
    

     
   
   
   


    Sleep(1000);
    SetCursorPos(500, 500); // bewegt Maus zum rechten Monitor (Minecraft)
    Sleep(1000);
    MouseClick(&buffer); // ist in Minecraft offiziell drin
    Sleep(1000);
    KeyPress(&buffer, VK_ESCAPE); // geht aus dem Chat
    Sleep(1000);
    KeyPress(&buffer, '9'); // wählt 9. Slot aus (nether star)
    Sleep(1000);
    MouseClick(&buffer);    // geht zu den Lobbys mit dem star
    Sleep(1000);
    SetCursorPos(1495, 610); // bewegt Maus zu Lobby 18
    Sleep(1000);
    MouseClick(&buffer); // ist in Lobby 18
    Sleep(1000);
    KeyDown(&buffer, VK_SHIFT); // fliegt nicht mehr
    Sleep(3000);
    KeyUp(&buffer, VK_SHIFT);
    Sleep(500);
    MouseMoveRelative(&buffer, -815, 0);
    Sleep(100);
    KeyDown(&buffer, 'W');
    Sleep(3000);
    KeyUp(&buffer, 'W');
    Sleep(2000);
    KeyDown(&buffer, 'W');
    KeyDown(&buffer, 'A');
    Sleep(6000);
    KeyUp(&buffer, 'W');
    KeyUp(&buffer, 'A');
    Sleep(100);
    MouseMoveRelative(&buffer, 1470, 0);
    Sleep(100);
    KeyDown(&buffer, '4');
    KeyUp(&buffer, '4');
    Sleep(300);
    MouseClick(&buffer);
    Sleep(500);
    MouseMoveAbsolute(&buffer, 1400, 581);
    Sleep(300);
    MouseClick(&buffer);




    return 0;
}
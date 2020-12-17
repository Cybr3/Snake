#include <iostream>
#include <Windows.h>

void setCursorPosition(unsigned short x, unsigned short y) {
    const HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD cords = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(cursor, cords);
}

void ShowConsoleCursor(bool activator)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursor_info;

    GetConsoleCursorInfo(out, &cursor_info);
    cursor_info.bVisible = activator;
    SetConsoleCursorInfo(out, &cursor_info);
}
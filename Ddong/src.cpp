#include <stdio.h>
#include <Windows.h>
#include <conio.h>



void gotoxy(int, int);
void set_console_size(int, int);
void hide_console_cursor();

int main() {
	set_console_size(50, 50);
	hide_console_cursor();

	return 0;
}

void set_console_size(int width, int hight) {
	char str[30];
	sprintf_s(str, sizeof(str), "mode con:cols=%d lines=%d", width * 2, hight);
	system(str);
}

void gotoxy(int x, int y) { 
	COORD CursorPosition = { x, y }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition); 
}

void hide_console_cursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 0, };
	cursor_info.dwSize = 1;
	cursor_info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
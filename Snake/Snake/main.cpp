#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Game.h"

using namespace std;

void hideCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
} // Hide Useless Cursor

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	hideCursor();

	Game g;

	char board[ROW][COL];

	while (g.getState())
	{
		g.render(board);
	}

	return 0;
}
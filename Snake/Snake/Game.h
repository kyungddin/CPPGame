#pragma once
#include <iostream>
#include <Windows.h>

#include "Point.h"
#include "Direction.h"
#include "Snake.h"
#include "Food.h"

class Game
{
private:
	Snake m_snake;
	Food m_food;
	bool gameOver;

public:
	Game();								// Food와 Snake는 각각의 생성자에게..
	~Game() = default;					// 소멸도 일단은 고려 X

	void render();						// 1. Draw & Print Game Screen				
	void input();						// 2. Get User Input
	void update();						// 3. Assign User Input

	void screenInit();					// prepare screen
	void screenFlipping();				// flipping screen
	void screenClear();					// clear out screen
	void screenRelease();				// free screen
	void screenPrint(int x, int y,		// print screen
		char board[ROW][COL]);			

	void drawBoard();					// set buffer
	void drawSnake();					// draw snake on buf
	void drawFood();					// draw food on buf

	bool getGameOver();					// GameOver!
};

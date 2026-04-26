#pragma once
#include "Snake.h"
#include "Food.h"

#define ROW 20
#define COL 40

enum state {
	DEAD = 0,
	ALIVE = 1
};

extern char board[ROW][COL];

class Game
{
private:
	Snake m_snake;
	Food m_food;
	int m_score;
	bool m_gameState;

public:
	Game();

	void update();
	void render(char board[ROW][COL]);
	void input();

	bool getState();
};

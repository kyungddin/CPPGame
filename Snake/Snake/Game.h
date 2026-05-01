#pragma once
#include <iostream>

#include "Point.h"
#include "Direction.h"
#include "Snake.h"
#include "Food.h"

class Game
{
private:
	Snake m_snake;
	Food m_food;

public:
	Game() = default; // 일단은 Food와 Snake니 각각의 생성자에게 맡겨보자
	~Game() = default; // 소멸도 일단은 고려 X

	void render();
	void input();
	void update();

	void showBoard();
	void drawSnake();
	void drawFood();
};

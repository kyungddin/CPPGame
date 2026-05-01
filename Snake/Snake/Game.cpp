#include "Game.h"

char board[ROW][COL];

void Game::render()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == (ROW - 1) || j == 0 || j == (COL - 1))
				board[i][j] = '*';
			else
				board[i][j] = ' ';
		}
	}

	drawSnake();
	showBoard();
}

void Game::input()
{

}

void Game::update()
{

}

void Game::showBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Game::drawSnake()
{
	Point tmpHead;
	tmpHead = m_snake.getHead();

	board[tmpHead.row][tmpHead.col] = '@';

	std::vector<Point> tmpBody = m_snake.getBody();
	int vectorSize = tmpBody.size();

	for (int i = 0; i < vectorSize; i++)
	{
		board[tmpBody[i].row][tmpBody[i].col] = '#'; // ¾Æ x¶û y ÀÌ¸§À» ¹Ù²ã¾ß ÇÏ³ª..
	}
}

void Game::drawFood()
{
}

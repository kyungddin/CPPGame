#include "Game.h"
#include <iostream>
#include <Windows.h>


Game::Game() :
	m_score(0), m_gameState(ALIVE) {}


void Game::update()
{

}


void Game::render(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || j == 0 || i == (ROW - 1) || j == (COL - 1))
				board[i][j] = '#';
			else
				board[i][j] = ' ';
		}
	} // 벽 + 빈공간 초기화

	// 뱀과 음식 그려주기 필요

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << "\n";
	} // 출력
	Sleep(1000);
	system("cls");
}


void Game::input()
{

}


bool Game::getState()
{
	return m_gameState;
}

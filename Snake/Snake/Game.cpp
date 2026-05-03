#include "Game.h"

static char board[ROW][COL];
static int g_nScreenIndex = 0;
static HANDLE g_hScreen[2];

int main()
{
	Game g;

	g.screenInit();

	while (g.getGameOver())
	{
		g.render();
		g.input();
		g.update();
	}

	g.screenRelease();

	return 0;
}

Game::Game() : gameOver(true)
{
	// just gameOver Init!
}

void Game::input()
{
	//std::cin >> m_inputBuf;
	// input에 따라 snake의 head의 direction이 변화해야 함
}

void Game::update()
{
	// snake의 위치를 direction에 따라 update 해줘야 함
	
}

void Game::render()
{
	screenClear();

	drawBoard();
	drawSnake();

	screenPrint(0, 0, board);
	screenFlipping();
}

void Game::screenInit()
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;

	for (int i = 0; i < 2; i++) 
	{
		g_hScreen[i] = CreateConsoleScreenBuffer(
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			CONSOLE_TEXTMODE_BUFFER,
			NULL
		);

		SetConsoleCursorInfo(g_hScreen[i], &cci);
	}
}

void Game::screenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void Game::screenClear()
{
	COORD Coor = { 0, 0 }; // 좌표에 대한 구조체
	DWORD dw;              // 결과 저장 변수

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(g_hScreen[g_nScreenIndex], &csbi);

	int width = csbi.dwSize.X;
	int height = csbi.dwSize.Y;

	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ',
		width * height, Coor, &dw);
}

void Game::screenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void Game::screenPrint(int x, int y, char board[ROW][COL])
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);

	for (int i = 0; i < ROW; i++)
	{
		WriteFile(g_hScreen[g_nScreenIndex], board[i], COL, &dw, NULL);
		WriteFile(g_hScreen[g_nScreenIndex], "\n", 1, &dw, NULL);
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
		board[tmpBody[i].row][tmpBody[i].col] = '#';
	}
}

void Game::drawBoard()
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
}

void Game::drawFood()
{
	// boost 난수 생성 활용하기
}

bool Game::getGameOver()
{
	return gameOver;
}
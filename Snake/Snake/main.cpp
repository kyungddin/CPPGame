#include <iostream>
#include <vector>
#include <string>

#define ROW 20
#define COL 40

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char board[ROW][COL];

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || j == 0 || i == (ROW - 1) || j == (COL - 1)) board[i][j] = '#';
			else board[i][j] = ' ';
		}
	}

	bool state = false;
	while (!state)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				cout << board[i][j];
			}
			cout << "\n";
		}
		cout << "\n\n";
		state = true;
	}

	return 0;
}
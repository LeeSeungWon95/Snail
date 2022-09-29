#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;
int board[MAX][MAX] = {0, };
int N = 0;
enum Dir
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3
};

void PrintBoard()
{
	for (int Y = 0; Y < N; Y++)
	{
		for (int X = 0; X < N; X++)
		{
			cout << setfill('0') << setw(2) << board[Y][X] << " ";
		}
		cout << endl;
	}
}

bool CanGo(int Y, int X)
{
	if (Y < 0 || Y >= N)
	{
		return false;
	}
	if (X < 0 || X >= N)
	{
		return false;
	}
	if (board[Y][X] != 0)
	{
		return false;
	}
	return true;
}

void SetBoard()
{
	int Y = 0;
	int X = 0;
	int Dir = RIGHT;
	int Number = 1;
	while (true)
	{
		board[Y][X] = Number;
		if (Number == N * N)
		{
			break;
		}

		int NewY = 0;
		int NewX = 0;
		switch (Dir)
		{
		case RIGHT:
			NewY = Y;
			NewX = X + 1;
			break;
		case DOWN:
			NewY = Y + 1;
			NewX = X;
			break;
		case LEFT:
			NewY = Y;
			NewX = X - 1;
			break;
		case UP:
			NewY = Y - 1;
			NewX = X;
			break;
		}

		if (CanGo(NewY, NewX))
		{
			Y = NewY;
			X = NewX;
			Number++;
		}
		else
		{
			switch (Dir)
			{
			case RIGHT:
				Dir = DOWN;
				break;
			case DOWN:
				Dir = LEFT;
				break;
			case LEFT:
				Dir = UP;
				break;
			case UP:
				Dir = RIGHT;
				break;
			}
		}
	}
}

int main()
{
	cin >> N;
	SetBoard();
	PrintBoard();
	return 0;
}
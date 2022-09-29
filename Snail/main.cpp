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
	int dY[] = { 0, 1, 0, -1 };
	int dX[] = { 1, 0, -1, 0 };
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
		NewY = Y + dY[Dir];
		NewX = X + dX[Dir];

		if (CanGo(NewY, NewX))
		{
			Y = NewY;
			X = NewX;
			Number++;
		}
		else
		{
			Dir = (Dir + 1) % 4;
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
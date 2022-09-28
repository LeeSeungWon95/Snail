#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

void SetBoard()
{
	int Number = 1;
	int t = 0;
	for (int x = t; x < N - t; x++)
	{
		board[t][x] = Number;
		Number++;
	}
	for (int y = t; y < N - t - 1; y++)
	{
		board[y + 1][N - t - 1] = Number;
		Number++;
	}
	for (int x = N - t - 1; x > t; x--)
	{
		board[N - t - 1][x - 1] = Number;
		Number++;
	}
	for (int y = N - t - 2; y > t; y--)
	{
		board[y][t] = Number;
		Number++;
	}
	t++;

	for (int x = t; x < N - t; x++)
	{
		board[t][x] = Number;
		Number++;
	}
	for (int y = t; y < N - t - 1; y++)
	{
		board[y + 1][N - t - 1] = Number;
		Number++;
	}
	for (int x = N - t - 1; x > t; x--)
	{
		board[N - t - 1][x - 1] = Number;
		Number++;
	}
	for (int y = N - t - 2; y > t; y--)
	{
		board[y][t] = Number;
		Number++;
	}
	t++;

	for (int x = t; x < N - t; x++)
	{
		board[t][x] = Number;
		Number++;
	}
	for (int y = t; y < N - t - 1; y++)
	{
		board[y + 1][N - t - 1] = Number;
		Number++;
	}
	for (int x = N - t - 1; x > t; x--)
	{
		board[N - t - 1][x - 1] = Number;
		Number++;
	}
	for (int y = N - t - 2; y > t; y--)
	{
		board[y][t] = Number;
		Number++;
	}
	t++;
}

int main()
{
	cin >> N;
	SetBoard();
	PrintBoard();
	return 0;
}
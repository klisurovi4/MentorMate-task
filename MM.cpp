#include <iostream>
#include <windows.h>
using namespace std;

//a function to print out a specified number of stars
void PrintStar(int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "*";
	}
}

//a function to print out a specified number of dashes
void PrintDash(int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "-";
	}
}

//a funciton to move the cursor position to specified coordinates
void GoToPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//prints the left right-leaning quater of the M
void PrintLeft(int n, int x, int y)
{
	GoToPos(x,y);
	for (int i = n; i >= 0; i--)
	{
		PrintDash(i);
		PrintStar(n);
		PrintDash(n-i);
		GoToPos(x, ++y);
	}
}

//prints a left-leaning quarter of the M
void PrintRight(int n, int x, int y)
{
	GoToPos(x, y);
	for (int i = n; i >= 0; i--)
	{
		PrintStar(n);
		PrintDash(i);
		GoToPos(++x, ++y);
	}
}

//prints the middle right-leaning quarter of the M
void PrintLeftMid(int n, int x, int y)
{
	x = x + n;
	GoToPos(x, y);
	for (int i = n; i >= 0; i--)
	{
		PrintStar(n);
		PrintDash(n-i);
		GoToPos(--x, ++y);
	}
}

//prints an M with specified size and coordinates for the upper left corner
void PrintM(int n, int x, int y)
{
	PrintLeft(n, x, y);
	PrintRight(n, x + n, y);
	PrintLeftMid(n, x + n * 2, y);
	PrintRight(n, x + n * 3, y);
	GoToPos(0, n + 2);
}


int main()
{
	int n = 3;
	int x = 0;
	int y = 1;
	cin >> n;
	
	PrintM(n, x, y);
	PrintM(n, x + n * 5, y);

	return 0;
}
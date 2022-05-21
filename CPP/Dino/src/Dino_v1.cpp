/*

//inspired from : https://github.com/BlockDMask/Google_Dino
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dino Run v1");
}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void DrawDino(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}

void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$ ");
}

int main()
{
	SetConsoleView();

	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;

	int dinoY = DINO_BOTTOM_Y;
	int treeX = TREE_BOTTOM_X;

	while (true)
	{
		if (GetKeyDown() == 'z' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		if (isJumping)
		{
			dinoY -= gravity;
		}
		else
		{
			dinoY += gravity;
		}

		if (dinoY >= DINO_BOTTOM_Y)
		{
			dinoY = DINO_BOTTOM_Y;
			isBottom = true;
		}

		treeX -= 2;
		if (treeX <= 0)
		{
			treeX = TREE_BOTTOM_X;
		}

		if (dinoY <= 3)
		{
			isJumping = false;
		}

		DrawDino(dinoY);
		DrawTree(treeX);
		Sleep(60);
		system("cls");
	}
	return 0;
}

*/
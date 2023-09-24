// Simple Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
extern int main();

using namespace std;

#define ssProgramName "Simple Snake"
#define ssProgramVersion "Version 0.9"
#define ssCommandPrompt endl << "Please Enter a Command: "
#define ssInvalidCommand "> " << ssUserInput << " <" << " is not a valid command!"

bool gameOver;
const int width = 50;
const int height = 25;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
int speed;
int points;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
char ssUserInput;
bool ssValidCommandCheck = true;
bool wallCollisionToggle = false;
bool strobe = false;
bool strobeX = false;

void endGame();

void setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";//Snake Head
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";//Snake tail
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;
}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		case 'q':
			gameOver = true;
			break;
		}
	}
}

void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (wallCollisionToggle != true)
	{
		if (x >= width) x = 0; else if (x < 0) x = width - 1;  //loops the snake back into field of play
		if (y >= height) y = 0; else if (y < 0) y = height - 1;
	}
	else
	{
		if (x > width || x < 0 || y > height || y < 0)  //ends game if snake hits the wall
		gameOver = true;
	}
	
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score += points;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

void startScreen()
{
	if (ssValidCommandCheck != false)
	{
		system("cls");
		cout << "Welcome to " << ssProgramName << " " << ssProgramVersion;
		cout << endl << "Start Menu" << endl << endl;
		cout << "Set game dificaulty" << endl;
		cout << "Enter '1' for EASY Mode" << endl << "Enter '2' For Moderate Mode - Increased Snake Speed" << endl << "Enter '3' for HARD Mode - Even Faster Snake Speed & Set the walls to Kill Mode" << endl << "Enter '4' for the Insaino Mode" << endl << "Enter 'q' to quit and return to the Main Menu" << endl;
	}
	else
	{
		cout << ssInvalidCommand;
		ssValidCommandCheck = true;
	}
	
	cout << ssCommandPrompt;
	cin >> ssUserInput;

	switch (ssUserInput)
	{
	case '1': points = 10; speed = 50; wallCollisionToggle = false; strobe = false; return; break;
	case '2': points = 13; speed = 25; wallCollisionToggle = false; strobe = false; return; break;
	case '3': points = 18; speed = 10; wallCollisionToggle = true; strobe = false; return; break;
	case '4': points = 22; speed = 1; wallCollisionToggle = true; strobe = true; return; break;
	case 'q': main(); break;
	default:
	{
		ssValidCommandCheck = false;
		startScreen();
		break;
	}
	}
}


void simpleSnake()
{
	system("color 09");
	startScreen();
	setup();
	while (!gameOver)
	{
		if (strobe == true)
		{
			if (strobeX == true)
			{
				system("color 0D");
				strobeX = false;
			}
			else
			{
				system("color 01");
				strobeX = true;
			}
		}
		
		draw();
		input();
		logic();
		Sleep(speed);
	}
	cout << "GAME OVER" << endl;
	endGame();
	simpleSnake();
}

void endGame()
{
	nTail = NULL;
	cout << "Would you Like to Play Again? y/n: ";
	cin >> ssUserInput;

	switch (ssUserInput)
	{
	case 'y': return; break;

	case 'n':main();; break;
	default:
	{
		cout << ssUserInput << " is not a valid command";
		cout << endl;
		endGame();
		break;
	}
	}

}



#include <iostream>
#include <conio.h>
#include <Windows.h>

class ErrorHandling {
public:
    void handleBufferOverflow() {
        // Implement buffer overflow handling code here
    }

    void handleMemoryExploits() {
        // Implement memory exploit handling code here
    }
};

class GameLogic : public ErrorHandling {
private:
    bool gameOver;
    const int width = 50;
    const int height = 25;
    int x, y, score;
    int tailX[100], tailY[100];
    int nTail;
    int speed;
    int points;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
    char userInput;
    bool validCommandCheck = true;
    bool wallCollisionToggle = false;
    bool strobe = false;
    bool strobeX = false;
    int fruitX, fruitY;

    void endGame() {
        nTail = NULL;
        std::cout << "Would you Like to Play Again? y/n: ";
        std::cin >> userInput;

        switch (userInput) {
        case 'y':
            return;
            break;

        case 'n':
            return;
            break;
        default: {
            std::cout << userInput << " is not a valid command";
            std::cout << std::endl;
            endGame();
            break;
        }
        }
    }

    void setup() {
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
    }

    void draw() {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            std::cout << "#";
        std::cout << std::endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    std::cout << "#";
                if (i == y && j == x)
                    std::cout << "O";//Snake Head
                else if (i == fruitY && j == fruitX)
                    std::cout << "F";
                else {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            std::cout << "o";//Snake tail
                            print = true;
                        }
                    }
                    if (!print)
                        std::cout << " ";
                }

                if (j == width - 1)
                    std::cout << "#";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < width + 2; i++)
            std::cout << "#";
        std::cout << std::endl;
        std::cout << "Score: " << score << std::endl;
    }

    void input() {
        if (_kbhit()) {
            switch (_getch()) {
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

    void logic() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
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

        if (wallCollisionToggle != true) {
            if (x >= width) x = 0; else if (x < 0) x = width - 1;  //loops the snake back into field of play
            if (y >= height) y = 0; else if (y < 0) y = height - 1;
        }
        else {
            if (x > width || x < 0 || y > height || y < 0) {  //ends game if snake hits the wall
                gameOver = true;
            }
        }

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;

        if (x == fruitX && y == fruitY) {
            score += points;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
        }
    }

    void startScreen() {
        if (validCommandCheck != false) {
            system("cls");
            std::cout << "Welcome to Simple Snake Version 0.9";
            std::cout << std::endl << "Start Menu" << std::endl << std::endl;
            std::cout << "Set game difficulty" << std::endl;
            std::cout << "Enter '1' for EASY Mode" << std::endl << "Enter '2' For Moderate Mode - Increased Snake Speed" << std::endl << "Enter '3' for HARD Mode - Even Faster Snake Speed & Set the walls to Kill Mode" << std::endl << "Enter '4' for the Insaino Mode" << std::endl << "Enter 'q' to quit and return to the Main Menu" << std::endl;
        }
        else {
            std::cout << "> " << userInput << " <" << " is not a valid command!";
            validCommandCheck = true;
        }

        std::cout << std::endl << "Please Enter a Command: ";
        std::cin >> userInput;

        switch (userInput) {
        case '1':
            points = 10; speed = 50; wallCollisionToggle = false; strobe = false; return;
            break;
        case '2':
            points = 13; speed = 25; wallCollisionToggle = false; strobe = false; return;
            break;
        case '3':
            points = 18; speed = 10; wallCollisionToggle = true; strobe = false; return;
            break;
        case '4':
            points = 22; speed = 1; wallCollisionToggle = true; strobe = true; return;
            break;
        case 'q':
            return;
            break;
        default: {
            validCommandCheck = false;
            startScreen();
            break;
        }
        }
    }

public:
    void simpleSnake() {
        system("color 09");
        startScreen();
        setup();
        while (!gameOver) {
            if (strobe == true) {
                if (strobeX == true) {
                    system("color 0D");
                    strobeX = false;
                }
                else {
                    system("color 01");
                    strobeX = true;
                }
            }

            draw();
            input();
            logic();
            Sleep(speed);
        }
        std::cout << "GAME OVER" << std::endl;
        endGame();
        simpleSnake();
    }
};

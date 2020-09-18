//Chase Staples
//Snake Game
/*
    Creating a simple snake game creating functions of 


*/




#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;

enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction direction;



void Setup() {

    gameOver = false;
    direction = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

}

void Draw() {
    system("cls"); //system("clear")
    for(int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0)
                cout << "#";
            if(i == y && j == x)
                cout << "O";
            else if(i == fruitY && j == fruitX)
                cout << "F"
            else
            {
                for(int tail = 0; tail < tailLength; tail++)
                {
                    bool print = false;
                    if(tailX[tail] == j && tailY[tail] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                    
                }
                if(!print)
                        out << " ";
            }
                
            if(j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for(int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input(){ 
    if(_kbhit())
    {
        switch(_getch())
        {
            case "a"
                dir = LEFT;
                break;
            case "s"
                dir = DOWN;
                break;
            case "d"
                dir = RIGHT;
                break;
            case "w"
                dir = UP;
                break;
            case "x"
                gameOver = true;
                break;
        }
    }
}

void Logic(){

    int previousX = tailX[0];
    int previousY = tailY[0];
    int previous2X, previous2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i = 1; i < tailLength; i++)
    {
        previous2X = tailX[i];
        previous2Y = tailY[i];
        tailX[i] = previousX;
        tailY[i] = previousY;
        previousX = previous2X;
        previousY = previous2Y;

    }
    switch(direction)
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
    //if(x > width || x < 0 || y > height || y < 0)         If you want a gameover when you hit the wall
    //    gameOver = true;
    
    if(x >= width) 
        x = 0; 
    else if (x < 0) 
        x = width - 1;
    if(y >= height) 
        y = 0; 
    else if (y < 0) 
        x = height - 1;

    for(int i = 0; i < tailLength; i++)
        if(tailX[i] == x && tailY[i] == Y)
            gameOver = true;

    if(x == fruitX && y == fruitY)
    {

            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            tailLength++;
    }

}

int main(){

    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        sleep(10); 
    }
    return 0;
}

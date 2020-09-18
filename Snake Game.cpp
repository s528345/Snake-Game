//Chase Staples
//Snake Game
/*
    Creating a simple snake game creating functions of 
    setup, draw, input, and logic. These will allow a simple 
    snake game to be played in the console. Created in C++ 
*/

//Adding headers and libraries
#include <iostream>         
#include <conio.h>
#include <windows.h>

using namespace std;

//Creating global variables
bool gameOver;
const int width = 50;
const int height = 50;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;

//Creating a way to accomadate direction in the console
enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction direction;


//Creating the setup function to intialize the game
void Setup() {

    gameOver = false;
    direction = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

}

//Creating tje 
void Draw() {
    system("cls"); 
    //system("clear") //for linux

    //Printing out the playing area 
    for(int i = 0; i < width + 2; i++)              //Printing the width symbols "-"
        cout << "-";                                //Printing the bottom of the board
    cout << endl;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0)                              //Printing the width symbols "|"
                cout << "|";
            if(i == y && j == x)                    //Printing the head of the snake
                cout << "O";
            else if(i == fruitY && j == fruitX)     //Printing fruits
                cout << "F"
            else
            {
                for(int tail = 0; tail < tailLength; tail++)    //Printing the tail
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
                cout << "-";
        }
        cout << endl;
    }

    for(int i = 0; i < width + 2; i++) //Printing the bottom of the board
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;     //Printing the score
}

void Input(){ 
    if(_kbhit())
    {
        switch(_getch())
        {
            case "a"                //If 'a' is pressed; go left
                dir = LEFT;
                break;
            case "s"                //If 's' is pressed; go down
                dir = DOWN;
                break;
            case "d"                //If 'd' is pressed; go right
                dir = RIGHT;
                break;
            case "w"                //If 'w' is pressed; go up
                dir = UP;
                break;
            case "x"                //If 'x' is pressed; automatically exit game
                gameOver = true;
                break;
        }
    }
}

void Logic(){

    //Tail variables to track movement of the tail properly
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
        //Tracking the head
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
    
    //Allows for snake to travel through walls and return on the opposite side
    if(x >= width) 
        x = 0; 
    else if (x < 0) 
        x = width - 1;
    if(y >= height) 
        y = 0; 
    else if (y < 0) 
        x = height - 1;

    //Logic if snake runs into itself
    for(int i = 0; i < tailLength; i++)
        if(tailX[i] == x && tailY[i] == Y)
            gameOver = true;

    //Printing new fruits and adding score
    if(x == fruitX && y == fruitY)
    {

            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            tailLength++;
    }

}

//Running Game
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

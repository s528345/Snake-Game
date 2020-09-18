#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
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
                cout << " ";
            if(j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for(int i = 0; i < width + 2; i++)
        cout << "#";
      cout << endl;
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

}

int main(){

    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        //Sleep(10); sleep(10);
    }
    return 0;
}

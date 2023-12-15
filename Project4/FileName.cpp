#include <iostream>
#include <windows.h>
using namespace std;
#define SIZE 3;
void Input(char** num1, int& x, int& y) {


    char key = _getwch();
    if ((key == 'w' || key == 'W') && y > 0) {
        y--;
    }
    if ((key == 's' || key == 'S') && y < 2) {
        y++;
    }
    if ((key == 'a' || key == 'A') && x > 0) {
        x--;
    }
    if ((key == 'd' || key == 'D') && x < 2) {
        x++;
    }
    if (key == '\r' && num1[y][x] != 'o') {

        num1[y][x] = 'x';
    }

    if (key == ' ' && num1[y][x] != 'x') {
        num1[y][x] = 'o';

    }
}
void Draw(char** num1, int  x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << "+---+---+---+" << endl;
        for (int j = 0; j < SIZE; j++)
        {
            cout << "|" << " ";
            if (x == j && y == i) {
                SetConsoleTextAttribute(h, (2 << 4) | 8);
            }
            cout << (num1[i][j]);
            SetConsoleTextAttribute(h, (0 << 4) | 8);
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << "+---+---+---+" << endl;
}
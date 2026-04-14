#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

vector<vector<char>> maze = {
    {'S', '.', '.', '#', '.', '.'},
    {'#', '#', '.', '#', '.', '#'},
    {'.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '.'},
    {'.', '.', '.', '#', '.', 'E'}
};

int playerX = 0, playerY = 0;

bool isValid(int x, int y) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] != '#';
}

void draw() {
    system("cls");

    cout << "🎮 MAZE RUNNER\n";
    cout << "Use W A S D to move\n\n";

    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {

            if (i == playerX && j == playerY) {
                setColor(10);
                cout << " P ";
            }
            else if (maze[i][j] == '#') {
                setColor(8);
                cout << " # ";
            }
            else if (maze[i][j] == 'E') {
                setColor(12);
                cout << " E ";
            }
            else {
                setColor(7);
                cout << " . ";
            }
        }
        cout << endl;
    }
}

int main() {
    while (true) {
        draw();

        if (maze[playerX][playerY] == 'E') {
            cout << "\n🎉 You reached the exit!\n";
            break;
        }

        char ch = _getch();

        int newX = playerX, newY = playerY;

        if (ch == 'w' || ch == 'W') newX--;
        else if (ch == 's' || ch == 'S') newX++;
        else if (ch == 'a' || ch == 'A') newY--;
        else if (ch == 'd' || ch == 'D') newY++;

        if (isValid(newX, newY)) {
            playerX = newX;
            playerY = newY;
        }
    }

    return 0;
}
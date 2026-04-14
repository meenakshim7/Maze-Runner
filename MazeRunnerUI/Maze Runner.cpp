#include <iostream>
#include <vector>
#include <conio.h>   // for _getch()
#include <windows.h> // for colors
using namespace std;

// Color function
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Maze
vector<vector<char>> maze = {
    {'S', '.', '.', '#', '.', '.'},
    {'#', '#', '.', '#', '.', '#'},
    {'.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '.'},
    {'.', '.', '.', '#', '.', 'E'}
};

int rows = maze.size();
int cols = maze[0].size();

int playerX = 0, playerY = 0;

// Clear screen
void clearScreen() {
    system("cls");
}

// Display UI
void draw() {
    clearScreen();

    cout << "🎮 MAZE RUNNER\n";
    cout << "Use W A S D to move\n\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (i == playerX && j == playerY) {
                setColor(10); // Green
                cout << " P ";
            }
            else if (maze[i][j] == '#') {
                setColor(8); // Gray
                cout << " # ";
            }
            else if (maze[i][j] == 'E') {
                setColor(12); // Red
                cout << " E ";
            }
            else {
                setColor(7); // White
                cout << " . ";
            }
        }
        cout << endl;
    }

    setColor(7);
}

// Check valid move
bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != '#';
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
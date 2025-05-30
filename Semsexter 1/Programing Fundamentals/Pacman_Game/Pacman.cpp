#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int rows = 31;
const int cols = 71;
const int tickTime = 100;

char mapp[rows][cols + 1] = {
    "#######################################################################",
    "# . . . . . . . . . . . . . . . . ### . . . . . . . . . . . . . . . . #",
    "# O ########### . ############# . ### . ############# . ########### O #",
    "# . ########### . ############# . ### . ############# . ########### . #",
    "# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #",
    "# . ###########   ### . ####################### . ### . ########### . #",
    "# . . . . . . . . ### . . . . . . ### . . . . . . ### . . . . . . . . #",
    "############### . #############   ###   ############# . ###############",
    "              # . #############         ############# . #              ",
    "              # . ###                             ### . #              ",
    "############### . ###   _________     _________   ### . ###############",
    "                .       |                     |       .                ",
    "############### . ###   |                     |   ### . ###############",
    "              # . ###   |_____________________|   ### . #              ",
    "              # . ###              p              ### . #              ",
    "############### . ###   #######################   ### . ###############",
    "# . . . . . . . . . . . . . . . . ### . . . . . . . . . . . . . . . . #",
    "# O ########### . ############# . ### . ############# . ########### O #",
    "# . . . ####### . . . . . . . . . . . . . . . . . . . . ####### . . . #",
    "##### . ####### . ### . ####################### . ### . ####### . #####",
    "# . . . . . . . . ### . . . . . . ### . . . . . . ### G . . . . . . . #",
    "# . ########################### . ### . ########################### . #",
    "# . . . . . . . . . . . . . . . . .G. . . . . . . . . . . . . . . . . #",
    "#######################################################################"
};

int x = 35, y = 14, effectiveTickTime = tickTime, score = 0, lives = 3,
    ghost1X = 54, ghost1Y = 20,
    ghost2X = 2, ghost2Y = 22,
    ghost3X = 3, ghost3Y = 16,
    ghost4X = 22, ghostY = 14;

bool gameRunning = true;
bool isEnergized = false;

bool movingLeft = false;
bool movingRight = false;
bool movingUp = false;
bool movingDown = false;

bool ghost1MovingUp = true;
bool ghost1MovingDown = false;

bool ghost2MovingRight = true;
bool ghost2MovingLeft = false;

bool ghost3movingLeft = false;
bool ghost3movingRight = false;
bool ghost3movingUp = false;
bool ghost3movingDown = false;

unsigned int seed = 12345;
int randy;

void gotoxy(int x, int y);
char getCharAt(int x, int y);
void hideCursor();
void clearScreen();
void loadMap();
void printMap();
void updatePacman();
void updateGhost1();
void updateGhost2();
void updateGhost3();
void updateGhost4();
void countScore();
int randomNumber(int min, int max);

int main() {
    clearScreen();
    hideCursor();
    loadMap();
    printMap();
    randy = randomNumber(1, 100);
    bool d = false;
    unsigned int randomInput = 0;
    while (gameRunning) {
        Sleep(100);
        updateGhost1();
        updateGhost2();
        if (randomInput % 4 == 0) randy = randomNumber(1, 100);
        updateGhost3();
       // updateGhost4();
        updatePacman();
        countScore();
        gotoxy(0, 28); cout << "Lives: " << lives << "\tScore: " << score;
        randomInput++;
        if (lives == 0) {
            clearScreen();
            cout << "Game over\tFinal Score: " << score;
            gameRunning = false;
        }
    }
    return 0;
}

void updateGhost1() {
    char bg_tile;
    if (ghost1MovingUp) {
        bg_tile = getCharAt(ghost1X, ghost1Y+1);
        if (bg_tile == '#') bg_tile = '.';
        
        
        if (bg_tile != '#') {
            bg_tile = getCharAt(ghost1X, ghost1Y-1);
            if (bg_tile == 'G') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost1X, ghost1Y);
            cout << bg_tile;
            gotoxy(ghost1X, ghost1Y-1);
            cout << "G";
            ghost1Y--;
            if (getCharAt(ghost1X, ghost1Y-1) == '#') {
                ghost1MovingDown = true;
                ghost1MovingUp = false;
            }
        }

    }
    else if (ghost1MovingDown) {
        bg_tile = getCharAt(ghost1X, ghost1Y-1);
        if (bg_tile == '#') bg_tile = '.';
        
        if (bg_tile != '#') {
            bg_tile = getCharAt(ghost1X, ghost1Y+1);
            if (bg_tile == 'G') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost1X, ghost1Y);
            cout << bg_tile;
            gotoxy(ghost1X, ghost1Y+1);
            cout << "G";
            ghost1Y++;
            if (getCharAt(ghost1X, ghost1Y+1) == '#') {
                ghost1MovingUp = true;
                ghost1MovingDown = false;
            }
        }
    }
}
char ghost3PrevChar = ' ';
void updateGhost2() {
    char bg_tile;
    if (ghost2MovingRight) {
        bg_tile = getCharAt(ghost2X-2, ghost2Y);
        if (bg_tile == '#') bg_tile = '.';
        
        if (bg_tile != '#') {
            bg_tile = getCharAt(ghost2X+1, ghost2Y);
            if (bg_tile == 'G') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost2X, ghost2Y);
            cout << bg_tile;
            gotoxy(ghost2X+1, ghost2Y);
            cout << "G";
            ghost2X++;
            if (getCharAt(ghost2X+2, ghost2Y) == '#') {
                ghost2MovingLeft = true;
                ghost2MovingRight = false;
            }
        }
    }
    else if (ghost2MovingLeft) {
        bg_tile = getCharAt(ghost2X+2, ghost2Y);
        if (bg_tile == '#') bg_tile = '.';
        if (bg_tile != '#') {
            bg_tile = getCharAt(ghost2X-1, ghost2Y);
            if (bg_tile == 'G') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost2X, ghost2Y);
            cout << bg_tile;
            gotoxy(ghost2X-1, ghost2Y);
            cout << "G";
            ghost2X--;
            if (getCharAt(ghost2X-2, ghost2Y) == '#') {
                ghost2MovingRight = true;
                ghost2MovingLeft = false;
            }
        }
    }
}
void updateGhost3() {
    if (randy >= 1 && randy <= 25) {
        ghost3movingRight = true;
        ghost3movingLeft = ghost3movingUp = ghost3movingDown = false;
    }
    else if (randy > 25 && randy <= 50) {
        ghost3movingLeft = true;
        ghost3movingRight = ghost3movingUp = ghost3movingDown = false;
    }
    else if (randy > 50 && randy <= 75) {
        if (getCharAt(ghost3X, ghost3Y - 1) != '#' && getCharAt(ghost3X+1, ghost3Y-1) != '#' && getCharAt(ghost3X-1, ghost3Y-1) != '#') {
            ghost3movingUp = true; 
            ghost3movingRight = ghost3movingLeft = ghost3movingDown = false;
        }
    }
    else if (randy > 75 && randy <= 100) {
        if (getCharAt(ghost3X, ghost3Y + 1) != '#' && getCharAt(ghost3X+1, ghost3Y+1) != '#' && getCharAt(ghost3X-1, ghost3Y+1) != '#') {
            ghost3movingDown = true; 
            ghost3movingRight = ghost3movingLeft = ghost3movingUp = false;
        }
    }

    if (ghost3movingRight && getCharAt(ghost3X + 2, ghost3Y) == '#') {
        ghost3movingRight = false;
    }
    if (ghost3movingLeft && getCharAt(ghost3X - 2, ghost3Y) == '#') {
        ghost3movingLeft = false;
    }
    if (ghost3movingUp && getCharAt(ghost3X, ghost3Y - 1) == '#') {
        ghost3movingUp = false;
    }
    if (ghost3movingDown && getCharAt(ghost3X, ghost3Y + 1) == '#') {
        ghost3movingDown = false;
    }
    
    // Erase ghost from previous position (print what was there before)
    gotoxy(ghost3X, ghost3Y);
    cout << ghost3PrevChar;

    // Calculate new position and store the character from it
    if (ghost3movingRight) {
        ghost3PrevChar = getCharAt(ghost3X + 1, ghost3Y);
        if (ghost3PrevChar == 'G') {
            ghost3PrevChar = ' ';
        }
        if (ghost3PrevChar == 'p') {
            lives--;
            x = 35, y = 14;
            ghost3PrevChar = ' ';
        }
        ghost3X++;
    }
    else if (ghost3movingLeft) {
        ghost3PrevChar = getCharAt(ghost3X - 1, ghost3Y);
        if (ghost3PrevChar == 'G') {
            ghost3PrevChar = ' ';
        }
        if (ghost3PrevChar == 'p') {
            lives--;
            x = 35, y = 14;
            ghost3PrevChar = ' ';
        }
        ghost3X--;
    }
    else if (ghost3movingUp) {
        ghost3PrevChar = getCharAt(ghost3X, ghost3Y - 1);
        if (ghost3PrevChar == 'G') {
            ghost3PrevChar = ' ';
        }
        if (ghost3PrevChar == 'p') {
            lives--;
            x = 35, y = 14;
            ghost3PrevChar = ' ';
        }
        ghost3Y--;
    }
    else if (ghost3movingDown) {
        ghost3PrevChar = getCharAt(ghost3X, ghost3Y + 1);
        if (ghost3PrevChar == 'G') {
            ghost3PrevChar = ' ';
        }
        if (ghost3PrevChar == 'p') {
            lives--;
            x = 35, y = 14;
            ghost3PrevChar = ' ';
        }
        ghost3Y++;
    }

    // Draw ghost at new position
    gotoxy(ghost3X, ghost3Y);
    cout << "G";
    
}

enum Direction { NONE, LEFT, RIGHT, UP, DOWN };
Direction ghostLastDir = NONE;

bool clearPathHorizontally(int fromX, int toX, int y) {
    int step = (toX > fromX) ? 1 : -1;
    for (int i = fromX + step; i != toX; i += step) {
        if (getCharAt(i, y) == '#') return false;
    }
    return true;
}

void updateGhost4() {
    gotoxy(ghost4X, ghostY);
    cout << " ";

    int dx = x - ghost4X;
    int dy = y - ghostY;
    bool moved = false;

    // Not aligned vertically → focus on aligning Y
    if (ghostY != y) {
        int dirY = (dy > 0) ? 1 : -1;

        if (getCharAt(ghost4X, ghostY + dirY) != '#') {
            ghostY += dirY;
            ghostLastDir = (dirY > 0) ? DOWN : UP;
            moved = true;
        } else {
            // Y path blocked → smart side-step
            if (getCharAt(ghost4X + 1, ghostY) != '#' && ghostLastDir != LEFT) {
                ghost4X++;
                ghostLastDir = RIGHT;
                moved = true;
            } else if (getCharAt(ghost4X - 1, ghostY) != '#' && ghostLastDir != RIGHT) {
                ghost4X--;
                ghostLastDir = LEFT;
                moved = true;
            }
        }
    }
    // Vertically aligned → try horizontal move if clear path
    else {
        if (clearPathHorizontally(ghost4X, x, ghostY)) {
            int dirX = (dx > 0) ? 1 : -1;

            if (getCharAt(ghost4X + dirX, ghostY) != '#') {
                ghost4X += dirX;
                ghostLastDir = (dirX > 0) ? RIGHT : LEFT;
                moved = true;
            }
        } else {
            // Horizontal path blocked → re-align Y to find another angle
            if (getCharAt(ghost4X, ghostY + 1) != '#' && ghostLastDir != UP) {
                ghostY++;
                ghostLastDir = DOWN;
                moved = true;
            } else if (getCharAt(ghost4X, ghostY - 1) != '#' && ghostLastDir != DOWN) {
                ghostY--;
                ghostLastDir = UP;
                moved = true;
            }
        }
    }

    // Fallback if stuck
    if (!moved) {
        if (getCharAt(ghost4X + 1, ghostY) != '#') {
            ghost4X++;
            ghostLastDir = RIGHT;
        } else if (getCharAt(ghost4X - 1, ghostY) != '#') {
            ghost4X--;
            ghostLastDir = LEFT;
        } else if (getCharAt(ghost4X, ghostY + 1) != '#') {
            ghostY++;
            ghostLastDir = DOWN;
        } else if (getCharAt(ghost4X, ghostY - 1) != '#') {
            ghostY--;
            ghostLastDir = UP;
        }
    }

    gotoxy(ghost4X, ghostY);
    cout << "G";
}

void updatePacman() {
    // Handle input once (toggle logic)
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        movingRight = true; 
        movingLeft = movingUp = movingDown = false;
    } 
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        movingLeft = true; 
        movingRight = movingUp = movingDown = false;
    } 
    else if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (getCharAt(x, y - 1) != '#' && getCharAt(x+1, y-1) != '#' && getCharAt(x-1, y-1) != '#') {
            movingUp = true; 
            movingRight = movingLeft = movingDown = false;
        }
    } 
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (getCharAt(x, y + 1) != '#' && getCharAt(x+1, y+1) != '#' && getCharAt(x-1, y+1) != '#') {
            movingDown = true; 
            movingRight = movingLeft = movingUp = false;
        }
    }

    // Wall hit detection – cancel movement if a wall is ahead
    if (movingRight && getCharAt(x + 2, y) == '#') movingRight = false;
    if (movingLeft && getCharAt(x - 2, y) == '#') movingLeft = false;
    if (movingUp && getCharAt(x, y - 1) == '#') movingUp = false;
    if (movingDown && getCharAt(x, y + 1) == '#') movingDown = false;

    // Move Pac-Man
    gotoxy(x, y); cout << " ";
    if (movingRight) x++; 
    else if (movingLeft) x--;
    else if (movingDown) y++;
    else if (movingUp) y--;
    gotoxy(x, y); cout << "p";
}

int randomNumber(int min, int max) {
    seed = 1664525 * seed + 1013904223;
    return min + (seed % (max - min + 1));
}

void countScore() {
    if (getCharAt(x + 1, y) == '.' && movingRight) {
        score++;
    }
    else if (getCharAt(x - 1, y) == '.' && movingLeft) {
        score++;
    }
    else if (getCharAt(x, y + 1) == '.' && movingDown) {
        score++;
    }
    else if (getCharAt(x, y - 1) == '.' && movingUp) {
        score++;
    }
}

void printMap() {
    for (int row = 0; row < 24; row++) {
        for (int col = 0; col < 71; col++) {
            cout << mapp[row][col];
        }
        cout << endl;
    }
}

void loadMap() {
    fstream map;
    map.open("map2.txt", ios::in);
    if (!map.is_open()) {
        cerr << "Error: Could not open map file.\n";
        exit(1);
    }

    string line;
    for (int row = 0; row < 24 && getline(map, line); row++) {
        for (int col = 0; col < 71 && col < line.length(); col++) {
            mapp[row][col] = line[col];
        }
    }

    map.close();
}

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAt(int x, int y) {
    CHAR ch;
    DWORD read;
    COORD coord = { (SHORT)x, (SHORT)y };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (ReadConsoleOutputCharacterA(hConsole, &ch, 1, coord, &read)) {
        return ch;
    } else {
        return '\0'; // Return null character if read fails
    }
}

void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);  // Get current cursor settings
    cursorInfo.bVisible = FALSE;                  // Set cursor visibility to false
    SetConsoleCursorInfo(hConsole, &cursorInfo);  // Apply the new settings
}

void clearScreen() {
    system("cls");
}
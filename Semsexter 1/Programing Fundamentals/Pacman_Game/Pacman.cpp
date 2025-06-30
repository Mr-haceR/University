#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

// Constants
const int rows = 31;
const int cols = 71;
const int tickTime = 100;
const int ghost1StartX = 54, ghost1StartY = 20,
          ghost2StartX = 2, ghost2StartY = 22,
          ghost3StartX = 3, ghost3StartY = 16,
          ghost4StartX = 22, ghost4StartY = 9;

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
    "############### . ###   #########     #########   ### . ###############",
    "# . . . . . . . .       #                     #       . . . . . . . . #",
    "############### . ###   #                     #   ### . ###############",
    "              # . ###   #######################   ### . #              ",
    "              # . ### G            p              ### . #              ",
    "############### . ###   #######################   ### . ###############",
    "# .G. . . . . . . . . . . . . . . ### . . . . . . . . . . . . . . . . #",
    "# O ########### . ############# . ### . ############# . ########### O #",
    "# . . . ####### . . . . . . . . . . . . . . . . . . . . ####### . . . #",
    "##### . ####### . ### . ####################### . ### . ####### . #####",
    "# . . . . . . . . ### . . . . . . ### . . . . . . ### G . . . . . . . #",
    "# . ########################### . ### . ########################### . #",
    "# . . . . . . . . . . . . . . . . .G. . . . . . . . . . . . . . . . . #",
    "#######################################################################"
};

// Globol Variables
int x = 35, y = 14, tickCounter = 0, score = 0, lives = 3, randy, tickCountForisEnergized = 0,
    ghost1X = ghost1StartX, ghost1Y = ghost1StartY,
    ghost2X = ghost2StartX, ghost2Y = ghost2StartY,
    ghost3X = ghost3StartX, ghost3Y = ghost3StartY,
    ghost4X = ghost4StartX, ghost4Y = ghost4StartY;

bool gameRunning = true;
bool isEnergized = false;

// Pacman Direction Flags
bool movingLeft = false;
bool movingRight = false;
bool movingUp = false;
bool movingDown = false;

// ghost1 Direction Flags
bool ghost1MovingUp = true;
bool ghost1MovingDown = false;

// ghost2 Direction Flags
bool ghost2MovingRight = true;
bool ghost2MovingLeft = false;

// ghost3 Direction Flags
bool ghost3movingLeft = false;
bool ghost3movingRight = false;
bool ghost3movingUp = false;
bool ghost3movingDown = false;

// Seed for Psuedo-Random Path of ghost3
unsigned int seed = 6969;

// Function Prototypes
void SetColor(int color);
void gotoxy(int x, int y);
char getCharAt(int x, int y);
void hideCursor();
void clearScreen();
void loadMap();
void printMap();
void updatePacman();
void updateGhost1();
void updateGhost2();
bool clearPathHorizontally(int fromX, int toX, int y);
void updateGhost3();
void updateGhost4();
void countScore();
int randomNumber(int min, int max);

// main Function
int main() {
    clearScreen();
    hideCursor();
    loadMap();
    printMap();
    randy = randomNumber(1, 100); // Initial random Input for ghost3
    unsigned int randomInput = 0;
    while (gameRunning) {
        Sleep(tickTime);

        if (randomInput % 4 == 0) randy = randomNumber(1, 100); // Updating ghost3 direction every 4 ticks to reduce chaotic direction changes.

        // Updating All GameObjects
        updateGhost1();
        updateGhost2();
        updateGhost3();
        updateGhost4();
        updatePacman();
        randomInput++;

        // Printing Score
        gotoxy(0, 28); cout << "Lives: " << lives << "\tScore: " << score;
        

        // Game Over Checks
        if (score >= 250) {
            clearScreen();
            cout << "You Won!!!\tFinal Score: " << score;
            gameRunning = false;
        }
        else if (lives == 0) {
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
            if (bg_tile == 'G' || bg_tile == 'g') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost1X, ghost1Y);
            cout << bg_tile;
            gotoxy(ghost1X, ghost1Y-1);
            SetColor(5); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
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
            if (bg_tile == 'G' || bg_tile == 'g') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost1X, ghost1Y);
            cout << bg_tile;
            gotoxy(ghost1X, ghost1Y+1);
            SetColor(5); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
            ghost1Y++;
            if (getCharAt(ghost1X, ghost1Y+1) == '#') {
                ghost1MovingUp = true;
                ghost1MovingDown = false;
            }
        }
    }
}

void updateGhost2() {
    char bg_tile;
    if (ghost2MovingRight) {
        bg_tile = getCharAt(ghost2X-2, ghost2Y);
        if (bg_tile == '#') bg_tile = '.';
        if (bg_tile != '#') {
            bg_tile = getCharAt(ghost2X+1, ghost2Y);
            if (bg_tile == 'G' || bg_tile == 'g') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost2X, ghost2Y);
            cout << bg_tile;
            gotoxy(ghost2X+1, ghost2Y);
            SetColor(4); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
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
            if (bg_tile == 'G' || bg_tile == 'g') bg_tile = ' ';
            if (bg_tile == 'p') {lives--;x = 35, y = 14;bg_tile = ' ';}
            gotoxy(ghost2X, ghost2Y);
            cout << bg_tile;
            gotoxy(ghost2X-1, ghost2Y);
            SetColor(4); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
            ghost2X--;
            if (getCharAt(ghost2X-2, ghost2Y) == '#') {
                ghost2MovingRight = true;
                ghost2MovingLeft = false;
            }
        }
    }
}

char ghost3PrevChar = ' ';
void updateGhost3() {
    // Check for Random Inputs
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

    // Wall Detection
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
    
    gotoxy(ghost3X, ghost3Y);
    cout << ghost3PrevChar;
    
    // Necessary checks for stuff!
    if (ghost3movingRight) {
        ghost3PrevChar = getCharAt(ghost3X + 1, ghost3Y);
        if (ghost3PrevChar == 'G' || ghost3PrevChar == 'g') {
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
        if (ghost3PrevChar == 'G' || ghost3PrevChar == 'g') {
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
        if (ghost3PrevChar == 'G' || ghost3PrevChar == 'g') {
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
        if (ghost3PrevChar == 'G' || ghost3PrevChar == 'g') {
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
    SetColor(2); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
}

// 0 = none, 1 = left, 2 = right, 3 = up, 4 = down
int ghostLastDir = 0;
char ghost4PreviousChar = ' ';

// Function to check if there is a wall between pacman and ghost, when they are vetically aligned :)
bool clearPathHorizontally(int fromX, int toX, int y) {
    int step = (toX > fromX) ? 1 : -1;
    for (int i = fromX + step; i != toX; i += step) {
        if (getCharAt(i, y) == '#') return false;
    }
    return true;
}

void updateGhost4() {
    // Restore the previous background character
    gotoxy(ghost4X, ghost4Y);
    cout << ghost4PreviousChar;

    // Store the current charcter at the new location
    int dx = x - ghost4X;
    int dy = y - ghost4Y;
    bool moved = false;
    int newX = ghost4X, newY = ghost4Y;

    if (dy != 0) {
        int stepY = (dy > 0) ? 1 : -1;
        if (getCharAt(ghost4X, ghost4Y + stepY) != '#') {
            newY += stepY;
            ghostLastDir = (stepY > 0) ? 4 : 3;
            moved = true;
        } 
        else {
            if (getCharAt(ghost4X + 1, ghost4Y) != '#' && ghostLastDir != 1) {
                newX++;
                ghostLastDir = 2;
                moved = true;
            } 
            else if (getCharAt(ghost4X - 1, ghost4Y) != '#' && ghostLastDir != 2) {
                newX--;
                ghostLastDir = 1;
                moved = true;
            }
        }
    } 
    else {
        if (clearPathHorizontally(ghost4X, x, ghost4Y)) {
            int stepX = (dx > 0) ? 1 : -1;
            if (getCharAt(ghost4X + stepX, ghost4Y) != '#') {
                newX += stepX;
                ghostLastDir = (stepX > 0) ? 2 : 1;
                moved = true;
            }
        } 
        else {
            if (getCharAt(ghost4X, ghost4Y + 1) != '#' && ghostLastDir != 3) {
                newY++;
                ghostLastDir = 4;
                moved = true;
            } 
            else if (getCharAt(ghost4X, ghost4Y - 1) != '#' && ghostLastDir != 4) {
                newY--;
                ghostLastDir = 3;
                moved = true;
            }
        }
    }

    // Fallback
    if (!moved) {
        if (getCharAt(ghost4X + 1, ghost4Y) != '#') {
            newX++;
            ghostLastDir = 2;
        } else if (getCharAt(ghost4X - 1, ghost4Y) != '#') {
            newX--;
            ghostLastDir = 1;
        } else if (getCharAt(ghost4X, ghost4Y + 1) != '#') {
            newY++;
            ghostLastDir = 4;
        } else if (getCharAt(ghost4X, ghost4Y - 1) != '#') {
            newY--;
            ghostLastDir = 3;
        }
    }

    // Update ghast position and store th background char at new position
    ghost4PreviousChar = getCharAt(newX, newY);
    ghost4X = newX;
    ghost4Y = newY;

    // Reset position if pacman is energizzed
    if (ghost4X == x && ghost4Y == y) {
        if (!isEnergized) {
            lives--;
            x = 35, y = 14;
        } else {
            ghost4X = ghost4StartX;
            ghost4Y = ghost4StartY;
            ghost4PreviousChar = getCharAt(ghost4X, ghost4Y);
            gotoxy(ghost4X, ghost4Y);
            SetColor(3); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
        }
        
    }

    gotoxy(ghost4X, ghost4Y);
    if (ghost4PreviousChar != 'p' && ghost4PreviousChar != 'J' && ghost4PreviousChar != 'g' && ghost4PreviousChar != 'G') {
        cout << ghost4PreviousChar;
    }
    gotoxy(ghost4X, ghost4Y);
    // Draw ghost at new position
    
    SetColor(3); isEnergized ? cout << "g" : cout << "G"; SetColor(7);
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
        if (getCharAt(x, y - 1) != '#' && getCharAt(x + 1, y - 1) != '#' && getCharAt(x - 1, y - 1) != '#') {
            movingUp = true; 
            movingRight = movingLeft = movingDown = false;
        }
    } 
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (getCharAt(x, y + 1) != '#' && getCharAt(x + 1, y + 1) != '#' && getCharAt(x - 1, y + 1) != '#') {
            movingDown = true; 
            movingRight = movingLeft = movingUp = false;
        }
    }

    // Wall hit detection – cancel movement if a wall is ahead
    if (movingRight && getCharAt(x + 2, y) == '#') movingRight = false;
    if (movingLeft && getCharAt(x - 2, y) == '#') movingLeft = false;
    if (movingUp && getCharAt(x, y - 1) == '#') movingUp = false;
    if (movingDown && getCharAt(x, y + 1) == '#') movingDown = false;

    countScore();

    // Clear previous Pac-Man
    gotoxy(x, y); cout << " ";

    // Move Pac-Man
    if (movingRight) x++;
    else if (movingLeft) x--;
    else if (movingDown) y++;
    else if (movingUp) y--;

    // Check for ghost collision
    if (getCharAt(x, y) == 'G') {
        lives--;
        x = 35, y = 14;
    }

    // Draw Pac-Man
    gotoxy(x, y);
    SetColor(6);
    cout << (isEnergized ? 'J' : 'p');
    SetColor(7);
}

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
    if ((getCharAt(x + 1, y) == 'O' && movingRight) || (getCharAt(x - 1, y) == 'O' && movingLeft) || (getCharAt(x, y + 1) == 'O' && movingDown) || (getCharAt(x, y - 1) == 'O' && movingUp)) {
        isEnergized = true;
        score += 4;
    }
    if ((getCharAt(x + 1, y) == 'g' && movingRight) || (getCharAt(x - 1, y) == 'g' && movingLeft) || (getCharAt(x, y + 1) == 'g' && movingDown) || (getCharAt(x, y - 1) == 'g' && movingUp)) {
        score += 10;
    }
    if (isEnergized) {
        tickCountForisEnergized++;
        if (tickCountForisEnergized == 30) {
            isEnergized = false;
            tickCountForisEnergized = 0;
        }
    }
}

void printMap() {
    for (int row = 0; row < 24; row++) {
        for (int col = 0; col < 71; col++) {
            mapp[row][col] == '#' ? SetColor(1) : SetColor(7);
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
    GetConsoleCursorInfo(hConsole, &cursorInfo);  
    cursorInfo.bVisible = FALSE;                  
    SetConsoleCursorInfo(hConsole, &cursorInfo);  
}

void clearScreen() {
    system("cls");
}
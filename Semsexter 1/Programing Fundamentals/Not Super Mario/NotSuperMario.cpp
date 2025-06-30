#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int levelRows = 28;
const int levelColumns = 530;  
const int renderWidth = 100;
const int cameraMargin = renderWidth / 2;
const string player = "\033[48;2;46;188;254m@\033[0m\033[48;2;46;188;254m";



char level[levelRows][levelColumns];
char render[levelRows][renderWidth];

string levelNo = "";

int playerX = 6, playerY = 7;
int score = 0, health = 3;
float playerYFloat = playerY;
float velocityY = 0.0f;
float gravity = 0.3f;
float jumpStrength = -2.5f;

int cameraX = 0;
bool gameRunning = true;

void mainMenu();
bool loadLevel(string levelFileName);

void updateRender();
void drawFrame();
void movePlayer(string direction);
void gotoxy(int x, int y);
void hideCursor();
bool isGrounded();
void clearScreen();
char getCharAtLevel(int x, int y);
void moveEnemy(int row, int &col, int &direction, char enemyChar);
void clearInputBuffer();

int main() { 
    cout << "\033[0m";
    hideCursor();

    if (levelNo == "") mainMenu();
    const int MAX_ENEMIES = 10;
    int enemyX[MAX_ENEMIES] = {23};   
    int enemyY[MAX_ENEMIES] = {115}; 
    int enemyDir[MAX_ENEMIES] = {1};  
    int enemyCount = 1;
    if (!loadLevel(levelNo+".txt")) {
        cout << "Failed to load level.\n";
        return 1;
    }
    clearScreen();
   

    updateRender();
    drawFrame();
    gotoxy(playerX - cameraX, playerY);
    cout << player;
    while (gameRunning) {
        Sleep(10);
        if ((playerY >= levelRows + 3) || (getCharAtLevel(playerX, playerY)) == 'E') {
            health--;
            cameraX = 0;
            playerX = 6;
            playerY = 7;
            if (health == 0) {
                levelNo = "level1";
                health = 3;
                score = 0;
                main();
            }
            else if (health > 0) {
                cout << "\033[0m";
            }
        }
        for (int i = 0; i < enemyCount; i++) {
            moveEnemy(enemyX[i], enemyY[i], enemyDir[i], 'E');
        }

        // Movement
        if (GetAsyncKeyState('A') & 0x8000) movePlayer("LEFT");
        else if (GetAsyncKeyState('D') & 0x8000) movePlayer("RIGHT");

        // Jump
        if ((GetAsyncKeyState('W') & 0x0001) && isGrounded()) {
            velocityY = jumpStrength;
        }

        // Gravitity and collision
        velocityY += gravity;
        float nextYFloat = playerYFloat + velocityY;
        int newY = (int)(nextYFloat);

        while (playerY != newY) {
            int step = (newY > playerY) ? 1 : -1;
            if (getCharAtLevel(playerX, playerY + step) == '#' || 
                getCharAtLevel(playerX, playerY + step) == 'M' || 
                getCharAtLevel(playerX, playerY + step) == '%') {
                if (getCharAtLevel(playerX, playerY + step) == 'M' && step < 0) score++;
                velocityY = 0;
                playerYFloat = playerY;
                break;
            }
            
            gotoxy(playerX - cameraX, playerY); cout << " ";
            playerY += step;
            gotoxy(playerX - cameraX, playerY); cout << player;
        }

        playerYFloat += velocityY;

        // Camera 
        if (playerX - cameraX >= cameraMargin && cameraX + renderWidth < levelColumns) {
            cameraX = playerX - cameraMargin;
        } 
        else if (playerX - cameraX < cameraMargin && cameraX > 0) {
            cameraX = max(0, playerX - cameraMargin);
        }

        updateRender();
        drawFrame();
        gotoxy(playerX - cameraX, playerY);
        cout << player;

        
        
        
        // Exit
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            levelNo = "";
            main();
        }
      
    }
    cout << "\033[0m";
    clearScreen();
    return 0;
}

void moveEnemy(int row, int &col, int &direction, char enemyChar) {
    level[row][col] = ' ';

    int nextCol = col + direction;
    if (level[row][nextCol] == '%') {
        direction *= -1;
        nextCol = col + direction;
    }

    col = nextCol;
    level[row][col] = enemyChar;
}

void mainMenu() {
    clearInputBuffer();
    const int ROWS = 25;
    const int COLS = 116;
    clearScreen();
    char menu[ROWS][COLS];
    fstream file;
    file.open("MenuScreen.txt", ios::in);

    if (!file) {
        cout << "Failed to open file.\n";
        return;
    }

    string line;
    int row = 0;
    while (getline(file, line) && row < ROWS) {
        for (int col = 0; col < COLS; ++col) {
            menu[row][col] = (col < line.length()) ? line[col] : ' ';
        }
        row++;
    }

    // Concatenate into a string and print
    string result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (menu[i][j] == '#') result += "\033[48;2;116;0;0m\033[38;2;0;0;0m" + string(1, menu[i][j]) + "\033[0m";
            else if (menu[i][j] == '*') result += "\033[48;2;0;0;0m\033[38;2;255;255;0m" + string(1, menu[i][j]) + "\033[0m";
            else result += "\033[48;2;46;188;254m" + string(1, menu[i][j]) + "\033[0m";
        }
        result += '\n';
    }

    cout << result;
    char choice = getch();
    if (choice == '1') {
        levelNo = "level1";
        cameraX = 0; playerX = 6; playerY = 7; score = 0; health = 3; cout << "\033[0m";
    }
    else if (choice == '3') {
        clearScreen();
        exit(0);
    }
    else mainMenu();
}

void movePlayer(string direction) {
    int newX = playerX;
    if (direction == "LEFT") newX--;
    else if (direction == "RIGHT") newX++;

    if (newX >= 0 && newX < levelColumns && (getCharAtLevel(newX, playerY) != '#' && getCharAtLevel(newX, playerY) != 'M' && getCharAtLevel(newX, playerY) != '%')) {
        gotoxy(playerX - cameraX, playerY); cout << ' ';
        playerX = newX;
        gotoxy(playerX - cameraX, playerY); cout << player;
    }
    if (newX >= 0 && newX < levelColumns && getCharAtLevel(newX, playerY) == '"') {
        if (levelNo == "level1") levelNo = "level2";
        else if (levelNo == "level2") levelNo = "level3";
        else if (levelNo == "level3") {
            clearInputBuffer();
            const int ROWS = 25;
            const int COLS = 116;
            clearScreen();
            char win[ROWS][COLS];
            fstream file;
            file.open("WinScreen.txt", ios::in);

            if (!file) {
                cout << "Failed to open file.\n";
                return;
            }

            string line;
            int row = 0;
            while (getline(file, line) && row < ROWS) {
                for (int col = 0; col < COLS; ++col) {
                    win[row][col] = (col < line.length()) ? line[col] : ' ';
                }
                row++;
            }

            // Concatenate into a string and print
            clearScreen();
            string result;
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    if (win[i][j] == '#') result += "\033[48;2;116;0;0m\033[38;2;0;0;0m" + string(1, win[i][j]) + "\033[0m";
                    else if (win[i][j] == '*') result += "\033[48;2;0;0;0m\033[38;2;255;255;0m" + string(1, win[i][j]) + "\033[0m";
                    else result += "\033[48;2;46;188;254m" + string(1, win[i][j]) + "\033[0m";
                }
                result += '\n';
            }
            
            cout << result;
            getch();
            exit(0);
        }
        cameraX = 0; playerX = 6; playerY = 7; cout << "\033[0m";
        main();
    }
    if (playerY == levelRows + 3 || getCharAtLevel(newX, playerY) == 'E') {
        health--;
            cameraX = 0;
            playerX = 6;
            playerY = 7;
            if (health == 0) {
                levelNo = "level1";
                health = 3;
                score = 0;
                main();
            }
            else if (health > 0) {
                cout << "\033[0m";
            }
    }
}


bool isGrounded() {
    return (getCharAtLevel(playerX, playerY + 1) == '#' || getCharAtLevel(playerX, playerY + 1) == 'M' || getCharAtLevel(playerX, playerY + 1) == '%');
}

bool loadLevel(string levelFileName) {
    fstream file(levelFileName, ios::in);
    if (file.is_open()) {
        string line;
        for (int row = 0; row < levelRows; row++) {
            getline(file, line);
            for (int col = 0; col < levelColumns; col++) {
                level[row][col] = line[col];
            }
        }
        file.close();
        return true;
    }
    return false;
}

void updateRender() {
    for (int row = 0; row < levelRows; row++) {
        for (int col = 0; col < renderWidth; col++) {
            if (cameraX + col < levelColumns) {
                render[row][col] = level[row][cameraX + col];
            } 
            else {
                render[row][col] = ' ';
            }
        }
    }
    string sc = "Score: " + to_string(score);
    for (int i = 0; i < sc.length(); i++) {
        render[2][i+3] = sc[i]; 
    }
    string h = "Health: " + to_string(health);
    for (int i = 0; i < h.length(); i++) {
        render[2][i+80] = h[i]; 
    }
}

void drawFrame() {
    gotoxy(0, 0);
    string frame;
    for (int row = 0; row < levelRows; row++) {
        for (int col = 0; col < renderWidth; col++) {
            if (render[row][col] == 'M') frame += "\033[48;2;255;255;0m\033[38;2;255;255;0m" + string(1, render[row][col]) + "\033[0m";
            else if (render[row][col] == '%') frame += "\033[48;2;0;255;0m\033[38;2;0;255;0m" + string(1, render[row][col]) + "\033[0m";
            else if (render[row][col] == '#') frame += "\033[48;2;116;0;0m\033[38;2;116;0;0m" + string(1, render[row][col]) + "\033[0m";
            else if (render[row][col] == '?') frame += "\033[48;2;46;188;254m" + string(1, render[row][col]) + "\033[0m";
            else if (render[row][col] == '/' || render[row][col] == '\\' || render[row][col] == '|') frame += "\033[48;2;0;0;0m\033[38;2;0;0;0m" + string(1, render[row][col]) + "\033[0m";
            else frame += "\033[48;2;46;188;254m" + string(1, render[row][col]) + "\033[0m";
        }
        frame += "\n";
    }
    cout << frame;
}

char getCharAtLevel(int x, int y) {
    if (x >= 0 && x < levelColumns && y >= 0 && y < levelRows) {
        return level[y][x];
    }
    return ' ';
}

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hConsole, &info);
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &info);
}

void clearScreen() {
    system("cls");
}

void clearInputBuffer() {
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
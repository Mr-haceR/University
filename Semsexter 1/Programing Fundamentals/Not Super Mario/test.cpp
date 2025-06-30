#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int levelRows = 28;
const int levelColumns = 530;  
const int renderWidth = 100;
const int cameraMargin = renderWidth / 2;
const string player = "\033[48;2;46;188;254m\033[38;2;0;0;0m@\033[0m\033[48;2;46;188;254m";
const int MAX_HEALTH = 3;

const int NONGAMEPLAYSCREENROWS = 25;
const int NONGAMEPLAYSCREENCOLUMNS = 116;

const char enemyCharacter = 'E';
const int MAX_ENEMIES = 10;









string nonGamePlayScreens(string filename, char nonGamePlayScreen[][NONGAMEPLAYSCREENCOLUMNS]);
bool loadLevel(char level[][levelColumns], string levelFileName);
void handleLevelTransition(string &levelNo, int &cameraX, int &playerX, int &playerY, bool &gameRunning, char nonGamePlayScreen[][NONGAMEPLAYSCREENCOLUMNS]);
void updateRender(char level[][levelColumns], char render[][renderWidth], int &cameraX, int &score, int &health);
void drawFrame(char render[][renderWidth]);
char movePlayer(char level[][levelColumns], string direction, string &levelNo, int &playerX, int &playerY, int &cameraX);
void gotoxy(int x, int y);
void hideCursor();
bool isGrounded(char level[][levelColumns], int &playerX, int &playerY);
void clearScreen();
char getCharAtLevel(char level[][levelColumns], int x, int y);
void moveEnemy(char level[][levelColumns], int row, int &col, int &direction, char enemyChar);
void clearInputBuffer();

int main() { 
    srand(time(0));
    char level[levelRows][levelColumns];
    char render[levelRows][renderWidth];
    char nonGamePlayScreen[NONGAMEPLAYSCREENROWS][NONGAMEPLAYSCREENCOLUMNS];
    string levelNo = "";

    int playerX = 6, playerY = 7;
    float playerYFloat = playerY;float velocityY = 0.0f;
    float gravity = 0.3f;
    float jumpStrength = -2.5f;

    
    int cameraX = 0;

    int score = 0, health = MAX_HEALTH;

    bool gameRunning = true;


    // Mystery Box Coords
    int level1MysteryBoxX[5] = {76, 77, 78, 79, 80};
    int level1MysteryBoxY[3] = {5, 6, 7};
    int level2MysteryBoxX[5] = {301, 302, 303, 304, 305};
    int level2MysteryBoxY[3] = {15, 16, 17};
    int level3MysteryBoxX[5] = {319, 320, 321, 322, 323};
    int level3MysteryBoxY[3] = {15, 16, 17};

    hideCursor();
    a:
    if (levelNo == "") {
        cout << nonGamePlayScreens("MenuScreen", nonGamePlayScreen);
        char choice = getch();
        if (choice == '1') {
            levelNo = "level1";
            cameraX = 0; playerX = 6; playerY = 7; score = 0; health = 3; cout << "\033[0m";
        }
        else if (choice == '3') {
            // Reset Console
            clearScreen();
            exit(0);
        }
        else goto a;
    }

    // Enemies Coords
    
    int enemyX[MAX_ENEMIES] = {23, 23, 23, 23};   
    int enemyY[MAX_ENEMIES] = {115, 165, 275, 290}; 
    int enemyDir[MAX_ENEMIES] = {1, -1, 1, -1};  
    int enemyCount = 4;

    // Load the level
    if (!loadLevel(level, levelNo+".txt")) {
        cout << "Failed to load level.\n";
        return 1;
    }

    clearScreen();
   
    updateRender(level, render, cameraX, score, health);
    drawFrame(render);
    gotoxy(playerX - cameraX, playerY);
    cout << player;

    while (gameRunning) {
        Sleep(20);

        // Update Enemies
        for (int i = 0; i < enemyCount; i++) {
            moveEnemy(level, enemyX[i], enemyY[i], enemyDir[i], enemyCharacter);
        }

        // Movement, Coins and level transition
        if ((GetAsyncKeyState('A') & 0x8000) || (GetAsyncKeyState('D') & 0x8000)) {
            string direction = (GetAsyncKeyState('A') & 0x8000) ? "LEFT" : "RIGHT";
            char ch = movePlayer(level, direction, levelNo, playerX, playerY, cameraX);
            if (ch == '"') {
                handleLevelTransition(levelNo, cameraX, playerX, playerY, gameRunning, nonGamePlayScreen);
                goto a;
            }
            else if (ch == 'O') {
                score++;
                level[playerY][playerX] = ' ';
            }
            
        }

        // Jump
        if ((GetAsyncKeyState('W') & 0x0001) && isGrounded(level, playerX, playerY)) {
            velocityY = jumpStrength;
        }

        // Gravitity and collision
        velocityY += gravity;
        float nextYFloat = playerYFloat + velocityY;
        int newY = (int)(nextYFloat);

        while (playerY != newY) {
            int step = (newY > playerY) ? 1 : -1;
            if (getCharAtLevel(level, playerX, playerY + step) == '#' || 
                getCharAtLevel(level, playerX, playerY + step) == 'M' || 
                getCharAtLevel(level, playerX, playerY + step) == '%') {

                // Mystery Box Removal Logic
                if (getCharAtLevel(level, playerX, playerY + step) == 'M' && step < 0) {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (levelNo == "level1") {
                                level[level1MysteryBoxY[j]][level1MysteryBoxX[i]] = ' ';
                            }
                            else if (levelNo == "level2") {
                                level[level2MysteryBoxY[j]][level2MysteryBoxX[i]] = ' ';
                            }
                            else if (levelNo == "level3") {
                                level[level3MysteryBoxY[j]][level3MysteryBoxX[i]] = ' ';
                            }
                        }
                    }
                    score += rand() % 91 + 10;
                }

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

        updateRender(level, render, cameraX, score, health);
        drawFrame(render);
        gotoxy(playerX - cameraX, playerY);
        cout << player;

        // Health System
        if ((playerY >= levelRows + 3) || (getCharAtLevel(level, playerX, playerY)) == 'E' || (getCharAtLevel(level, playerX+1, playerY)) == 'E' || (getCharAtLevel(level, playerX-1, playerY)) == 'E') {
            health--;
            cameraX = 0;
            playerX = 6;
            playerY = 7;
            if (health == 0) {
                levelNo = "level1";
                health = 3;
                score = 0;
                b:
                cout << nonGamePlayScreens("LostScreen", nonGamePlayScreen);
                char ch = getch();
                if (ch == '1') goto a;
                else if (ch == '2') {
                    levelNo = "";
                    goto a;
                }
                else if (ch == '3') gameRunning = false;
                else goto b;
            }
            else if (health > 0) {
                cout << "\033[0m";
            }
        }

        // Exit to Main menu
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            levelNo = "";
            main();
        }
    }

    // Reset Console
    cout << "\033[0m"; 
    clearScreen();

    return 0;
}

void handleLevelTransition(string &levelNo, int &cameraX, int &playerX, int &playerY, bool &gameRunning, char nonGamePlayScreen[][NONGAMEPLAYSCREENCOLUMNS]) {
    if (levelNo == "level1") levelNo = "level2";
    else if (levelNo == "level2") levelNo = "level3";
    else if (levelNo == "level3") {
        while (true) {
            cout << nonGamePlayScreens("WinScreen", nonGamePlayScreen);
            char ch = getch();
            if (ch == 'q' || ch == 'Q') {
                gameRunning = false;
                break;
            }
        }
    }
    cameraX = 0;
    playerX = 6;
    playerY = 7;
    cout << "\033[0m";
}

void moveEnemy(char level[][levelColumns], int row, int &col, int &direction, char enemyChar) {
    level[row][col] = ' ';

    int nextCol = col + direction;
    if (level[row][nextCol] == '%' || level[row][nextCol] == '#') {
        direction *= -1;
        nextCol = col + direction;
    }

    col = nextCol;
    level[row][col] = enemyChar;
}

string nonGamePlayScreens(string filename, char nonGamePlayScreen[][NONGAMEPLAYSCREENCOLUMNS]) {
    clearInputBuffer();
    clearScreen();
    char screen[NONGAMEPLAYSCREENROWS][NONGAMEPLAYSCREENCOLUMNS];
    fstream file;
    file.open(filename+".txt", ios::in);

    string line;
    int row = 0;
    while (getline(file, line) && row < NONGAMEPLAYSCREENROWS) {
        for (int col = 0; col < NONGAMEPLAYSCREENCOLUMNS; col++) {
            screen[row][col] = (col < line.length()) ? line[col] : ' ';
        }
        row++;
    }
    file.close();
    // Concatenate into a string and print
    string result;
    for (int i = 0; i < NONGAMEPLAYSCREENROWS; i++) {
        for (int j = 0; j < NONGAMEPLAYSCREENCOLUMNS; j++) {
            if (screen[i][j] == '#') result += "\033[48;2;116;0;0m\033[38;2;0;0;0m" + string(1, screen[i][j]) + "\033[0m";
            else if (screen[i][j] == '*') result += "\033[48;2;0;0;0m\033[38;2;255;255;0m" + string(1, screen[i][j]) + "\033[0m";
            else result += "\033[48;2;46;188;254m" + string(1, screen[i][j]) + "\033[0m";
        }
        result += '\n';
    }
    return result;
}

char movePlayer(char level[][levelColumns], string direction, string &levelNo, int &playerX, int &playerY, int &cameraX) {
    int newX = playerX;
    if (direction == "LEFT") newX--;
    else if (direction == "RIGHT") newX++;

    if (newX >= 0 && newX < levelColumns && (getCharAtLevel(level, newX, playerY) != '#' && getCharAtLevel(level, newX, playerY) != 'M' && getCharAtLevel(level, newX, playerY) != '%')) {
        gotoxy(playerX - cameraX, playerY); cout << ' ';
        playerX = newX;
        gotoxy(playerX - cameraX, playerY); cout << player;
    }
    if (newX >= 0 && newX < levelColumns && getCharAtLevel(level, newX, playerY) == '"') {
        return '"';
    }
    if (newX >= 0 && newX < levelColumns && getCharAtLevel(level, newX, playerY) == 'O') {
        return 'O';
    }
    
    return '!';
}

bool isGrounded(char level[][levelColumns], int &playerX, int &playerY) {
    return (getCharAtLevel(level, playerX, playerY + 1) == '#' || getCharAtLevel(level, playerX, playerY + 1) == 'M' || getCharAtLevel(level, playerX, playerY + 1) == '%');
}

bool loadLevel(char level[][levelColumns], string levelFileName) {
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

void updateRender(char level[][levelColumns], char render[][renderWidth], int &cameraX, int &score, int &health) {
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

void drawFrame(char render[][renderWidth]) {
    gotoxy(0, 0);
    string frame;
    for (int row = 0; row < levelRows; row++) {
        for (int col = 0; col < renderWidth; col++) {
            if (render[row][col] == 'M') frame += "\033[48;2;255;255;0m\033[38;2;255;255;0m" + string(1, render[row][col]) + "\033[0m";
            else if (render[row][col] == 'O') frame += "\033[48;2;46;188;254m\033[38;2;255;255;0m" + string(1, render[row][col]) + "\033[0m";
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

char getCharAtLevel(char level[][levelColumns], int x, int y) {
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
    cout << "\033[0m";
    system("cls");
}

void clearInputBuffer() {
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
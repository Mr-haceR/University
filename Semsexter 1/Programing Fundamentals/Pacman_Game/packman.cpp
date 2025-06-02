#include <iostream>
// #include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int pacmanX = 6, pacmanY = 4;

int ghost1X = 1, ghost1Y = 16;
bool ghost1up = true;

int ghost2X = 22, ghost2Y = 35;
bool ghost2right = true;

int ghost3X = 6, ghost3Y = 69;

int ghost4X = 14, ghost4Y = 35;

int score = 0;
int dots = 100;
int energizer_timer = 0;
int pacman_lives = 3;

const int rows = 31;
const int cols = 71;


bool gameRunning = true;
bool energizer = false;



void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo); // Get current cursor settings
    cursorInfo.bVisible = FALSE;                 // Set cursor visibility to false
    SetConsoleCursorInfo(hConsole, &cursorInfo); // Apply the new settings
}

void updatePacman()
{
    pacmanX = 6;
    pacmanY = 4;
    gotoxy(pacmanY, pacmanX);
    cout << "p";
}

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
    "              # . ###                             ### . #              ",
    "############### . ###   #######################   ### . ###############",
    "# . . . . . . . . . . . . . . . . ### . . . . . . . . . . . . . . . . #",
    "# O ########### . ############# . ### . ############# . ########### O #",
    "# . . . ####### . . . . . . . . . . . . . . . . . . . . ####### . . . #",
    "##### . ####### . ### . ####################### . ### . ####### . #####",
    "# . . . . . . . . ### . . . . . . ### . . . . . . ### . . . . . . . . #",
    "# . ########################### . ### . ########################### . #",
    "# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #",
    "#######################################################################"};
void printMap()
{
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 71; col++)
        {
            cout << mapp[row][col];
        }
        cout << endl;
    }
}

void initialghost()
{
    gotoxy(ghost1Y, ghost1X);
    cout << "G";
    gotoxy(ghost2Y, ghost2X);
    cout << "G";
    gotoxy(ghost3Y, ghost3X);
    cout << "G";
    gotoxy(ghost4Y, ghost4X);
    cout << "G";
}

void moveGhost1UP()
{
    if (ghost1X - 1 == pacmanX && ghost1Y == pacmanY)
    {
        if (energizer)
        {
            score += 10;
            char original = mapp[ghost1X][ghost1Y];
            gotoxy(ghost1Y, ghost1X);
            cout << original;
            ghost1X = 1;
            ghost1Y = 16;
            gotoxy(ghost1Y, ghost1X);
            cout << "G";
            return;
        }
        else
        {
            pacman_lives--;
            updatePacman();
        }
    }
    if (mapp[ghost1X - 1][ghost1Y] == '#')
    {
        ghost1up = false;
        return;
    }
    if (mapp[ghost1X - 1][ghost1Y] == ' ' || mapp[ghost1X - 1][ghost1Y] == '.' || mapp[ghost1X - 1][ghost1Y] == 'O')
    {
        char original = mapp[ghost1X][ghost1Y];
        gotoxy(ghost1Y, ghost1X);
        cout << original;
    }
    ghost1X = ghost1X - 1;
    gotoxy(ghost1Y, ghost1X);
    cout << "G";
}
void moveGhost1Down()
{
    if (ghost1X + 1 == pacmanX && ghost1Y == pacmanY)
    {
        if (energizer)
        {
            score += 10;
            char original = mapp[ghost1X][ghost1Y];
            gotoxy(ghost1Y, ghost1X);
            cout << original;
            ghost1X = 1;
            ghost1Y = 16;
            gotoxy(ghost1Y, ghost1X);
            cout << "G";
            return;
        }
        else
        {
            pacman_lives--;
            updatePacman();
        }
    }
    if (mapp[ghost1X + 1][ghost1Y] == '#')
    {
        ghost1up = true;
        return;
    }
    if (mapp[ghost1X + 1][ghost1Y] == ' ' || mapp[ghost1X + 1][ghost1Y] == '.' || mapp[ghost1X + 1][ghost1Y] == 'O')
    {
        char original = mapp[ghost1X][ghost1Y];
        gotoxy(ghost1Y, ghost1X);
        cout << original;
    }
    ghost1X = ghost1X + 1;
    gotoxy(ghost1Y, ghost1X);
    cout << "G";
}

void moveghost2right()
{
    if (ghost2X == pacmanX && ghost2Y + 1 == pacmanY)
    {
        if (energizer)
        {
            score += 10;
            char original = mapp[ghost2X][ghost2Y];
            gotoxy(ghost2Y, ghost2X);
            cout << original;
            ghost2X = 22;
            ghost2Y = 35;
            gotoxy(ghost2Y, ghost2X);
            cout << "G";
            return;
        }
        else
        {
            pacman_lives--;
            updatePacman();
        }
    }
    if (mapp[ghost2X][ghost2Y + 1] == '#')
    {
        ghost2right = false;
        return;
    }
    if (mapp[ghost2X][ghost2Y + 1] == ' ' || mapp[ghost2X][ghost2Y + 1] == '.' || mapp[ghost2X][ghost2Y + 1] == 'O')
    {
        char original = mapp[ghost2X][ghost2Y];
        gotoxy(ghost2Y, ghost2X);
        cout << original;
    }
    ghost2Y = ghost2Y + 1;
    gotoxy(ghost2Y, ghost2X);
    cout << "G";
}
void moveghost2left()
{
    if (ghost2X == pacmanX && ghost2Y - 1 == pacmanY)
    {
        if (energizer)
        {
            score += 10;
            char original = mapp[ghost2X][ghost2Y];
            gotoxy(ghost2Y, ghost2X);
            cout << original;
            ghost2X = 22;
            ghost2Y = 35;
            gotoxy(ghost2Y, ghost2X);
            cout << "G";
            return;
        }
        else
        {
            pacman_lives--;
            updatePacman();
        }
    }
    if (mapp[ghost2X][ghost2Y - 1] == '#')
    {
        ghost2right = true;
        return;
    }
    if (mapp[ghost2X][ghost2Y - 1] == ' ' || mapp[ghost2X][ghost2Y - 1] == '.' || mapp[ghost2X][ghost2Y - 1] == 'O')
    {
        char original = mapp[ghost2X][ghost2Y];
        gotoxy(ghost2Y, ghost2X);
        cout << original;
    }
    ghost2Y = ghost2Y - 1;
    gotoxy(ghost2Y, ghost2X);
    cout << "G";
}

void updating()
{
    if (ghost1up)
    {
        moveGhost1UP();
    }
    else
    {
        moveGhost1Down();
    }
    if (ghost2right)
    {
        moveghost2right();
    }
    else
    {
        moveghost2left();
    }
}

void moveGhost3Random()
{
    int dir = rand() % 8;
    int newX = ghost3X;
    int newY = ghost3Y;
    if (dir == 0 || dir == 4)
    {
        newX--;
    }
    else if (dir == 1 || dir == 5)
    {
        newX++;
    }
    else if (dir == 2 || dir == 6)
    {
        newY--;
    }
    else if (dir == 3 || dir == 7)
    {
        newY++;
    }
    if (newX <= 0 || newX >= 23 || newY <= 0 || newY >= 70)
    {
        return;
    }
    if (mapp[newX][newY] == '#' || mapp[newX][newY] == '_')
    {
        return;
    }
    char original = mapp[ghost3X][ghost3Y];
    gotoxy(ghost3Y, ghost3X);
    cout << original;
    if (newX == pacmanX && newY == pacmanY)
    {
        if (energizer)
        {
            score += 10;
            int randX, randY;
            do
            {
                randX = rand() % 23;
                randY = rand() % 70;
            } while (mapp[randX][randY] == '#' || mapp[randX][randY] == '_' || mapp[randX][randY] == '|' || mapp[randX][randY] == 'G');
            ghost3X = randX;
            ghost3Y = randY;
            gotoxy(ghost3Y, ghost3X);
            cout << "G";
            return;
        }
        else
        {
            pacman_lives--;
            updatePacman();
        }
    }
    ghost3X = newX;
    ghost3Y = newY;
    gotoxy(ghost3Y, ghost3X);
    cout << "G";
}
void moveGhost4FollowPacman()
{
    int newX = ghost4X;
    int newY = ghost4Y;

    gotoxy(ghost4Y, ghost4X);
    cout << mapp[ghost4X][ghost4Y];

    bool moved = false;

    if (pacmanX < ghost4X && mapp[ghost4X - 1][ghost4Y] != '#' && mapp[ghost4X - 1][ghost4Y] != '_' && mapp[ghost4X - 1][ghost4Y] != '|')
    {
        newX = ghost4X - 1;
        moved = true;
    }
    else if (pacmanX > ghost4X && mapp[ghost4X + 1][ghost4Y] != '#' && mapp[ghost4X + 1][ghost4Y] != '_' && mapp[ghost4X + 1][ghost4Y] != '|')
    {
        newX = ghost4X + 1;
        moved = true;
    }

    if (!moved)
    {
        if (pacmanY < ghost4Y && mapp[ghost4X][ghost4Y - 1] != '#' && mapp[ghost4X][ghost4Y - 1] != '_' && mapp[ghost4X][ghost4Y - 1] != '|')
        {
            newY = ghost4Y - 1;
            moved = true;
        }
        else if (pacmanY > ghost4Y && mapp[ghost4X][ghost4Y + 1] != '#' && mapp[ghost4X][ghost4Y + 1] != '_' && mapp[ghost4X][ghost4Y + 1] != '|')
        {
            newY = ghost4Y + 1;
            moved = true;
        }
    }

    if (!moved)
    {
        if (mapp[ghost4X - 1][ghost4Y] != '#' && mapp[ghost4X - 1][ghost4Y] != '_' && mapp[ghost4X - 1][ghost4Y] != '|')
        {
            newX = ghost4X - 1;
        }
        else if (mapp[ghost4X + 1][ghost4Y] != '#' && mapp[ghost4X + 1][ghost4Y] != '_' && mapp[ghost4X + 1][ghost4Y] != '|')
        {
            newX = ghost4X + 1;
        }
        else if (mapp[ghost4X][ghost4Y - 1] != '#' && mapp[ghost4X][ghost4Y - 1] != '_' && mapp[ghost4X][ghost4Y - 1] != '|')
        {
            newY = ghost4Y - 1;
        }
        else if (mapp[ghost4X][ghost4Y + 1] != '#' && mapp[ghost4X][ghost4Y + 1] != '_' && mapp[ghost4X][ghost4Y + 1] != '|')
        {
            newY = ghost4Y + 1;
        }
    }

    if (newX == pacmanX && newY == pacmanY)
    {
        if (energizer)
        {
            score += 10;
            int randX, randY;
            do
            {
                randX = rand() % 23;
                randY = rand() % 70;
            } while (mapp[randX][randY] == '#' || mapp[randX][randY] == '_' || mapp[randX][randY] == '|' || mapp[randX][randY] == 'G');
            ghost4X = randX;
            ghost4Y = randY;
            gotoxy(ghost4Y, ghost4X);
            cout << 'G';
            return;
        }
        else
        {
            pacman_lives--;
            updatePacman();
        }
    }

    ghost4X = newX;
    ghost4Y = newY;
    gotoxy(ghost4Y, ghost4X);
    cout << 'G';
}

void movePacmanLeft()
{
    if (mapp[pacmanX][pacmanY - 1] == ' ' || mapp[pacmanX][pacmanY - 1] == '.' || mapp[pacmanX][pacmanY - 1] == 'O')
    {
        if (mapp[pacmanX][pacmanY - 1] == '.')
        {
            score++;
            dots--;
        }
        if (mapp[pacmanX][pacmanY - 1] == 'O')
        {
            score += 5;
            energizer = true;
            energizer_timer = 30;
        }
        mapp[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY - 1;
        if (pacmanY == 0)
        {
            pacmanY = 69;
        }
        gotoxy(pacmanY, pacmanX);
        cout << "p";
    }
}
void movePacmanRight()
{
    if (mapp[pacmanX][pacmanY + 1] == ' ' || mapp[pacmanX][pacmanY + 1] == '.' || mapp[pacmanX][pacmanY + 1] == 'O')
    {
        if (mapp[pacmanX][pacmanY + 1] == '.')
        {
            score++;
            dots--;
        }
        if (mapp[pacmanX][pacmanY + 1] == 'O')
        {
            score += 5;
            energizer = true;
            energizer_timer = 30;
        }
        mapp[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY + 1;
        if (pacmanY == 70)
        {
            pacmanY = 1;
        }
        gotoxy(pacmanY, pacmanX);
        cout << "p";
    }
}
void movePacmanUP()
{
    if (mapp[pacmanX - 1][pacmanY] == ' ' || mapp[pacmanX - 1][pacmanY] == '.' || mapp[pacmanX - 1][pacmanY] == 'O')
    {
        if (mapp[pacmanX - 1][pacmanY] == '.')
        {
            score++;
            dots--;
        }
        if (mapp[pacmanX - 1][pacmanY] == 'O')
        {
            score += 5;
            energizer = true;
            energizer_timer = 30;
        }
        mapp[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX - 1;
        gotoxy(pacmanY, pacmanX);
        cout << "p";
    }
}
void movePacmanDown()
{
    if (mapp[pacmanX + 1][pacmanY] == ' ' || mapp[pacmanX + 1][pacmanY] == '.' || mapp[pacmanX + 1][pacmanY] == 'O')
    {
        if (mapp[pacmanX + 1][pacmanY] == '.')
        {
            score++;
            dots--;
        }
        if (mapp[pacmanX + 1][pacmanY] == 'O')
        {
            score += 5;
            energizer = true;
            energizer_timer = 30;
        }
        mapp[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX + 1;
        gotoxy(pacmanY, pacmanX);
        cout << "p";
    }
}

void energizertime()
{
    if (energizer)
    {
        energizer_timer--;
        if (energizer_timer <= 0)
        {
            energizer = false;
        }
    }
}
void printscore()
{
    gotoxy(85, 5);
    cout << "Score: " << score << "\tlives: " << pacman_lives;
}

main()
{
    system("CLS");
    srand(time(0));
    hideCursor();
    printMap();
    gotoxy(pacmanY, pacmanX);
    cout << "p";
    initialghost();
    while (gameRunning)
    {
        Sleep(100);
        printscore();
        energizertime();
        updating();
        moveGhost3Random();
        moveGhost4FollowPacman();
        if (dots == 0)
        {
            system("CLS");
            cout << "\t YOU WIN!";
            cout << "Press any key to continue...";
            getch();
            gameRunning = false;
        }
        if (pacman_lives == 0)
        {
            system("CLS");
            cout << "\t YOU lOSE!";
            cout << "Press any key to continue...";
            getch();
            gameRunning = false;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacmanLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePacmanRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePacmanUP();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePacmanDown();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("CLS");
            cout << "\t EXITING...!";
            cout << "Press any key to continue...";
            getch();
            gameRunning = false;
        }
    }
}
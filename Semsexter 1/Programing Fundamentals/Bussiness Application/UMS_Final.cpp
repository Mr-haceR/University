#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Constants and Global Data
const int TOTAL_USERS = 10;
int userCount = 0;
string usernames[TOTAL_USERS];
string passwords[TOTAL_USERS];
string roles[TOTAL_USERS];
int uniqueId[TOTAL_USERS];


string students[TOTAL_USERS];
int matric_marks[TOTAL_USERS];
int inter_marks[TOTAL_USERS];
int ecat_marks[TOTAL_USERS];
float aggregate[TOTAL_USERS];
string firstPref[TOTAL_USERS];
string secondPref[TOTAL_USERS];
string thirdPref[TOTAL_USERS];
bool admitted[TOTAL_USERS];
string admittedProgram[TOTAL_USERS];

string Programs[3] = {"CS", "SE", "IT"};
int ProgramAvailableSeats[3] = {3, 3, 3};
float minPercentageForPrograms[3];
bool resultAnnounced = false;
bool meritSet = false;
int choice = 0;

// Function Prototypes
void printHeader();
int landingPage();
string pref(int n);
string login(string username, string password, int id);
float calculateAggregate(float matric, float inter, float ecat);
bool signUp();
void setMerit();
void addUser(string role);
void displaySeats();
void UpdateSeats();
void adminMenu();
int studentMenu(string username);
void clearScreen();
void sortMerit();
void announceResult();
void viewMeritList();
int manageSeats();
void viewStudentProfile(string username);
void checkAdmissionStatus(string username);
void changePassword(string username);

// Main Function
int main() {
    while (true) {
        choice = landingPage();
        if (choice == 1) {
            string username, password; 
            int id;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter the unique ID given to you at the time of sign up: ";
            cin >> id;
            string role = login(username, password, id);
            if (role == "ADMIN") {
                adminMenu();
            } else if (role == "STUDENT") {
                while (true) {
                    int opt = studentMenu(username);
                    if (opt == 1) {
                        viewStudentProfile(username);
                    } else if (opt == 2) {
                        checkAdmissionStatus(username);
                    } else if (opt == 3) {
                        changePassword(username);
                    } else if (opt == 4) {
                        break;
                    } else {
                        cout << "Invalid choice! Press any key to try again...";
                        getch();
                    }
                }
            } else {
                while (true) {
                    cout << "\nWrong information. Press 'q' to go back or any other key to try again...";
                    char x = getch();
                    if (x == 'q' || x == 'Q') break;
                    login(username, password, id);
                }
            }
        } else if (choice == 2) {
            while (true) {
                if (signUp()) {
                    break;
                }
                char x = getch();
                if (x == 'q' || x == 'Q') {
                    break;
                }
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "\nInvalid Choice. Pressl;askd any key to try again...";
            choice = 0;
            getch();
            continue;
        }
    }
}

// Function Definitions

void printHeader() {
    cout << "\n******************************************************************\n"
         << "*             University Admission Management System             *\n"
         << "******************************************************************\n\n";
}

int landingPage() {
    clearScreen();
    printHeader();
    cout << "1. Login\n2. Sign Up\n3. Exit\n\nEnter your choice: ";
    cin >> choice;
    return choice;
}

string login(string username, string password, int id) {
    clearScreen();
    printHeader();
    

    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username && passwords[i] == password && uniqueId[i] == id) {
            return roles[i];
        }
    }
    return "WRONG";
}

bool signUp() {
    clearScreen();
    printHeader();
    cout << "1. Admin\n2. Student\n3. Go back\n\nSelect your role: ";
    cin >> choice;
    if (choice == 1) {
        addUser("ADMIN");
    } else if (choice == 2) {
        addUser("STUDENT");
    } else if (choice == 3) {
        return true;
    } else {
        cout << "\nInvalid Choice. Press 'q' to go back or any other key to continue...";
        return false;
    }
    return true;
}

void addUser(string role) {
    if (userCount >= TOTAL_USERS) {
        cout << "\nCan't add user: Maximum capacity reached.";
        getch();
        return;
    }

    if (role == "STUDENT") {
        cout << "\n************** Add New Student **************\n\n";
        cout << "Enter student name: ";
        cin >> students[userCount];
        usernames[userCount] = students[userCount];
        cout << "Enter a password: ";
        cin >> passwords[userCount];
        cout << "Enter Matric marks (out of 1100): ";
        cin >> matric_marks[userCount];
        cout << "Enter Inter marks (out of 550): ";
        cin >> inter_marks[userCount];
        cout << "Enter ECAT marks (out of 400): ";
        cin >> ecat_marks[userCount];
        aggregate[userCount] = calculateAggregate(matric_marks[userCount], inter_marks[userCount], ecat_marks[userCount]);
        firstPref[userCount] = pref(1);
        secondPref[userCount] = pref(2);
        thirdPref[userCount] = pref(3);
        admitted[userCount] = false;
        uniqueId[userCount] = userCount;
        cout << "\nStudent Added: " << usernames[userCount] << "\nYour unique ID is " << uniqueId[userCount] << "\nPress any key to continue...";
    } else {
        cout << "\n************** Add New Admin **************\n\n";
        cout << "Enter admin name: ";
        cin >> usernames[userCount];
        cout << "Enter a password: ";
        cin >> passwords[userCount];
        uniqueId[userCount] = userCount;
        cout << "\nAdmin Added: " << usernames[userCount] << "\nYour unique ID is " << uniqueId[userCount] << "\nPress any key to continue...";
    }
    roles[userCount] = role;
    
    userCount++;
    getch();
}

string pref(int n) {
    clearScreen();
    
    while (true) {
        cout << "\n*************** Preferences ****************\n\n" << 
                "1. " << Programs[0] << "\n" << 
                "2. " << Programs[1] << "\n" <<
                "3. " << Programs[2] << "\n\n" <<
                "Enter your preference number " << n << ": ";
        cin >> choice;
        if (choice == 1) {
            return Programs[0];
        } else if (choice == 2) {
            return Programs[1];
        } else if (choice == 3) {
            return Programs[2];
        }
        else {
            cout << "\nInvalid choice. Press any key to try again...";
            getch();
        }
        
    }
}

float calculateAggregate(float matric, float inter, float ecat) {
    return (matric / 1100 * 0.30 + inter / 550 * 0.30 + ecat / 400 * 0.40) * 100;
}

void adminMenu() {
    while (true) {
        clearScreen();
        printHeader();
        cout << "Admin Menu >\n"
             << "1. Add new student\n2. View all students\n3. Print merit order\n"
             << "4. Set merit\n5. Seat Management\n6. Announce Result\n7. Logout\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addUser("STUDENT");
        } else if (choice == 2) {
            for (int i = 0; i < userCount; i++) {
                if (roles[i] == "STUDENT") {
                    cout << "\nUsername: " << usernames[i] <<
                            "\nMatric: " << matric_marks[i] <<
                            "\nInter: " << inter_marks[i] <<
                            "\nECAT: " << ecat_marks[i] <<
                            "\nAggregate: " << aggregate[i] <<
                            "\nPreferences: 1. " << firstPref[i] << " 2. " << secondPref[i] << " 3. " << thirdPref[i] <<
                            "\nAdmitted: " << (admitted[i] ? "Yes" : "No") << "\n";
                }
            }
            cout << "\nPress any key to continue...";
            getch();
        } else if (choice == 3) {
            viewMeritList();
        } else if (choice == 4) {
            setMerit();
        } else if (choice == 5) {
            while (true) {
                choice = manageSeats();
                if (choice == 1) {
                    displaySeats();
                } else if (choice == 2) {
                    UpdateSeats();
                } else if (choice == 3) {
                    break;
                } else {
                    cout << "\nInvalid Choice. Press any key to try again...";
                    getch();
                }
            }
        } else if (choice == 6) {
            announceResult();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice. Press any key...";
            getch();
        }
    }
}

void setMerit() {
    clearScreen();
    printHeader();
    cout << "\n*************** Generate Merit *******************\n\n";
    for (int i = 0; i < 3; i++) {
        cout << "Enter minimum merit for " << Programs[i] << ": ";
        cin >> minPercentageForPrograms[i];
        cout << "\n";
    }
    meritSet = true;
    cout << "\nMerit Set. Press any key to continue...";
    getch();
}

void sortMerit() {
    for (int i = 0; i < userCount - 1; i++) {
        for (int j = i + 1; j < userCount; j++) {
            if (roles[i] == "STUDENT" && roles[j] == "STUDENT") {
                if (aggregate[j] > aggregate[i]) {
                    swap(usernames[i], usernames[j]);
                    swap(passwords[i], passwords[j]);
                    swap(roles[i], roles[j]);
                    swap(students[i], students[j]);
                    swap(matric_marks[i], matric_marks[j]);
                    swap(inter_marks[i], inter_marks[j]);
                    swap(ecat_marks[i], ecat_marks[j]);
                    swap(aggregate[i], aggregate[j]);
                    swap(admitted[i], admitted[j]);
                }
            }
        }
    }
}

void viewMeritList() {
    sortMerit();
    cout << "\n************ Merit List ************\n";
    for (int i = 0; i < userCount; i++) {
        if (roles[i] == "STUDENT") {
            cout << i << ". " << students[i] << " - Aggregate: " << aggregate[i] << "%\n";
        }
    }
    cout << "\nPress any key to continue...";
    getch();
}

void announceResult() {
    if (meritSet) {
        int seatsFilled = 0;
        for (int i = 0; i < userCount; i++) {
            if (roles[i] == "STUDENT") {
                int first_index = -1, second_index = -1, third_index = -1;
                for (int j = 0; j < 3; j++) {
                    if (firstPref[j] == Programs[j]) {
                        first_index = j;
                    }
                    if (secondPref[j] == Programs[j]) {
                        second_index = j;
                    }
                    if (thirdPref[j] == Programs[j]) {
                        third_index = j;
                    }
                }
                if (first_index != -1 && aggregate[i] >= minPercentageForPrograms[first_index]) {
                    admittedProgram[i] = Programs[first_index];
                    admitted[i] = true;
                } else if (second_index != -1 && aggregate[i] >= minPercentageForPrograms[second_index]) {
                    admittedProgram[i] = Programs[second_index];
                    admitted[i] = true;
                } else if (third_index != -1){
                    admittedProgram[i] = Programs[third_index];  
                    admitted[i] = true; 
                }
            }
        }
        resultAnnounced = true;
        cout << "\nResult announced successfully. Press any key...";
        getch();
    } else {
        cout << "\nYou haven't set the merit for each program yet. Press any key to continue...";
        getch();
    }
}

int manageSeats() {
    clearScreen();
    printHeader();
    cout << "\nSeat Management >\n" <<
            "--------------------------------\n\n" <<
            "1. See Available seats for offered programs.\n" <<
            "2. Add more seats for a programs.\n" << 
            "3. Go back.\n\n" << 
            "Enter your choice: ";
    cin >> choice;
    return choice;
}
void displaySeats() {
    cout << "\n1. " << Programs[0] << "\tSeats: " << ProgramAvailableSeats[0] <<
            "\n2. " << Programs[1] << "\tSeats: " << ProgramAvailableSeats[1] <<
            "\n1. " << Programs[2] << "\tSeats: " << ProgramAvailableSeats[2] <<
            "\nPress any key to continue...";
    getch();
}
void UpdateSeats() {
    while (true) {
        cout << "\n*************** Programs ****************\n\n" << 
                    "1. " << Programs[0] << "\tSeats: " << ProgramAvailableSeats[0] << "\n" << 
                    "2. " << Programs[1] << "\tSeats: " << ProgramAvailableSeats[0] << "\n" <<
                    "3. " << Programs[2] << "\tSeats: " << ProgramAvailableSeats[0] << "\n\n" <<
                    "Which program's seats you want to increase: ";
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            int x;
            cout << "Enter number of seats you wants to add in the existing number: ";
            cin >> x;
            ProgramAvailableSeats[choice - 1] += x;
            cout << "\n" << x << " Seats Added: " << Programs[choice - 1] << ". Press any key to continue...";
            getch();
            break;
        }
        else {
            cout << "\nInvalid Choice. Press any key to try again...";
            getch();
        }
    }
}

int studentMenu(string username) {
    clearScreen();
    printHeader();
    cout << "Student Menu >\n"
         << "1. View your profile\n2. Check Admission Status\n3. Change Password\n4. Logout\n\nEnter your choice: ";
    cin >> choice;
    return choice;
}

void viewStudentProfile(string username) {
    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username) {
            cout << "\nName: " << usernames[i]
                 << "\nMatric: " << matric_marks[i]
                 << "\nInter: " << inter_marks[i]
                 << "\nECAT: " << ecat_marks[i]
                 << "\nAggregate: " << aggregate[i] << "\n";
            break;
        }
    }
    cout << "\nPress any key to continue...";
    getch();
}

void checkAdmissionStatus(string username) {
    if (!resultAnnounced) {
        cout << "\nResult not announced yet. Press any key...";
        getch();
        return;
    }

    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username) {
            if (admitted[i]) {
                cout << "\nCongratulations! You are admitted in " << admittedProgram[i] << " Program :)";
            } else {
                cout << "\nSorry! You are not admitted :(";
            }
            break;
        }
    }
    cout << "\nPress any key to continue...";
    getch();
}

void changePassword(string username) {
    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username) {
            string newPass;
            cout << "Enter new password: ";
            cin >> newPass;
            passwords[i] = newPass;
            cout << "\nPassword changed successfully. Press any key...";
            break;
        }
    }
    getch();
}

void clearScreen() {
    system("cls");
}

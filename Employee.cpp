#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

struct emp {
    string name, id, address;
    int contact, salary;
};

emp e[100];
int total = 0;

// ---------------- ADD EMPLOYEE ----------------
void empData() {
    int choice;
    cout << "How many employees do you want to enter? ";
    cin >> choice;
    cin.ignore();

    if (total + choice > 100) {
        cout << "Employee limit exceeded!\n";
        return;
    }

    for (int i = total; i < total + choice; i++) {
        cout << "\nEnter data for employee " << i + 1 << endl;

        cout << "Employee Name: ";
        getline(cin, e[i].name);

        cout << "ID: ";
        getline(cin, e[i].id);

        cout << "Address: ";
        getline(cin, e[i].address);

        cout << "Contact: ";
        cin >> e[i].contact;

        cout << "Salary: ";
        cin >> e[i].salary;
        cin.ignore();
    }
    total += choice;
}

// ---------------- SHOW EMPLOYEES ----------------
void show() {
    if (total == 0) {
        cout << "No records available.\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nEmployee " << i + 1 << endl;
        cout << "Name: " << e[i].name << endl;
        cout << "ID: " << e[i].id << endl;
        cout << "Address: " << e[i].address << endl;
        cout << "Contact: " << e[i].contact << endl;
        cout << "Salary: " << e[i].salary << endl;
    }
}

// ---------------- SEARCH EMPLOYEE ----------------
void searchEmp() {
    if (total == 0) {
        cout << "No records available.\n";
        return;
    }

    string id;
    cout << "Enter ID to search: ";
    getline(cin, id);

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (e[i].id == id) {
            cout << "\nEmployee Found:\n";
            cout << "Name: " << e[i].name << endl;
            cout << "ID: " << e[i].id << endl;
            cout << "Address: " << e[i].address << endl;
            cout << "Contact: " << e[i].contact << endl;
            cout << "Salary: " << e[i].salary << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee not found!\n";
}

// ---------------- UPDATE EMPLOYEE ----------------
void update() {
    if (total == 0) {
        cout << "No records available.\n";
        return;
    }

    string id;
    cout << "Enter ID to update: ";
    getline(cin, id);

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (e[i].id == id) {
            cout << "\nEnter new details:\n";

            cout << "Employee Name: ";
            getline(cin, e[i].name);

            cout << "ID: ";
            getline(cin, e[i].id);

            cout << "Address: ";
            getline(cin, e[i].address);

            cout << "Contact: ";
            cin >> e[i].contact;

            cout << "Salary: ";
            cin >> e[i].salary;
            cin.ignore();

            cout << "Record updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee not found!\n";
}

// ---------------- DELETE EMPLOYEE ----------------
void deleteData() {
    if (total == 0) {
        cout << "No records available.\n";
        return;
    }

    cout << "Press 1 to delete all records\n";
    cout << "Press 2 to delete specific record\n";
    char ch = getch();

    if (ch == '1') {
        total = 0;
        cout << "\nAll records deleted.\n";
    }
    else if (ch == '2') {
        string id;
        cout << "\nEnter ID to delete: ";
        getline(cin, id);

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (e[i].id == id) {
                for (int j = i; j < total - 1; j++) {
                    e[j] = e[j + 1];
                }
                total--;
                cout << "Record deleted successfully.\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Employee not found!\n";
    }
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    string username, password;
    string u, p;

    cout << "EMPLOYEE MANAGEMENT SYSTEM\n";
    cout << "\nSIGN UP\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    cout << "\nCreating account";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(700);
    }

    system("CLS");

    while (true) {
        cout << "LOGIN\n";
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;
        cin.ignore();

        if (u == username && p == password) {
            system("CLS");
            char choice;

            while (true) {
                cout << "\n1. Add Employee\n2. Show Employees\n3. Search Employee\n";
                cout << "4. Update Employee\n5. Delete Employee\n6. Logout\n7. Exit\n";
                choice = getch();
                system("CLS");

                switch (choice) {
                    case '1': empData(); break;
                    case '2': show(); break;
                    case '3': searchEmp(); break;
                    case '4': update(); break;
                    case '5': deleteData(); break;
                    case '6': system("CLS"); goto login;
                    case '7': exit(0);
                    default: cout << "Invalid option!\n";
                }
            }
        } else {
            cout << "Invalid credentials. Try again.\n";
            Sleep(2000);
            system("CLS");
        }
        login:;
    }

    return 0;
}

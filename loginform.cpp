#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool loggingin() {
    string username, password, user, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");

    // Check if the file exists
    if (!read) {
        cout << "Error: Username not found!\n";
        return false;
    }

    getline(read, user);
    getline(read, pass);
    read.close(); // Always close the file after reading

    if (user == username && pass == password) {
        return true;
    } else {
        return false;
    }
}

int login() {
    bool status = loggingin();
    if (!status) {
        cout << "!!! Incorrect info !!!\n\n";
        return 0;
    } else {
        cout << "**** Login Successful ****\n";
        return 1;
    }
}

void regist() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    // Check if the username already exists
    ifstream checkFile(username + ".txt");
    if (checkFile.good()) {
        cout << "Error: Username already taken! Choose a different username.\n";
        return;
    }
    checkFile.close();

    cout << "Enter a password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password; // Storing inside that file
    file.close();

    cout << "Registration successful! You can now log in.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n**** Welcome to Login Page *******";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                regist();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid input!!!!\n";
        }
    }
}

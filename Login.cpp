#include "Login.h"
#include <iostream>
#include <fstream>
#include <map>
#include <conio.h> // for _getch()

using namespace std;

string getMaskedInput() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

bool login(string &username) {
    ifstream fin("admin.txt");
    string storedUser, storedPass, inputPass;
    fin >> storedUser >> storedPass;

    int attempts = 3;
    while (attempts--) {
        cout << "🔐 Username: ";
        cin >> username;
        cout << "🔐 Password: ";
        inputPass = getMaskedInput(); // ✅ Masked input

        if (username == storedUser && inputPass == storedPass) {
            cout << "✅ Login successful!\n";
            return true;
        } else {
            cout << "❌ Invalid credentials. Attempts left: " << attempts << "\n";
        }
    }
    return false;
}

void changePassword(const string& username) {
    string oldPass, newPass, confirmPass;
    string storedUser, storedPass;

    ifstream fin("admin.txt");
    fin >> storedUser >> storedPass;
    fin.close();

    cout << "🔐 Enter current password: ";
    oldPass = getMaskedInput(); // ✅ Masked input

    if (oldPass != storedPass) {
        cout << "❌ Incorrect current password.\n";
        return;
    }

    cout << "🔐 Enter new password: ";
    newPass = getMaskedInput(); // ✅ Masked input
    cout << "🔐 Confirm new password: ";
    confirmPass = getMaskedInput(); // ✅ Masked input

    if (newPass != confirmPass) {
        cout << "❌ Passwords do not match.\n";
        return;
    }

    ofstream fout("admin.txt");
    fout << username << "\n" << newPass << "\n";
    fout.close();

    cout << "✅ Password changed successfully!\n";
}

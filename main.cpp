#include <iostream>
#include <string>
#include "Login.h"
#include "StudentManager.h"

using namespace std;

int main() {
    string currentUser;
    if (!login(currentUser)) return 0;

    StudentManager manager;
    manager.loadFromFile();

    int ch;
    do {
        cout << "\n🎓 STUDENT GRADE MANAGER\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Add Subject\n";
        cout << "5. View All\n";
        cout << "6. Search by Roll No\n";
        cout << "7. Search by Name\n";
        cout << "8. Show Topper\n";
        cout << "9. Export CSV\n";
        cout << "10. Show Ranking\n";
        cout << "99. Change Password\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: manager.addStudent(); break;
            case 2: manager.editStudent(); break;
            case 3: manager.deleteStudent(); break;
            case 4: manager.addSubject(); break;
            case 5: manager.viewAll(); break;
            case 6: manager.searchByRoll(); break;
            case 7: manager.searchByName(); break;
            case 8: manager.showTopper(); break;
            case 9: manager.exportCSV(); break;
            case 10: manager.showRanking(); break;
            case 99: changePassword(currentUser); break;
            case 0: cout << "👋 Bye!\n"; break;
            default: cout << "❌ Invalid.\n";
        }

    } while (ch != 0);

    return 0;
}

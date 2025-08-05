#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

void StudentManager::loadFromFile() {
    students.clear();
    ifstream fin("students.txt");  // ✅ Unified file name
    string line;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string part;
        Student s;

        getline(ss, part, ';');
        s.rollNo = stoi(part);

        getline(ss, part, ';');
        s.name = part;

        while (getline(ss, part, ';')) {
            size_t colon = part.find(':');
            if (colon != string::npos) {
                string subject = part.substr(0, colon);
                int marks = stoi(part.substr(colon + 1));
                s.subjects[subject] = marks;
            }
        }

        students.push_back(s);
    }

    cout << "✅ Loaded " << students.size() << " students from students.txt\n";
}

void StudentManager::saveToFile() {
    ofstream fout("students.txt");  // ✅ Unified file name
    for (auto &s : students) {
        fout << s.rollNo << ";" << s.name;
        for (auto &sub : s.subjects)
            fout << ";" << sub.first << ":" << sub.second;
        fout << "\n";
    }
}

void StudentManager::addStudent() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;
    for (auto &s : students)
        if (s.rollNo == roll) {
            cout << "❌ Roll No already exists.\n";
            return;
        }
    cin.ignore();
    string name;
    cout << "Enter Name: ";
    getline(cin, name);
    students.emplace_back(roll, name);
    saveToFile();
    cout << "✅ Student added.\n";
}

void StudentManager::editStudent() {
    int roll;
    cout << "Enter Roll No to edit: ";
    cin >> roll;
    for (auto &s : students) {
        if (s.rollNo == roll) {
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, s.name);
            saveToFile();
            cout << "✅ Updated.\n";
            return;
        }
    }
    cout << "❌ Not found.\n";
}

void StudentManager::deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;
    auto it = remove_if(students.begin(), students.end(), [&](Student &s) {
        return s.rollNo == roll;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        saveToFile();
        cout << "✅ Deleted.\n";
    } else cout << "❌ Not found.\n";
}

void StudentManager::addSubject() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;
    for (auto &s : students) {
        if (s.rollNo == roll) {
            string sub;
            int marks;  // ✅ Changed from float to int
            cin.ignore();
            cout << "Enter subject: ";
            getline(cin, sub);
            cout << "Enter marks: ";
            cin >> marks;
            s.subjects[sub] = marks;
            saveToFile();
            cout << "✅ Subject added.\n";
            return;
        }
    }
    cout << "❌ Not found.\n";
}

void StudentManager::viewAll() {
    for (auto &s : students)
        s.display();
}

void StudentManager::searchByRoll() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    bool found = false;
    for (auto &s : students) {
        if (s.rollNo == roll) {
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Not found.\n";
}

void StudentManager::searchByName() {
    string q;
    cin.ignore();
    cout << "Enter name part: ";
    getline(cin, q);
    for (auto &s : students)
        if (s.name.find(q) != string::npos)
            s.display();
}

void StudentManager::showTopper() {
    if (students.empty()) return;
    auto top = max_element(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.calculateAverage() < b.calculateAverage();
    });
    top->display();
}

void StudentManager::showRanking() {
    if (students.empty()) {
        cout << "⚠️ No students available.\n";
        return;
    }

    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), [](const Student& a, const Student& b) {
        return a.calculateAverage() > b.calculateAverage();
    });

    cout << "\n🏆 Student Rankings:\n";
    cout << "Rank\tRoll\tName\t\t\tAverage\tGrade\n";

    int rank = 1;
    float prevAvg = -1;
    int tieCount = 0;

    for (size_t i = 0; i < sorted.size(); ++i) {
        float avg = sorted[i].calculateAverage();
        if (avg == prevAvg) tieCount++;
        else {
            rank = i + 1;
            tieCount = 0;
            prevAvg = avg;
        }

        cout << rank << "\t" << sorted[i].rollNo << "\t" << sorted[i].name
             << "\t\t" << avg << "\t" << sorted[i].getGrade() << "\n";
    }
}

void StudentManager::exportCSV() {
    ofstream f1("subjectwise.csv");
    f1 << "Roll No,Name,Subject,Marks,Grade\n";
    for (auto &s : students)
        for (auto &p : s.subjects) {
            char g = (p.second >= 90) ? 'A' : (p.second >= 75) ? 'B' : (p.second >= 60) ? 'C' : (p.second >= 40) ? 'D' : 'F';
            f1 << s.rollNo << "," << s.name << "," << p.first << "," << p.second << "," << g << "\n";
        }
    f1.close();

    ofstream f2("summary.csv");
    f2 << "Roll No,Name,Average,Grade\n";
    for (auto &s : students)
        f2 << s.rollNo << "," << s.name << "," << s.calculateAverage() << "," << s.getGrade() << "\n";

    cout << "✅ CSVs exported.\n";
}

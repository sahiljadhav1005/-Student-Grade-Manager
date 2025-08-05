#include "Student.h"
#include <iostream>
#include <iomanip>
#include <map> // ✅ Required for map

using namespace std;

Student::Student(int roll, const string &nm) : rollNo(roll), name(nm) {}

float Student::calculateAverage() const {
    if (subjects.empty()) return 0.0;
    float sum = 0;
    for (const auto &pair : subjects)
        sum += pair.second;
    return sum / subjects.size();
}

char Student::getGrade() const {
    float avg = calculateAverage();
    if (avg >= 90) return 'A';
    if (avg >= 75) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 40) return 'D';
    return 'F';
}

void Student::display() const {
    cout << "📘 Roll No: " << rollNo << " | Name: " << name << "\n";
    if (subjects.empty()) {
        cout << "  📄 No subjects added.\n";
    } else {
        for (const auto &s : subjects) {
            cout << "  ➤ " << s.first << ": " << s.second << "\n";
        }
        cout << fixed << setprecision(2);
        cout << "  📊 Average: " << calculateAverage() << " | Grade: " << getGrade() << "\n";
    }
    cout << "----------------------------------\n";
}

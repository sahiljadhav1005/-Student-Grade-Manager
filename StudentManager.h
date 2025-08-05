#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>

class StudentManager {
private:
    std::vector<Student> students;

public:
    void loadFromFile();
    void saveToFile();
    void addStudent();
    void editStudent();
    void deleteStudent();
    void addSubject();
    void viewAll();
    void searchByRoll();
    void searchByName();
    void showTopper();
    void exportCSV();
    void showRanking();
};

#endif // STUDENTMANAGER_H

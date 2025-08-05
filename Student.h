#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>

class Student {
public:
    int rollNo;
    std::string name;
    std::map<std::string, int> subjects;

    // Constructors
    Student() = default;
    Student(int roll, const std::string& name);

    // Member functions
    float calculateAverage() const;
    char getGrade() const;
    void display() const;

    // Optional utility
    int getSubjectCount() const { return subjects.size(); }
};

#endif // STUDENT_H

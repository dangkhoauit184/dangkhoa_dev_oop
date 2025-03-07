#include <iostream>
#include<string>
#include "Student.h"

using namespace std;

int main() {
    int n;
    cout << "Enter numbers of student: ";
    cin >> n;
    cin.ignore();

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        string name;
        int id;

        cout << "Enter student name " << i + 1 << ": ";
        getline(cin, name); 

        cout << "Enter student id: ";
        cin >> id;
        cin.ignore();

        students[i] = Student(name, id); 
    }

    cout << "\nStudent List:\n";
    for (int i = 0; i < n; i++) {
        students[i].displayInformation();
    }

    cout << "\nTotal number of students: " << Student::getStudentCount() << endl;
    delete[] students;

    return 0;
}

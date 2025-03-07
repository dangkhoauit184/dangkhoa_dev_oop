#include<iostream>
#include "Student.h"
using namespace std;

int Student::StudentCount = 0;

Student::Student() {
	name = "";
	id = 0;
}

Student::Student(string StudentName, int StudentId) {
	name = StudentName;
	id = StudentId;
	StudentCount++;
}

void Student::displayInformation() {
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
}

int Student::getStudentCount() {
	return StudentCount;
}

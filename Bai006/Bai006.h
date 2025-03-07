#pragma once
#include<string>
class Student {
private:
	std::string name;
	int id;
	static int StudentCount;

public:
	Student(): name(""), id(0) {}
	Student(std::string StudentName, int StudentId);
	void displayInformation();
	static int getStudentCount();
};

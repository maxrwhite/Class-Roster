#pragma once
#include <string>
#include "degree.h"
//Max White - PA for C867
using namespace std;

//D.1 Create class for Student
class Student 
{
//D.1 
private:

	string StudentID;
	string FirstName;
	string LastName;
	string EmailAddress;
	int Age;
	int DaysInCourse[3];
	DegreeProgram degreeProgram;

public:

//D.2.d
	Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeprogram);

//D.2.a 
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();



//D.2.b
	void setStudentID(string student_id);
	void setFirstName(string first_name);
	void setLastName(string last_name);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDaysInCourse(int, int);
	void setDegreeProgram(DegreeProgram degree);

//D.2.e
	void print();
};
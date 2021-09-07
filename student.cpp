#include <iostream>
#include "student.h"
#include "degree.h"

//Max White - PA for C867


Student::Student(string studentID, string firstName, string lastName, string address, int age, int daysInCourse[], DegreeProgram program)
{
	StudentID = studentID;
	FirstName = firstName;
	LastName = lastName;
	EmailAddress = address;
	Age = age;
	DaysInCourse[0] = daysInCourse[0];
	DaysInCourse[1] = daysInCourse[1];
	DaysInCourse[2] = daysInCourse[2];
	degreeProgram = program;
}
//D.2.a
string Student::getStudentID()
{
	return StudentID;
}
string Student::getFirstName()
{
	return FirstName;
}
string Student::getLastName()
{
	return LastName;
}
string Student::getEmailAddress()
{
	return EmailAddress;
}
int Student::getAge()
{
	return Age;
}
int* Student::getDaysInCourse()
{
	return DaysInCourse;
}
DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

//D.2.b
void Student::setStudentID(string studentID)
{
	StudentID = studentID;
}
void Student::setFirstName(string firstName)
{
	FirstName = firstName;
}
void Student::setLastName(string lastName)
{
	LastName = lastName;
}
void Student::setEmailAddress(string email)
{
	EmailAddress = email;
}
void Student::setAge(int age)
{
	Age = age;
}
void Student::setDaysInCourse(int DayInCourse, int CourseNumber)
{
	DaysInCourse[CourseNumber - 1] = DayInCourse;
}
void Student::setDegreeProgram(DegreeProgram degree)
{
	degreeProgram = degree;
}
//D.2.e 
void Student::print()
{
	string degreeProgramString;

	if (getDegreeProgram() == DegreeProgram::SOFTWARE)
	{
		degreeProgramString = "SOFTWARE";
	}
	else if (getDegreeProgram() == DegreeProgram::NETWORK)
	{
		degreeProgramString = "NETWORK";
	}
	else if (getDegreeProgram() == DegreeProgram::SECURITY)
	{
		degreeProgramString = "SECURITY";
	}
	
//D.2.e printing student data
	cout << left << getStudentID() << "\t";
	cout << left << " First Name: " << getFirstName() << "\t";
	cout << left << " Last Name: " << getLastName() << "\t";
	cout << left << " Email Address: " << getEmailAddress() << "\t";
	cout << left << " Age: " << getAge() << "\t";
	cout << left << " Days In Course: " << DaysInCourse[0] << "," << DaysInCourse[1] << "," << DaysInCourse[2] << "\t";
	cout << left << " Degree Program: " << degreeProgramString << endl;
}
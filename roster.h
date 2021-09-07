
#include "student.h"
#include <iostream>
#include <cstring>
//Max White PA C867

using namespace std;

class Roster
{
private:
	int parseCounter;
	int numStudents = 5;


public:
	//constructor / deconstructor 
	Roster();
	~Roster();


	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDayInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void parse(string studentData[]);

	Student* classRosterArray[5];
};

#include "roster.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
//Max White - PA C867



int main()
{
	//F.1
	
	cout << "Scripting and Programming: Applications - C867" << endl;

	cout << "C++ Programming Language" << endl;

	cout << "Student ID: 005946697" << endl;

	cout << "Max White" << endl;

	const int rosterSize = 5;

	string studentData[5] =
	{ "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
	  "A2, Suzan,Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
	  "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
	  "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
	  "A5, Max, White, mwhi850@my.wgu.edu, 26, 20, 4, 10, SOFTWARE"
	};

	//F.2
	Roster classRoster;
	DegreeProgram degreeProgram;


	//F.3
	classRoster.parse(studentData);
	string studentID;

	//F.4 
	cout << endl << "Students on Roster:" << endl;
	classRoster.printAll();
	cout << endl;

	// invalid emails
	classRoster.printInvalidEmails();
	cout << endl;

	//average days in course
	cout << "Average Days in Course Sorted by Student ID:";
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		classRoster.printAverageDayInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;
	classRoster.remove("A3");
}
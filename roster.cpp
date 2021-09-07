#include <iostream>
#include <string>
#include "roster.h"
#include <vector>
#include <sstream>
//Max White - PA C867

//E. CREATE Roster Class
Roster::Roster()
{
	classRosterArray[4] = {};
	parseCounter = 0;
	numStudents = 5;
}



Roster::~Roster()
{
	for (int i = 0; i < 5; ++i)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}



void Roster::parse(string studentArray[])
{
	for (int i = 0; i < numStudents; ++i)
	{
		string my_str = studentArray[i];
		vector<string> result;
		DegreeProgram degree{};
		istringstream s_stream(my_str);


		while (s_stream.good())
		{
			string subStr;

			getline(s_stream, subStr, ',');

			result.push_back(subStr);
		}
		if (result.at(8) == "SECURITY")
		{
			degree = DegreeProgram::SECURITY;
		}
		else if (result.at(8) == "NETWORK")
		{
			degree = DegreeProgram::NETWORK;
		}
		else if (result.at(8) == "SOFTWARE")
		{
			degree = DegreeProgram::SOFTWARE;
		}
		
		this->add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stoi(result.at(5)), stoi(result.at(6)), stoi(result.at(7)), degree);
		parseCounter = parseCounter + 1;
	}
}


//E.3.a
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[parseCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}



//E.3.b
void Roster::remove(string studentID)
{
	cout << "Removing " << studentID << endl;
	for (int i = 0; i < numStudents; ++i)
	{
		if (classRosterArray[i] == nullptr)
		{
			cout << "Student " << studentID << " was not found." << endl;
		}
		else if (classRosterArray[i]->getStudentID() == studentID)
		{
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}

//E.3.c
void Roster::printAll()
{
	for (int i = 0; i < parseCounter; i++)
	{
		if (classRosterArray[i] == nullptr){}
		else {
			classRosterArray[i]->print();
		}
	}
}


//E.3.d
void Roster::printAverageDayInCourse(string studentID)
{
	for (int i = 0; i < parseCounter; i++)
	{
		string stuID = classRosterArray[i]->getStudentID();
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			int course1 = classRosterArray[i]->getDaysInCourse()[0];
			int course2 = classRosterArray[i]->getDaysInCourse()[1];
			int course3 = classRosterArray[i]->getDaysInCourse()[2];

			cout << "Student ID: " << classRosterArray[i]->getStudentID() << " Average Days in Courses are: ";
			cout << (course1 + course2 + course3) / 3 << endl;
		}
	}
}


//E.3.e
void Roster::printInvalidEmails()
{
	cout << "Invalid emails: " << endl;
	for (int i = 0; i < parseCounter; ++i)
	{
		string emailCheck = classRosterArray[i]->getEmailAddress();
		if (emailCheck.find(' ') != string::npos)
		{
			cout << emailCheck << " Reason: No Spaces allowed." << endl;
		}
		else if (emailCheck.find('.') == string::npos)
		{
			cout << emailCheck << " Reason: Missing period." << endl;
		}
		else if (emailCheck.find('@') == string::npos)
		{
			cout << emailCheck << " Reason: Missing @ Symbol." << endl;
		}
	}
}

//E.3.f
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	string degreeProgramString;
	if (degreeProgram == DegreeProgram::SOFTWARE)
	{
		degreeProgramString = "SOFTWARE";
	}
	else if (degreeProgram == DegreeProgram::NETWORK)
	{
		degreeProgramString = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::SECURITY)
	{
		degreeProgramString = "SECURITY";
	}

	cout << "This is the Students in Degree Program: " << degreeProgramString << endl;

	for (int i = 0; i < 5; ++i)
	{
		DegreeProgram checkDegree;
		checkDegree = classRosterArray[i]->getDegreeProgram();
		if (checkDegree == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
}
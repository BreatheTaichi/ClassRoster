/*
 * File:   roster.cpp
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish
 *
 * Created on September 11, 2018, 10:45 AM
 */

#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#include "student.h"
#include "degree.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "roster.h"

int main() {
    // Intro
    cout << "Scripting and Programming - Applications - c867\n";
    cout << "Programming Language Used: C++\n";
    cout << "Jaime Gladish\n\n";
    
    // Initialize Roster constructor, adding students.
    Roster classRoster;
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();
    classRoster.PrintDaysToComplete();
    classRoster.PrintByDegreeProgram(SOFTWARE);
    classRoster.Remove("A3");
    classRoster.Remove("A3");
    
    return 0;
}

Roster::Roster() {
    const int NUM_STUDENTS = 5;
    const int NUM_COLS = 9;
    int length = 0;
    int prevPos = 0;
    int currPos = 0;
    int j = 0;
    int i = 0;
    string* classRosterLoader[NUM_STUDENTS][NUM_COLS];
    string* subPtr = nullptr;

    //Data to be input by pointer array
    const string studentData[NUM_STUDENTS] = {
     "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Jaime,Gladish,jgladi3@wgu.edu,39,13,25,7,SOFTWARE"
    };
    
    
    
    // Fill out the class roster *classRosterLoader for Array.
    // Outer loop iterates through all students, adding the first element.
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        prevPos = 0;
        j = 0;
        currPos = studentData[i].find(",");
        subPtr = new string;
        *subPtr = studentData[i].substr(prevPos, currPos);
        classRosterLoader[i][j] = subPtr;
        prevPos = currPos;
        
        // Inner loop adds the remaining 8 items to each student record.
        for (int j = 1; j < NUM_COLS; ++j) {
            currPos = studentData[i].find(",", prevPos + 1);
            subPtr = new string;
            *subPtr = studentData[i].substr(prevPos + 1, currPos - prevPos - 1);
            classRosterLoader[i][j] = subPtr;
            prevPos = currPos;
        }
        
        //Recast strings to integers
        int theAge = stoi(*classRosterLoader[i][4]); 
        int theDay1 = stoi(*classRosterLoader[i][5]);
        int theDay2 = stoi(*classRosterLoader[i][6]);
        int theDay3 = stoi(*classRosterLoader[i][7]);
        
        //Create Student objects based on program type, and add to array
        if (*classRosterLoader[i][8] == "SECURITY") {
            SecurityStudent* student = new SecurityStudent(*classRosterLoader[i][0], *classRosterLoader[i][1], *classRosterLoader[i][2], 
                    *classRosterLoader[i][3], theAge, theDay1, theDay2, theDay3);
            classRosterArray[i] = student;
        }
        if (*classRosterLoader[i][8] == "NETWORK") {
            NetworkStudent* student = new NetworkStudent(*classRosterLoader[i][0], *classRosterLoader[i][1], *classRosterLoader[i][2], 
                    *classRosterLoader[i][3], theAge, theDay1, theDay2, theDay3);
            classRosterArray[i] = student;
        }
        if (*classRosterLoader[i][8] == "SOFTWARE") {
            SoftwareStudent* student = new SoftwareStudent(*classRosterLoader[i][0], *classRosterLoader[i][1], *classRosterLoader[i][2], 
                    *classRosterLoader[i][3], theAge, theDay1, theDay2, theDay3);
            classRosterArray[i] = student;
        }
        
    }    
}

//Destructor
Roster::~Roster() {
    cout << "Destructor called.\n";
    for (int i = 0; i < 5; ++i) {
        delete classRosterArray[i];
    }
}

//Student Add() function
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, 
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree program) {
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse1(int daysInCourse1);
    void SetDaysInCourse2(int daysInCourse2);
    void SetDaysInCourse3(int daysInCourse3);
    void SetDegreeProgram(degree program);
}

// Delete student data.
void Roster::Remove(string studentID) {
    bool foundStudent = false;
    //Search array for studentID
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            foundStudent = true;
            classRosterArray[i]->SetStudentID("");
            classRosterArray[i]->SetFirstName("");
            classRosterArray[i]->SetLastName("");
            classRosterArray[i]->SetEmailAddress("");
            classRosterArray[i]->SetStudentAge(0);
            classRosterArray[i]->SetDaysInCourse1(0);
            classRosterArray[i]->SetDaysInCourse2(0);
            classRosterArray[i]->SetDaysInCourse3(0);
        }
    }
    //Print whether deleted or not found.
    if (foundStudent) {
        cout << "Student: " << studentID << " deleted.\n";
    }
    else {
        cout << "Student: " << studentID << " not found\n";
    }
    cout << endl;
}

// Print all student info (except email addresses)
void Roster::PrintAll() {
    cout << "Student records:\n";
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i]->PrintStudent();
    }
    cout << endl;
}

//Test and print functions, FIXME turn into print function for all data 
// on a given student.
void Roster::PrintDaysToComplete() {
    int dAvg = 0;
    for (int i = 0; i < 5; ++i) {
        dAvg = (classRosterArray[i]->GetDay1() + classRosterArray[i]->GetDay2() + classRosterArray[i]->GetDay3()) / 3;
        cout << "Average Days in courses for " << classRosterArray[i]->GetStudentID() << ": " << dAvg << endl;
    }
    cout << endl;
}

//Output all invalid email addresses.
void Roster::PrintInvalidEmails() {
    size_t searchString;
    cout << "Invalid emails:\n";
    for (int i = 0; i < 5; ++i) {
        searchString = classRosterArray[i]->GetEmailAddress().find(" ");
        if (searchString != std::string::npos) {
            cout << classRosterArray[i]->GetStudentID() << " contains invalid address: " << classRosterArray[i]->GetEmailAddress() << endl;
        }
        searchString = classRosterArray[i]->GetEmailAddress().find(".");
        if (searchString == std::string::npos) {
            cout << classRosterArray[i]->GetStudentID() << " contains invalid address: " << classRosterArray[i]->GetEmailAddress() << endl;
        }
        searchString = classRosterArray[i]->GetEmailAddress().find("@");
        if (searchString == std::string::npos) {
            cout << classRosterArray[i]->GetStudentID() << " contains invalid address: " << classRosterArray[i]->GetEmailAddress() << endl;
        }
    }
    cout << endl;
}

//Print out all students in given degree.
void Roster::PrintByDegreeProgram(degree mProgram) {
    cout << "Students in chosen degree program:\n";
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == mProgram) {
            cout << classRosterArray[i]->GetStudentID() << "\t" << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << endl;
        }
    }
    cout << endl;
}
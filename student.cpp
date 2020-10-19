/* 
 * File:   student.cpp
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 * 
 * Created on September 11, 2018, 10:49 AM
 */

#include <iostream>
#include <vector>

using namespace std;
#include "student.h"

//Default Constructor for Student class
Student::Student() {};

//Destructor
Student::~Student() {
}

//Mutators for Student class
void Student::SetStudentID(string mStudentID) {
    studentID = mStudentID;
}
void Student::SetFirstName(string mFirstName) {
    firstName = mFirstName;
}

void Student::SetLastName(string mLastName) {
    lastName = mLastName;
}

void Student::SetEmailAddress(string mEmailAddress) {
    emailAddress = mEmailAddress;
}

void Student::SetStudentAge(int mStudentAge) {
    studentAge = mStudentAge;
}

void Student::SetDaysInCourse1(int mNumDays1) {
    numDays1 = mNumDays1;
}

void Student::SetDaysInCourse2(int mNumDays2) {
    numDays2 = mNumDays2;
}

void Student::SetDaysInCourse3(int mNumDays3) {
    numDays3 = mNumDays3;
}

// Accessors for Student class
string Student::GetStudentID() const {
    return studentID;
}
string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetStudentAge() const {
    return studentAge;
}

int Student::GetDay1() const {
    return numDays1;
}
int Student::GetDay2() const {
    return numDays2;
}
int Student::GetDay3() const {
    return numDays3;
}

degree Student::GetDegreeProgram(){}

void Student::PrintStudent(){
        cout << (i + 1) << "\t First Name: " << this->GetFirstName() << "\tLast Name: " << this->GetLastName();
        cout << "\tAge: " << this->GetStudentAge() << "\t\tDays in course: {" << this->GetDay1();
        cout << ", " << this->GetDay2() << ", " << this->GetDay3() << "}\t\n";
}



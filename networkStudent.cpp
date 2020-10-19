/*
 * File:   networkStudent.cpp
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 * 
 * Created on September 11, 2018, 10:50 AM
 */

#include "networkStudent.h"
#include "student.h"
#include "degree.h"

NetworkStudent::NetworkStudent(string mStudentID, string mFirstName, string mLastName, string mEmailAddress, int mStudentAge, int days1, int days2, int days3) {
    studentID = mStudentID;
    firstName = mFirstName;
    lastName = mLastName;
    emailAddress = mEmailAddress;
    studentAge = mStudentAge;
    numDays1 = days1;
    numDays2 = days2;
    numDays3 = days3;
}

NetworkStudent::NetworkStudent(const NetworkStudent& orig) {
}

NetworkStudent::~NetworkStudent() {
}

degree NetworkStudent::GetDegreeProgram() {
    return degreeType;
}
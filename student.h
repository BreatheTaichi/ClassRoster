/*
 * File:   student.h
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 *
 * Created on September 11, 2018, 10:49 AM
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

#include "degree.h"

class Student {
    public:
        Student();
        ~Student();
        
        void    SetStudentID(string mStudentID);
        void    SetFirstName(string mFirstName);
        void    SetLastName(string mLastName);
        void    SetEmailAddress(string mEmailAddress);
        void    SetStudentAge(int mStudentAge);
        void    SetDaysInCourse1(int mNumDays1);
        void    SetDaysInCourse2(int mNumDays2);
        void    SetDaysInCourse3(int mNumDays3);
        
        string  GetStudentID() const;
        string  GetFirstName() const;
        string  GetLastName() const;
        string  GetEmailAddress() const;
        int     GetStudentAge() const;
        int     GetDay1() const;
        int     GetDay2() const;
        int     GetDay3() const;
        virtual degree GetDegreeProgram();
        virtual void PrintStudent();

    protected:
        string  studentID;
        string  firstName;
        string  lastName;
        string  emailAddress;
        int     studentAge;
        int     numDays1;
        int     numDays2;
        int     numDays3;
        int     i;
        degree  degreeType;
};

#endif /* STUDENT_H */


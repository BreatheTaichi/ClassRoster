/* 
 * File:   securityStudent.h
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 *
 * Created on September 11, 2018, 10:51 AM
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"
#include "degree.h"

class SecurityStudent : public Student {
    public:
        SecurityStudent(string mStudentID, string mFirstName, string mLastName, string mEmailAddress, int mStudentAge, int days1, int days2, int days3);
        SecurityStudent(const SecurityStudent& orig);
        virtual ~SecurityStudent();
        degree GetDegreeProgram();

    private:
        degree degreeType = SECURITY;
        
};

#endif /* SECURITYSTUDENT_H */


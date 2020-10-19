/* 
 * File:   softwareStudent.h
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 *
 * Created on September 11, 2018, 10:51 AM
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student {
    public:
        SoftwareStudent(string mStudentID, string mFirstName, string mLastName, string mEmailAddress, int mStudentAge, int days1, int days2, int days3);
        SoftwareStudent(const SoftwareStudent& orig);
        virtual ~SoftwareStudent();
        degree GetDegreeProgram();

    private:
        degree degreeType = SOFTWARE;

};

#endif /* SOFTWARESTUDENT_H */


/* 
 * File:   networkStudent.h
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 *
 * Created on September 11, 2018, 10:50 AM
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include "degree.h"

class NetworkStudent : public Student {
    public:
        NetworkStudent(string mStudentID, string mFirstName, string mLastName, string mEmailAddress, int mStudentAge, int days1, int days2, int days3);
        NetworkStudent(const NetworkStudent& orig);
        virtual ~NetworkStudent();
        degree GetDegreeProgram();
        
    private:
        degree degreeType = NETWORKING;

};

#endif /* NETWORKSTUDENT_H */


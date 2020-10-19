/* 
 * File:   roster.h
 * 
 * Programming Language Used: C++
 * IDE: NetBeans IDE 8.2
 * Author: Jaime Gladish, #000826682
 *
 * Created on September 11, 2018, 10:46 AM
 */

#ifndef ROSTER_H
#define ROSTER_H

class Roster {
    public:
        Roster();
        ~Roster();
        void FillRoster();
        void Add(string studentID, string firstName, string lastName, string emailAddress, 
                int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree program);
        
        void Remove(string studentID);
        void PrintAll();
        void PrintDaysToComplete();
        void PrintInvalidEmails();
        void PrintByDegreeProgram(degree mProgram);
        
        Student* classRosterArray[5];
        const int NUM_STUDENTS = 5;
        const int NUM_COLS = 9;
        
    private:
        string* classRosterLoader[5];
        int length = 0;
        
        //Data to be input by pointer array
        const string studentData[5];
        int i = 0;
        int j = 0;
            
};

#endif /* ROSTER_H */


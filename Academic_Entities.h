#ifndef ACADEMIC_ENTITIES_H
#define ACADEMIC_ENTITIES_H

#include <iostream>
using namespace std;
#include "Courses.h"
#include "Assessments.h"


class AcademicEntity{       
    string name,email,ID;
    int num_courses;
    Course *courses;
public:
    virtual void displayProfile()=0;

    string getName();
    string getEmail();
    string getID();
    int getNumCourses();

    void setName(string name);
    void setEmail(string email);
    void setID(string ID);
    void setNumCourses(int num);
};

class Student: public AcademicEntity{      
    int semester;
public:
    void calculateGPA();
    void viewTranscript();
    char* getcourses();
    int getSemester();
    void displayProfile();


    /* void addCourse(char* course);*/
    //void updateCourse(char );    
    void setSemester(int sem);


};
class Regular_Student: public Student{
    float gpa;  //CGPA
    float sgpa;

public:
    void displayProfile();
    float GPAcalculation();

    float getGPA();
    float getSGPA();
};

class Scholarship_Student: public Regular_Student{
    string status_flag;
public:
    void displayProfile();
    float GPA();

    string getStatus();
    void setStatus(string status);
};

class Exchange_Student: public Student{
public:
    void displayProfile();
    bool grading();     //either pass or fail
};


class Teacher: public AcademicEntity{
    string department;
    char*designation;
public:
    void setdepartment(string dept);
    void setdesignation(char* desig);

    string getDept();
    string getDesignation();
    void displayProfile();

};


#endif
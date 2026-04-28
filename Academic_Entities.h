#ifndef ACADEMIC_ENTITIES_H
#define ACADEMIC_ENTITIES_H

#include <iostream>
using namespace std;
#include "Courses.h"


class AcademicEntity{       
    string name,email,ID;
    int num_core, num_lab, num_elective;
    Core *core; Elective *elective; Lab *labs;
public:
    virtual void displayProfile()=0;

    string getName();
    string getEmail();
    string getID();
    int getNumCore();
    int getNumElective();
    int getNumLab();
    Core* getCore(int i);
    Elective* getElective(int i);
    Lab* getLab(int i);

    void setName(string name);
    void setEmail(string email);
    void setID(string ID);
    void setNumCore(int num);
    void setNumElective(int num);
    void setNumLab(int num);
};

class Student: public AcademicEntity{      
    int semester;
public:
    void viewTranscript();
    int getSemester();
    void displayProfile();
    /* void addCourse(char* course);*/
    //void updateCourse(char );    
    void setSemester(int sem);
    virtual string getType()=0;
};
class Regular_Student: public Student{
    float gpa;  //CGPA
    float sgpa;

public:
    Regular_Student();
    Regular_Student(string id,string name, string email, int semester,float gpa);
    void displayProfile();
    float GPAcalculation();
    string getType();
    float getGPA();
    float getSGPA();
    void setgpa(float gpa);
};

class Scholarship_Student: public Regular_Student{
    string status_flag;
public:
    Scholarship_Student(string id, string name, string email, int semester, float gpa);
    void displayProfile();
    //float GPA();
    string getType();
    string getStatus();
    void setStatus(string status);
};

class Exchange_Student: public Student{
public:
    Exchange_Student(string id,string name, string email, int semester);
    string getType();
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

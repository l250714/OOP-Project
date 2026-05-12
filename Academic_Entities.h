#pragma once
#ifndef ACADEMIC_ENTITIES_H
#define ACADEMIC_ENTITIES_H

#include <iostream>
using namespace std;
#include "Courses.h"

float getPointsCore(Course* ptr, Student* s);
float getPointsElective(Course* ptr, Student* s);
float getPointsLab(Course* ptr, Student* s);

class AcademicEntity {
protected:
    string name, email, ID;
    int num_core, num_lab, num_elective;
    vector <Core> core; vector <Elective> elective;  vector <Lab> labs;
public:
    AcademicEntity();
    virtual void displayProfile() = 0;
    string getName();
    string getEmail();
    string getID();
    int getNumCore();
    int getNumElective();
    int getNumLab();
    Core& getCore(int i);
    Elective& getElective(int i);
    Lab& getLab(int i);

    void setName(string name);
    void setEmail(string email);
    void setID(string ID);
    void setNumCore(int num);
    void setNumElective(int num);
    void setNumLab(int num);
    void setCore(Core* ptr);
    void setElective(Elective* ptr);
    void setLab(Lab* ptr);
    virtual ~AcademicEntity();

};

class Student : public AcademicEntity {
    int semester;
    string section;
public:
    Student();
    virtual void viewTranscript()=0;
    virtual int getSemester();
    virtual void displayProfile()=0;
    string getSection();
    void setSection(string section);   
    virtual void setSemester(int sem);
    virtual string getType() = 0;
    virtual float GPAcalculation() = 0;
    virtual ~Student();
};

class Regular_Student : public Student {
    float gpa;  //CGPA

public:
    Regular_Student();
    Regular_Student(string id, string name, string email, int semester, float gpa,string section);
    void displayProfile();
    float GPAcalculation();
    string getType();
    void setgpa(float gpa);
    ~Regular_Student();
    void viewTranscript();
};

class Scholarship_Student : public Regular_Student {
    string status_flag;
public:
    Scholarship_Student();
    Scholarship_Student(string id, string name, string email, int semester, float gpa, string section);
    void displayProfile();
    string getType();
    string getStatus();
    void setStatus(string status);
    float GPAcalculation();
    ~Scholarship_Student();
    void viewTranscript();
};

class Exchange_Student : public Student {
public:
    Exchange_Student();
    Exchange_Student(string id, string name, string email, int semester, string section);
    string getType();
    void displayProfile();
    bool grading();     //either pass or fail
    float GPAcalculation() override { return -1; }    //since we do not need to calculate the gpa of an exchange student
    ~Exchange_Student();
    void viewTranscript();
};


class Teacher : public AcademicEntity {
    string department;
    string designation;
    float avgFeedback;
public:
    Teacher();
    void setdepartment(string dept);
    void setdesignation(string desig);
    void setavgFeedback(float feedback);
    float getavgFeedback();
    string getDept();
    string getDesignation();
    void displayProfile();
    ~Teacher();

};

#endif

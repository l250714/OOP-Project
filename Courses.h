#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Assessments.h"
using namespace std;

class Student;

//think about schedule and timings and venue
class Course{   //base class
protected:      //makes data members accessible in child classes
    char* ID;
    char* name;
    int TQuizzes, TExams, TAssignments;     //total of each assessment type (in class)
    float exam_duration;
    int credithr;      
    float batch_average;    //out of 100 (in class)
public:
    Course();
    void set_ID(const char* id);
    void setname(const char* name);
    void setExamduration(float time);
    string getID();
    string getName();
    float getExamDuration();
    
};

//----Types of Courses-----

class Core: public Course{
    Quiz* quizzes;
    Exam* exams;
    Assignment* assignments;
    vector <Student*> students;
    float points;
    char*grade;

public:
    Core();
    void setpoints(float points);
    void setgrade(char* grade);
    float getpoints();
    string getgrade();

};

class Elective: public Course{
    Assignment* assignments;
    Project final_project;
    Quiz* quizzes;
    float points;
    char*grade;
public:
    Elective();
    void setpoints(float points);
    void setgrade(char* grade);
    float getpoints();
    string getgrade();
};

class Lab: public Course{
    Quiz* quizzes;
    Assignment* Lab_tasks;
    float points;
    char*grade;
public:
    Lab();
    void setpoints(float points);
    void setgrade(char* grade);
    float getpoints();
    string getgrade();
};


#endif
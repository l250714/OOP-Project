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
    string ID;
    string name;
    int TQuizzes, TExams, TAssignments;     //total of each assessment type (in class)
    float exam_duration;
    int credithr;      
    float batch_average;    //out of 100 (in class)
    string teacherID;
    vector <Student*> students;
public:
    Course();
    void set_ID(const char* id);
    void setname(const char* name);
    void setExamduration(float time);
    void setStudent(Student& obj);
    string getID();
    string getName();
    float getExamDuration();
    Student& getStudent(int i);
    
};

//----Types of Courses-----

class Core: public Course{
    vector<Quiz> quizzes;
    vector<Exam> exams;
    vector <Assignment> assignments;
    float points;
    char*grade;

public:
    Core();
    void setpoints(float points);
    void setgrade(char* grade);
    void setQuiz(Quiz& obj);
    void setExam(Exam& obj);
    void setAssignment(Assignment& obj);
    float getpoints();
    string getgrade();
    Exam& getExam(int i);
    Quiz& getQuiz(int i);
    Assignment& getAssignment(int i);

};

class Elective: public Course{
    vector <Assignment> assignments;
    Project final_project;
    vector<Quiz> quizzes;
    float points;
    char*grade;
public:
    Elective();
    void setpoints(float points);
    void setQuiz(Quiz& obj);
    void setgrade(char* grade);
    void setLabtasks(Assignment& obj);
    //void setProject();
    float getpoints();
    string getgrade();
     Quiz& getQuiz(int i);
    Assignment& getLabTasks(int i);
};

class Lab: public Course{
    vector<Quiz> quizzes;
    vector <Assignment> Lab_tasks;
    float points;
    char*grade;
public:
    Lab();
    void setpoints(float points);
    void setgrade(char* grade);
    void setQuiz(Quiz& obj);
    void setAssignment(Assignment& obj);
    Quiz& getQuiz(int i);
    Assignment& getAssignment(int i);
    float getpoints();
    string getgrade();
};


#endif

#pragma once
#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Assessments.h"
using namespace std;

class Student;
//think about schedule and timings and venue
class Course {   //base class
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
    void set_ID(string id);
    void set_teacherID(string id);
    void setname(string name);
    void setExamduration(float time);
    void setStudent(Student& obj);
    string getID();
    string getName();
    float getExamDuration();
    string get_teacherid();
    Student& getStudent(int i);
    virtual int getTQuizzes()=0;
    virtual int getTExams()=0;
    virtual int getTAssignments()=0;
    virtual int getCredits()=0;
    virtual string getType() = 0;
    //vector<Student*> getallStudents();
    virtual ~Course();

};

//----Types of Courses-----

class Core : public Course {
    vector<Quiz> quizzes;
    vector<Exam> exams;
    vector <Assignment> assignments;
    float points;
    string grade;

public:
    Core();
    void setpoints(float points);
    void setgrade(string grade);
    void setQuiz(Quiz& obj);
    void setExam(Exam& obj);
    void setAssignment(Assignment& obj);

    float getpoints();
    string getgrade();
    Exam& getExam(int i);
    Quiz& getQuiz(int i);
    string getType();
    Assignment& getAssignment(int i);
    int getCredits();
    int getTQuizzes();
    int getTExams();
    int getTAssignments();
    ~Core();

};

class Elective : public Course {
    vector <Assignment> assignments;
    vector<Quiz> quizzes;
    float points;
    string grade;
public:
    Elective();
    void setpoints(float points);
    void setQuiz(Quiz& obj);
    void setgrade(string grade);
    void setAssignment(Assignment& obj);
    //void setProject();

    float getpoints();
    string getgrade();
    Quiz& getQuiz(int i);
    string getType();
    Assignment& getAssignment(int i);
    int getCredits();
    int getTQuizzes();
    int getTExams();
    int getTAssignments();
    ~Elective();
};

class Lab : public Course {
    vector<Quiz> quizzes;
    vector <Assignment> Lab_tasks;
    float points;
    string grade;
public:
    Lab();
    void setpoints(float points);
    void setgrade(string grade);
    void setQuiz(Quiz& obj);
    void setAssignment(Assignment& obj);
    Quiz& getQuiz(int i);
    float getpoints();
    string getgrade();
    string getType();
    int getCredits();
    int getTQuizzes();
    int getTExams();
    Assignment& getAssignment(int i);
    int getTAssignments();
    ~Lab();
};


#endif

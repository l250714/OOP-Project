#pragma once
#ifndef ASSESSMENTS_H
#define ASSESSMENTS_H

#include <iostream>
using namespace std;

class Assessments {
    float weightage;
    float max, min, avg;
    int num;    //assessment number
    float rawscore;
    int totalMarks;
    string sectionid;
    string StudentID;
    string courseID;
public:
    Assessments();

    virtual string getType() = 0;
    float getWeight();
    float getMax();
    float getMin();
    float getAvg();
    float getRawscore();
    int getNum();
    int getTMarks();
    string getsectionid();
    string getCourseID();
    string getStudentID();
    void setWeight(float weight);
    void setMax(float max);
    void setMin(float min);
    void setAvg(float avg);
    void setRawscore(float rawScore);
    void setNum(int num);
    void setTMarks(int total);
    void setsectionid(string id);
    void setStudentID(string id);

    virtual ~Assessments();
    void setCourseID(std::string id);
};

class Quiz : public Assessments {

public:
    Quiz();
    string getType();
    ~Quiz();

};

class Assignment : public Assessments {

public:
    Assignment();
    string getType();
    ~Assignment();
};

class Exam : public Assessments {
    int num_questions;
    float* marks_perQ;
public:
    Exam();
    string getType();
    ~Exam();
};


#endif

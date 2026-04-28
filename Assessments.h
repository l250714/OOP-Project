#ifndef ASSESSMENTS_H
#define ASSESSMENTS_H

#include <iostream>
using namespace std; 

class Assessments{
    float weightage;        
    float max,min,avg;
    int num;    //assessment number
    float rawscore;
    int totalMarks;
public:
    Assessments();

    virtual string getType()=0;
    float getWeight();
    float getMax();
    float getMin();
    float getAvg();
    float getRawscore();
    int getNum();
    int getTMarks();
    string getsectionid();

    void setWeight(float weight);
    void setMax(float max);
    void setMin(float min);
    void setAvg(float avg);
    void setRawscore(float rawScore);
    void setNum(int num);
    void setTMarks(int total);
    void setsectionid(string id);
};

class Quiz: public Assessments{
    
public:
   string getType();
   
};

class Assignment: public Assessments{

public:
   string getType();
};

class Exam: public Assessments{
    int num_questions;
    float* marks_perQ;
public:
    Exam();
    string getType();
};

class Project: public Assessments{

public:
    string getType();
};

#endif

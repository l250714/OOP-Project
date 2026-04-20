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

};

class Quiz: public Assessments{

};

class Assignment: public Assessments{
    
};

class Exam: public Assessments{
    int num_questions;
    float* marks_perQ;
};

class Project: public Assessments{
    
};

#endif
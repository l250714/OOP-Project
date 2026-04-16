#include <iostream>
using namespace std;

class Assessments{
    float weightage;
    float max,min,avg;
    int num;    //assessment number
    float rawscore;
    int totalMarks;
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

/* int main(){

    return 0;
} */

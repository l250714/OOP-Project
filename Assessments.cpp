#include <iostream>
using namespace std;
#include "Assessments.h"


//Assessment base class
Assessments::Assessments(){
    weightage=0;
    max=0, min=0, avg=0, num=0, rawscore=0, totalMarks=0;
}
float Assessments::getWeight(){
    return weightage;
}
float Assessments::getMax(){
    return max;
}
float Assessments::getMin(){
    return min;
}
float Assessments::getAvg(){
    return avg;
}
float Assessments::getRawscore(){
    return rawscore;
}
int Assessments::getNum(){
    return num;
}
int Assessments::getTMarks(){
    return totalMarks;
}

string Assessments::getsectionid(){
    return sectionid;
}
string Assessments::getStudentID() {
    return StudentID;
}

void Assessments::setWeight(float weight){
    weightage=weight;
}
void Assessments::setMax(float max){
    this->max=max;
}
void Assessments::setMin(float min){
    this->min=min;
}
void Assessments::setAvg(float avg){
    this->avg=avg;
}
void Assessments::setRawscore(float rawScore){
    rawscore=rawScore;
}
void Assessments::setNum(int num){
    this->num=num;
}
void Assessments::setTMarks(int total){
    totalMarks=total;
}

void Assessments::setsectionid(string id){
    sectionid=id;
}
void Assessments::setStudentID(string id) {
    StudentID = id;
}
Assessments::~Assessments(){}


//Quiz class
Quiz::Quiz(){
}
string Quiz:: getType(){
    return "Quiz";
}
Quiz::~Quiz(){}

//Assignment class
Assignment::Assignment(){}
string Assignment:: getType(){
    return "Assignment";
}
Assignment::~Assignment(){}

//Exam class
Exam::Exam(){}
string Exam:: getType(){
    return "Exam";
}
Exam::~Exam(){}

//Project class
Project::Project(){}
string Project:: getType(){
    return "Project";
}
Project::~Project(){}

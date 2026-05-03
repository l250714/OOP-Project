#include <iostream>
#include <string.h>
#include <vector>
#include "Academic_Entities.h"
#include "Assessments.h"
#include "Courses.h"
#include "Management.h"
#include "Venues.h"
using namespace std;
//think about schedule and timings and venue

Course::Course(){
    ID="none";
    name="none";
    teacherID="none";
    TQuizzes=0;
    TExams=0;
    TAssignments=0;
    exam_duration=0;        //has to be decided
}
void Course::set_ID(const char* id){
    //course ID must be alphanumeric and not longer than 7
    int idlen=strlen(id);
    if(idlen>7){
        cout<<"\nError: Course Code is Invalid. Please Try Again.";
        return;
    }
    for(int i=0;id[i]!='\0';i++){
        if(iswalnum(id[i])){
            continue;
        }
        else{
            cout<<"\nError: Course Code must only contain alphanumeric characters.";
            return;
        }
    }
    ID=new char[idlen+1];
    for(int i=0;id[i]!='\0';i++){
        ID[i]=id[i];
    }
    ID[idlen]='\0';
}
void Course::set_teacherID(string id){
    //course ID must be alphanumeric and not longer than 7
    int idlen=id.length();
    if(idlen>4){
        cout<<"\nError: Course Code is Invalid. Please Try Again.";
        return;
    }
    for(int i=0;id[i]!='\0';i++){
        if(iswalnum(id[i])){
            continue;
        }
        else{
            cout<<"\nError: Teacher ID must only contain alphanumeric characters.";
            return;
        }
    }
    teacherID=new char[idlen+1];
    for(int i=0;id[i]!='\0';i++){
        teacherID[i]=id[i];
    }
    teacherID[idlen]='\0';
}

void Course::setname(string name){
    int namelen=strlen(name);
    if(!isalpha(name[0])){
        cout<<"\nName of the course must begin with an alphabet or a number.";
        return;
    }
    else{
        this->name=new char[namelen+1];
        for(int i=0;i<namelen;i++){
            if(iswalnum(name[i])){
                this->name[i]=name[i];
            }
            else{
                cout<<"\nError: Course Name must only contain alphanumeric characters.";
                return;
            }
            
        }
        this->name[namelen]='\0';
    }
}
void Course::setExamduration(float time){
    //min time: 1hr & max time: 3hr
    if(time>3 || time<1){
        cout<<"\nError: Exam duration must be between 1-3 hours;";
        return;
    }
    else{
        exam_duration=time;
    }
}
void Course::setStudent(Student& obj){
    Student *s;
    if(obj.getType()=="Regular"){
        s=new Regular_Student;
        s->setEmail(obj.getEmail());
        s->setID(obj.getID());
        s->setName(obj.getName());
        s->setNumCore(obj.getNumCore());
        s->setNumElective(obj.getNumElective());
        s->setNumLab(obj.getNumLab());
        s->setSemester(obj.getSemester());
    }
    else if(obj.getType()=="Exchange"){
        s=new Exchange_Student(obj.getID(),obj.getName(),obj.getEmail(),obj.getSemester());
        s->setNumCore(obj.getNumCore());
        s->setNumElective(obj.getNumElective());
        s->setNumLab(obj.getNumLab());
        s->setSemester(obj.getSemester());
    }
    else if(obj.getType()=="Scholarship"){
        s= new Scholarship_Student(obj.getID(),obj.getName(),obj.getEmail(),obj.getSemester(),obj.GPAcalculation());
        s->setNumCore(obj.getNumCore());
        s->setNumElective(obj.getNumElective());
        s->setNumLab(obj.getNumLab());
        s->setSemester(obj.getSemester());
    }
}
Student& Course::getStudent(int i){
    return *students[i];
}

string Course::getID(){
    string temp="";
    for(int i=0;ID[i]!='\0';i++){
        temp+=ID[i];
    }
    return temp;
}
string Course::getName(){
    string temp="";
    for(int i=0;name[i]!='\0';i++){
        temp+=name[i];
    }
    return temp;
}
float Course::getExamDuration(){
    return exam_duration;
}
string Course::get_teacherid(){
    return teacherID;
}
    


//----Types of Courses-----


Core::Core(){
    credithr=3;
}
void Core::setpoints(float points){
    this->points=points;
}
void Core::setgrade(char* grade){
    if(strlen(grade)>2){
        cout<<"\nGrade is too long in length.";
        return;
    }
    else{
        for(int i=0;i<strlen(grade)+1;i++){
            this->grade[i]=grade[i];
        }
        this->grade[strlen(grade)]='\0';
    }
}
float Core::getpoints(){
    return points;
}
string Core::getgrade(){
    string temp="";
    for(int i=0;grade[i]!='\0';i++){
        temp+=grade[i];
    }
    return grade;
}


Elective::Elective(){
    credithr=2;
}
void Elective::setpoints(float points){
    this->points=points;
}
void Elective::setgrade(char* grade){
    if(strlen(grade)>2){
        cout<<"\nGrade is too long in length.";
        return;
    }
    else{
        for(int i=0;i<strlen(grade)+1;i++){
            this->grade[i]=grade[i];
        }
        this->grade[strlen(grade)]='\0';
    }
}
float Elective::getpoints(){
    return points;
}
string Elective::getgrade(){
    string temp="";
    for(int i=0;grade[i]!='\0';i++){
        temp+=grade[i];
    }
    return grade;
}



Lab::Lab(){
    credithr=1;
}
void Lab::setpoints(float points){
    this->points=points;
}
void Lab::setgrade(char* grade){
    if(strlen(grade)>2){
        cout<<"\nGrade is too long in length.";
        return;
    }
    else{
        for(int i=0;i<strlen(grade)+1;i++){
            this->grade[i]=grade[i];
        }
        this->grade[strlen(grade)]='\0';
    }
}
float Lab::getpoints(){
    return points;
}
string Lab::getgrade(){
    string temp="";
    for(int i=0;grade[i]!='\0';i++){
        temp+=grade[i];
    }
    return grade;
}


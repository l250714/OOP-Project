#include <iostream>
#include <cctype>
#include "allheaders.h"
using namespace std;

//Academic Entity class

string AcademicEntity:: getName(){
    return name;
}
string AcademicEntity:: getEmail(){
    return email;
}
string AcademicEntity:: getID(){
    return ID;
}
int AcademicEntity::getNumCore(){
    return num_core;
}
int AcademicEntity::getNumElective(){
    return num_elective;
}
int AcademicEntity::getNumLab(){
    return num_lab;
}
Core* AcademicEntity::getCore(int i){
    return &core[i];
}
Elective* AcademicEntity::getElective(int i){
    return &elective[i];
}
Lab* AcademicEntity::getLab(int i){
    return &labs[i];
}

void AcademicEntity:: setName(string name){
    this->name=name;
}
void AcademicEntity:: setEmail(string email){
    this->email=email;
}
void AcademicEntity:: setID(string ID){
    this->ID=ID;
}
void AcademicEntity:: setNumCore(int num){
    num_core=num;
}
void AcademicEntity:: setNumElective(int num){
    num_elective=num;
}
void AcademicEntity:: setNumLab(int num){
    num_lab=num;
}



//Student class
void Student::viewTranscript(){     //printing

}
int Student::getSemester(){
    return semester;
}
void Student::displayProfile(){}

/* void Student::addCourse(char* course){
    num_courses++;
    char** temp=courses;
    courses= new char*[num_courses];
    int x;
    for(int i=0;i<num_courses-1;i++){
        for(int j=0;temp[i][j]!='\0';j++){
            courses[i][j]=temp[i][j];
            x=j+1;
        }
        courses[i][x]='\0';
    }
    for(int i=0;course[i]!='\0';i++){
        courses[num_courses][i]=temp[i][j];
        x=i+1;
    }
    courses[num_courses][x]='\0';
} */
//void Student::updateCourse(char )    
void Student::setSemester(int sem){
    semester=sem;
}

//Regular Student class
Regular_Student::Regular_Student(){
    setID("0000");
    setName("xyz");
    setEmail("xyz@nowehere.com");
    setSemester(0);
}
Regular_Student::Regular_Student(string id,string name, string email, int semester,float gpa){
    setID(id);
    setName(name);
    setEmail(email);
    setSemester(semester);
    this->gpa=gpa;
}
void Regular_Student::displayProfile(){ //printing

}

float Regular_Student::GPAcalculation(){

}
float Regular_Student::getGPA(){
    return gpa;
}
float Regular_Student::getSGPA(){
    return sgpa;
}
string Regular_Student::getType(){
    return "Regular";
}
void Regular_Student::setgpa(float gpa){
    this->gpa=gpa;
}


//Scholarship Student class
Scholarship_Student::Scholarship_Student(string id, string name, string email, int semester, float gpa){
    setID(id);
    setEmail(email);
    setName(name);
    setSemester(semester);
    setgpa(gpa);
}
void  Scholarship_Student::displayProfile(){}
float  Scholarship_Student::GPA(){}
string  Scholarship_Student::getStatus(){
    return status_flag;
}
void Scholarship_Student::setStatus(string status){
    string lowstat="";
    for(int i=0;status[i]!='\0';i++){
        lowstat+=tolower(status[i]);
    }
    if(lowstat=="settled" || lowstat=="probabtion"){
        status_flag=lowstat;
        status_flag[0]=toupper(status_flag[0]);
    }
    else{
        cout<<"\nError: Invalid status.";
        return;
    }
    
}

string Scholarship_Student::getType(){
    return "Scholarship";
}


//Exchange Student Class
Exchange_Student::Exchange_Student(string id,string name, string email, int semester){
    setID(id);
    setEmail(email);
    setName(name);
    setSemester(semester);
}
void Exchange_Student::displayProfile(){}
bool Exchange_Student::grading(){}   //either pass or fail
string Exchange_Student::getType(){
    return "Exchange";
}


//Teacher Class
void Teacher::setdepartment(string dept){
    dept=department;
}
void Teacher::setdesignation(char* desig){
    for(int i=0;desig[i]!='\0';i++){
        designation[i]=desig[i];
    }
    designation[strlen(desig)+1]='\0';
}

string Teacher::getDept(){
    return department;
}
string Teacher::getDesignation(){
    string temp="";
    for(int i=0;designation[i]!='\0';i++){
        temp+=designation[i];
    }
    return temp;
}
void Teacher::displayProfile(){}



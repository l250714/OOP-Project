#include <iostream>
#include <cctype>
#include "Courses.h"
#include "Assessments.h"
#include "Academic_Entities.h"
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
int AcademicEntity:: getNumCourses(){
    return num_courses;
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
void AcademicEntity:: setNumCourses(int num){
    num_courses=num;
}


//Student class
void Student::calculateGPA(){}
void Student::viewTranscript(){}
char* Student::getcourses(){
    
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
void Regular_Student::displayProfile(){}
float Regular_Student::GPAcalculation(){

}
float Regular_Student::getGPA(){
    return gpa;
}
float Regular_Student::getSGPA(){
    return sgpa;
}

//Scholarship Student class
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

//Exchange Student Class

void Exchange_Student::displayProfile(){}
bool Exchange_Student::grading(){}   //either pass or fail

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



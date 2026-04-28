#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "allheaders.h"
using namespace std;

vector <Student*> studentinfo;
vector <Teacher> teacherinfo;


string trim(const string& line){
    int start=0, end=line.size()-1;
    while(start<=end && (isspace(line[start]) || line[start]=='\r')){
        start++;
    }
    while(end>=start && (isspace(line[end])   || line[end]=='\r')){
        end--;
    }
    if(start>end) return "";
    return line.substr(start, end-start+1);
}

void readStudentdata(){
    Student *s;
    ifstream students("Students.txt");
    string id,name,email,type, gpa,section,semester,line;
    while (getline(students, line)) {
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, type, '|');
        getline(ss, gpa, '|');
        getline(ss, section, '|');
        getline(ss, semester, '|');
        id=trim(id); name=trim(name); type=trim(type);
        gpa=trim(gpa); semester=trim(semester);
        if(type=="Regular"){
            s=new Regular_Student(id,name,email,stoi(semester),stof(gpa));
        }
        else if(type=="Exchange"){
            s=new Exchange_Student(id,name,email,stoi(semester));
        }
        else if(type=="Scholarship"){
            s=new Scholarship_Student(id,name,email,stoi(semester),stof(gpa));
        }
        studentinfo.push_back(s);
   }
    students.close();
}

void readSectionsdata(){}

void readTeachersdata(){}

void readVenuesdata(){}

void readWeightagesdata(){}

void readAssessmentsdata(){}

void readCoursesdata(){}


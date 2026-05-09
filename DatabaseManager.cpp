#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Assessments.h"
#include "DatabaseManager.h"
#include "Academic_Entities.h"
#include "Management.h"
#include "Courses.h"

using namespace std;

vector <Student*> studentinfo;  
vector <Teacher> teacherinfo;       
vector <section_course> sectioninfo;    
vector <Course*> courseinfo;   
vector <Venue> venueinfo;      
vector <Assessments*> assesssmentinfo; 
W weightstore[3];  


string trim(const string& line){
    int start=0, end=line.length()-1;
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
    ifstream students("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Students.txt");
    string id,name,email,type, gpa,section,semester,line;
    if (!students.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(students, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, email, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, gpa, '|');
        getline(ss, semester, '|');
        getline(ss, section, '|');
        id=trim(id); name=trim(name); type=trim(type);
        gpa=trim(gpa); semester=trim(semester);
        //cout << semester;
        if(type=="Regular"){
            s=new Regular_Student(id,name,email,stoi(semester),stof(gpa));
        }
        else if(type=="Exchange"){
            s=new Exchange_Student(id,name,email,stoi(semester));
        }
        else if(type=="Scholarship"){
            s=new Scholarship_Student(id,name,email,stoi(semester),stof(gpa));
        }
        else {
            s = nullptr;
        }
        studentinfo.push_back(s);
        //cout << endl << studentinfo[0]->getID();
   }
    students.close();
}

void readCoursesdata(){     
    Course *c;
    ifstream course("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Courses.txt");
    string id,name,teacherid,c_type,line1;
    if (!course.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(course, line1)) {
        if (line1.empty()) continue;
        istringstream ss(line1);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, teacherid, '|');
        getline(ss, c_type, '|');
        id=trim(id); name=trim(name); c_type=trim(c_type); teacherid=trim(teacherid);
        if(c_type=="Core"){
            c=new Core;

        }
        else if(c_type=="Elective"){
            c=new Elective;
        }
        else if(c_type=="Lab"){
            c=new Lab;
        }
        else {  //this will never happen but just a precaution
            c = nullptr;
        }
        c->set_ID(id);
        c->set_teacherID(teacherid);
        c->setname(name);
        courseinfo.push_back(c);
   }
    course.close();
}

void readTeachersdata(){
    Teacher t;
    ifstream teachers("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Teachers.txt");
    string id,name,feedback,line,designation, department, email;
    if (!teachers.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(teachers, line)) {
        if (trim(line).empty()) {
            continue;
        }
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, designation, '|');
        getline(ss, department, '|');
        getline(ss, email, '|');
        getline(ss, feedback, '|');

        id = trim(id); name = trim(name);
        designation = trim(designation); department = trim(department);
        email = trim(email); feedback = trim(feedback);
        t.setID(id);
        t.setName(name);
        t.setdesignation(designation);
        t.setdepartment(department);
        t.setEmail(email);
        t.setavgFeedback(stof(feedback));
        teacherinfo.push_back(t);
    }
    teachers.close();
}

void readVenuesdata(){
    Venue v;
    ifstream venues("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Venues.txt");
    string id,capacity,hasComp,line;
    if (!venues.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(venues, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, capacity, '|');
        getline(ss, hasComp, '|');
        id=trim(id); capacity=trim(capacity); hasComp=trim(hasComp);
        v.setID(id);
        v.setCapacity(stoi(capacity));
        v.setComputer(stoi(hasComp));
        venueinfo.push_back(v);
   }
    venues.close();
}

void readSectionsdata(){
    section_course s;
    ifstream sections("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Sections.txt");
    string sectionid,courseid,teacherid,venueid, timing,line;
    if (!sections.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(sections, line)) {
        istringstream ss(line);     //Input-only stream for strings.
        if (line.empty()) continue;
        getline(ss, sectionid, '|');
        getline(ss, courseid, '|');
        getline(ss, teacherid, '|');
        getline(ss, venueid, '|');
        getline(ss, timing, '|');
        sectionid=trim(sectionid); courseid=trim(courseid); teacherid=trim(teacherid);
        venueid=trim(venueid); timing=trim(timing);
        //find courses      can use .at()
        for(int i=0;i<courseinfo.size();i++){
            if(courseinfo[i]->getID()==courseid){
                s.setCourse(*courseinfo[i]);
                break;
            }
        }
        //find teacher
        for(int i=0;i<teacherinfo.size();i++){
            if(teacherinfo[i].getID()==teacherid){
                s.setTeacher(teacherinfo[i]);
                break;
            }
        }
        //find venue
        for(int i=0;i<venueinfo.size();i++){
            if(venueinfo[i].getID()==venueid){
                s.setVenue(venueinfo[i]);
                break;
            }
        }
        s.setsectionID(sectionid);
        s.setTimings(timing);
        sectioninfo.push_back(s);
   }
    sections.close();
}

void readWeightagesdata(){
    ifstream weights("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Weightages.txt");
    string w_type,exam,assignment,quiz,line2;
    int index;
    if (!weights.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(weights, line2)) {
        if (line2.empty()) continue;
        istringstream ss(line2);
        getline(ss, w_type, '|');
        getline(ss, exam, '|');
        getline(ss, assignment, '|');
        getline(ss, quiz, '|');
        w_type=trim(w_type); exam=trim(exam); assignment=trim(assignment); quiz=trim(quiz);
        if(w_type=="Core"){
            index = 0;
        }
        else if(w_type=="Elective"){
            index = 1;
        }
        else if(w_type=="Lab"){
            index = 2;
        }
        weightstore[index].assignment = stof(assignment);
        weightstore[index].exam = stof(exam);
        weightstore[index].quiz = stof(quiz);
   }
    weights.close();
} 

void readAssessmentsdata(){
    //SectionID | StudentID| Type (Exam/Quiz/Assignment) | RawScore |MaxScore | MinScore
    Assessments* a=nullptr;
    ifstream assess("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project\\Assessments.txt");
    string id,stdID,type,rawscore,maxscore,minscore,line;
    if (!assess.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(assess, line)) {     
        istringstream ss(line);
        if (line.empty()) continue;

        // Parse all 5 delimited fields
        getline(ss, id, '|');
        getline(ss, stdID, '|');
        getline(ss, type, '|');
        getline(ss, rawscore, '|');
        getline(ss, maxscore, '|');
        getline(ss, minscore, '|');

        id = trim(id);
        stdID = trim(stdID);
        type = trim(type);
        rawscore = trim(rawscore);
        maxscore = trim(maxscore);
        minscore = trim(minscore);

        if (type == "Exam") {
            a = new Exam;
        }
        else if (type == "Assignment") {
            a = new Assignment;
        }
        else if (type == "Quiz") {
            a = new Quiz;
        }
        else if (type == "Project") {
            a = new Project;
        }
        else {
            a = nullptr; 
            return;
        }
        if (a && ss) {      //making sure data is valid
            a->setsectionid(id);
            a->setStudentID(stdID);
            a->setRawscore(stof(rawscore));
            a->setMax(stof(maxscore));
            a->setMin(stof(minscore));
            assesssmentinfo.push_back(a);
            //cout << "\nSize: " << assesssmentinfo.size();
        }
    }       
    assess.close();
}

//LINKING ALL DATA TOGETHER:

void Linking(){
    for (int i = 0; i < teacherinfo.size(); i++) {
        //first we need to count how many labs, elective and core courses there are
        int coreCount = 0, elecCount = 0, labCount = 0;
        for (int k = 0; k < courseinfo.size(); k++) {
            if (courseinfo[k]->get_teacherid() == teacherinfo[i].getID()) {
                string ctype = courseinfo[k]->getType();
                if (ctype == "Core") {
                    coreCount++;
                }
                else if (ctype == "Elective") {
                    elecCount++;
                }
                else if (ctype == "Lab") {
                    labCount++;
                }
            }
        }
        teacherinfo[i].setNumCore(coreCount);
        teacherinfo[i].setNumElective(elecCount);
        teacherinfo[i].setNumLab(labCount);

        //now after allocating memory we can add the courses
        for (int k = 0; k < courseinfo.size(); k++) {
            if (courseinfo[k]->get_teacherid() == teacherinfo[i].getID()) {
                string ctype = courseinfo[k]->getType();
                if (ctype == "Core") {
                    Core* c = dynamic_cast<Core*>(courseinfo[k]);   //dyanmic casting to be sure the data will get stored properly
                    if (c) {    //had to make sure something went in the pointer
                        teacherinfo[i].setCore(*c);
                    }
                }
                else if (ctype == "Elective") {
                    Elective* e = dynamic_cast<Elective*>(courseinfo[k]);
                    if (e) {
                        teacherinfo[i].setElective(*e);
                    }
                }
                else if (ctype == "Lab") {
                    Lab* l = dynamic_cast<Lab*>(courseinfo[k]);
                    if (l) {
                        teacherinfo[i].setLab(*l);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < studentinfo.size(); i++) {
        for (int j = 0; j < sectioninfo.size(); j++) {
            if (studentinfo[i]->getSection() == sectioninfo[j].getSectionID()) {
                string cid = sectioninfo[j].getCourse().getID();
                for (int k = 0; k < courseinfo.size(); k++) {
                    if (courseinfo[k]->getID() == cid) {
                        courseinfo[k]->setStudent(*studentinfo[i]);
                        break;
                    }
                }
            }
        }
    }
    /*for (int i = 0;i < sectioninfo.size();i++) { something is going wrong here. Trying to set sectioninfo by comparing with section info wowwww
        for (int j = 0;j < teacherinfo.size();j++) {
            if (teacherinfo[j].getID() == sectioninfo[i].getCourseTeacherID()) {
                sectioninfo[i].setTeacher(teacherinfo[j]);
                break;
            }
       }
        for (int j = 0;j < venueinfo.size();j++) {
            if (venueinfo[j].getID() == sectioninfo[i].getVenue().getID()) {
                sectioninfo[i].setVenue(venueinfo[j]);
                break;
            }
        }
        for (int j = 0;j < courseinfo.size();j++) {
            if (courseinfo[j]->getID() == sectioninfo[i].getCourseID()) {
                sectioninfo[i].setCourse(*courseinfo[j]);
                break;
            }
        }
    }*/

}


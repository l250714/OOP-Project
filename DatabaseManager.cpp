#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "allheaders.h"
using namespace std;

vector <Student*> studentinfo;  //ID | Name | Type | GPA | Semester| SectionID
vector <Teacher> teacherinfo;       //ID | Name | AverageFeedback
vector <section_course> sectioninfo;    //SectionID | CourseID | TeacherID | VenueID | TimeSlot
vector <Course*> courseinfo;    //CourseID | Title | TeacherID | Type
vector <Venue> venueinfo;     //RoomID | Capacity | HasComputers(1/0)  
vector <Assessments*> assesssmentinfo; //SectionID | Type (Exam/Quiz/Assignment) | RawScore |MaxScore | MinScore
W weightstore[3];   //0: core; 1: elective; 2: lab


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
    string id,name,feedback,line;
    if (!teachers.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(teachers, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, feedback, '|');
        id=trim(id); name=trim(name); feedback=trim(feedback);
        t.setavgFeedback(stof(feedback));
        t.setID(id);
        t.setName(name);
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
    struct W{
        float exam;
        float assignment;
        float quiz;
    };
    W weightstore[3];   //0: core; 1: elective; 2: lab
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
            weightstore[0].assignment=stof(assignment);
            weightstore[0].exam=stof(exam);
            weightstore[0].quiz=stof(quiz);
        }
        else if(w_type=="Elective"){
            weightstore[1].assignment=stof(assignment);
            weightstore[1].exam=stof(exam);
            weightstore[1].quiz=stof(quiz);
        }
        else if(w_type=="Lab"){
            weightstore[2].assignment=stof(assignment);
            weightstore[2].exam=stof(exam);
            weightstore[2].quiz=stof(quiz);
        }
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
}


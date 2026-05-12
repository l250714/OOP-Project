#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
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

string trim(const string& line) {
    int start = 0, end = line.length() - 1;
    while (start <= end && (isspace(line[start]) || line[start] == '\r')) {
        start++;
    }
    while (end >= start && (isspace(line[end]) || line[end] == '\r')) {
        end--;
    }
    if (start > end) return "";
    return line.substr(start, end - start + 1);
}

void readExamSchedule() {
    ifstream file("ExamSchedule.txt");

    ExamSlot temp;
    string section, cid, vid, date, time, line;
    ifstream exam("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\ExamSchedule.txt");
    if (!exam.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(exam, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        getline(ss, section, '|');
        getline(ss, cid, '|');
        getline(ss, vid, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        section = trim(section); cid = trim(cid); vid = trim(vid); date = trim(date); time = trim(time);
        temp.courseID = cid;
        temp.date = stoi(date);
        temp.sectionID = section;
        temp.venueID = vid;
        temp.time = time;
        finalschedule.push_back(temp);
    }

    exam.close();
}

void readStudentdata() {
    Student* s;
    ifstream students("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Students.txt");
    string id, name, email, type, gpa, section, semester, line;
    if (!students.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(students, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, type, '|');
        getline(ss, gpa, '|');
        getline(ss, semester, '|');
        getline(ss, section, '|');
        id = trim(id); name = trim(name); type = trim(type);
        gpa = trim(gpa); semester = trim(semester); section = trim(section);
        if (type == "Regular") {
            s = new Regular_Student(id, name, email, stoi(semester), stof(gpa), section);
        }
        else if (type == "Exchange") {
            s = new Exchange_Student(id, name, email, stoi(semester), section);
        }
        else if (type == "Scholarship") {
            s = new Scholarship_Student(id, name, email, stoi(semester), stof(gpa), section);
        }
        else {
            s = nullptr;
        }
        studentinfo.push_back(s);
    }
    students.close();
}

void readCoursesdata() {
    Course* c;
    ifstream course("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Courses.txt");
    string id, name, semester, teacherid, c_type, line1;
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
        getline(ss, semester, '|');
        id = trim(id); name = trim(name); c_type = trim(c_type); teacherid = trim(teacherid); semester = trim(semester);
        if (c_type == "Core") {
            c = new Core;
        }
        else if (c_type == "Elective") {
            c = new Elective;
        }
        else if (c_type == "Lab") {
            c = new Lab;
        }
        else {  //this will never happen but just a precaution
            c = nullptr;
        }
        c->set_ID(id);
        c->set_teacherID(teacherid);
        c->setname(name);
        c->setSemester(stoi(semester));
        courseinfo.push_back(c);
    }
    course.close();
}

float readTeacherFeedback(string t_id) {
    float avg = 0;
    int count = 1;
    ifstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt");
    string id, FB, line;
    if (!feedback.is_open()) {
        cout << "\nError opening file!" << endl;
        return -1.1;
    }
    while (getline(feedback, line)) {
        if (trim(line).empty()) {
            continue;
        }
        istringstream ss(line);
        getline(ss, id, '|');
        getline(ss, FB, '|');
        id = trim(id); FB = trim(FB);
        if (id == t_id) {
            avg += stof(FB);
            count++;
        }
    }
    feedback.close();
    avg /= count;
    return avg;
}

void readResultsdata() {
    ifstream results("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Results.txt");
    string sid, cid, points, line;
    if (!results.is_open()) {
        cout << "\nError opening file!" << endl;
        return;
    }
    while (getline(results, line)) {
        if (trim(line).empty()) {
            continue;
        }
        istringstream ss(line);
        getline(ss, sid, '|');
        getline(ss, cid, '|');
        getline(ss, points, '|');

        sid = trim(sid); cid = trim(cid);
        points = trim(points);
    }
    //find student
    for (int i = 0;i < studentinfo.size();i++) {
        if (studentinfo[i]->getID() == sid) {
            for (int j = 0;j < studentinfo[i]->getNumCore();j++) {
                if (studentinfo[i]->getCore(j).getID() == cid) {
                    studentinfo[i]->getCore(j).setpoints(stof(points));
                }
            }
        }
        
    }
    results.close();

}

void readTeachersdata() {
    Teacher t;
    ifstream teachers("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Teachers.txt");
    string id, name, line, designation, department, email;
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

        id = trim(id); name = trim(name);
        designation = trim(designation); department = trim(department);
        email = trim(email);
        t.setID(id);
        t.setName(name);
        t.setdesignation(designation);
        t.setdepartment(department);
        t.setEmail(email);
        t.setavgFeedback(readTeacherFeedback(id));
        teacherinfo.push_back(t);
    }
    teachers.close();
}

void readVenuesdata() {
    Venue v;
    ifstream venues("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Venues.txt");
    string id, capacity, hasComp, line;
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
        id = trim(id); capacity = trim(capacity); hasComp = trim(hasComp);
        v.setID(id);
        v.setCapacity(stoi(capacity));
        v.setComputer(stoi(hasComp));
        venueinfo.push_back(v);
    }
    venues.close();
}

void readSectionsdata() {
    section_course s;
    ifstream sections("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Sections.txt");
    string sectionid, courseid, teacherid, venueid, timing, line;
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
        sectionid = trim(sectionid); courseid = trim(courseid); teacherid = trim(teacherid);
        venueid = trim(venueid); timing = trim(timing);
        //find courses      can use .at()
        for (int i = 0;i < courseinfo.size();i++) {
            if (courseinfo[i]->getID() == courseid) {
                s.setCourse(courseinfo[i]);
                break;
            }
        }
        //find teacher
        for (int i = 0;i < teacherinfo.size();i++) {
            if (teacherinfo[i].getID() == teacherid) {
                s.setTeacher(teacherinfo[i]);
                break;
            }
        }
        //find venue
        for (int i = 0;i < venueinfo.size();i++) {
            if (venueinfo[i].getID() == venueid) {
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

void readWeightagesdata() {
    ifstream weights("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Weightages.txt");
    string w_type, exam, assignment, quiz, line2;
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
        w_type = trim(w_type); exam = trim(exam); assignment = trim(assignment); quiz = trim(quiz);
        if (w_type == "Core") {
            index = 0;
        }
        else if (w_type == "Elective") {
            index = 1;
        }
        else if (w_type == "Lab") {
            index = 2;
        }
        weightstore[index].assignment = stof(assignment);
        weightstore[index].exam = stof(exam);
        weightstore[index].quiz = stof(quiz);
    }
    weights.close();
}

void readAssessmentsdata() {
    //SectionID | StudentID| Type (Exam/Quiz/Assignment) | RawScore |MaxScore | MinScore
    Assessments* a = nullptr;
    ifstream assess("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Assessments.txt");
    string id, stdID, courseID, type, rawscore, maxscore, minscore, line, total;
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
        getline(ss, courseID, '|');
        getline(ss, type, '|');
        getline(ss, rawscore, '|');
        getline(ss, maxscore, '|');
        getline(ss, minscore, '|');
        getline(ss, total, '|');

        id = trim(id);
        stdID = trim(stdID);
        courseID = trim(courseID);
        type = trim(type);
        rawscore = trim(rawscore);
        maxscore = trim(maxscore);
        minscore = trim(minscore);
        total = trim(total);
        //figure out what the course type is
        string ctype;
        for (int i = 0;i < courseinfo.size();i++) {
            if (courseID == courseinfo[i]->getID()) {
                ctype = courseinfo[i]->getType();
            }
        }

        if (type == "Exam") {
            a = new Exam;
            if (ctype == "Core") {   //exams only for Core courses
                a->setWeight(weightstore[0].exam);
            }
        }
        else if (type == "Assignment") {
            a = new Assignment;
            if (ctype == "Core") {
                a->setWeight(weightstore[0].assignment);
            }
            else if (ctype == "Elective") {
                a->setWeight(weightstore[1].assignment);
            }
            else {
                a->setWeight(weightstore[2].assignment);
            }
        }
        else if (type == "Quiz") {
            a = new Quiz;
            if (ctype == "Core") {
                a->setWeight(weightstore[0].quiz);
            }
            else if (ctype == "Elective") {
                a->setWeight(weightstore[1].quiz);
            }
            else {
                a->setWeight(weightstore[2].quiz);
            }
        }
        else {
            a = nullptr;
            return;
        }
        if (a && ss) {      //making sure data is valid
            a->setsectionid(id);
            a->setStudentID(stdID);
            a->setCourseID(courseID); 
            a->setRawscore(stof(rawscore));
            a->setMax(stof(maxscore));
            a->setMin(stof(minscore));
            a->setTMarks(stof(total));
            assesssmentinfo.push_back(a);
            
        }
    }
    assess.close();
}

//LINKING ALL DATA TOGETHER:

void Linking() {
    for (int i = 0; i < teacherinfo.size(); i++) {
        for (int k = 0; k < courseinfo.size(); k++) {
            if (courseinfo[k]->get_teacherid() == teacherinfo[i].getID()) {
                string ctype = courseinfo[k]->getType();
                if (ctype == "Core") {
                    Core* c = dynamic_cast<Core*>(courseinfo[k]);   //dyanmic casting to be sure the data will get stored properly
                    if (c) {    //had to make sure something went in the pointer
                        teacherinfo[i].setCore(c);
                    }
                }
                else if (ctype == "Elective") {
                    Elective* e = dynamic_cast<Elective*>(courseinfo[k]);
                    if (e) {
                        teacherinfo[i].setElective(e);
                    }
                }
                else if (ctype == "Lab") {
                    Lab* l = dynamic_cast<Lab*>(courseinfo[k]);
                    if (l) {
                        teacherinfo[i].setLab(l);
                    }
                }
            }
        }
    }

    for (int i = 0; i < studentinfo.size(); i++) {
        for (int j = 0; j < sectioninfo.size(); j++) {
            if (studentinfo[i]->getSection() == sectioninfo[j].getSectionID()) {
                string cid = sectioninfo[j].getCourseID();
                for (int k = 0; k < courseinfo.size(); k++) {
                    if (courseinfo[k]->getID() == cid) {
                        courseinfo[k]->setStudent(*studentinfo[i]);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0;i < sectioninfo.size();i++) { 
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
                sectioninfo[i].setCourse(courseinfo[j]);
                break;
            }
        }
    }
    // Assumption: all students of a section are registered for the same courses
    //in sectionsinfo, we have sectionID and CourseID
    for (int i = 0;i < studentinfo.size();i++) {    //for all students
        for (int j = 0;j < sectioninfo.size();j++) {
            if (sectioninfo[j].getSectionID() == studentinfo[i]->getSection()) {    //if section ID matches
                //finding the core course using course ID
                for (int k = 0;k < courseinfo.size();k++) {
                    if (sectioninfo[j].getCourseID() == courseinfo[k]->getID() && courseinfo[k]->getType() == "Core") {
                        studentinfo[i]->setCore(dynamic_cast<Core*>(courseinfo[k]));
                    }
                    else if (sectioninfo[j].getCourseID() == courseinfo[k]->getID() && courseinfo[k]->getType() == "Elective") {
                        studentinfo[i]->setElective(dynamic_cast<Elective*>(courseinfo[k]));
                    }
                    else if (sectioninfo[j].getCourseID() == courseinfo[k]->getID() && courseinfo[k]->getType() == "Lab") {
                        studentinfo[i]->setLab(dynamic_cast<Lab*>(courseinfo[k]));
                    }
                }
            }
        }
    }
    //add relevant assessments to each student
    for (int i = 0;i < assesssmentinfo.size();i++) {
        //find course type
        string type;
        for (int j = 0;j < courseinfo.size();j++) {
            if (courseinfo[j]->getID() == assesssmentinfo[i]->getCourseID()) {
                type = courseinfo[j]->getType();
                break;
            }
        }
        for (int j = 0;j < studentinfo.size();j++) {
            if (studentinfo[j]->getID() == assesssmentinfo[i]->getStudentID()) {    //match student ID
                if (type == "Core") {
                    if (assesssmentinfo[i]->getType() == "Quiz") {  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumCore();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getCore(k).getID()) {  //match the course ID
                                studentinfo[j]->getCore(k).setQuiz(dynamic_cast<Quiz*>(assesssmentinfo[i]));
                            }
                        }
                    }
                    else if (assesssmentinfo[i]->getType() == "Assignment") {  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumCore();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getCore(k).getID()) {  //match the course ID
                                studentinfo[j]->getCore(k).setAssignment(dynamic_cast<Assignment*>(assesssmentinfo[i]));
                            }
                        }
                    }
                    else{  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumCore();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getCore(k).getID()) {  //match the course ID
                                studentinfo[j]->getCore(k).setExam(dynamic_cast<Exam*>(assesssmentinfo[i]));
                            }
                        }
                    }
                }
                if (type == "Elective") {
                    if (assesssmentinfo[i]->getType() == "Quiz") {  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumElective();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getElective(k).getID()) {  //match the course ID
                                studentinfo[j]->getElective(k).setQuiz(dynamic_cast<Quiz*>(assesssmentinfo[i]));
                            }
                        }
                    }
                    else if (assesssmentinfo[i]->getType() == "Assignment") {  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumElective();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getElective(k).getID()) {  //match the course ID
                                studentinfo[j]->getElective(k).setAssignment(dynamic_cast<Assignment*>(assesssmentinfo[i]));
                            }
                        }
                    }
                }
                else {
                    if (assesssmentinfo[i]->getType() == "Quiz") {  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumLab();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getLab(k).getID()) {  //match the course ID
                                studentinfo[j]->getLab(k).setQuiz(dynamic_cast<Quiz*>(assesssmentinfo[i]));
                            }
                        }
                    }
                    else if (assesssmentinfo[i]->getType() == "Assignment") {  //match the type
                        for (int k = 0;k < studentinfo[j]->getNumLab();k++) {
                            if (assesssmentinfo[i]->getCourseID() == studentinfo[j]->getLab(k).getID()) {  //match the course ID
                                studentinfo[j]->getLab(k).setAssignment(dynamic_cast<Assignment*>(assesssmentinfo[i]));
                            }
                        }
                    }
                }
                
            }
        }
    }
}


void closing() {
    //Students.txt
    string line;
    ofstream students("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Students.txt");
    ofstream results("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Results.txt");   
    for (int i = 0;i < studentinfo.size();i++) {
        line = studentinfo[i]->getID() + "|" + studentinfo[i]->getName() + "|" + studentinfo[i]->getEmail() + "|" + studentinfo[i]->getType() + "|" + to_string(studentinfo[i]->GPAcalculation()) + "|" + to_string(studentinfo[i]->getSemester()) + "|" + studentinfo[i]->getSection();
        students << line << endl;
        string l;
        for (int j = 0;j < studentinfo[i]->getNumCore();j++) {
            l = studentinfo[i]->getID() + "|" + studentinfo[i]->getCore(j).getID() + "|" + to_string(studentinfo[i]->getCore(j).getpoints());
            results << l << endl;
        }
    }
    students.close();
    results.close();

    //Teachers.txt
    ofstream teachers("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Teachers.txt");
    for (int i = 0;i < teacherinfo.size();i++) {
        line = teacherinfo[i].getID() + "|" + teacherinfo[i].getName() + "|" + teacherinfo[i].getDesignation() + "|" + teacherinfo[i].getDept() + "|" + teacherinfo[i].getEmail();
        teachers << line << endl;
    }
    teachers.close();

    //Weightages
    ofstream weights("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Weightages.txt");
    line = "Core|" + to_string(weightstore[0].exam) + "|" + to_string(weightstore[0].assignment) + "|" + to_string(weightstore[0].quiz);
    weights << line << endl;
    line = "Elective|" + to_string(weightstore[1].exam) + "|" + to_string(weightstore[1].assignment) + "|" + to_string(weightstore[1].quiz);
    weights << line << endl;
    line = "Lab|" + to_string(weightstore[2].exam) + "|" + to_string(weightstore[2].assignment) + "|" + to_string(weightstore[2].quiz);
    weights << line << endl;
    weights.close();

    //Courses
    ofstream courses("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Courses.txt");
    for (int i = 0;i < courseinfo.size();i++) {
        line = courseinfo[i]->getID() + "|" + courseinfo[i]->getName() + "|" + courseinfo[i]->get_teacherid() + "|" + courseinfo[i]->getType() + "|" + to_string(courseinfo[i]->getSemester());
        courses << line << endl;
    }
    courses.close();

    //Venues.txt
    ofstream venues("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Venues.txt");
    for (int i = 0;i < venueinfo.size();i++) {
        line = venueinfo[i].getID() + "|" + to_string(venueinfo[i].getCapacity()) + "|";
        if (venueinfo[i].getComputers()) {
            line += "1";
        }
        else {
            line += "0";
        }
        venues << line << endl;
    }
    venues.close();

    //Sections.txt
    ofstream sections("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\Sections.txt");
    for (int i = 0;i < sectioninfo.size();i++) {
        line = sectioninfo[i].getSectionID() + "|" + sectioninfo[i].getCourseID() + "|" + sectioninfo[i].getTeacher().getID() + "|" + sectioninfo[i].getVenue().getID() + "|" + sectioninfo[i].getTimings();
        sections << line << endl;
    }
    sections.close();

    //Assessments.txt
    ofstream tests("C:\\Users\\hp\\OneDrive\\Desktop\\Uni study\\Sem 2\\OOP\\Project ver 2\\text files\\Assessments.txt");
    for (int i = 0;i < assesssmentinfo.size();i++) {
        line = assesssmentinfo[i]->getsectionid() + "|" + assesssmentinfo[i]->getStudentID() + "|" + assesssmentinfo[i]->getCourseID() + "|" + assesssmentinfo[i]->getType() + "|" + to_string(assesssmentinfo[i]->getRawscore()) + "|" + to_string(assesssmentinfo[i]->getMax()) + "|" + to_string(assesssmentinfo[i]->getMin())+ "|"+ to_string(assesssmentinfo[i]->getTMarks());
        tests << line << endl;
    }
    tests.close();

    //Results.txt

}

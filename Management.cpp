#include <iostream>
#include <fstream>
#include <iomanip>
#include "Assessments.h"
#include "Management.h"
#include "Courses.h"
#include "Venues.h"
#include "Academic_Entities.h"
#include "DatabaseManager.h"
using namespace std;


section_course::section_course() {
    courseID = "none";
    courseName = "none";
    courseTeacherID = "none";
    courseExamDuration = 0.0f;
    courseType = "none";

    teacher.setdepartment("none");
    teacher.setdesignation("none");
    teacher.setEmail("none");
    teacher.setID("none");
    teacher.setName("none");
    teacher.setNumCore(0);
    teacher.setNumElective(0);
    teacher.setNumLab(0);

    venue.setCapacity(0);
    venue.setComputer(0);
    venue.setID("none");

    sectionid = "none";
    timings = "none";
}

void section_course::setCourse(Course*ptr) {
    courseID = ptr->getID();
    courseName = ptr->getName();
    courseTeacherID = ptr->get_teacherid();
    courseExamDuration = ptr->getExamDuration();
    courseType = ptr->getType();   // works on concrete Core/Elective/Lab
}

void section_course::setTeacher(Teacher& obj) {
    teacher.setavgFeedback(obj.getavgFeedback());
    teacher.setdepartment(obj.getDept());
    teacher.setdesignation(obj.getDesignation());
    teacher.setEmail(obj.getEmail());
    teacher.setID(obj.getID());
    teacher.setName(obj.getName());
    teacher.setNumCore(obj.getNumCore());
    teacher.setNumElective(obj.getNumElective());
    teacher.setNumLab(obj.getNumLab());
}

void section_course::setVenue(Venue& obj) {
    venue.setCapacity(obj.getCapacity());
    venue.setComputer(obj.getComputers());
    venue.setID(obj.getID());
}

void section_course::setsectionID(string id) { 
    sectionid = id; 
}
void section_course::setTimings(string t) { 
    timings = t; 
}
string section_course::getCourseID() const { 
    return courseID; 
}
string section_course::getCourseName() const { 
    return courseName; 
}
string section_course::getCourseTeacherID() const { 
    return courseTeacherID; 
}
float  section_course::getCourseExamDuration() const { 
    return courseExamDuration; 
}
string section_course::getCourseType() const { 
    return courseType; 
}


Course* section_course::getCourse(string id) const {
    for(int i=0;i<courseinfo.size();i++){
        if (courseinfo[i]->getID() == id) {
            return courseinfo[i];
        }
    }
    return courseinfo[0];   //hopefully will never happen
}
Teacher& section_course::getTeacher() { 
    return teacher; 
}
Venue& section_course::getVenue() { 
    return venue; 
}
string   section_course::getSectionID() const { 
    return sectionid; 
}
string   section_course::getTimings() const { 
    return timings; 
}

section_course::~section_course() {}

void CoreFeedback(Student* ptr) {
    ofstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt",ios::app);
    int numq = 0;
    float score;
    int Tscore = 0;
    for (int i = 0;i < ptr->getNumCore();i++) {
        cout << "Course: " << ptr->getCore(i).getName();
        cout << "\nHow would you rate the teaching style on a scale of 0-5?";   //doing 2 questions for now
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }
        }
        cout << "\nHow well did you understand the course contents on a scale of 0-5?";
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }

        }
        string line = "";
        line += (ptr->getCore(i).get_teacherid() + "|" + to_string(Tscore / numq));
        feedback << line<<endl;
    }

    feedback.close();
}
void ElectiveFeedback(Student* ptr) {
    ofstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt", ios::app);
    int numq = 0;
    float score;
    int Tscore = 0;
    for (int i = 0;i < ptr->getNumElective();i++) {
        cout << "Course: " << ptr->getElective(i).getName();
        cout << "\nHow would you rate the teaching style on a scale of 0-5?";   //doing 2 questions for now
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }
        }
        cout << "\nHow well did you understand the course contents on a scale of 0-5?";
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }

        }
        string line = "";
        line += (ptr->getElective(i).get_teacherid() + "|" + to_string(Tscore / numq));
        feedback << line<<endl;
    }

    feedback.close();
}
void LabFeedback(Student* ptr) {
    ofstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt", ios::app);
    int numq = 0;
    float score;
    int Tscore = 0;
    for (int i = 0;i < ptr->getNumLab();i++) {
        cout << "Course: " << ptr->getLab(i).getName();
        cout << "\nHow would you rate the teaching style on a scale of 0-5?";   //doing 2 questions for now
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }
        }
        cout << "\nHow well did you understand the course contents on a scale of 0-5?";
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }

        }
        string line = "";
        line += (ptr->getLab(i).get_teacherid() + "|" + to_string(Tscore / numq));
        feedback << line<<endl;
    }

    feedback.close();
}


//Feedback system
void TeacherFeedbacks(Student* ptr) {
    CoreFeedback(ptr);
    ElectiveFeedback(ptr);
    LabFeedback(ptr);
}


void availableCourses(int sem) {
    cout << "\n========================================================\n";
    cout << left
        << setw(15) << "Course ID"
        << setw(30) << "Course Name"
        << setw(15) << "Type" << endl;
    cout << "========================================================\n";
    for (int i = 0;i < courseinfo.size();i++) {
        if (courseinfo[i]->getSemester() == sem) {
            cout << "\nCode: " << courseinfo[i]->getID() << endl << "Name: " << courseinfo[i]->getName() << endl << "Type: " << courseinfo[i]->getType();
        }
    }
}
int RegisteredStudents(string courseID) {

    int count = 0;

    for (int i = 0; i < studentinfo.size(); i++) {

        for (int j = 0; j < studentinfo[i]->getNumCore(); j++) {
            if (studentinfo[i]->getCore(j).getID() == courseID)
                count++;
        }

        for (int j = 0; j < studentinfo[i]->getNumElective(); j++) {
            if (studentinfo[i]->getElective(j).getID() == courseID)
                count++;
        }

        for (int j = 0; j < studentinfo[i]->getNumLab(); j++) {
            if (studentinfo[i]->getLab(j).getID() == courseID)
                count++;
        }
    }

    return count;
}
void SmartResgitartion(Student* ptr, string id) {
    //find the course the student wants to register for
    for (int i = 0;i < courseinfo.size();i++) {
        if (courseinfo[i]->getID() == id) {
            //checking if student is already registered for this course
            for (int j = 0;j < courseinfo[i]->getStudent().size();j++) {
                if (courseinfo[i]->getStudent()[j]->getID() == ptr->getID()) {
                    cout << "\nAlready registered for this course.";
                    return;
                }
            }
            //check if capacity is available
            for (int j = 0;j < sectioninfo.size();j++) {
                if (sectioninfo[j].getCourseID() == id) {
                    int count = RegisteredStudents(id);
                    if (sectioninfo[j].getVenue().getCapacity() == count) {
                        cout << "\nCourse is full :(";
                        return;
                    }
                }
            }
            //registering for this course
            if (courseinfo[i]->getType() == "Core") {
                ptr->setCore(dynamic_cast<Core*>(courseinfo[i]));
            }
            else if (courseinfo[i]->getType() == "Elective") {
                ptr->setElective(dynamic_cast<Elective*>(courseinfo[i]));
            }
            else {
                ptr->setLab(dynamic_cast<Lab*>(courseinfo[i]));
            }
            courseinfo[i]->setStudent(*ptr);
        }
    }
    cout << "\nRegistration successful!";
}


//Exam schedule Manager
vector<ExamSlot> finalschedule;

int CountStudentsInSection(string section) {

    int count = 0;

    for (int i = 0; i < studentinfo.size(); i++) {

        if (studentinfo[i]->getSection() == section) {

            count++;
        }
    }

    return count;
}
void Scheduler() {
    string time[3] = { "9AM-12PM", "1:30PM-4:30PM","4:30-6:30" };
    int index = 0; int usage=0, vcounter=0;
    int date = 1;  //1st May
    ExamSlot temp;
    for (int i = 0;i < sectioninfo.size();i++) {
        if (CountStudentsInSection(sectioninfo[i].getSectionID()) <= venueinfo[vcounter].getCapacity()) {
            temp.courseID = sectioninfo[i].getCourseID();
            temp.date = date;
            temp.sectionID = sectioninfo[i].getSectionID();
            temp.time = time[index];
            index++;
            usage++;
            temp.venueID = sectioninfo[i].getVenue().getID();
            finalschedule.push_back(temp);
            if (usage > 3) {
                vcounter++;
                usage = 0;
            }
            if (index > 2) {
                index = 0;
                date++;
            }
        }
        else {
            vcounter++; //move on to a different venue
        }
    }
    SaveExamSchedule();

}
void SaveExamSchedule() {

    ofstream file("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\ExamSchedule.txt",ios::app);

    for (int i = 0; i < finalschedule.size(); i++) {
        file<< finalschedule[i].sectionID << " | "<< finalschedule[i].courseID << " | "<< finalschedule[i].venueID << " | "<< finalschedule[i].date << " | "<< finalschedule[i].time << endl;
    }

    file.close();
}

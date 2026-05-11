#include <iostream>
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

vector <booking> examschedule;
void ConflictSolver() {
    for (int i = 0;i < examschedule.size()-1;i++) {
        if (examschedule[i].date == examschedule[i + 1].date) {
            examschedule[i + 1].date += 1;
        }
    }
}

void Scheduler(string section) {
    //management can set the number of hours for each exam: in Database Manager
    //count number of students in a single section:
    int count = 0;
    for (int i = 0;i < sectioninfo.size();i++) {
        if (section == sectioninfo[i].getSectionID()) {
            count++;
        }
    }
    //find total number of courses for each section (assuming all students are registered for the same courses)
    int tcourses = 0;
    for (int i = 0;i < studentinfo.size();i++) {
        if (studentinfo[i]->getSection() == section) {
            tcourses = (studentinfo[i]->getNumCore()) + (studentinfo[i]->getNumElective()) + (studentinfo[i]->getNumLab());
        }
    }
    for (int i = 0;i < venueinfo.size();i++) {  //initializing examschedule
        booking temp;
        temp.v = &venueinfo[i];
        temp.status = false;
        temp.date = 0;
        examschedule.push_back(temp);
    }
    //assuming exams start on 20th May
    for (int i = 0;i < venueinfo.size();i++) {
        if (examschedule[i].date==0) {
            //check if venues are booked
            for (int j = 0;j < examschedule.size();j++) {
                if (!(examschedule[j].status) && examschedule[j].v->getID() == venueinfo[i].getID() && examschedule[j].v->getCapacity() <= count) {
                    booking temp;
                    temp.v = &venueinfo[i];
                    temp.status = true;
                    temp.date = 20;
                    examschedule.push_back(temp);
                    ConflictSolver();
                }
            }
        }
        else {
            booking temp;
            temp.v = &venueinfo[i];
            temp.status = true;
            temp.date = 20;
            examschedule.push_back(temp);
        }
    }
}

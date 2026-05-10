#include <iostream>
#include "Assessments.h"
#include "Management.h"
#include "Courses.h"
#include "Venues.h"
#include "Academic_Entities.h"
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

void section_course::setCourse(Course& obj) {
    courseID = obj.getID();
    courseName = obj.getName();
    courseTeacherID = obj.get_teacherid();
    courseExamDuration = obj.getExamDuration();
    courseType = obj.getType();   // works on concrete Core/Elective/Lab
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

section_course::CourseProxy section_course::getCourse() const {
    CourseProxy p;
    p.id = courseID;
    p.name = courseName;
    p.teacherID = courseTeacherID;
    p.examDuration = courseExamDuration;
    p.type = courseType;
    return p;
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

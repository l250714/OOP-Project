#include <iostream>
#include "allheaders.h"
#include "Venues.h"
#include "Management.h"
using namespace std;


section_course::section_course(){
    course.set_ID("none");
    course.set_teacherID("none");
    course.setname("none");

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

    sectionid="none";
    timings="none";
}
void section_course::setCourse(Course& obj){
    course.set_ID(obj.getID());
    course.set_teacherID(obj.get_teacherid());
    course.setExamduration(obj.getExamDuration());
    course.setname(obj.getName());
}
void section_course::setTeacher(Teacher& obj){
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
void section_course::setVenue(Venue& obj){
    venue.setCapacity(obj.getCapacity());
    venue.setComputer(obj.getComputers());
    venue.setID(obj.getID());
}
void section_course::setsectionID(string id){
    sectionid=id;
}
void section_course::setTimings(string timings){
    this->timings=timings;
}

Course& section_course::getCourse(){
    return course;
}
Teacher& section_course::getTeacher(){
    return teacher;
}
Venue& section_course::getVenue(){
    return venue;
}
string section_course::getSectionID(){
    return sectionid;
}
string section_course::getTimings(){
    return timings;
}
section_course::~section_course(){}
/* void DataBaseManager(){

}

void Scheduler(){
    
}

void ConflictSolver(){


}

void TeacherFeedbacks(){

}

void SmartRegistration(){

} */

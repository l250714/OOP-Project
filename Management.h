#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include "allheaders.h"
#include "Venues.h"
using namespace std;


class section_course{       //to connect each teacher with a course + section
    Course course;
    Teacher teacher;
    Venue venue;
    string sectionid, timings;
public: 
    section_course();
    void setCourse(Course& obj);
    void setTeacher(Teacher& obj);
    void setVenue(Venue& obj);
    void setsectionID(string id);
    void setTimings(string timings);

    Course& getCourse();
    Teacher& getTeacher();
    Venue& getVenue();
    string getSectionID();
    string getTimings();
};

void Scheduler();
void ConflictSolver();
void TeacherFeedbacks();
void SmartRegistration();


#endif

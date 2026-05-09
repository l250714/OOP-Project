#pragma once
#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include "Academic_Entities.h"
#include "Assessments.h"
#include "Venues.h"
using namespace std;

class section_course {   
    string courseID;
    string courseName;
    string courseTeacherID;
    float  courseExamDuration;
    string courseType;  // Core | Elective | Lab
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

    string getCourseID() const;
    string getCourseName() const;
    string getCourseTeacherID() const;
    float  getCourseExamDuration() const;
    string getCourseType() const;


    //used AI for the concept of a proxy class:
    // Keep getCourse() so existing call sites (readSectionsdata, Linking) still compile.
    // It returns a struct-of-strings wrapper; callers that need the real Course*
    // should look it up in courseinfo by getCourseID().
    // To avoid breaking your existing code we provide a small inner proxy class:
    struct CourseProxy {
        string id, name, teacherID, type;
        float  examDuration;
        string getID()           const { return id; }
        string getName()         const { return name; }
        string get_teacherid()   const { return teacherID; }
        float  getExamDuration() const { return examDuration; }
        string getType()         const { return type; }
    };
    CourseProxy getCourse() const;

    Teacher& getTeacher();
    Venue& getVenue();
    string   getSectionID() const;
    string   getTimings()   const;
    ~section_course();
};


void Scheduler();
void ConflictSolver();
void TeacherFeedbacks();
void SmartRegistration();


#endif

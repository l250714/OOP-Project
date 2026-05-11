#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include "Academic_Entities.h"
#include "Courses.h"
#include "Management.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

extern vector <Student*> studentinfo;
extern vector <Teacher> teacherinfo;
extern vector <section_course> sectioninfo;
extern vector <Course*> courseinfo;
extern vector <Venue> venueinfo;
extern vector <Assessments*> assesssmentinfo;
struct W{
    float exam;
    float assignment;
    float quiz;
};
extern W weightstore[3];   //0: core; 1: elective; 2: lab


void readStudentdata();

void readSectionsdata();

float readTeacherFeedback(string t_id);

void readTeachersdata();

void readVenuesdata();

void readWeightagesdata();

void readAssessmentsdata();

void readCoursesdata();

void Linking();

#endif

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include "allheaders.h"
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
struct W{
    float exam;
    float assignment;
    float quiz;
};
extern W weightstore[3];   //0: core; 1: elective; 2: lab


void readStudentdata();

void readSectionsdata();

void readTeachersdata();

void readVenuesdata();

void readWeightagesdata();

void readAssessmentsdata();

void readCoursesdata();

void Linking();
#endif

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

void readStudentdata();

void readSectionsdata();

void readTeachersdata();

void readVenuesdata();

void readWeightagesdata();

void readAssessmentsdata();

void readCoursesdata();
#endif
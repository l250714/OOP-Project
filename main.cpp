#include <iostream>
#include "allheaders.h"
using namespace std;

/* cd "C:\Users\hp\OneDrive\Desktop\Uni study\Sem 2\OOP\Project" g++ -g Academic_Entities.cpp Assessments.cpp Courses.cpp DatabaseManager.cpp Management.cpp Venues.cpp main.cpp -o Project.exe
./Project.exe */

int main(){
    readStudentdata();
    cout<<"\nStudent data read";
    readCoursesdata();
    cout<<"\nCourses data read";
    readTeachersdata();
    cout<<"\nTeachers data read";
    readVenuesdata();
    cout<<"\nVenues data read";
    readSectionsdata();
    cout<<"\nSections data read";
    readWeightagesdata();
    cout<<"\nWeightages data read";
    readAssessmentsdata();
    cout<<"\nAssessments data read";
    return 0;
}

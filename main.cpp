#include <iostream>
#include <vector>
#include "DatabaseManager.h"
using namespace std;

void StudentProfile() {
    int choice;
    while (true) {
        cout << "\nPlease choose your action: 1. View Profile\n2. View Timetable\n3. View Courses\n4. View Marks\n5. Teacher Feedbacks\n6. View Transcript\n7. Registration\n8. Exam Schedule\n9. Close System\nYour choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            S_viewProfile();
        case 2:
            S_viewTimetable();
        case 3:
            S_viewCourses();
        case 4:
            S_viewMarks();
        case 5:
            S_feedback();
        case 6: 
            S_viewTranscript();
        case 7:
            S_registration();
        case 8:
            S_examSchedule();
        case 9:
            cout << "\nGoodbye! :)";
            return;
        }
    }
}

void TeacherProfile() {
    int choice;
    while (true) {
        cout << "\nPlease choose your action: 1. View Profile\n2. View Schedule\n3. View Classes\n4. Set Marks\n5. View Feedback Results\n6. View Class Average\n7. Close System\nYour choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            T_viewProfile();
        case 2:
            T_viewSchedule();
        case 3:
            T_viewClasses();
        case 4:
            T_setMarks();
        case 5:
            T_viewFeedback();
        case 6:
            T_viewAverage();
        case 7:
            cout << "\nGoodbye! :)";
            return;
        }
    }
}

int main(){
    /*readStudentdata();
    cout<<endl<<"Student data read"; 
    cout << endl << studentinfo[0]->getName();
    readCoursesdata();
    cout<<endl<<"Courses data read"; 
    cout << endl << courseinfo[0]->getName();
    readTeachersdata();
    cout<<endl<<"Teachers data read"; 
    cout << endl << teacherinfo[0].getID();
    readVenuesdata();
    cout<<endl<<"Venues data read"; 
    cout << endl << venueinfo[0].getID();
    readSectionsdata();
    cout<<endl<<"Sections data read";
    cout << endl << sectioninfo[0].getTimings();
    readWeightagesdata();
    cout<<endl<<"Weightages data read"; 
    cout << endl << weightstore[0].exam;
    readAssessmentsdata();
    cout<<endl<<"Assessments data read";
    cout << endl << assesssmentinfo[0]->getRawscore();*/


    return 0;
}

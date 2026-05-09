#include <iostream>
#include <vector>
#include "DatabaseManager.h"
using namespace std;


void S_viewProfile(Student* ptr) {                                                                  
    cout << endl;
    cout << "_____ _             _            _     _____            __ _ _" << endl;
    cout << "/ ____| |           | |          | |   |  __ \\          / _(_) |" << endl;
    cout << "| (___ | |_ _   _  __| | ___ _ __ | |_  | |__) | __ ___ | |_ _| | ___" << endl;
    cout << "\\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| |  ___/ '__/ _ \\|  _| | |/ _ \\"<< endl;
    cout << "____) | |_| |_| | (_| |  __/ | | | |_  | |   | | | (_) | | | | |  __/" << endl;
    cout << "|_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| |_|   |_|  \\___/|_| |_|_|\\___|" << endl;
    //Name, ID, Semester,Section, Email, gpa, number of courses
    ptr->displayProfile();
}
void S_viewTimetable(Student* ptr) {
    for (int i = 0;i < sectioninfo.size();i++) {
        cout << sectioninfo[i].getCourseName()<<endl;
    }
    cout << "\nTimeTable";
    for (int i = 0;i < sectioninfo.size();i++) {
        if (sectioninfo[i].getSectionID() == ptr->getSection()) {
            cout << endl<<sectioninfo[i].getCourseName() << "\t\t" << sectioninfo[i].getTimings() << "\t\tVenue: " << sectioninfo[i].getVenue().getID();
        }
    }
    
}
void StudentProfile(Student* ptr) {
    int choice;
    while (true) {
        cout << endl;
        cout << "888b     d888          d8b               888b     d888" << endl;
        cout << "8888b   d8888          Y8P               8888b   d8888" << endl;
        cout << "88888b.d88888                            88888b.d88888" << endl;
        cout << "888Y88888P888  8888b.  888 88888b.       888Y88888P888  .d88b.  88888b.  888  888" << endl;
        cout << "888 Y888P 888     \"88b 888 888 \"88b      888 Y888P 888 d8P  Y8b 888 \"88b 888  888" << endl;
        cout << "888  Y8P  888 .d888888 888 888  888      888  Y8P  888 88888888 888  888 888  888" << endl;
        cout << "888   \"   888 888  888 888 888  888      888   \"   888 Y8b.     888  888 Y88b 888" << endl;
        cout << "888       888 \"Y888888 888 888  888      888       888  \"Y8888  888  888  \"Y88888" << endl;
                                                                                                    
        cout << "\nPlease choose your action: 1. View Profile\n2. View Timetable\n3. View Courses\n4. View Marks\n5. Teacher Feedbacks\n6. View Transcript\n7. Registration\n8. Exam Schedule\n9. Close System\nYour choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            S_viewProfile(ptr);
       case 2:
            S_viewTimetable(ptr);
        /* case 3:
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
            S_examSchedule();*/
        case 9:
            cout << "\nGoodbye! :)";
            return;
        }
    }
}

void TeacherProfile(Teacher& obj) {
    int choice;
    while (true) {
        cout << "\nPlease choose your action: 1. View Profile\n2. View Schedule\n3. View Classes\n4. Set Marks\n5. View Feedback Results\n6. View Class Average\n7. Close System\nYour choice: ";
        cin >> choice;
        /*switch (choice) {
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
        }*/
    }
}

int main(){
    readStudentdata();
    readSectionsdata();
    readCoursesdata();
    readTeachersdata();
    readVenuesdata();
    readWeightagesdata();
    readAssessmentsdata();
    Linking();

    string ID;
    int index;
    while (true) {
        cout << endl;
        cout << "_    ____ ____ _ _  _" << endl;
        cout << "|    |  | | __ | |\\ |" << endl;
        cout << "|___ |__| |__] | | \\|" << endl;
        cout << "\nUsername: ";
        cin >> ID;      //input validation
        bool found = false;
        if (ID[0] == 'S') {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getID() == ID) {
                    found = true;
                    index = i;
                    break;
                }
            }
            if (found) {
                StudentProfile(studentinfo[index]);
                break;
            }
            else {
                cout << "\nError: ID does not exist. Please Try Again.";
            }
        }
        else {
            for (int i = 0;i < teacherinfo.size();i++) {
                if (teacherinfo[i].getID() == ID) {
                    found = true;
                    index = i;
                    break;
                }
            }
            if (found) {
                TeacherProfile(teacherinfo[index]);
                break;
            }
            else {
                cout << "\nError: ID does not exist. Please Try Again.";
            }
        }
    }
   
    

    return 0;
}

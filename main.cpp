#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DatabaseManager.h"
#include "Management.h"
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
    cout << "\nTimeTable";
    for (int i = 0;i < sectioninfo.size();i++) {
        if (sectioninfo[i].getSectionID() == ptr->getSection()) {
            cout << endl<<sectioninfo[i].getCourseName() << "\t\t" << sectioninfo[i].getTimings() << "\t\tVenue: " << sectioninfo[i].getVenue().getID();
        }
    }
    
}
void S_viewCourses(Student* ptr) {
    cout << "Course Code\t\t\t\tName\t\t\tType\t\t\tCredit Hours"<<endl;
    for (int i = 0;i < sectioninfo.size();i++) {
        if (sectioninfo[i].getSectionID() == ptr->getSection()) {
            for (int j = 0;j < courseinfo.size();j++) {
                if (sectioninfo[i].getCourseID() == courseinfo[j]->getID()) {
                    cout <<j+1<<". " << courseinfo[j]->getID() << "\t\t\t" << courseinfo[j]->getName() << "\t\t\t" << courseinfo[j]->getType() << "\t\t" << courseinfo[j]->getCredits();
                }
            }
        }
    }
}
void S_viewMarks(Student* ptr) {
    cout << "You are registered for the following courses:" ;
    string choice;
    S_viewCourses(ptr);
    cout << endl << "Please enter a course code: ";
    cin >> choice;
    //find out if the course is core, elective or lab
    string type;
    for (int i = 0;i < courseinfo.size();i++) {
        if (courseinfo[i]->getType() == "Core") {
            type = "Core";
        }
        else if (courseinfo[i]->getType() == "Elective") {
            type = "Elective";
        }
        else {
            type = "Lab";
        }
    }
    //now we need to find the course in Student and its respective marks
    if (type == "Core") {
        if (ptr->getNumCore() > 0) {
            for (int i = 0;i < ptr->getNumCore();i++) {
                if (ptr->getCore(i).getID() == choice) {
                    if (ptr->getCore(i).getTQuizzes() > 0) {
                        cout << "Quizzes: \n";
                        for (int j = 0;j < ptr->getCore(i).getTQuizzes();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getCore(i).getQuiz(j).getRawscore() << "/" << ptr->getCore(i).getQuiz(j).getTMarks() << "\tMinimum: " << ptr->getCore(i).getQuiz(j).getMax() << "\tMaximum: " << ptr->getCore(i).getQuiz(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Quiz marks uploaded yet.";
                    }
                    if (ptr->getCore(i).getTExams() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getCore(i).getTExams();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getCore(i).getExam(j).getRawscore() << "/" << ptr->getCore(i).getExam(j).getTMarks() << "\tMinimum: " << ptr->getCore(i).getExam(j).getMax() << "\tMaximum: " << ptr->getCore(i).getExam(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Exam marks uploaded yet.";
                    }
                    if (ptr->getCore(i).getTAssignments() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getCore(i).getTAssignments();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getCore(i).getAssignment(j).getRawscore() << "/" << ptr->getCore(i).getAssignment(j).getTMarks() << "\tMinimum: " << ptr->getCore(i).getAssignment(j).getMax() << "\tMaximum: " << ptr->getCore(i).getAssignment(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Exam marks uploaded yet.";
                    }
                    
                }
            }
        }
    }
    else if (type == "Elective") {
        if (ptr->getNumElective() > 0) {
            for (int i = 0;i < ptr->getNumElective();i++) {
                if (ptr->getElective(i).getID() == choice) {
                    if (ptr->getElective(i).getTQuizzes() > 0) {
                        cout << "Quizzes: \n";
                        for (int j = 0;j < ptr->getElective(i).getTQuizzes();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getElective(i).getQuiz(j).getRawscore() << "/" << ptr->getElective(i).getQuiz(j).getTMarks() << "\tMinimum: " << ptr->getElective(i).getQuiz(j).getMax() << "\tMaximum: " << ptr->getElective(i).getQuiz(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Quiz marks uploaded yet.";
                    }
                    if (ptr->getElective(i).getTAssignments() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getElective(i).getTAssignments();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getElective(i).getAssignment(j).getRawscore() << "/" << ptr->getElective(i).getAssignment(j).getTMarks() << "\tMinimum: " << ptr->getElective(i).getAssignment(j).getMax() << "\tMaximum: " << ptr->getElective(i).getAssignment(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Exam marks uploaded yet.";
                    }

                }
            }
        }
    }
    else {
        if (ptr->getNumLab() > 0) {
            for (int i = 0;i < ptr->getNumLab();i++) {
                if (ptr->getLab(i).getID() == choice) {
                    if (ptr->getLab(i).getTQuizzes() > 0) {
                        cout << "Quizzes: \n";
                        for (int j = 0;j < ptr->getLab(i).getTQuizzes();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getLab(i).getQuiz(j).getRawscore() << "/" << ptr->getLab(i).getQuiz(j).getTMarks() << "\tMinimum: " << ptr->getLab(i).getQuiz(j).getMax() << "\tMaximum: " << ptr->getLab(i).getQuiz(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Quiz marks uploaded yet.";
                    }
                    if (ptr->getLab(i).getTAssignments() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getLab(i).getTAssignments();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getLab(i).getAssignment(j).getRawscore() << "/" << ptr->getElective(i).getAssignment(j).getTMarks() << "\tMinimum: " << ptr->getElective(i).getAssignment(j).getMax() << "\tMaximum: " << ptr->getElective(i).getAssignment(j).getMin();
                        }
                    }
                    else {
                        cout << "\nNo Exam marks uploaded yet.";
                    }

                }
            }
        }
    }
}

//feedback would work once all the data is linked
void CoreFeedback(Student* ptr) {
    ofstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt");
    int numq = 0;
    float score;
    int Tscore = 0;
    for (int i = 0;i < ptr->getNumCore();i++) {
        cout << "Course: " << ptr->getCore(i).getName();
        cout << "\nHow would you rate the teaching style on a scale of 0-5?";   //doing 2 questions for now
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }
        }
        cout << "\nHow well did you understand the course contents on a scale of 0-5?";
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }

        }
        string line = "";
        line += (ptr->getCore(i).get_teacherid() + "|" + to_string(Tscore / numq));
        //feedback << line;
    }

    feedback.close();
}
void ElectiveFeedback(Student* ptr) {
    ofstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt");
    int numq = 0;
    float score;
    int Tscore = 0;
    for (int i = 0;i < ptr->getNumElective();i++) {
        cout << "Course: " << ptr->getElective(i).getName();
        cout << "\nHow would you rate the teaching style on a scale of 0-5?";   //doing 2 questions for now
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }
        }
        cout << "\nHow well did you understand the course contents on a scale of 0-5?";
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }

        }
        string line = "";
        line += (ptr->getElective(i).get_teacherid() + "|" + to_string(Tscore / numq));
        feedback << line;
    }

    feedback.close();
}
void LabFeedback(Student* ptr) {
    ofstream feedback("C:\\Users\\hp\\source\\repos\\Projectver2\\Projectver2\\StudentFeedback.txt");
    int numq = 0;
    float score;
    int Tscore = 0;
    for (int i = 0;i < ptr->getNumLab();i++) {
        cout << "Course: " << ptr->getLab(i).getName();
        cout << "\nHow would you rate the teaching style on a scale of 0-5?";   //doing 2 questions for now
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }
        }
        cout << "\nHow well did you understand the course contents on a scale of 0-5?";
        while (true) {
            cin >> score;
            if (score > 0 && score < 6) {
                numq++;
                Tscore += score;
                break;
            }
            else {
                cout << "\nError: Out of range 0-5. Try Again: ";
            }

        }
        string line = "";
        line += (ptr->getLab(i).get_teacherid() + "|" + to_string(Tscore / numq));
        feedback << line;
    }

    feedback.close();
}
void S_feedback(Student* ptr) {
    //must send feedback to all teachers in one go
    CoreFeedback(ptr);
    ElectiveFeedback(ptr);
    LabFeedback(ptr);
}
void S_registration(Student* ptr) {     //assuming registration only happens at the beginning of the semester & all sections have the same courses
    if (ptr->getNumCore() == 0 && ptr->getNumElective() == 0 && ptr->getNumLab() == 0) {    //no registered courses atm
        cout << "\nCode " << "\tName\tcredits\tType";
        string choice;
        for (int i = 0;i < courseinfo.size();i++) {
            if (ptr->getSemester() == courseinfo[i]->getSemester()) {
                cout <<endl<< courseinfo[i]->getID() << " " << courseinfo[i]->getName() << " " << courseinfo[i]->getCredits()<<" "<<courseinfo[i]->getType();
                cout << "\nWould you like to register for this? (Yes/No) ";
                cin >> choice;
                if (choice == "Yes") {
                    if (courseinfo[i]->getType() == "Core") {
                        ptr->setCore(dynamic_cast<Core*>(courseinfo[i]));
                    }
                    else if (courseinfo[i]->getType() == "Elective") {
                        ptr->setElective(dynamic_cast<Elective*>(courseinfo[i]));
                    }
                    else {
                        ptr->setLab(dynamic_cast<Lab*>(courseinfo[i]));
                    }
                }
                else {
                    continue;
                }
            }
        }
    }
}
//exam schedule needs help
void S_examSchedule(Student* ptr) {
    Scheduler(ptr->getSection());
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
        case 3:
            S_viewCourses(ptr);
        case 4:
            S_viewMarks(ptr);
        case 5:
            S_feedback(ptr);
        case 6: 
           ptr->viewTranscript();
        case 7:
            S_registration(ptr);
        case 8:
            S_examSchedule(ptr);
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
    readCoursesdata();
    readTeachersdata();
    readVenuesdata();
    readSectionsdata();
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

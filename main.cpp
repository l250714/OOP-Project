#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "DatabaseManager.h"
#include "Management.h"
using namespace std;


template <typename T>
int getValid(const string& prompt, T lo, T hi) { //we can use float or integer
    int val;
    while (true) {
        cout << prompt;
        cin >> val;
        if (!cin.fail() && (val >= lo && val <= hi)) {
            return val;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between " << lo << " and " << hi << ".\n";
    }
}
string getValidString(const string& prompt) {
    string val;
    while (true) {
        cout << prompt;
        if (cin >> val && !val.empty()) {
            return val;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a non-empty value.\n";
    }
}

void S_viewProfile(Student* ptr) {                                                                  
    cout << "\nSTUDENT PROFILE";
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
    cout << "Course Code\t\Name\t\Type\tCredit Hours"<<endl;
    for (int i = 0;i < sectioninfo.size();i++) {
        if (sectioninfo[i].getSectionID() == ptr->getSection()) {
            for (int j = 0;j < courseinfo.size();j++) {
                if (sectioninfo[i].getCourseID() == courseinfo[j]->getID()) {
                    cout <<j+1<<". " << courseinfo[j]->getID() << "\t" << courseinfo[j]->getName() << " " << courseinfo[j]->getType() << "\t" << courseinfo[j]->getCredits();
                }
            }
        }
    }
}
void S_viewMarks(Student* ptr) {
    cout << "You are registered for the following courses:" ;
    string choice;
    S_viewCourses(ptr);
    choice=getValidString("Please enter a course code: ");
    //find out if the course is core, elective or lab
    string type;
    for (int i = 0;i < courseinfo.size();i++) {
        if (courseinfo[i]->getID() == choice) {
            type = courseinfo[i]->getType();
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
                            cout << endl << j + 1 << ".\t" << ptr->getCore(i).getQuiz(j).getRawscore() << "/" << ptr->getCore(i).getQuiz(j).getTMarks() << "\tMinimum: " << ptr->getCore(i).getQuiz(j).getMin() << "\tMaximum: " << ptr->getCore(i).getQuiz(j).getMax();
                        }
                    }
                    else {
                        cout << "\nNo Quiz marks uploaded yet.";
                    }
                    if (ptr->getCore(i).getTExams() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getCore(i).getTExams();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getCore(i).getExam(j).getRawscore() << "/" << ptr->getCore(i).getExam(j).getTMarks() << "\tMinimum: " << ptr->getCore(i).getExam(j).getMin() << "\tMaximum: " << ptr->getCore(i).getExam(j).getMax();
                        }
                    }
                    else {
                        cout << "\nNo Exam marks uploaded yet.";
                    }
                    if (ptr->getCore(i).getTAssignments() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getCore(i).getTAssignments();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getCore(i).getAssignment(j).getRawscore() << "/" << ptr->getCore(i).getAssignment(j).getTMarks() << "\tMinimum: " << ptr->getCore(i).getAssignment(j).getMin() << "\tMaximum: " << ptr->getCore(i).getAssignment(j).getMax();
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
                            cout << endl << j + 1 << ".\t" << ptr->getElective(i).getQuiz(j).getRawscore() << "/" << ptr->getElective(i).getQuiz(j).getTMarks() << "\tMinimum: " << ptr->getElective(i).getQuiz(j).getMin() << "\tMaximum: " << ptr->getElective(i).getQuiz(j).getMax();
                        }
                    }
                    else {
                        cout << "\nNo Quiz marks uploaded yet.";
                    }
                    if (ptr->getElective(i).getTAssignments() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getElective(i).getTAssignments();j++) {
                            cout << endl << i + 1 << ".\t" << ptr->getElective(i).getAssignment(j).getRawscore() << "/" << ptr->getElective(i).getAssignment(j).getTMarks() << "\tMinimum: " << ptr->getElective(i).getAssignment(j).getMin() << "\tMaximum: " << ptr->getElective(i).getAssignment(j).getMax();
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
                            cout << endl << i + 1 << ".\t" << ptr->getLab(i).getQuiz(j).getRawscore() << "/" << ptr->getLab(i).getQuiz(j).getTMarks() << "\tMinimum: " << ptr->getLab(i).getQuiz(j).getMin() << "\tMaximum: " << ptr->getLab(i).getQuiz(j).getMax();
                        }
                    }
                    else {
                        cout << "\nNo Quiz marks uploaded yet.";
                    }
                    if (ptr->getLab(i).getTAssignments() > 0) {
                        cout << "Exams: \n";
                        for (int j = 0;j < ptr->getLab(i).getTAssignments();j++) {
                            cout << endl << j + 1 << ".\t" << ptr->getLab(i).getAssignment(j).getRawscore() << "/" << ptr->getLab(i).getAssignment(j).getTMarks() << "\tMinimum: " << ptr->getLab(i).getAssignment(j).getMin() << "\tMaximum: " << ptr->getLab(i).getAssignment(j).getMax();
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
void S_feedback(Student* ptr) {
    //must send feedback to all teachers in one go
    CoreFeedback(ptr);
    ElectiveFeedback(ptr);
    LabFeedback(ptr);
}
void S_registration(Student* ptr) {     
    availableCourses(ptr->getSemester());
    string choice;
    choice=getValidString("\nEnter the course code you wish to register in: ");
    SmartResgitartion(ptr, choice);
}
void S_examSchedule(Student* ptr) {
    cout << "\n------ My Exams ------\n";
    cout << "\n====================================================================\n";
    cout << left
        << setw(15) << "Course"
        << setw(15) << "Section"
        << setw(15) << "Venue"
        << setw(10) << "Date"
        << setw(15) << "Time" << endl;

    cout << "====================================================================\n";
    for (int i = 0; i < finalschedule.size(); i++) {

        if (finalschedule[i].sectionID ==
            ptr->getSection()) {

            cout << left
                << setw(15) << finalschedule[i].courseID
                << setw(15) << finalschedule[i].sectionID
                << setw(15) << finalschedule[i].venueID
                << setw(10) << finalschedule[i].date
                << setw(15) << finalschedule[i].time
                << endl;
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
        choice=getValid("\nPlease choose your action: \n1. View Profile\n2. View Timetable\n3. View Courses\n4. View Marks\n5. Teacher Feedbacks\n6. View Transcript\n7. Registration\n8. Exam Schedule\n9. Close System\nYour choice: ", 1, 9);
        switch (choice) {
        case 1:
            S_viewProfile(ptr);
            break;
        case 2:
            S_viewTimetable(ptr);
            break;
        case 3:
            S_viewCourses(ptr);
            break;
        case 4:
            S_viewMarks(ptr);
            break;
        case 5:
            S_feedback(ptr);
            break;
        case 6: 
           ptr->viewTranscript();   //not working :(
           break;
        case 7:
            S_registration(ptr);
            break;
        case 8:
            S_examSchedule(ptr);
            break;
        case 9:
            closing();
            cout << "\nGoodbye! :)";
            return;
        }
    }
}


void T_viewFeedback(Teacher& obj) {
    cout << "\nYour Average Feedback for this Semester is: " << obj.getavgFeedback() << "/5.0";
}


void T_viewClasses(Teacher& obj) {      //core and electives have the same credit hours????
    //here we can give the option to add scores etc
    cout << endl << "-----Core Courses-----";
    for (int i = 0;i < obj.getNumCore();i++) {
        cout << endl<<i + 1<<endl;
        cout << "\nCode: " << obj.getCore(i).getID() << "\nName: " << obj.getCore(i).getName() << "\nCedit hours: " << obj.getCore(i).getCredits()<<"\nSection(s): ";
        //we can get the section by searching through sectionsinfo
        for (int j = 0;j < sectioninfo.size();j++) {
            if (obj.getID() == sectioninfo[j].getCourseTeacherID()) {
                cout << sectioninfo[j].getSectionID() << "\t";
            }
        }
    }
    cout << endl << "-----Elective Courses-----";
    for (int i = 0;i < obj.getNumElective();i++) {
        cout << i + 1 << endl;
        cout << "\nCode: " << obj.getElective(i).getID() << "\nName: " << obj.getElective(i).getName() << "\nCedit hours: " << obj.getElective(i).getCredits() << "\nSection(s): ";
        //we can get the section by searching through sectionsinfo
        for (int j = 0;j < sectioninfo.size();j++) {
            if (obj.getID() == sectioninfo[j].getCourseTeacherID()) {
                cout << sectioninfo[j].getSectionID() << "\t";
            }
        }
    }
    cout << endl << "-----Lab Courses-----";
    for (int i = 0;i < obj.getNumLab();i++) {
        cout << i + 1 << endl;
        cout << "\nCode: " << obj.getLab(i).getID() << "\nName: " << obj.getLab(i).getName() << "\nCedit hours: " << obj.getLab(i).getCredits() << "\nSection(s): ";
        //we can get the section by searching through sectionsinfo
        for (int j = 0;j < sectioninfo.size();j++) {
            if (obj.getID() == sectioninfo[j].getCourseTeacherID()) {
                cout << sectioninfo[j].getSectionID() << "\t";
            }
        }
    }
}
void T_setMarks(Teacher& obj) {
    T_viewClasses(obj);
    string c_id, sec, type;
    c_id=getValidString("\nEnter the Course ID: ");
    //find the course and respective sections:
    cout << "\nSection: ";
    cin >> sec;
    //validate
    int option;
    double Tmarks, min,max, marks;
    option=getValid("\n1. Add Quiz\n2. Add Exam\n3. Add Asignment\nEnter the choice: ", 1, 3);
    //find out the type of course
    for (int i = 0;i < courseinfo.size();i++) {
        if (courseinfo[i]->getID() == c_id) {
            type = courseinfo[i]->getType();
        }
    }
    Tmarks = getValid("\nTotal Marks: ", 1, 150);
    max = getValid("\nMaximum Marks: ", 0.0, Tmarks);
    min = getValid("\nMinimum Marks: ", 0.0, Tmarks);
    switch (option) {
    case 1:
        if (type == "Core") {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumCore() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumCore(); j++) {
                        if (studentinfo[i]->getCore(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Quiz obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getCore(j).setQuiz(&obj);

                        }
                    }
                }

            }
        }
        else if (type == "Elective") {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumElective() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumElective(); j++) {
                        if (studentinfo[i]->getElective(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Quiz obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getElective(j).setQuiz(&obj);

                        }
                    }
                }

            }
        }
        else {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumLab() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumLab(); j++) {
                        if (studentinfo[i]->getLab(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Quiz obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getLab(j).setQuiz(&obj);

                        }
                    }
                }

            }
        }
        break;
    case 2:
        if (type == "Core") {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumCore() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumCore(); j++) {
                        if (studentinfo[i]->getCore(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Exam obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getCore(j).setExam(&obj);

                        }
                    }
                }

            }
        }
        else if (type == "Elective") {
            cout << "\nNo exams for elective courses.";
        }
        else {
            cout << "\nNo exams for Labs.";
        }
        break;
    case 3:
        if (type == "Core") {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumCore() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumCore(); j++) {
                        if (studentinfo[i]->getCore(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Assignment obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getCore(j).setAssignment(&obj);

                        }
                    }
                }

            }
        }
        else if (type == "Elective") {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumElective() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumElective(); j++) {
                        if (studentinfo[i]->getElective(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Assignment obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getElective(j).setAssignment(&obj);

                        }
                    }
                }
            }
        }
        else {
            for (int i = 0;i < studentinfo.size();i++) {
                if (studentinfo[i]->getNumLab() != 0) {
                    for (int j = 0; j < studentinfo[i]->getNumLab(); j++) {
                        if (studentinfo[i]->getLab(j).getID() == c_id && studentinfo[i]->getSection() == sec) {
                            Assignment obj;
                            cout << "\nStudent ID: " << studentinfo[i]->getID();
                            obj.setTMarks(Tmarks);
                            obj.setCourseID(c_id);
                            obj.setMax(max);
                            obj.setMin(min);
                            marks = getValid("\nObtained Marks: ", min, max);
                            /*cout << "\nObtained Marks: ";
                            cin >> marks;*/
                            obj.setRawscore(marks);
                            obj.setsectionid(studentinfo[i]->getSection());
                            obj.setStudentID(studentinfo[i]->getID());
                            //obj.setWeight(); we dont need this
                            studentinfo[i]->getLab(j).setAssignment(&obj);

                        }
                    }
                }
            }
            break;
        }


    }
}

void T_viewSchedule(Teacher&obj) {
    for (int i = 0;i < sectioninfo.size();i++) {
        if (obj.getID() == sectioninfo[i].getCourseTeacherID()) {
            cout << "\nCourse Code: " << sectioninfo[i].getCourseID() << "\tVenue: " << sectioninfo[i].getVenue().getID() << "\tTimings: " << sectioninfo[i].getTimings();
        }
    }
}
void TeacherProfile(Teacher& obj) {
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
        choice=getValid("\nPlease choose your action: \n1. View Profile\n2. View Schedule\n3. View Classes\n4. Set Marks\n5. View Feedback Results\n6. View Class Average\n7. Close System\nYour choice: ", 1, 7);
        switch (choice) {
        case 1:
            cout << "\nTEACHER PROFILE";
            obj.displayProfile();
            break;
        case 2:
            T_viewSchedule(obj);
            break;
        case 3:
            T_viewClasses(obj);
            break;
        case 4:
            T_setMarks(obj);
            break;
        case 5:
            T_viewFeedback(obj);
            break;
        case 6:
            closing();
            cout << "\nGoodbye! :)";
            return;
        }
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
    readExamSchedule();
    readResultsdata();
    Linking();
    if (finalschedule.size() != 0) {
        Scheduler();
    }

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

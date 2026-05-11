#include <iostream>
#include <string.h>
#include <vector>
#include "Academic_Entities.h"
#include "Assessments.h"
#include "Courses.h"
#include "Management.h"
#include "Venues.h"
using namespace std;
//think about schedule and timings and venue

#include <iostream>
#include <string.h>
#include <vector>
#include "Academic_Entities.h"
#include "Assessments.h"
#include "Courses.h"
#include "Management.h"
#include "Venues.h"
using namespace std;
//think about schedule and timings and venue

Course::Course() {
    ID = "none";
    name = "none";
    teacherID = "none";
    TQuizzes = 0;
    TExams = 0;
    TAssignments = 0;
    exam_duration = 0;        //has to be decided
}
void Course::set_ID(string id) {
    //course ID must be alphanumeric and not longer than 7
    int idlen = id.length();
    /*if (idlen > 7) {
        cout << "\nError: Course Code is Invalid. Please Try Again.";
        return;
    }
    for (int i = 0;id[i] != '\0';i++) {
        if (iswalnum(id[i])) {
            continue;
        }
        else {
            cout << "\nError: Course Code must only contain alphanumeric characters.";
            return;
        }
    }*/
    ID = id;
}
void Course::set_teacherID(string id) {
    //course ID must be alphanumeric and not longer than 7
    int idlen = id.length();
    /*if (idlen > 4) {
        cout << "\nError: Course Code is Invalid. Please Try Again.";
        return;
    }
    for (int i = 0;id[i] != '\0';i++) {
        if (iswalnum(id[i])) {
            continue;
        }
        else {
            cout << "\nError: Teacher ID must only contain alphanumeric characters.";
            return;
        }
    }*/
    //teacherID = new char[idlen + 1];
    teacherID = id;
}
void Course::setname(string name) {
    int namelen = name.length();
    /*if (!isalpha(name[0])) {
        cout << "\nName of the course must begin with an alphabet or a number.";
        return;
    }
    else {
        this->name = new char[namelen + 1];
        for (int i = 0;i < namelen;i++) {
            if (iswalnum(name[i])) {
                this->name[i] = name[i];
            }
            else {
                cout << "\nError: Course Name must only contain alphanumeric characters.";
                return;
            }

        }
        this->name[namelen] = '\0';
    }*/
    this->name = name;
}
void Course::setExamduration(float time) {
    //min time: 1hr & max time: 3hr
    if (time > 3 || time < 1) {
        cout << "\nError: Exam duration must be between 1-3 hours;";
        return;
    }
    else {
        exam_duration = time;
    }
}
void Course::setSemester(int i) {
    semester = i;
}
void Course::setStudent(Student& obj) {
    Student* s;
    if (obj.getType() == "Regular") {
        s = new Regular_Student;
        s->setEmail(obj.getEmail());
        s->setID(obj.getID());
        s->setName(obj.getName());
        s->setNumCore(obj.getNumCore());
        s->setNumElective(obj.getNumElective());
        s->setNumLab(obj.getNumLab());
        s->setSemester(obj.getSemester());
        s->setSection(obj.getSection());
    }
    else if (obj.getType() == "Exchange") {
        s = new Exchange_Student(obj.getID(), obj.getName(), obj.getEmail(), obj.getSemester(),obj.getSection());
        s->setNumCore(obj.getNumCore());
        s->setNumElective(obj.getNumElective());
        s->setNumLab(obj.getNumLab());
        s->setSemester(obj.getSemester());
    }
    else //if (obj.getType() == "Scholarship") 
    {
        s = new Scholarship_Student(obj.getID(), obj.getName(), obj.getEmail(), obj.getSemester(), obj.GPAcalculation(), obj.getSection());
        s->setNumCore(obj.getNumCore());
        s->setNumElective(obj.getNumElective());
        s->setNumLab(obj.getNumLab());
        s->setSemester(obj.getSemester());
    }
    students.push_back(s);
}
Student& Course::getStudent(int i) {
    return *students[i];
}
//vector <Student*> Course::getallStudents() {
//    return students;
//}
string Course::getID() {
    return ID;
}
string Course::getName() {
    return name;
}
float Course::getExamDuration() {
    return exam_duration;
}
string Course::get_teacherid() {
    return teacherID;
}
int Course::getSemester() {
    return semester;
}
Course::~Course() {
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

//----Types of Courses-----


Core::Core() {
    credithr = 3;
    points = 0;
}
void Core::setpoints(float points) {
    this->points = points;
}
void Core::setgrade(string grade) {
    if (grade.length() > 2) {
        cout << "\nGrade is too long in length.";
        return;
    }
    else {
        this->grade = grade;
    }
}
float Core::getpoints() {
    return points;
}
string Core::getgrade() {
    return grade;
}
Core::~Core() {
}
string Core::getType() {
    return "Core";
}
int Core::getCredits() {
    return credithr;
}
int Core::getTQuizzes() {
    return TQuizzes;
}
int Core::getTExams() {
    return TExams;
}
int Core::getTAssignments() {
    return TAssignments;
}
Quiz& Core::getQuiz(int i) {
    return quizzes[i];
}
Assignment& Core::getAssignment(int i) {
    return  assignments[i];
}
Exam& Core::getExam(int i) {
    return exams[i];
}


Elective::Elective() {
    credithr = 2;
    points = 0;
}
void Elective::setpoints(float points) {
    this->points = points;
}
void Elective::setgrade(string grade) {
    if (grade.length() > 2) {
        cout << "\nGrade is too long in length.";
        return;
    }
    else {
        this->grade = grade;
    }
}
float Elective::getpoints() {
    return points;
}
string Elective::getgrade() {
    return grade;
}
Elective::~Elective() {
}
string Elective::getType() {
    return "Elective";
}
int Elective::getCredits() {
    return credithr;
}
int Elective::getTQuizzes() {
    return TQuizzes;
}
int Elective::getTExams() {
    return TExams;
}
int Elective::getTAssignments() {
    return TAssignments;
}
Quiz& Elective::getQuiz(int i) {
    return quizzes[i];
}
Assignment& Elective::getAssignment(int i) {
    return  assignments[i];
}


Lab::Lab() {
    credithr = 1;
    points = 0;
}
void Lab::setpoints(float points) {
    this->points = points;
}
void Lab::setgrade(string grade) {
    if (grade.length() > 2) {
        cout << "\nGrade is too long in length.";
        return;
    }
    else {
        this->grade = grade;
    }
}
float Lab::getpoints() {
    return points;
}
string Lab::getgrade() {
    return grade;
}
Lab::~Lab() {
}
string Lab::getType() {
    return "Lab";
}
int Lab::getCredits() {
    return credithr;
}
int Lab::getTQuizzes() {
    return TQuizzes;
}
int Lab::getTExams() {
    return TExams;
}
int Lab::getTAssignments() {
    return TAssignments;
}
Quiz& Lab::getQuiz(int i) {
    return quizzes[i];
}
Assignment& Lab::getAssignment(int i) {
    return  Lab_tasks[i];
}


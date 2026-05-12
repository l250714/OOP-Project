#include <iostream>
#include <cctype>
#include <iomanip>
#include "Academic_Entities.h"
#include "Courses.h"
#include "DatabaseManager.h"
using namespace std;


//Academic Entity class

float getPointsCore(Course* ptr, Student* s) {
    float q=0, e=0, a=0;
    float tq = 0, te = 0, ta = 0;
    for (int j = 0;j < s->getNumCore();j++) {
        if (s->getCore(j).getID() == ptr->getID()) {
            for (int i = 0;i < ptr->getTQuizzes();i++) {
                q += s->getCore(j).getQuiz(i).getRawscore();
                tq+= s->getCore(j).getQuiz(i).getTMarks();
            }
            for (int i = 0;i < ptr->getTExams();i++) {
                e += s->getCore(j).getExam(i).getRawscore();
                te += s->getCore(j).getExam(i).getTMarks();
            }
            for (int i = 0;i < ptr->getTAssignments();i++) {
                a += s->getCore(i).getAssignment(i).getRawscore();
                ta += s->getCore(i).getAssignment(i).getTMarks();
            }
            break;
        }
        
    }
    //total all marks for quizzes
    
    q = (q / tq) * weightstore[0].quiz;
    e = (e / te) * weightstore[0].exam;
    a = (a / ta) * weightstore[0].assignment;
    return ((q + e + a) / 100) * 4.0;
}
float getPointsElec(Course* ptr, Student* s) {
    float q = 0, a = 0;
    float tq = 0, ta = 0;
    for (int j = 0;j < s->getNumElective();j++) {
        if (s->getElective(j).getID() == ptr->getID()) {
            for (int i = 0;i < ptr->getTQuizzes();i++) {
                q += s->getElective(j).getQuiz(i).getRawscore();
                tq += s->getElective(j).getQuiz(i).getTMarks();
            }
            for (int i = 0;i < ptr->getTAssignments();i++) {
                a += s->getElective(i).getAssignment(i).getRawscore();
                ta += s->getElective(i).getAssignment(i).getTMarks();
            }
            break;
        }

    }
    //total all marks for quizzes

    q = (q / tq) * weightstore[0].quiz;
    a = (a / ta) * weightstore[0].assignment;
    return ((q + a) / 100) * 4.0;
}
float getPointsLab(Course* ptr, Student *s) {
    float q = 0, a = 0;
    float tq = 0, ta = 0;
    for (int j = 0;j < s->getNumLab();j++) {
        if (s->getLab(j).getID() == ptr->getID()) {
            for (int i = 0;i < ptr->getTQuizzes();i++) {
                q += s->getLab(j).getQuiz(i).getRawscore();
                tq += s->getLab(j).getQuiz(i).getTMarks();
            }
            for (int i = 0;i < ptr->getTAssignments();i++) {
                a += s->getLab(i).getAssignment(i).getRawscore();
                ta += s->getLab(i).getAssignment(i).getTMarks();
            }
            break;
        }

    }
    //total all marks for quizzes

    q = (q / tq) * weightstore[0].quiz;
    a = (a / ta) * weightstore[0].assignment;
    return ((q + a) / 100) * 4.0;
}


AcademicEntity:: AcademicEntity(){
    name="none";
    email="none";
    ID="xxx";
    num_core=0;
    num_elective=0;
    num_lab=0;
}
string AcademicEntity:: getName(){
    return name;
}
string AcademicEntity:: getEmail(){
    return email;
}
string AcademicEntity:: getID(){
    return ID;
}
int AcademicEntity::getNumCore(){
    return num_core;
}
int AcademicEntity::getNumElective(){
    return num_elective;
}
int AcademicEntity::getNumLab(){
    return num_lab;
}
Core& AcademicEntity::getCore(int i){
    return core[i];
}
Elective& AcademicEntity::getElective(int i){
    return elective[i];
}
Lab& AcademicEntity::getLab(int i){
    return labs[i];
}
    
void AcademicEntity:: setName(string name){
    this->name=name;
}
void AcademicEntity:: setEmail(string email){
    this->email=email;
}
void AcademicEntity:: setID(string ID){
    this->ID=ID;
}
void AcademicEntity:: setNumCore(int num){
    num_core = num;
}
void AcademicEntity:: setNumElective(int num){
    num_elective = num;
}
void AcademicEntity:: setNumLab(int num){
    num_lab = num;
}
void AcademicEntity::setCore(Core* ptr) {
    Core c;
    c.set_ID(ptr->getID());
    c.setname(ptr->getName());
    c.set_teacherID(ptr->get_teacherid());
    num_core++;
    core.push_back(c);
}
void AcademicEntity::setElective(Elective* ptr) {
    Elective e;
    e.set_ID(ptr->getID());
    e.setname(ptr->getName());
    e.set_teacherID(ptr->get_teacherid());
    num_elective++;
    elective.push_back(e);
}
void AcademicEntity::setLab(Lab* ptr) {
    Lab l;
    l.set_ID(ptr->getID());
    l.setname(ptr->getName());
    l.set_teacherID(ptr->get_teacherid());
    num_lab++;
    labs.push_back(l);
}
AcademicEntity::~AcademicEntity(){
}



//Student class
Student::Student(){
    setID("0000");
    setName("xyz");
    setEmail("xyz@nowehere.com");
    semester=0;
    section = "xyz";

}
int Student::getSemester(){
    return semester;
}
void Student::setSemester(int sem){
    semester=sem;
}
string Student::getSection() {
    return section;
}
void Student::setSection(string section) {
    this->section = section;
}
Student::~Student(){}

//Regular Student class
Regular_Student::Regular_Student(){
    setID("0000");
    setName("xyz");
    setEmail("xyz@nowehere.com");
    setSemester(0);
    gpa = 0.0;
    setSection("xyz");
}
Regular_Student::Regular_Student(string id,string name, string email, int semester,float gpa, string section){
    setID(id);
    setName(name);
    setEmail(email);
    setSemester(semester);
    this->gpa=gpa;
    this->setSection(section);
}
void Regular_Student::displayProfile(){ //printing
    //Name, ID, Semester,Section, Email, gpa, number of courses
    cout << "========================================\n";

    cout << left << setw(30) << "Student Name:"
        << getName() << endl;

    cout << left << setw(30) << "Student ID:"
        << getID() << endl;

    cout << left << setw(30) << "Semester:"
        << getSemester() << endl;

    cout << left << setw(30) << "Section:"
        << getSection() << endl;

    cout << left << setw(30) << "Email:"
        << getEmail() << endl;

    cout << left << setw(30) << "GPA:"
        << fixed << setprecision(2)
        << GPAcalculation() << endl;

    cout << left << setw(30) << "Registered Courses:"
        << getNumCore() + getNumElective() + getNumLab() << endl;

    cout << "========================================\n";
}
void Regular_Student::viewTranscript() {
    bool available = true;

    if (getNumCore() != 0) {

        if (getCore(0).getTExams() == 0)
            available = false;
    }

    if (getNumElective() != 0) {

        if (getElective(0).getTAssignments() == 0)
            available = false;
    }

    if (getNumLab() != 0) {

        if (getLab(0).getTAssignments() != 0)
            available = false;
    }

    if (!available) {

        cout << "\nOption not available.";
        return;
    }
    
    float points;
    cout << "\n====================================================\n";
    cout << left
        << setw(30) << "Course"
        << setw(15) << "Points"
        << setw(10) << "Grade" << endl;

    cout << "====================================================\n";
    for (int i = 0;i < num_core;i++) {  //Core
        points = getPointsCore(&getCore(i),this);
        cout << left
            << setw(30) << getCore(i).getName()
            << setw(15) << fixed << setprecision(2) << to_string(points);
        getCore(i).setpoints(points);
        if (points > 3.2 && points < 4.1) {
            cout << "\tA";
        }
        else if (points > 2.3 && points < 3.2) {
            cout << "\tB";
        }
        else if (points > 1.3 && points < 2.3) {
            cout << "\tC";
        }
        else {
            cout << "\tF";
        }
    }
    for (int i = 0;i < num_elective;i++) {  //electives
        points = getPointsElec(&getElective(i),this);
        cout << endl << getElective(i).getName() << "\t" << points;
        if (points > 3.2 && points < 4.1) {
            cout << "\tA";
        }
        else if (points > 2.3 && points < 3.2) {
            cout << "\tB";
        }
        else if (points > 1.3 && points < 2.3) {
            cout << "\tC";
        }
        else {
            cout << "\tF";
        }
        getElective(i).setpoints(points);
    }
    for (int i = 0;i < num_lab;i++) {  //labs
        points = getPointsLab(&getLab(i),this);
        cout << endl << getLab(i).getName() << "\t" << points;
        if (points > 3.2 && points < 4.1) {
            cout << "\tA";
        }
        else if (points > 2.3 && points < 3.2) {
            cout << "\tB";
        }
        else if (points > 1.3 && points < 2.3) {
            cout << "\tC";
        }
        else {
            cout << "\tF";
        }
        getLab(i).setpoints(points);
    }
}

float Regular_Student::GPAcalculation() {
    bool flag;
    if (gpa != 0 && getType() != "Exchange") {  //no need to recalculate gpa
        return gpa;
    }
    int thours=1, achieved=0;
    thours=(getNumCore()*3)+(getNumElective()*2)+(getNumLab()); 
    if (thours == 0) {
        return 0;
    }
    else {
        for(int i=0;i<getNumCore();i++){
            achieved+=(getCore(i).getpoints())*3;
        }
        for(int i=0;i<getNumElective();i++){
            achieved+=(getElective(i).getpoints())*2;
        }
        for(int i=0;i<getNumLab();i++){
            achieved+=(getLab(i).getpoints());
        }
        gpa=achieved/thours;
        return gpa;
    }
    
}
string Regular_Student::getType(){
    return "Regular";
}
void Regular_Student::setgpa(float gpa){
    this->gpa=gpa;
}
Regular_Student::~Regular_Student(){}

//Scholarship Student class
Scholarship_Student::Scholarship_Student(){
    status_flag="probation";
    setID("0000");
    setName("xyz");
    setEmail("xyz@nowehere.com");
    setSemester(0);
}
Scholarship_Student::Scholarship_Student(string id, string name, string email, int semester, float gpa,string section){
    setID(id);
    setEmail(email);
    setName(name);
    setSemester(semester);
    setgpa(gpa);
    this->setSection(section);
}
void  Scholarship_Student::displayProfile(){//printing
    //Name, ID, Semester,Section, Email, gpa,status, number of courses
    cout << "========================================\n";

    cout << left << setw(30) << "Student Name:"
        << getName() << endl;

    cout << left << setw(30) << "Student ID:"
        << getID() << endl;

    cout << left << setw(30) << "Semester:"
        << getSemester() << endl;

    cout << left << setw(30) << "Section:"
        << getSection() << endl;

    cout << left << setw(30) << "Email:"
        << getEmail() << endl;

    cout << left << setw(30) << "GPA:"
        << fixed << setprecision(2)
        << GPAcalculation() << endl;

    cout << left << setw(30) << "Status:"
        << fixed << setprecision(2)
        << getStatus() << endl;

    cout << left << setw(30) << "Registered Courses:"
        << getNumCore() + getNumElective() + getNumLab() << endl;

    cout << "========================================\n";
}
float  Scholarship_Student::GPAcalculation(){
    float g=Regular_Student::GPAcalculation();
    if (g < 2.0) {
        status_flag = "probation";
    }
    return g;
}
string  Scholarship_Student::getStatus(){
    return status_flag;
}
void Scholarship_Student::setStatus(string status){
    string lowstat="";
    for(int i=0;status[i]!='\0';i++){
        lowstat+=tolower(status[i]);
    }
    if(lowstat=="settled" || lowstat=="probation"){
        status_flag=lowstat;
        status_flag[0]=toupper(status_flag[0]);
    }
    else{
        cout<<"\nError: Invalid status.";
        return;
    }
    
}
string Scholarship_Student::getType(){
    return "Scholarship";
}
void Scholarship_Student::viewTranscript() {
    bool available = true;

    if (getNumCore() != 0) {

        if (getCore(0).getTExams() == 0)
            available = false;
    }

    if (getNumElective() != 0) {

        if (getElective(0).getTAssignments() == 0)
            available = false;
    }

    if (getNumLab() != 0) {

        if (getLab(0).getTAssignments() != 0)
            available = false;
    }

    if (!available) {

        cout << "\nOption not available.";
        return;
    }
    float points;
    cout << "\n====================================================\n";
    cout << left
        << setw(30) << "Course"
        << setw(15) << "Points"
        << setw(10) << "Grade" << endl;

    cout << "====================================================\n";
    for (int i = 0;i < num_core;i++) {  //Core
        points = getPointsCore(&getCore(i),this);
        cout << endl << getCore(i).getName() << "\t" << to_string(points);
        getCore(i).setpoints(points);
        if (points > 3.2 && points < 4.1) {
            cout << "\tA";
        }
        else if (points > 2.3 && points < 3.2) {
            cout << "\tB";
        }
        else if (points > 1.3 && points < 2.3) {
            cout << "\tC";
        }
        else {
            cout << "\tF";
        }
    }
    for (int i = 0;i < num_elective;i++) {  //electives
        points = getPointsElec(&getElective(i),this);
        cout << endl << getElective(i).getName() << "\t" << points;
        if (points > 3.2 && points < 4.1) {
            cout << "\tA";
        }
        else if (points > 2.3 && points < 3.2) {
            cout << "\tB";
        }
        else if (points > 1.3 && points < 2.3) {
            cout << "\tC";
        }
        else {
            cout << "\tF";
        }
        getElective(i).setpoints(points);
    }
    for (int i = 0;i < num_lab;i++) {  //labs
        points = getPointsLab(&getLab(i),this);
        cout << endl << getLab(i).getName() << "\t" << points;
        if (points > 3.2 && points < 4.1) {
            cout << "\tA";
        }
        else if (points > 2.3 && points < 3.2) {
            cout << "\tB";
        }
        else if (points > 1.3 && points < 2.3) {
            cout << "\tC";
        }
        else {
            cout << "\tF";
        }
        getLab(i).setpoints(points);
    }
    if (GPAcalculation() > 2.0) {
        status_flag = "sustained";
    }
    else {
        status_flag = "probation";
    }
}
Scholarship_Student::~Scholarship_Student(){}

//Exchange Student Class
Exchange_Student::Exchange_Student(){
    setID("0000");
    setName("xyz");
    setEmail("xyz@nowehere.com");
    setSemester(0);
}
Exchange_Student::Exchange_Student(string id,string name, string email, int semester, string section){
    setID(id);
    setEmail(email);
    setName(name);
    setSemester(semester);
    this->setSection(section);
}
void Exchange_Student::displayProfile(){    //printing
    //Name, ID, Semester,Section, Email, gpa, number of courses
    cout << "========================================\n";

    cout << left << setw(30) << "Student Name:"
        << getName() << endl;

    cout << left << setw(30) << "Student ID:"
        << getID() << endl;

    cout << left << setw(30) << "Semester:"
        << getSemester() << endl;

    cout << left << setw(30) << "Section:"
        << getSection() << endl;

    cout << left << setw(30) << "Email:"
        << getEmail() << endl;

    cout << left << setw(30) << "GPA:"
        << fixed << setprecision(2)
        << GPAcalculation() << endl;

    cout << left << setw(30) << "Registered Courses:"
        << getNumCore() + getNumElective() + getNumLab() << endl;

    cout << "========================================\n";
}
bool Exchange_Student::grading(){ //either pass or fail
    float total = 0;
    int courses = 0;

    for (int i = 0; i < num_core; i++) {
        total += getPointsCore(&getCore(i),this);
        courses++;
    }

    for (int i = 0; i < num_elective; i++) {
        total += getPointsElec(&getElective(i),this);
        courses++;
    }

    for (int i = 0; i < num_lab; i++) {
        total += getPointsLab(&getLab(i),this);
        courses++;
    }

    if (courses == 0) {
        return false;
    }

    total /= courses;

    return (total >= 2.0);
} 
void Exchange_Student::viewTranscript() {
    bool available = true;

    if (getNumCore() != 0) {

        if (getCore(0).getTExams() == 0)
            available = false;
    }

    if (getNumElective() != 0) {

        if (getElective(0).getTAssignments() == 0)
            available = false;
    }

    if (getNumLab() != 0) {

        if (getLab(0).getTAssignments() != 0)
            available = false;
    }

    if (!available) {

        cout << "\nOption not available.";
        return;
    }
    if (!available) {

        cout << "\nOption not available.";
        return;
    }
    cout << "\n====================================================\n";
    cout << left
        << setw(30) << "Course"
        << setw(15) << "Status"<< endl;

    cout << "====================================================\n";

    for (int i = 0; i < getNumCore(); i++) {
        cout << left
            << setw(30) << getCore(i).getName();

        if (grading()) {
            cout << "Pass\n";
        }
        else {
            cout << "Fail\n";
        }
    }

    for (int i = 0; i < getNumElective(); i++) {
        cout << getElective(i).getName() << "\t";

        if (grading()) {
            cout << "Pass\n";
        }
        else {
            cout << "Fail\n";
        }
    }

    for (int i = 0; i < getNumLab(); i++) {
        cout << getLab(i).getName() << "\t";

        if (grading()) {
            cout << "Pass\n";
        }
        else {
            cout << "Fail\n";
        }
    }
}
string Exchange_Student::getType(){
    return "Exchange";
}
Exchange_Student::~Exchange_Student(){}

//Teacher Class
Teacher::Teacher(){
    setID("0000");
    setName("xyz");
    setEmail("xyz@nowehere.com");
    department="xyz";
    designation="none";
    avgFeedback=0.0;
}
void Teacher::setdepartment(string dept){
    department = dept;
}
void Teacher::setdesignation(string desig){
    designation = desig;
}
void Teacher::setavgFeedback(float feedback){
    if(feedback>5.0 || feedback< 0.0){
        cout<<"\nError: Feedback is outside range of 0-5";
        return;
    }
    else{
        avgFeedback=feedback;
    }
}
float Teacher::getavgFeedback(){
    return avgFeedback;
}
string Teacher::getDept(){
    return department;
}
string Teacher::getDesignation(){
    return designation;
}
void Teacher::displayProfile(){ //printing
    cout << "========================================\n";

    cout << left << setw(30) << "Faculty Name:"
        << getName() << endl;

    cout << left << setw(30) << "Instructor ID:"
        << getID() << endl;

    cout << left << setw(30) << "Email:"
        << getEmail() << endl;

    cout << left << setw(30) << "Number of Core Courses:"
        << fixed << setprecision(2)
        << getNumCore() << endl;
    cout << left << setw(30) << "Number of Elective Courses:"
        << fixed << setprecision(2)
        << getNumElective() << endl;
    cout << left << setw(30) << "Number of Lab Courses:"
        << fixed << setprecision(2)
        << getNumLab() << endl;

    cout << left << setw(30) << "Registered Courses:"
        << getNumCore() + getNumElective() + getNumLab() << endl;

    cout << "========================================\n";
}
Teacher::~Teacher(){}


#include <iostream>
#include <cctype>
#include "Academic_Entities.h"
#include "Courses.h"
#include "DatabaseManager.h"
using namespace std;

//Academic Entity class

float getPointsCore(Course* ptr) {
    float q=0, e=0, a=0;
    float tq = 0, te = 0, ta = 0;
    //total all marks for quizzes
    for (int i = 0;i < ptr->getTQuizzes();i++) {
        q += ptr->getStudent(i).getCore(i).getQuiz(i).getRawscore();
        tq+= ptr->getStudent(i).getCore(i).getQuiz(i).getTMarks();
    }
    for (int i = 0;i < ptr->getTExams();i++) {
        e += ptr->getStudent(i).getCore(i).getExam(i).getRawscore();
        te += ptr->getStudent(i).getCore(i).getExam(i).getTMarks();
    }
    for (int i = 0;i < ptr->getTAssignments();i++) {
        a += ptr->getStudent(i).getCore(i).getAssignment(i).getRawscore();
        ta += ptr->getStudent(i).getCore(i).getAssignment(i).getTMarks();
    }
    q = (q / tq) * weightstore[0].quiz;
    e = (e / te) * weightstore[0].exam;
    a = (a / ta) * weightstore[0].assignment;
    return ((q + e + a) / 100) * 4.0;
}
float getPointsElec(Course* ptr) {
    float q = 0,  a = 0;
    float tq = 0, ta = 0;
    //total all marks for quizzes
    for (int i = 0;i < ptr->getTQuizzes();i++) {
        q += ptr->getStudent(i).getElective(i).getQuiz(i).getRawscore();
        tq += ptr->getStudent(i).getElective(i).getQuiz(i).getTMarks();
    }
    for (int i = 0;i < ptr->getTAssignments();i++) {
        a += ptr->getStudent(i).getElective(i).getAssignment(i).getRawscore();
        ta += ptr->getStudent(i).getElective(i).getAssignment(i).getTMarks();
    }
    q = (q / tq) * weightstore[1].quiz;
    a = (a / ta) * weightstore[1].assignment;
    return ((q + a) / 100) * 4.0;
}
float getPointsLab(Course* ptr) {
    float q = 0, a = 0;
    float tq = 0, ta = 0;
    //total all marks for quizzes
    for (int i = 0;i < ptr->getTQuizzes();i++) {
        q += ptr->getStudent(i).getLab(i).getQuiz(i).getRawscore();
        tq += ptr->getStudent(i).getLab(i).getQuiz(i).getTMarks();
    }
    for (int i = 0;i < ptr->getTAssignments();i++) {
        a += ptr->getStudent(i).getLab(i).getAssignment(i).getRawscore();
        ta += ptr->getStudent(i).getLab(i).getAssignment(i).getTMarks();
    }
    q = (q / tq) * weightstore[2].quiz;
    a = (a / ta) * weightstore[2].assignment;
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
    Core* c = new Core;
    c->set_ID(ptr->getID());
    c->setname(ptr->getName());
    c->set_teacherID(ptr->get_teacherid());
    num_core++;
    core.push_back(*c);
}
void AcademicEntity::setElective(Elective* ptr) {
    Elective* e = new Elective;
    e->set_ID(ptr->getID());
    e->setname(ptr->getName());
    e->set_teacherID(ptr->get_teacherid());
    num_elective++;
    elective.push_back(*e);
}
void AcademicEntity::setLab(Lab* ptr) {
    Lab* l = new Lab;
    l->set_ID(ptr->getID());
    l->setname(ptr->getName());
    l->set_teacherID(ptr->get_teacherid());
    num_lab++;
    labs.push_back(*l);
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

/* void Student::addCourse(char* course){
    num_courses++;
    char** temp=courses;
    courses= new char*[num_courses];
    int x;
    for(int i=0;i<num_courses-1;i++){
        for(int j=0;temp[i][j]!='\0';j++){
            courses[i][j]=temp[i][j];
            x=j+1;
        }
        courses[i][x]='\0';
    }
    for(int i=0;course[i]!='\0';i++){
        courses[num_courses][i]=temp[i][j];
        x=i+1;
    }
    courses[num_courses][x]='\0';
} */
//void Student::updateCourse(char )    
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
    cout << endl << "Student Name: " << this->getName() << endl << "Student ID: " << this->getID() << endl << "Semester: " << this->getSemester()
        << endl << "Section: " << this->getSection() << endl << "Email: " << this->getEmail() << endl << "GPA: " << this->GPAcalculation() << endl
        << "Number of Registered Courses: " << this->getNumCore() + this->getNumElective() + this->getNumLab();
}
void Regular_Student::viewTranscript() {
    if (getCore(0).getTExams() == 0) {
        cout << "\nOption not available.";
    }
    float points;
    cout << "Name\tPoints\tGrade";
    for (int i = 0;i < num_core;i++) {  //Core
        points = getPointsCore(&getCore(i));
        cout << endl << getCore(i).getName() << "\t" << points;
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
        points = getPointsElec(&getElective(i));
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
        points = getPointsLab(&getLab(i));
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

float Regular_Student::GPAcalculation(){
    int thours=1, achieved=0;
    //thours=(getNumCore()*3)+(getNumElective()*2)+(getNumLab()); //uncomment after linking all data
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
    cout << endl << "Student Name: " << this->getName() << endl << "Student ID: " << this->getID() << endl << "Semester: " << this->getSemester()
        << endl << "Section: " << this->getSection() << endl << "Email: " << this->getEmail() << endl << "GPA: " << this->GPAcalculation() << endl << "Status: " << this->getStatus()
        << "Number of Registered Courses: " << this->getNumCore() + this->getNumElective() + this->getNumLab();
}
float  Scholarship_Student::GPAcalculation(){
    return Regular_Student::GPAcalculation();
}
string  Scholarship_Student::getStatus(){
    return status_flag;
}
void Scholarship_Student::setStatus(string status){
    string lowstat="";
    for(int i=0;status[i]!='\0';i++){
        lowstat+=tolower(status[i]);
    }
    if(lowstat=="settled" || lowstat=="probabtion"){
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
    if (getCore(0).getTExams() == 0) {
        cout << "\nOption not available.";
    }
    float points;
    cout << "Name\tPoints\tGrade";
    for (int i = 0;i < num_core;i++) {  //Core
        points = getPointsCore(&getCore(i));
        cout << endl << getCore(i).getName() << "\t" << points;
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
        points = getPointsElec(&getElective(i));
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
        points = getPointsLab(&getLab(i));
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
    cout << endl << "Student Name: " << this->getName() << endl << "Student ID: " << this->getID() << endl << "Semester: " << this->getSemester()
        << endl << "Section: " << this->getSection() << endl << "Email: " << this->getEmail()  << endl
        << "Number of Registered Courses: " << this->getNumCore() + this->getNumElective() + this->getNumLab();
}
bool Exchange_Student::grading(){ //either pass or fail
    int thours=0, achieved=0;
    thours=(getNumCore()*3)+(getNumElective()*2)+(getNumLab());
    for(int i=0;i<getNumCore();i++){
        achieved+=(getCore(i).getpoints())*3;
    }
    for(int i=0;i<getNumElective();i++){
        achieved+=(getElective(i).getpoints())*2;
    }
    for(int i=0;i<getNumLab();i++){
        achieved+=(getLab(i).getpoints());
    }
    if(achieved/thours>2.00){
        return true;    //pass
    }
    else{
        return false;   //fail
    }
    
} 
void Exchange_Student::viewTranscript() {
    if (getCore(0).getTExams() == 0) {
        cout << "\nOption not available.";
    }
    float points;
    cout << "Name\tPoints\tGrade";
    for (int i = 0;i < num_core;i++) {  //Core
        points = getPointsCore(&getCore(i));
        cout << endl << getCore(i).getName() << "\t" << points;
        getCore(i).setpoints(points);
    }
    for (int i = 0;i < num_elective;i++) {  //electives
        points = getPointsElec(&getElective(i));
        cout << endl << getElective(i).getName() << "\t" << points;
        getElective(i).setpoints(points);
    }
    for (int i = 0;i < num_lab;i++) {  //labs
        points = getPointsLab(&getLab(i));
        cout << endl << getLab(i).getName() << "\t" << points;
        getLab(i).setpoints(points);
    }
    if (grading()) {
        cout << "\nResult: Pass";
    }
    else {
        cout << "\nResult: Fail";
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

}
Teacher::~Teacher(){}


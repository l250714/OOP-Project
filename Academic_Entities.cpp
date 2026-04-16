#include <iostream>
#include "Courses.cpp"
#include "Assessments.cpp"
using namespace std;

class AcademicEntity{
    string name,email,ID;
    Course *courses;
public:
    virtual void displayProfile()=0;
};

class Student: public AcademicEntity{      
    int num_courses;
    char*courses;
    int semester;
public:
    void calculateGPA(){}
    void viewTranscript(){}

};
class Regular_Student: public Student{
    float gpa;
    float cgpa;
public:
    void displayProfile();
};

class Scholarship_Student: public Regular_Student{
    string status_flag;
public:
    void displayProfile();
};

class Exchange_Student: public Student{
public:
    void displayProfile();
};


class Teacher: public AcademicEntity{
    char* assigned_courses;
    int num_courses;
};

int main(){

    return 0;
}

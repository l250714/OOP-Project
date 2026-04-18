#include <iostream>
#include "Courses.cpp"
#include "Assessments.cpp"
using namespace std;

class AcademicEntity{
    string name,email,ID;
    int num_courses;
    Course *courses;
public:
    virtual void displayProfile()=0;
    string getName(){
        return name;
    }
    string getEmail(){
        return email;
    }
    string getID(){
        return ID;
    }
    int getNumCourses(){
        return num_courses;
    }

    void setName(string name){
        this->name=name;
    }
    void setEmail(string email){
        this->email=email;
    }
    void setID(string ID){
        this->ID=ID;
    }
    void setNumCourses(int num){
        num_courses=num;
    }
};

class Student: public AcademicEntity{      
    //char**courses;
    int semester;
public:
    void calculateGPA(){}
    void viewTranscript(){}
    char* getcourses(){
        return courses;
    }
    int getSemester(){
        return semester;
    }


    /* void addCourse(char* course){
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
    //void updateCourse(char )    
    void setSemester(int sem){
        semester=sem;
    }

};
class Regular_Student: public Student{
    float gpa;  //CGPA
    float sgpa;

public:
    void displayProfile();
    float GPAcalculation(){

    }

    float getGPA(){
        return gpa;
    }
    float getSGPA(){
        return sgpa;
    }
};

class Scholarship_Student: public Regular_Student{
    string status_flag;
public:
    void displayProfile();
    float GPA();

    string getStatus(){
        return status_flag;
    }
    void setStatus(string status){
        if(tolower(status)=="settled" || tolower(status)=="probabtion"){
            status_flag=tolower(status);
            status_flag[0]=toupper(status_flag[0]);
        }
        else{
            cout<<"\nError: Invalid status.";
            return;
        }
        
    }
};

class Exchange_Student: public Student{
public:
    void displayProfile();
};


class Teacher: public AcademicEntity{
    string department;
    char*designation;
public:
    void setdepartment(string dept){
        dept=department;
    }
    void setdesignation(char* desig){
        for(int i=0;desig[i]!='\0';i++){
            designation[i]=desig[i];
        }
        designation[strlen(desig)+1]='\0';
    }

    string getDept(){
        return department;
    }
    string getDesignation(){
        string temp="";
        for(int i=0;designation[i]!='\0';i++){
            temp+=designation[i];
        }
        return temp;
    }
};

int main(){

    return 0;
}

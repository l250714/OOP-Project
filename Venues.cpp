#include <iostream>
#include <string.h>
#include "Venues.h"
using namespace std;


void Venue::setID(char* ID){
    if(strlen(ID)!=5){
        cout<<"\nError: Venue ID must be 5 character long.";
        return;
    }
    else if(!isalpha(ID[0])){
        cout<<"\nError: Venue ID must begin with a letter.";
        return;
    }
    else if(ID[1]!='-'){
        cout<<"\nError: Venue ID must have a '-' after the first alphabet.";
        return;
    }
    else if(!isdigit(ID[2]) || !isdigit(ID[3]) || !isdigit(ID[4])){
        cout<<"\nError: Venue ID must have 3 digits at the end.";
        return;
    }
    else{
        this->ID=new char[strlen(ID)+1];
        for(int i=0;ID[i]!='\0';i++){
            this->ID[i]=ID[i];
        }
        this->ID[strlen(ID)]='\0';
    }
}
void Venue::setCapacity(int cap){
    if(cap>0 && cap<300){
        capacity=cap;
    }
    else{
        cout<<"\nError: Venue capacity is invalid.";
    }
}
void Venue::setComputer(bool comp){
    has_computers=comp;
}

string Venue::getID(){
    string temp="";
    for(int i=0;ID[i]!='\0';i++){
        temp+=ID[i];
    }
    return temp;
}
int Venue::getCapacity(){
    return capacity;
}
bool Venue::getComputers(){
    return has_computers;
}


#include <iostream>
#include <string.h>
#include "Venues.h"
using namespace std;

Venue::Venue(){
    ID="none";
    capacity=0;
    has_computers=0;
}
void Venue::setID(string ID){
    this->ID = ID;
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
    return ID;
}
int Venue::getCapacity(){
    return capacity;
}
bool Venue::getComputers(){
    return has_computers;
}
Venue::~Venue(){}


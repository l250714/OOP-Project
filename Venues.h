#ifndef VENUES_H
#define VENUES_H

#include <iostream>
using namespace std;

class Venue{
    char* ID;
    int capacity;
    bool has_computers;
public:
    void setID(char* ID);
    void setCapacity(int cap);
    void setComputer(bool comp);
    string getID();
    int getCapacity();
    bool getComputers();
};

#endif
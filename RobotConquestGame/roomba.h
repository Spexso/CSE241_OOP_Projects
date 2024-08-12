#ifndef ROOMBA_H
#define ROOMBA_H
#include <iostream>
#include "robot.h"
using namespace std;

class roomba : public robot{
    public:
        roomba();           //Default constructor
        roomba(int, int);   //Custom constructor
        string getType();   //Returns the type of robot as class
        int getDamage();    //Returns the number of damage that roomba did
};

#endif //ROOMBA_H
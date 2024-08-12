#ifndef BULLDOZER_H
#define BULLDOZER_H
#include <iostream>
#include "robot.h"

using namespace std;

class bulldozer : public robot{
    public:
        bulldozer();            //Constructor
        bulldozer(int ,int);    //Also user could create a custom bulldozer robot with any strenght and hitpoints values
        string getType();       //Returns the type of robot as class
        int getDamage();        //Returns the number of damage that bulldozer did
};

#endif // BULLDOZER_H
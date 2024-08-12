#ifndef ROBOCOP_H
#define ROBOCOP_H
#include "humanic.h"
using namespace std;

class robocop : public humanic{
    public:
        robocop();          //Constructor
        string getType();   //Returns the type of robot as class
        int getDamage();    //Returns the number of damage that robocop did
};

#endif //ROBOCOP_H
#ifndef HUMANIC_H
#define HUMANIC_H
#include <iostream>
#include <time.h>
#include "robot.h"
using namespace std;

class humanic : public robot{
    public:
        humanic();                  //Constructor
        humanic(int, int, int);     //Also user could create a custom humanic robot with any strenght and hitpoints values
        string getType();   //Returns the type of robot as class
        int getDamage();    //Returns the number of damage that humanic robot did
};

#endif //HUMANIC_H
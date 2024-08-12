#ifndef OPT_H
#define OPT_H
#include "humanic.h"
using namespace std;

class optimusprime : public humanic{
    public:
        optimusprime();     //Constructor
        string getType();   //Returns the type of robot as class
        int getDamage();    //Returns the number of damage that optimusprime did
};

#endif // OPT_H
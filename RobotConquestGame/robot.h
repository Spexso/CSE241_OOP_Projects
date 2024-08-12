#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


class robot
{
    private:
        int strenght; // power of robot
        int hitpoints; // basically healt points of robot 
    public:
        //Stats
        int type; //defines the type of robot
        
        //Constructors 
        robot();  //Default Constructor
        robot(int, int, int); //Data provided Constructor 
        
        //Member functions
        string getType();   //Function to get type of robot
        void print_stats(); //Print the stats of object
        int getDamage();  //Returns the damage points
        
        //Accesor function
        int getHP();         //Returns the hitpoints of that robot
        
        //Mutator function
        int compAttack(int); //Function to compute attack result
};

#endif // ROBOT_H
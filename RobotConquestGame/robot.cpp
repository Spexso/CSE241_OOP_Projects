#include <iostream>
#include "robot.h"
using namespace std;

const int default_type = -1;
const int default_str = 1;
const int default_hp = 1;


robot::robot() : type{default_type}, strenght{default_str}, hitpoints{default_hp} {
     //Default robot constructor
} 

robot::robot(int newType, int newStrenght, int newHit) : type{newType}, strenght{newStrenght}, hitpoints{newHit}{
    //Custom robot contructor
}


string robot::getType(){
    //returns the type of robot
    string r_type;
        switch(type)
        {
            case 0:
                r_type = "optimusprime";
                break;
            case 1:
                r_type = "robocop";
                break;
            case 2:
                r_type = "roomba";
                break;
            case 3:
                r_type = "bulldozer";
                break;
            default:
                r_type = "unknown";
                break;
        }
        return r_type;
}

void robot::print_stats(){
    //Prints the statistics of robot
    cout << "Type of robot: " << type << endl;
    cout << "Strength of robot: " << strenght << endl;
    cout << "Hit-points of robot: " << hitpoints << endl;
}

int robot::getDamage(){
    int dmg;    //Variable to store random damage based on strenght 
    
    dmg = (rand() % strenght) + 1;  //assings a random number based on strenght which becomes damage
    
    return dmg;
}

//Function to acces hitpoints of robot
int robot::getHP(){
    return hitpoints; //returns the hitpoints since its private
}

//Function to adjust hp of robot
int robot::compAttack(int dmg_done){
    return (hitpoints -= dmg_done); //computes the dealt damage and returns the health which is hitpoints
}

 
#include "humanic.h"
using namespace std;


//Default stats for unknown humanic robot
const int hum_type = 4;
const int hum_str = 15;
const int hum_hit = 15;

humanic::humanic() : robot(hum_type, hum_str, hum_hit){
    //Default creation for unknown humanic robot
}

humanic::humanic(int h_type, int h_str, int h_hit) : robot(h_type, h_str, h_hit){
    //Custom humanic robot constructor
} 

string humanic::getType()
{
    //Implement getType function for every needed point in classes
    string name_obj;
    switch(type)
    {
        case 0:
            name_obj = "optimusprime";
            break;
        case 1:
            name_obj = "robocop";
            break;
        default:
            name_obj = "humanic";
            break;
            
    }
    return name_obj;
}

int humanic::getDamage(){
    int start_dmg;
    int chance;
    
    start_dmg = robot::getDamage();
    
    //Additional damage calculation for humanic robot
    chance = (rand() % 100);
    
    if(chance < 10)
    {
        //Tactical nuke attack happens
        start_dmg += 50;
    }
    
    cout << humanic::getType() << " attacks for " <<
    start_dmg << " points!" << endl;
    
    return start_dmg;
}
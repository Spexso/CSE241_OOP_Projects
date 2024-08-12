#include <iostream>
#include "roomba.h"
using namespace std;

const int default_type = 2;
const int default_str = 10;
const int default_hitp = 8;

roomba::roomba() : robot(default_type, default_str, default_hitp){
    //Default creation for roomba robot
}

roomba::roomba(int r_str, int r_hitp) : robot(default_type, r_str, r_hitp){
    //Custom roomba robot constructor
}

string roomba::getType(){
    return "roomba";
}

int roomba::getDamage(){
    int start_dmg;
    start_dmg = robot::getDamage();
    
    //Additional damage calculation for roomba robot
    start_dmg *= 2;
    cout << roomba::getType() << " attacks for " <<
    start_dmg << " points!" << endl;
    
    return start_dmg;
}
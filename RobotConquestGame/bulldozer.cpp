#include "bulldozer.h"
using namespace std;

//Default values for base bulldozer class
const int bull_type = 3;
const int bull_str = 10;
const int bull_hp = 10;

bulldozer::bulldozer() : robot(bull_type, bull_str, bull_hp){
    //Default creation for bulldozer robot
}

bulldozer::bulldozer(int b_str, int b_hp) : robot(bull_type, b_str, b_hp){
    //custom bulldozer constructor
}

string bulldozer::getType(){
    //returns the type of robot
    return "bulldozer";
}

int bulldozer::getDamage(){
    int start_dmg;
    
    start_dmg = robot::getDamage();
    
    //No bonus damage for bulldozer
    cout << getType() << " attacks for " <<
    start_dmg << " points!" << endl;
    
    return start_dmg;
}


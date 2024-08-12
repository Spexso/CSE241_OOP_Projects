#include "robocop.h"
using namespace std;

const int rob_type = 1;
const int rob_str = 8;
const int rob_hp = 14;

robocop::robocop() : humanic(rob_type, rob_str, rob_hp){
        //Default initiliziation for robocop humanic robot
}

string robocop::getType(){
    return "robocop";      //Returns the type of robocop
}

int robocop::getDamage(){
    return humanic::getDamage();    //Returns the amount of damage that robocop dealt
}
#include "optimusprime.h"
using namespace std;

const int opt_type = 0;
const int opt_str = 12;
const int opt_hp = 18;

optimusprime::optimusprime() : humanic(opt_type, opt_str, opt_hp){
    
}

string optimusprime::getType(){
    return "optimusprime";
}

int optimusprime::getDamage(){
    int start_dmg;
    int chance;
    
    
    start_dmg = humanic::getDamage();
    chance = (rand() % 100);
    
    if(chance < 15)
    {
        //Inflicts a strong attack 
        start_dmg *= 2;
    }
    
    //cout << optimusprime::getType() << " attacks for " <<
    //start_dmg << " points!" << endl;
    
    return start_dmg;
}
#include "gate_not.h"

gate_not::gate_not(string n, string single_in)
{
    flag = false;
    name = n;
    inp1 = single_in;
}

gate_not::~gate_not()
{
}

bool gate_not::evaluate(){
    if(flag == false)                       //If value computed before then return the same value
    {
        value = !(inp1_p->evaluate());      //else compute the root
        flag = true;
        return value;
    }
    else
    {
        return value;
    }
        
}


#include "gate_or.h"

gate_or::gate_or(string n, string in1, string in2)
{
    flag = false;
    name = n;
    inp1 = in1;
    inp2 = in2;
}

gate_or::~gate_or()
{
}

bool gate_or::evaluate(){
    if(flag == false)                                                       //If value computed before then return the same value
    {
        value = ( inp1_p->evaluate() || inp2_p->evaluate() );
        flag = true;                                                        ////else compute the root 
        return value;
    }
    else
    {
        return value; 
    }
        
}


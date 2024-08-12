#include "gate_and.h"

gate_and::gate_and(string n, string in1, string in2)
{
    //AND gate created
    flag = false;
    name = n;
    inp1 = in1;
    inp2 = in2;
}

gate_and::~gate_and()
{
}

bool gate_and::evaluate(){
    //Figures out the return value of gate
    if(flag == false)
    {
        value = ( inp1_p->evaluate() & inp2_p->evaluate() );
        flag == true;
        return value;
    }
    else
    {
        return value;
    }
        
}

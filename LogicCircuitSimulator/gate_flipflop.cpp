#include "gate_flipflop.h"

//Constructor
gate_flipflop::gate_flipflop(string n, string single_in) : prev_value{false} 
{
    flag = false;
    name = n;
    inp1 = single_in;
}

gate_flipflop::~gate_flipflop()
{
}

bool gate_flipflop::evaluate(){
    
    value = inp1_p->evaluate();                                         //Gets the output of input root
      
        if(flag == false)                                               //if flag is false on that line flipflop will work for the first time otherwise it will use the previous value
        {
            //cout << "First time ";
            if(value == false && prev_value == false)
            {
                value = false;
            }
            else if(value == false && prev_value == true)
            {
                value = true;
            }
            else if(value == true && prev_value == false)
            {
                value = true;
            }
            else if(value == true && prev_value == true)
            {
                value = false;
            }
            
                flag = true;
                prev_value = value;
        }
        else
            value = prev_value;
    
    return value;
}

string gate_flipflop::getType(){
    return "flipflop";
}


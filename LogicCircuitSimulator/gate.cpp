#include "gate.h"

//Constructor
gate::gate() : inp1{"None"}, inp2{"None"}
{
    name = "None";
}

//Destructor
gate::~gate()
{
}

string gate::getName(){
    return name;
}

void gate::adjustName(string new_name){
    name = new_name;
}

string gate::getType(){
    return "Default gate";
}

//Function to return inp1 pointer
string gate::getInput_1(){
    return inp1;
}

//Function to return inp2 pointer
string gate::getInput_2(){
    return inp2;
}

//Assigns pointers to the correct input pointer
void gate::adjustINP(int which, gate* pointed){
    if(which == 1)
    {
        inp1_p = pointed;
    }
    else if(which == 2)
    {
        inp2_p = pointed;
    }
    else
    {
        cout << "Error-->Every gate has maximum of 2 inputs" << endl;
    }
}

string gate::accessPointer_1(){
    return inp1_p->getName();
}

string gate::accessPointer_2(){
    return inp2_p->getName();
}

bool gate::check_inp_1(){
    if(inp1_p == NULL)
        return false;
    else
        return true;
    
}

bool gate::check_inp_2(){
    if(inp2_p == NULL)
        return false;
    else
        return true;
    
}

bool gate::evaluate(){
    //Do nothing
    return 0;
}

void gate::pre_evaluate(int x){
    //Do nothing
}

bool gate::assign_outputs(int x){
    //Do nothing
    return 0;
}

void gate::set_value(bool inp){
    value = inp;
}
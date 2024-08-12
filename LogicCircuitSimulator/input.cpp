#include "input.h"

input::input(string n)
{
    name = n;
}

input::~input()
{
}

string input::getType(){
    return "Input gate";
}

//Debug function
void input::print_value(){
    cout << value << endl;
}

bool input::evaluate(){
    return value;
}

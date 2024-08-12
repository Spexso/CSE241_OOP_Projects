#ifndef INPUT_H
#define INPUT_H
#include "gate.h"

using std::cout;
using std::endl;
using std::string;

class input : public gate
{
    
    public:
        input(string);                  //Constructor gets a name
        ~input();
        string getType();               //returns the type 
        
        bool evaluate();                //Since its input gate diretly returns the input values from txt
        void set_value(int);            //Sets the value of gate
        void print_value();             //Helper function
};

#endif // INPUT_H

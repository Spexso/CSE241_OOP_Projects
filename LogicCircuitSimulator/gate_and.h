#ifndef GATE_AND_H
#define GATE_AND_H
#include "gate.h"

using std::cout;
using std::endl;

class gate_and : public gate
{
    public:
        gate_and(string, string, string);       //Constructor gets a name and 2 input names
        ~gate_and();                            //Desctructor
        bool evaluate();                        //Figures out the output of gate

};

#endif // GATE_AND_H

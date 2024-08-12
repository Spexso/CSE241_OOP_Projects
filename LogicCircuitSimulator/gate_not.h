#ifndef GATE_NOT_H
#define GATE_NOT_H
#include "gate.h"

class gate_not : public gate
{
    public:
        gate_not(string, string);               //Constructor gets name and input of gate
        ~gate_not();
        bool evaluate();                        //Computes the output of not gate
};

#endif // GATE_NOT_H

#ifndef GATE_OR_H
#define GATE_OR_H
#include "gate.h"

using std::cout;
using std::endl;

class gate_or : public gate
{
    public:
        gate_or(string, string, string);                //Constructor gets 1 name and 2 inputs
        ~gate_or();
        bool evaluate();                                //Computes the gate's output
};

#endif // GATE_OR_H

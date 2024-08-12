#ifndef GATE_FLIPFLOP_H
#define GATE_FLIPFLOP_H
#include "gate.h"

class gate_flipflop : public gate
{
    private:
        bool prev_value;
    public:
        gate_flipflop(string, string);              //Constructor gets the name of flipflop gate and an input
        ~gate_flipflop();
        bool evaluate();                            //Computes the flip flop based on formet out
        string getType();                           //Returns the type of flipflop
};

#endif // GATE_FLIPFLOP_H

#ifndef GATE_DECODER_H
#define GATE_DECODER_H
#include "gate.h"

class gate_decoder : public gate
{
    protected:
        string out1;        //Name of 1. input
        string out2;        //Name of 2. input
        string out3;        //Name of 3. input
        string out4;        //Name of 4. input
        bool o1;
        bool o2;
        bool o3;
        bool o4;
    public:
        gate_decoder(string, string, string, string, string, string);           //Constructor gets 4 output names and 2 input
        ~gate_decoder();
        bool evaluate();                                                        //Assigns the output values
        bool assign_outputs(int);                                               //Returns the picked output value

};

#endif // GATE_DECODER_H

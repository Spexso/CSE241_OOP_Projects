#ifndef OUTPUT_H
#define OUTPUT_H
#include "gate.h"

using std::cout;
using std::endl;
using std::string;

class output : public gate
{
    private:
        bool out_value;                 //Value of output gate
        int pick;                       //Variable to pick output from decoder
    public:
        output(string);                 //Constructor gets a name
        ~output();

        string getType();
        void pre_evaluate(int);         //Picks the output to assigned
        bool evaluate();                //Returns the output of output get
};

#endif // OUTPUT_H

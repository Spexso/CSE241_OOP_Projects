#ifndef GATE_H
#define GATE_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class gate
{
    protected:
        string name;    //name of gate
        string inp1;    //first input's name of gate
        string inp2;    //second input's name of gate
        
        bool value;     //output value of gate
        string type;    //type of gate which means gate type
        gate* inp1_p;   //first input pointer of gate
        gate* inp2_p;   //second input pointer of gate
    
    public:
        gate();         //Constructor
        ~gate();        //Destructor
        
        string getName();                      //Function to get the name of gate
        string getInput_1();                   //Function to get the name of input 1
        string getInput_2();                   //Function to get the name of input 2
        string accessPointer_1();              //Function to get the pointer of input 1
        string accessPointer_2();              //Function to get the pointer of input 2
        
        bool flag;                             //Variable to track if gate has visited and processed before
        
        void set_value(bool);                  //Function to set the value of that gate
        bool check_inp_1();                    //Function to return the value of pointer 1
        bool check_inp_2();                    //Function to return the value of pointer 2
        void adjustINP(int, gate*);            //Function to assign pointers
        void adjustName(string);               //Function to assign names
        
        virtual bool evaluate();               //Pure virtual Function to get result of gate
        virtual void pre_evaluate(int);        //Pure virtual function to decide identical output 
        virtual string getType();              //Pure virtual function to get the type of gate
        virtual bool assign_outputs(int);      //Pure virtual function assign outputs of decoder to correct output gates
};

#endif // GATE_H

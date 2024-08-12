#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>

#include "gate.h"
#include "input.h"
#include "output.h"
#include "gate_and.h"
#include "gate_or.h"
#include "gate_not.h"
#include "gate_flipflop.h"
#include "gate_decoder.h"


using std::cout;
using std::endl;
using std::vector;
using std::fstream;
using std::ios;
using std::strlen;
using std::stringstream;
using std::stoi;

static int num_of_outputs = 0;                                     //Tracks the number of outputs
static int num_of_inputs = 0;                                      //Tracks the number of inputs 
static bool lock_gate_creation = false;                            //Variable to detect if gate need to create or not

void fill_data_for_in_out(string, vector<gate*>&, int&);           //Function to fill datas of gates to classes
bool read_circuit(vector<gate*>&);                                 //Function to read circuit file
void parse_line(string, vector<gate*>&);                           //Function to parse read line
int return_type(string);                                           //Returns the type of gates as number representation
void link_gates(vector<gate*>&);                                   //Function to link gates and lines
bool read_inputs(vector<gate*>&);
void evaluate_sim(vector<gate*>&);
void reset_gates(vector<gate*>&);

int main()
{
    vector<gate*>modules;                                           //Array to store gate pointers
    bool check_pro;                                                 //Variable to check file's condition 
    check_pro = read_circuit(modules);                              //Read the circuit txt file
    
        if(check_pro == false)
        {
            return 0;
        }
    
    link_gates(modules);
    /*
                    for(size_t c=4; c < modules.size(); c++)
                    {
                        if(modules[c]->check_inp_1() == true)
     DEBUG PURPOSES         cout << "First input of " << modules[c]->getName() << " has linked to " << modules[c]->accessPointer_1() << endl;
                        if(modules[c]->check_inp_2() == true)
                            cout << "Second input of " << modules[c]->getName() << " has linked to " << modules[c]->accessPointer_2() << endl;
                    }
    */

    //Read input.txt file ,Assign inputs and evaluate
    check_pro = read_inputs(modules);

    return 0;
}



bool read_circuit(vector<gate*> &mod){
    string line;                                        //string variable to read line from file 
    fstream circuit_f;                                  //stream object to read file
    circuit_f.open("circuit.txt", ios::in);             //Opens the file in read mode
            
        if(!(circuit_f.is_open()))                      //Checks whether the file is open
        {
            cout << "ERROR file couldn't read" << endl;
            return false;
        }

    while(getline(circuit_f, line))                     //reads the file line by line
    {
        parse_line(line, mod);                          //Parsing line
        lock_gate_creation = false;
    }
    circuit_f.close();                                  //Closes the txt file
    return true;    
}


void parse_line(string line, vector<gate*> &mod){
    static int input_type = 0;                                  //to comprehend data || 1->Straight input 2->Straight output 3->gates 
    vector <string> data_of_line;                               //Data of circuit line 
    int sub_type = 0;                                           //Type variable to identify and ,or ,not ,flipflop or decoder
    string sign = " ";
    size_t pos = 0;
    string token;
    size_t i; //test
        
        pos = line.find(sign);
        token = line.substr(0, pos);
        line.erase(0, pos + sign.length());
        
                if(token == "INPUT")
                {
                    //cout << "INPUTS:" << endl;
                    input_type = 1;
                }
                else if(token == "OUTPUT")
                {
                    //cout << "OUTPUTS:" << endl;
                    input_type = 2;
                }
                else
                {
                    //cout << "OTHER GATES:" << endl;
                    input_type = 3;
                    sub_type = return_type(token);
                }
            
        pos = 0;
        while((pos = line.find(sign)) != string::npos) //(string::npos lenght of that string also static member constant value)
        {
            token = line.substr(0, pos);
            
            if(input_type == 1 || input_type == 2)
            {
                fill_data_for_in_out(token, mod, input_type);
            }
            else
            {
                data_of_line.push_back(token);
            }
            
            line.erase(0, pos + sign.length());
            //FIND WHERE YOU END THE LINE 
        }
    //Get the last splitted word
            
            if(input_type == 1 || input_type == 2)
            {
                fill_data_for_in_out(line, mod, input_type);
            }
            else
            {
                data_of_line.push_back(line);
            }
    
    if(input_type == 3)
    {
        if(sub_type == 1)
        {
            //AND
            mod.push_back(new gate_and(data_of_line[0], data_of_line[1], data_of_line[2]));
            sub_type = 0;
        }
        else if(sub_type == 2)
        {
            //OR
            mod.push_back(new gate_or(data_of_line[0], data_of_line[1], data_of_line[2]));
            sub_type = 0;
        }
        else if(sub_type == 3)
        {
            //NOT
            mod.push_back(new gate_not(data_of_line[0], data_of_line[1]));
            sub_type = 0;
        }
        else if(sub_type == 4)
        {
            //FLIPFLOP
            mod.push_back(new gate_flipflop(data_of_line[0], data_of_line[1]));
            sub_type = 0;
        }
        else if(sub_type == 5)
        {
            //DECODER
            mod.push_back(new gate_decoder(data_of_line[0], data_of_line[1], data_of_line[2], data_of_line[3], data_of_line[4], data_of_line[5]));
            sub_type = 0;
        }
    }
}

void fill_data_for_in_out(string single_data, vector<gate*> &mod, int &inp_t){
    
        if(inp_t == 1)
        {
            mod.push_back(new input(single_data));
            num_of_inputs++;
        }
        else if(inp_t == 2)
        {
            mod.push_back(new output(single_data));
            num_of_outputs++;
        }      
}

int return_type(string type){
    int t;
        
        if(type == "AND")
        {
            //AND
            t = 1;
        }
        else if(type == "OR")
        {
            //OR
            t = 2;
        }
        else if(type == "NOT")
        {
            //NOT
            t = 3;
        }
        else if(type == "FLIPFLOP")
        {
            //FLIPFLOP
            t = 4;
        }
        else if(type == "DECODER")
        {
            //DECODER
            t = 5;
        }
    
    return t;
}

void link_gates(vector<gate*> &mod){
    size_t num_of_gates;
    num_of_gates = mod.size();
    
        //Link lines
        for(size_t i=0; i < num_of_gates;i++)
        {
            for(size_t k=0; k < num_of_gates;k++)
            {
                if(mod[i]->getName() == mod[k]->getInput_1() && i != k)
                {
                    mod[k]->adjustINP(1, mod[i]);
                }
                if(mod[i]->getName() == mod[k]->getInput_2() && i != k)
                {
                    mod[k]->adjustINP(2, mod[i]);
                }
            }
        }
        //Find and link output gates
        for(size_t h=0; h < num_of_gates;h++)
        {
          if(mod[h]->getType() == "Output gate")
          {
            mod[h]->adjustINP(1, mod[num_of_gates-1]);
          }
        }
}

bool read_inputs(vector<gate*> &mod){
    vector<bool>inp;
    string line;
    fstream inputs;
    int line_c = 0;                                  //Line count
    int inp_c = 0;                                   //Count of inputs in line
        
        inputs.open("input.txt", ios::in);
        
        if(!(inputs.is_open()))                      //Checks whether the file is open
        {
            cout << "ERROR file couldn't read" << endl;
            return false;
        }
        
    while(getline(inputs, line))
    {
        line_c++;
            stringstream cur_line(line);
            string tok;
            
            while(getline(cur_line, tok, ' '))
            {
                inp_c++;
                inp.push_back(stoi(tok));
            }
        //Assign values
        for(int v=0; v < inp_c;v++)
        {
            mod[v]->set_value(inp[v]);
        }
        evaluate_sim(mod);
        inp.clear();
        inp_c = 0;
    }    
    return true;
}

void evaluate_sim(vector<gate*> &mod){
    int c = 0;
    for(size_t s=0; s < mod.size(); s++)
    {
        if(mod[s]->getName() == "Decoder")
        {
            mod[s]->evaluate();
        }
    }
    
    for(size_t z=num_of_inputs; z < num_of_inputs+num_of_outputs; z++)
    {
        mod[z]->pre_evaluate(c);
        c++;
    }
    cout << endl;
    reset_gates(mod);
    
}

void reset_gates(vector<gate*> &mod){
    for(size_t f=0; f < mod.size();f++)
    {
        mod[f]->flag = false;
    }
}

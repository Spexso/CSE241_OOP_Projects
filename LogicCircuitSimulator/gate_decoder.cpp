#include "gate_decoder.h"

//Constructor
gate_decoder::gate_decoder(string o1, string o2, string o3, string o4, string in1, string in2)
{
    name = "Decoder";
    inp1 = in1;
    inp2 = in2;
    out1 = o1;
    out2 = o2;
    out3 = o3;
}

gate_decoder::~gate_decoder()
{
}

bool gate_decoder::evaluate(){
    //Computes the pointers and sets the outputs to correct values
    bool in_f = inp1_p->evaluate();
    bool in_s = inp2_p->evaluate();
    
        if(in_f == false && in_s == false)
        {
            o1 = true;
            o2 = false;
            o3 = false;
            o4 = false;
        }
        else if(in_f == false && in_s == true)
        {
            o1 = false;
            o2 = true;
            o3 = false;
            o4 = false;
        }
        else if(in_f == true && in_s == false)
        {
            o1 = false;
            o2 = false;
            o3 = true;
            o4 = false;
        }
        else if(in_f == true && in_s == true)
        {
            o1 = false;
            o2 = false;
            o3 = false;
            o4 = true;
        }
    //return "Assignment has complete";
    return 0;
}

bool gate_decoder::assign_outputs(int pick){
    bool ret;                       //Return value 
        
        //Sets the outputs of decoder
        switch(pick)
        {
            case 0:
            ret = o1;
            break;
            
            case 1:
            ret = o2;
            break;
            
            case 2:
            ret = o3;
            break;
            
            case 3:
            ret = o4;
            break;
            
            default:
                //cout << "Output value couldn't assigned" << endl;
                break;
        }
    return ret;
}

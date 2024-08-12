#include "output.h"

output::output(string n)
{
    name = n;
}

output::~output()
{
}

string output::getType(){
    return "Output gate";
}

void output::pre_evaluate(int p){
    pick = p;
    evaluate();
}


bool output::evaluate(){
    out_value = inp1_p->assign_outputs(pick);
    cout << out_value;
    return 0;
}


#ifndef _SPARSEVECTOR_H_
#define _SPARSEVECTOR_H_
#include <fstream>
#include <vector>
using namespace std;

class SparseVector
{  
    
    private:
        vector <double> data;
        string name_of_file;
        friend class SparseMatrix;
    public:
    //Overloaded constructors
        SparseVector(const string name_file);
        SparseVector();
    //Methods
        void read_file(string name_of_file);
        void fill_vector(int index, double val);
        void print_vec();
        int check_errors(ifstream* f);
        friend double dot(const SparseVector &left_obj, const SparseVector &right_obj);
    //Operator Overloading
        SparseVector operator+(const SparseVector &right_data);                         //Addition
        SparseVector &operator=(const SparseVector &right_data);                        //Copy Operator
        SparseVector operator-(const SparseVector &right_data);                         //Substraction
        SparseVector operator-();                                                       //Negation
        friend ostream& operator<<(ostream& out_stream, const SparseVector& data);      //As ostream object
};

#endif

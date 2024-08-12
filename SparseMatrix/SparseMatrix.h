#ifndef _SPARSEMATRIX_H_
#define _SPARSEMATRIX_H_
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;


class SparseMatrix
{
    //Datas from file
    private:
        vector <vector<double>> obj_data;
        string name_of_file;
        int cur_size=0;
    //Methods
    public:
        //Overloaded Constructors
        SparseMatrix(const string name_file);
        SparseMatrix();
        //Methods
        void read_file(string n_file);
        string get_index_row(string s);
        void assign_data_row(string line_out_r,int row_index);
        void print_matrix();
        int check_errors(ifstream* f);
        SparseMatrix transpose();
        //Overloaded Operators
        SparseMatrix operator=(const SparseMatrix &right_matrix);
        SparseMatrix operator+(const SparseMatrix &righy_matrix);
        SparseMatrix operator-(const SparseMatrix &right_matrix);
        SparseMatrix operator-();
        friend ostream& operator<<(ostream& out_stream, const SparseMatrix &main_matrix);
        SparseMatrix operator*(const SparseMatrix &right_matrix);
};

#endif

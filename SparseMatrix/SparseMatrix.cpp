#include <vector>
#include <fstream>
#include <cstring>
#include "SparseMatrix.h"

using namespace std;


    //Overloaded Constructors
    SparseMatrix::SparseMatrix(){
        name_of_file = "None";          //Assigns a Name just for debugging
    }
    SparseMatrix::SparseMatrix(const string name_file){
        name_of_file = name_file;
        read_file(name_of_file);                    //Reads and assigns the values to class
    }
    
    //Overloaded Constructors
    SparseMatrix SparseMatrix::operator=(const SparseMatrix &right_matrix){
        obj_data = right_matrix.obj_data;       //Assigns the right class's vector to left class's vector
            return *this;                   //Returns value of class
    }
    SparseMatrix SparseMatrix::operator+(const SparseMatrix &right_matrix){
        //Stores the size of row_index and line index
        int row_size_l = (int)this->obj_data.size();
        int row_size_r = (int)right_matrix.obj_data.size();
        int colm_size_l = (int)this->obj_data[0].size();
        int colm_size_r = (int)right_matrix.obj_data[0].size();
        
        //Create a temporary class
        SparseMatrix temp;
            temp.obj_data.resize(row_size_r, vector<double>(colm_size_r));
        
       if( row_size_l != row_size_r)
       {
           //Since size of 2 matrix is not equal addition process is not possible-->Program Aborted
           exit(1);
       }
       else if( colm_size_l != colm_size_r )
       {
           //Since size of 2 matrix is not equal addition process is not possible-->Program Aborted
           exit(1);
       }
       
         //Sum progress of two matrix   
            for(int i=0;i<(int)this->obj_data.size();i++)
            {
                for(int k=0;k<(int)this->obj_data[i].size();k++)
                {
                    //Add every element of matrix
                    temp.obj_data[i].at(k) = this->obj_data[i].at(k) + right_matrix.obj_data[i].at(k);
                }
            }
                
        return temp;  //Return the temporary class
    }
    SparseMatrix SparseMatrix::operator-(const SparseMatrix &right_matrix){
        //Stores the size of row_index and line index
        int row_size_l = (int)this->obj_data.size();
        int row_size_r = (int)right_matrix.obj_data.size();
        int colm_size_l = (int)this->obj_data[0].size();
        int colm_size_r = (int)right_matrix.obj_data[0].size();
        
        //Create a temporary class
        SparseMatrix temp;
            temp.obj_data.resize(row_size_r, vector<double>(colm_size_r));
        
       if( row_size_l != row_size_r)
       {
           //Since size of 2 matrix is not equal substraction process is not possible-->Program Aborted
           exit(1);
       }
       else if( colm_size_l != colm_size_r )
       {
           //Since size of 2 matrix is not equal substraction process is not possible-->Program Aborted
           exit(1);
       }
       
         //Subs progress of two matrix   
            for(int i=0;i<(int)this->obj_data.size();i++)
            {
                for(int k=0;k<(int)this->obj_data[i].size();k++)
                {
                    //Substract every element of matrix
                    temp.obj_data[i].at(k) = this->obj_data[i].at(k) - right_matrix.obj_data[i].at(k);
                }
            }
                
        return temp;  //Return the temporary class
    }
    SparseMatrix SparseMatrix::operator-(){
        //Gets the size of matrix
        int row_size = this->obj_data.size();
        int colm_size = this->obj_data[0].size();
        
            //Create a temporary Class 
            SparseMatrix temp;
                temp.obj_data.resize(row_size, vector<double>(colm_size));
                
            for(int i=0;i<row_size;i++)
            {
                for(int k=0;k<colm_size;k++)
                {
                    temp.obj_data[i].at(k) = -(this->obj_data[i].at(k));
                }
            }
            return temp;
    }
    SparseMatrix SparseMatrix::operator*(const SparseMatrix &right_matrix){
        //Information about this section is not clear in PA2 pdf 
        //So I assumed we should program it just like vector multiplication
        int row_size_l = (int)this->obj_data.size();
        int row_size_r = (int)right_matrix.obj_data.size();
        int colm_size_l = (int)this->obj_data[0].size();
        int colm_size_r = (int)right_matrix.obj_data[0].size();
        
        //Create a temporary class
        SparseMatrix temp;
            temp.obj_data.resize(row_size_r, vector<double>(colm_size_r));
        
       if( row_size_l != row_size_r)
       {
           //Since size of 2 matrix is not equal multiplication process is not possible-->Program Aborted
           exit(1);
       }
       else if( colm_size_l != colm_size_r )
       {
           //Since size of 2 matrix is not equal multiplication process is not possible-->Program Aborted
           exit(1);
       }
       
         //Multiply progress of two matrix   
            for(int i=0;i<(int)this->obj_data.size();i++)
            {
                for(int k=0;k<(int)this->obj_data[i].size();k++)
                {
                    //Multiply every element of matrix and sum it with previous multiplications
                    temp.obj_data[i].at(k) += this->obj_data[i].at(k) * right_matrix.obj_data[i].at(k);
                }
            }
                
        return temp;  //Return the temporary class
    }
    ostream& operator<<(ostream& out_stream, const SparseMatrix& main_matrix){
        //Stores the size of row_index and line index
        int row_size = main_matrix.obj_data.size();
        int colm_size = main_matrix.obj_data[0].size();
        int cur_colm_size=0;
        //Variable to track the endline and row_index print
        bool result;
        
            for(int i=0;i<main_matrix.obj_data.size();i++)
            {
                //Tracks the point of endl and row_index
                cur_colm_size = main_matrix.obj_data[i].size();
                for(int l=0;l<cur_colm_size;l++)
                    {
                        if(main_matrix.obj_data[i][l] != 0)
                        {
                            result = true;
                        }
                    }
                    
                if(result == true)
                {
                    out_stream << i+1 << ' ';
                    result = false;
                }
                    
                for(int k=0;k<main_matrix.obj_data[i].size();k++)
                {
                    if(main_matrix.obj_data[i][k] != 0)
                        out_stream << k+1 << ":" << main_matrix.obj_data[i][k] << ' ';          //Prints the data to file
                }
                
                //Tracks the point of endl and row_index
                cur_colm_size = main_matrix.obj_data[i].size();
                for(int l=0;l<cur_colm_size;l++)
                    {
                        if(main_matrix.obj_data[i][l] != 0)
                        {
                            out_stream << endl;
                            break;
                        }
                    }
                
            }
        return out_stream;
    }
    
    //Member Functions
    void SparseMatrix::read_file(string n_file){
        string line;
        string temp;
        int row_index;
        ifstream cinfromfile(n_file);
        
        if(!cinfromfile)
        {
            //File couldn't read
            exit(1);
        }
        //Reads the file line by line
        while(getline(cinfromfile, line))
        {
            temp = get_index_row(line);
            line.erase(0,temp.size());           //Deletes the extra line after row_index
            row_index = stoi(temp);              //Turns line row_index data to int
            /*
            cout << row_index << endl;
            cout << line << "//" << endl;                   DEBUG 
            cout << temp.size() << "ER" << endl;
            */
            assign_data_row(line, row_index);
            cur_size = obj_data[0].size();      //Current size of row_index
        }
        
        cinfromfile.close();
    }
    int SparseMatrix::check_errors(ifstream* f){
        //Checks for fail of reading process
        int stop = 0;
        if(f->eof()){
            stop = 0;
        }
        if(f->fail()){
            stop = 1;
        }
        if(f->bad()){
            stop = 1;
        }
        
        return stop;
    }
    string SparseMatrix::get_index_row(string s){
        int index_r;
        int pos = s.find(" ");              //Reads the line until first space 
        string sub = s.substr(0 , pos);     //Cuts the string from space
            return sub;                     //Returns the modified string
    }
    void SparseMatrix::assign_data_row(string line_out_r, int row_index){
        int index_s;                    //index of vector
        double data_s;                  //Value of vector
        char c;                         //Variable to get ':' char
        bool flag = true;

        //Create and open the file
        ofstream tempFile("temp.txt");

        //Write to file
        tempFile << line_out_r;
        
        //Close the file
        tempFile.close();
        
        //Open and read file 
        ifstream cinfromfile("temp.txt");
        
        //Gets the data from file
        while(cinfromfile >> index_s >> c >> data_s)    
        {
            if(check_errors(&cinfromfile))
                break;
            
            if(row_index != (int)obj_data.size())
                obj_data.resize(row_index, vector<double>(0));      //Allocates size for vector
            
            if(index_s != (int)obj_data[row_index-1].size())
            {
                if(index_s < cur_size)
                {
                   obj_data[row_index-1].resize(index_s, 0);       //If index size is lower than current index size allocates space
                   obj_data[row_index-1][index_s-1] = data_s;
                   flag = false;
                }
                else
                {
                    for(int i=0;i<row_index;i++)
                    {
                        obj_data[row_index-(1+i)].resize(index_s, 0);   //Allocates size for every row_index
                    }
                    
                }
            }
                
            if(flag == true)
            {
                obj_data[row_index-1][index_s-1] = data_s;              //Assigns the data so matrix
            }
            flag = true;
        }
        
        cinfromfile.close();
        remove("temp.txt");
        
    }
    SparseMatrix SparseMatrix::transpose(){
        int row_size = obj_data.size();
        int colm_size = obj_data[0].size();
        
            //Create the transpose Matrix
                SparseMatrix transpose;
            
            //Resize the transpose Matrix
                transpose.obj_data.resize(colm_size, vector<double>(row_size));
                
            //Loop to make transpose process
            for(int i=0;i<row_size;i++)
            {
                for(int k=0; k<colm_size;k++)
                {
                    transpose.obj_data[k][i] = obj_data[i][k];
                }
            }
        return transpose;
    }
    

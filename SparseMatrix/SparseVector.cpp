#include <fstream>
#include <vector>
#include <iostream>
#include "SparseVector.h"
using namespace std;


 //Overloaded operators
    SparseVector &SparseVector::operator=(const SparseVector &right_data){
        data = right_data.data;                 //Assingment of vector
        return *this;
    }
    SparseVector SparseVector::operator+(const SparseVector &right_data){
        //Get the size of vectors
        int size_r = right_data.data.size();
        int size_l = this->data.size();
        
        //Create temp Class
        SparseVector temp;
            temp.data.resize(size_r, 0);
            
        //Checking for same size of vectors
        if(size_l != size_r)
        {
            exit(1);
        }
        else
        {
            for(int i=0;i<size_r;i++)
            {
                temp.data.at(i) = this->data.at(i) + right_data.data.at(i);         //Sum of data
            }
            
        }
        return temp;
    }
    SparseVector SparseVector::operator-(const SparseVector &right_data){
        //Get the size of vectors
        int size_r = right_data.data.size();
        int size_l = this->data.size();
        
        //Create temp Class
        SparseVector temp;
            temp.data.resize(size_r, 0);
            
        //Checking for same size of vectors
        if(size_l != size_r)
        {
            exit(1);
        }
        else
        {
            for(int i=0;i<size_r;i++)
            {
                temp.data.at(i) = this->data.at(i) - right_data.data.at(i);
            }
            
        }
        return temp;
    }
    SparseVector SparseVector::operator-(){
        
        //Get the size of vectors
        int size = this->data.size();
        
        //Create temp Class
        SparseVector temp;
            temp.data.resize(size, 0);
        
        //Assigns the negative of every vector data
        for(int i=0;i<size;i++)
        {
            temp.data.at(i) = -(this->data.at(i));
        }
            
            
        return temp;
    }
    ostream& operator<<(ostream& out_stream, const SparseVector& main_vec){
        int size = main_vec.data.size();
        for(int i=0;i<size;i++)
        {
            if(main_vec.data.at(i) != 0){
                    out_stream << i+1 << ":" << main_vec.data.at(i) << ' ';     //prints the data to text file 
            }
            
        } 
        return out_stream;
    }
    
    //Constructors
    SparseVector::SparseVector(){
        name_of_file = "None";
    }
    SparseVector::SparseVector(const string name_file){
        name_of_file = name_file;
        read_file(name_of_file);
    }    
    
    //Member Functions
    double dot(const SparseVector &left_obj,const SparseVector &right_obj){
        double sum;
        int size_r = right_obj.data.size(); 
        int size_l = left_obj.data.size();
        
            if(size_r != size_l)
            {
                exit(1);
            }
            else
            {
                for(int i=0;i<size_r;i++)
                {
                    sum += (right_obj.data.at(i) * left_obj.data.at(i));
                }
            }
        return sum;
    }
    void SparseVector::fill_vector(int index, double val){
        if(index != (int)data.size())
        {
            data.resize(index-1, 0);
        }
        data.push_back(val);
        //cout << data.size() << "-->" <<data.at(index-1) <<  endl;
    }
    void SparseVector::read_file(string n_file){
        
        int index_s;
        double data_s;
        char c;
        string line;
        
        ifstream cinfromfile(n_file);
        
        if(!cinfromfile)
        {
            exit(1);
        }
        
            while(cinfromfile>>index_s>>c>>data_s)
            {
                if(check_errors(&cinfromfile))
                    break;
                fill_vector(index_s, data_s);
            }
        
        cinfromfile.close();
        
        
    }
    int SparseVector::check_errors(ifstream* f){
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
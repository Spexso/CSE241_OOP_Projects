#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DynamicStringArray
{
    private:
        string *dynamicArray;
        int size;
    public:
        DynamicStringArray();
        DynamicStringArray(const DynamicStringArray& otherobj);
        ~DynamicStringArray();
        DynamicStringArray& operator =(const DynamicStringArray& rightSide);
        void addEntry(string);
        bool deleteEntry(string);
        string getEntry(int);
        int getSize();
};


DynamicStringArray::DynamicStringArray(){
    dynamicArray = NULL;
    size = 0;
}

//Copy Constructor
DynamicStringArray::DynamicStringArray(const DynamicStringArray& otherobj)
{
    size = otherobj.size;
    if(size == 0)
    {
        dynamicArray = NULL;
    }
    else
    {
        dynamicArray = new string[size];
        for(int i=0;i < size; i++)
        {
            dynamicArray[i] = otherobj.dynamicArray[i];
        }
    }
}

//Overloaded assignment
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& rightSide){
    if(dynamicArray != NULL)
    {
        delete[] dynamicArray;
    }
    if( rightSide.size == 0)
    {
        size = 0;
        dynamicArray = NULL;
    }
    else
    {
        size = rightSide.size;
        dynamicArray = new string[size];
        for(int i=0;i < size; i++)
        {
            dynamicArray[i] = rightSide.dynamicArray[i];
        }
    }
    return *this;
}

DynamicStringArray::~DynamicStringArray(){
    if(dynamicArray != NULL)
    {
        delete[] dynamicArray;
    }
}

int DynamicStringArray::getSize(){
    return size;
}

//adds an entry to dynamic array
void DynamicStringArray::addEntry(string newEntry){
    //create a new array, copy the contents of the old array, then
    //delete it 
    string *newArray = new string[size + 1];
    for(int i = 0; i < size; i++)
    {
        newArray[i] = dynamicArray[i];
    }
    delete[] this->dynamicArray;
    this->dynamicArray = newArray;
    //add the new entry and increment the size
    newArray[size++] = newEntry;
}

// Removes an entry from the dynamic array. If the entry is not
// found in the array, the array is unmodified
bool DynamicStringArray::deleteEntry(string entry)
{
    string *result = NULL;
    int pos = -1;
    
    // First see if the entry is in the array
    for(int i = 0; (i < size) && (pos == -1); i++)
    {
        if(dynamicArray[i] == entry)
        {
            pos = i;
        }
    }
    
    // if entry not found, exit
    if( pos == -1)
    {
        return false;
    }
    
    if(size > 1)
    {
        result = new string[size - 1];
    }
    for(int i = 0, j = 0; i < size; i++)
    {
        //skip over the deleted element
        if(i != pos)
        {
            result[j++] = dynamicArray[i];
        }
    }
    size--;
    delete[] this->dynamicArray;
    dynamicArray = result;
}

// Retrieve the string at a given index
string DynamicStringArray::getEntry(int index)
{
    if((index < 0) || (index >= size))
        return NULL;
    return dynamicArray[index];
}

int main(int argc, char **argv)
{
    DynamicStringArray names;
    
    //list of names
    names.addEntry("Frank");
    names.addEntry("Sinatra");
    names.addEntry("Harry");
    names.addEntry("Dave");
    names.addEntry("Abel");
    
    //output list
    cout << "List of names:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    //Addition and remove process of some names
    names.addEntry("Nirvana");
    cout << "After adding a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    names.deleteEntry("Nirvana");
    cout << "After removing a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    names.deleteEntry("Demon");
    cout << "After removing a name that isnt on the list:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    names.addEntry("God");
    cout << "After adding a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    //Remove all of the names by repeatedly deleting the last one
    while(names.getSize() > 0)
    {
        names.deleteEntry(names.getEntry(names.getSize() -1));
    }
    
    cout << "After removing all of the names:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    names.addEntry("Pain");
    cout << "After adding a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
        
    cout << endl;
    
    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names);
    //Remove Pain from names
    names.deleteEntry("Pain");
        cout << "Copied names:" << endl;
    for(int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;
        
    cout << endl;
    
    cout << "Testing Assignment" << endl;
    DynamicStringArray names3 = names2;
    //Remove Pain from names2
    names2.deleteEntry("Pain");
        cout << "Copied names:" << endl;
    for(int i = 0; i < names3.getSize(); i++)
        cout << names3.getEntry(i) << endl;
        
    cout << endl;
    
    cout << "Enter any character to exit." << endl;
    char wait;
    cin >> wait;
    
	return 0;
}

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student
{
	public:
	Student();
	~Student();
	void InputData();			//Input all data from user
	void OutputData();			//Output class list to console
	void ResetClasses();			//Reset class list
	Student& operator =(const Student& rightSide); // Assignment operator
	private:
		string name;
		int numClasses;
		string *classList;
		void res();
};

int main()
{
	Student s1, s2;

	
	s1.InputData();					//Input for student 1
	cout << "Student 1's data:" << endl;
	
	cout << endl;

	s2 = s1;

	cout << "Student 2's data after assignment from student 1:" << endl;
	s2.OutputData();			//Prints the same data as for student 1

	s1.ResetClasses();
	cout << "Student 1's data after reset:" << endl;
	s1.OutputData();			//Empty 


	cout << "Student 2's data, still have original classes:" << endl;
	s2.OutputData();			//Prints the original data from student 1

	cout << endl;
	return 0;
}
//Student::Student
//The Default constructor initialized variables to empty.
//The Dynamic array is initialized to NULL.

Student::Student()
{
	numClasses = 0;
	classList = NULL;
	name = "";
}

//=========================
//The destructor frees up any memory allocated to
//the dynamic array
//=========================

Student::~Student()
{
	res();
}

//=========================
//Student::ResetClasses
//This method deletes the class list
//=========================
void Student::ResetClasses()
{
	res();
	numClasses = 0;
}

void Student::res()
{
	if(classList != NULL)
	{
		delete [] classList;
		classList = NULL;
	}

}


//=========================
//Student::InputData
//This method inputs all data from the user
//It allows the user to enter an arbitrary number of classes
//using a dynamic array to store the string.
//=========================

void Student::InputData()
{
	int i;

	//Reset the class list just in case this method
	//was called again and the dynamic array wasnt cleared
	ResetClasses();

	cout << "Enter student name." << endl;
	getline(cin, name);
	cout << "Enter the number of classes." << endl;
	cin >> numClasses;
	cin.ignore(2, '\n');	//Discard extra newline
	if(numClasses > 0)
	{
		//Dynamically construct array large enough to hold
		//number of classes
		classList = new string[numClasses];
		//Loop through the number of classes, inputting
		//the name of each one into our dynamic array
		for(i = 0;i<numClasses;i++)
		{
			cout << "Enter name of class " << (i+1) << endl;
			getline(cin, classList[i]);
		}
	}
	cout << endl;
}

//=========================
//Student::OutputData
//This method outputs the data entered by the user
//=========================
void Student::OutputData()
{
	int i;

		cout << "Name: " << name << endl;
		cout << "Number of classes: " << numClasses << endl;
		for(i=0;i<numClasses;i++)
		{
			cout << " Class " << (i+1) << ":" << classList[i] << endl;
		}
		cout << endl;
}

//=========================
//Student ::=
//This method copies a new classList to 
//the target of the assignement. Without overloading this
//operator, we should end up with two references to the same
//class list if the assignment operator is used.
//=========================

Student& Student::operator =(const Student& rightSide)
{
	int i;

	if(this->classList == rightSide.classList)
	{
		return *this;
	}

	ResetClasses();  //Erase list of classes
	name = rightSide.name;
	numClasses = rightSide.numClasses;

	//Copy the list of classes
	if(numClasses > 0)
	{
		classList = new string[numClasses];
		for(i=0;i<numClasses;i++)
		{
			classList[i] = rightSide.classList[i];
		}
	}
	return *this;
}



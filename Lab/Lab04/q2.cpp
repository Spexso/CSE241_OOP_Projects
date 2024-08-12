#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;




class MyInteger
{
	public:
		MyInteger();
		MyInteger(int newint);
		void SetInt(int newint);
		int GetInt();
		int operator[](int index);

	private:
		int num;
};

// ==================
// MyInteger::MyInteger
// Default Constructor
// ==================
MyInteger::MyInteger()
{
	num = 0;
}


// ==================
// MyInteger::MyInteger
// Constructor to initialize the int value
// ==================
MyInteger::MyInteger(int newnum)
{
	num=newnum;	
}


// ================
// MyInteger::SetInt
// Method to change the value
// ================
void MyInteger::SetInt(int newnum)
{
	num=newnum;
}

// ================
// MyInteger::GetInt
// Method to get the entire value
// ================
int MyInteger::GetInt()
{
	return (num);
}


// ================
// MyInteger::[]
// Overrides [] to compute the ith digit
// ================
int MyInteger::operator[](int index)
{
	int temp;

	if(index < 0)
	{
	cout << "Illegal index value.\n";
	return -1;
	}
	else
	{
	temp = (int) (num / (pow(10,index)));
	return (temp % 10);
	}
}



int main()
{
	MyInteger num(418);


	cout << num[0] << " " << num[1] << " " << num[2] << endl;
	cout << num[3] << endl;
	cout << num[-1] << endl;


	return 0;
}
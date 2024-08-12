#include <iostream>
#include <cstdlib>
using namespace std;

class HotDogStand
{

public:
	HotDogStand();
	HotDogStand(int newID, int newNnumsold);
	int GetID();
	void setID(int newID);
	void JustSold();
	int GetNumSold();
	static int GetTotalSold();

private:
	static int totalSold;
	int numSold;
	int ID;
};

int HotDogStand::totalSold = 0;

//==========================
//HotDogStand::HotDogStand
//The default constructor initializes the ID and num sold to zero.
//==========================

HotDogStand::HotDogStand()
{
	numSold = 0;
	ID = 0;
}

//==========================
//HotDogStand::HotDogStand
//The constructor initializes the ID and num sold..
//==========================

HotDogStand::HotDogStand(int newID, int newNnumsold)
{
	numSold = newNnumsold;
	ID = newID;
}

//==========================
//HotDogStand::GetID
//Returns the ID number of this stand.
//==========================

int HotDogStand::GetID()
{
	return ID;
}

//==========================
//HotDogStand::SetID
//Sets the ID number of this stand.
//==========================

void HotDogStand::setID(int newID)
{
	ID = newID;
}

//==========================
//HotDogStand::JustSold
//Increments the number of hotdogs this stand
//has sold by one.
//==========================

void HotDogStand::JustSold()
{
	numSold++;		// increment number sold at this stand
	totalSold++;	// increment number sold across all stands
}

//==========================
//HotDogStand::GetNumtSold
//Returns the number of hotdogs this stand has sold. 
//==========================

int HotDogStand::GetNumSold()
{
	return numSold;
}

//==========================
//HotDogStand::GetTotalSold
//Returns the number of hotdogs sold by all stands 
//==========================

int HotDogStand::GetTotalSold()
{
	return totalSold;
}

int main()
{
	// Test our code with three hot dog stands 
	HotDogStand s1(1,0),s2(2,0),s3(3,0);


	// Sold at stand 1, 2
	s1.JustSold();
	s2.JustSold();
	s1.JustSold();

	cout << "Stand " << s1.GetID() << " sold " << s1.GetNumSold() << endl;
	cout << "Stand " << s2.GetID() << " sold " << s2.GetNumSold() << endl;
	cout << "Stand " << s3.GetID() << " sold " << s3.GetNumSold() << endl;
	cout << "Total sold = " << s1.GetTotalSold() << endl;
	cout << "Total sold = " << HotDogStand::GetTotalSold() << endl;
	cout << endl;


	// Sold some more
	s3.JustSold();
	s1.JustSold();

	cout << "Stand " << s1.GetID() << " sold " << s1.GetNumSold() << endl;
	cout << "Stand " << s2.GetID() << " sold " << s2.GetNumSold() << endl;
	cout << "Stand " << s3.GetID() << " sold " << s3.GetNumSold() << endl;
	cout << "Total sold = " <<  s1.GetTotalSold() << endl;
	cout << endl;
	return 0;

}















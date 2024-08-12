#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;


const int NUM_DUELS = 10000;

void Aaron_shoots(bool aaron, bool& bob, bool& charlie);
void Bob_shoots(bool& aaron, bool bob, bool& charlie);
void Charlie_shoots(bool& aaron, bool& bob, bool charlie);


void Aaron_shoots(bool aaron, bool& bob, bool& charlie)
{
	int shot;

	//IF Aaron is dies, returns

	if(aaron == false)
	{
		return;
	} 

	//Aaron's shot
	shot = rand() % 3;  // 1/3 chance of hitting the target

	// If random number is 0 then shots
	if(shot==0)
	{
		if(charlie) //If charlie is not dead shots him/her
		{
			charlie = false; //set to dead
		}
		else if(bob) // Secondly shots bob
		{
			bob = false;    //set to dead
		}
	}
	return;
}


void Bob_shoots(bool& aaron, bool bob, bool& charlie)
{
	int shot;

	//IF bob is dies, returns

	if(bob == false)
	{
		return;
	} 

	//bob's shot
	shot = rand() % 2;  // 1/2 chance of hitting the target

	// If random number is 0 then shots
	if(shot==0)
	{
		if(charlie) //If charlie is not dead shots him/her
		{
			charlie = false; //set to dead
		}
		else if(aaron) // Secondly shots aaron
		{
			aaron = false;    //set to dead
		}
	}
	return;
}


void Charlie_shoots(bool& aaron, bool& bob, bool charlie)
{
	//if charlie is dead, do nothing
	if(charlie == false)
	{
		return;
	}

	//charlie has %100 chance

	if(bob)
	{
		bob = false;
	}
	else if(aaron)
	{
		aaron = false;
	}
	return;
}

int main()
{
	bool aaronAlive, bobAlive, charlieAlive;
	int aaronWins = 0;
	int bobWins = 0;
	int charlieWins = 0;
	int i;


	//Random number generator
	srand(time(NULL));


	// Play 10,000 duels
	for(i=0; i<NUM_DUELS; i++)
	{
		aaronAlive = true;
		bobAlive = true;
		charlieAlive = true;

		// Duel will go on until two people left
		do
		{
		Aaron_shoots(aaronAlive, bobAlive, charlieAlive);
		Bob_shoots(aaronAlive, bobAlive, charlieAlive);
		Charlie_shoots(aaronAlive, bobAlive, charlieAlive);

	
		}while(((aaronAlive==true) && (bobAlive == true) ) || ((aaronAlive==true) && (charlieAlive==true)) || ((bobAlive==true) && (charlieAlive==true)));
		
		if(aaronAlive) aaronWins++;
		if(bobAlive) bobWins++;
		if(charlieAlive) charlieWins++;
	}

	



	

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);


	cout << "Aaron won " << aaronWins << "/10000 duels or " <<
		(static_cast<double>(aaronWins) / NUM_DUELS)*100 << "%" << endl;

	cout << "Bob won " << bobWins << "/10000 duels or " <<
		(static_cast<double>(bobWins) / NUM_DUELS)*100 << "%" << endl;

	cout << "Charlie won " << charlieWins << "/10000 duels or " <<
		(static_cast<double>(aaronWins) / NUM_DUELS)*100 << "%" << endl;
}

#include <iostream>

using namespace std;
					
void print_prime();     			//Sub-function to print prime numbers
	
int main()				
{
	print_prime();
}


void print_prime()
{
	int k;							// Variable for loop
	int l;							// Variable for loop
	bool Prime = true;

	for(k = 3;k<100;k++)			// First loop to go through all numbers 
	{
		if(Prime !=true)			// If function did find prime number before this needs to get reset
		{
			Prime = true;
		}
		
		for(l = 2;l<k-1;l++)		// Second loop to compare every number with current checked number
		{
			if(k % l == 0)			// Condition to be prime number
			{
				Prime = false;
				break;
			}
		}

		if(Prime)
		{
				cout << k << " is a prime number." << endl;		//If number is prime function will print it
		}
		
	}

}
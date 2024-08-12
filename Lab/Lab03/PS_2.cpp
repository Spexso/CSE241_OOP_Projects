#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



int main()
{
	int i;
	int current;
	int numSuitors;


	cout << "Enter the number of suitors" << endl;
	cin >> numSuitors;


	vector<int> suitors(numSuitors);

	for(int i=0; i<numSuitors; i++)
	{
		suitors[i] = i+1; // Number each suitor's position
	}




	if(numSuitors <=0)
	{
		cout << "Not enough suitors." << endl;
	}
	else if(numSuitors == 1)
	{
		cout << "You would stand first in line." << endl;
	}
	else
	{
		current = 0; // Current suitor the princess will examine
		// Eliminate a suitor as long as there is at least one
		while(suitors.size() > 1)
		{
			// Count three people ahead, or go two people down
			// Since we include the current person in the count
			for(i=0; i<2; i++)
			{
				current++;
				//if we reached the end, go back to the front
				if(current == suitors.size())
				{
					current=0;
				}
			}
			// Eliminate contestant current
			suitors.erase(suitors.begin() + current);
			// if we were at the last suitor, go to the first one
			if(current == suitors.size())
			{
				current=0;
			}

		}
		cout << "To win the princess, you should in the position " << suitors[0] << endl;

	}

	return 0;
}
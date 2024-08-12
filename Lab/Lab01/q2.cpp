#include <iostream>
#include <cstdlib>	//Library for srand function
#include <ctime>	//Library for srand function

using namespace std;

int roll();						// Function to randomly get a number between 1-6
int humanTurn(int humanScore);	// Human Player's turn
int computerTurn(int compScore);// Computer's turn

int main()
{
	int human_p;				//General score variable for player
	int comp_p;					//General score variable for computer
	bool gameOver = false;

	cout << "Welcome to Pig Game!" << endl << endl;
	srand(static_cast<int>(time(NULL)));

		while(!gameOver)					// Loop until a gameOver boolean gets true it depends on the max point
		{
			//First move belongs to human
			human_p += humanTurn(human_p);
			cout << "==========================================" << endl;


			//Now computer if the game is not over
			if(human_p < 100)
			{
				comp_p += computerTurn(comp_p);
				cout << "==========================================" << endl;
			}


			if(human_p >=100)							// If score of player exceeds the 100 then player wins 
			{
				cout << "Congrats, you won!" << endl;
				gameOver = true;
			}
			else if(comp_p >=100)						// If score of computer exceeds the 100 then computer wins 
			{
				cout << "Computer Won, Good luck next time!" << endl;
				gameOver = true;
			}
		}
}



int humanTurn(int humanScore)
{
	int score;				// Player's Score for this scope
	char inp;
	bool bTurn = false;		// Until this boolean value get true human's turn will go on
	
	cout << "Your turn! Enter 'r' to roll" << endl;
	cin >> inp;

	score = 0;

		do 					//Loop to get random number and sum it with current score
		{
			int roll_d = roll();
			cout << "Your rolled " << roll_d << endl;
			if(roll_d == 1)
			{
				cout << "_____________________________" << endl;
				cout << "If you roll 1-->Round is over " << endl << "_____________________________" << endl << "   ||Enter 'c' to continue " << endl;
				cin >> inp;
				return 0;
			}
			else
			{
				score +=roll_d;
				cout << "-Your score this round: " << score << endl;
				cout << "-If you hold, your total score would be: " << humanScore + score << endl;
				cout << "-------------------------------" << endl;
				cout << "-Enter 'h' to hold or 'r' to roll again " << endl;
				
				cin >> inp;

				if(humanScore+score >=100)			// Win condition
				{
					break;
				}

				if(inp == 'h')						// If char h is entered turn will skip and scores will be held
				{
					bTurn = true;
				}
				
			}
		}while(!bTurn);
	
	return score;
}

int computerTurn(int compScore)
{
	int score;										// Computer's Score for this scope
	char inp;
	bool bTurn;

	cout << "It's the Computer's turn!" << endl;

	score = 0;
	do
	{
		int roll_d = roll();
		if(roll_d == 1)
		{
			cout << "Computer lost it's turn by rolling 1  " << endl << "   ||Enter 'c' to continue" << endl;
			cin >> inp;

			return 0;
		}
		else
		{
			score +=roll_d;
			cout << "Computer rolled " << roll_d << endl;
			cout << "If Computer holds , its total score will be: " << score + compScore << endl;
			cout << "-------------------------------" << endl;
		}
		
		if((score >=20) || (score + compScore>=100))			// Win condition + Computer plays by using a tactic if gain is 20 points or more in a single round it holds			
		{
			cout << "Computer holds." << "||Enter 'c' to continue" << endl;
			cin >> inp;
			bTurn = true;
		}
	}while(!bTurn);

	return score;
}


int roll()
{
	return (rand() % 6) + 1;		// Funtion to return a random number between 1-6
}
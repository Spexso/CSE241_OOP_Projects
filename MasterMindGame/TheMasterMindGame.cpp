#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int max_size = 9;												//max size of digit arrays

int pre_check(int &c_arg);											//Inspects the argc variable to make sure program call is valid 

int random_num(int secret_size);									//Generates a random number with the given digit count info (Returns generated random number)

int hint(int user_guess, int secret_num);							//Gives hint about on-going game (Returns the two numbers that has so meaning as hint)

bool contain_digit(string str);										//Searches the string to find if it does contain any digit (Returns boolean value)								

int count_digit(int number);									    //Counts the digit of given number

int valid_num_check(int taken);										//Checks if the number has duplication in between its digits




int main(int argc, char** argv)
{
	char seen[max_size] = {0};			  									//Array to store duplication info value of entered number in -u mode
	int check_m = 0;					 								   //Variable to check mod condition (-r or -u)
	char size_n[max_size];												  //Array to store digit count of secret number 
	int size_num;					   									 //Variable to hold converted string which is digit count of secret number info 
	int size_num_sub;				  									//Sub variable to use while extracting digits by digits
	int digit;						 								   //Variable to hold digits individually 	
	int guess;				  	    								  //Variable for player's guess
	char temp_n;				   									 //Single char to check if input has non int characters
	int s_num;				 	  									//Variable for Secret Number
	int turns = 0;				 								   //Number of turns that user played
	int global_check = 1;										  //Variable to control return value of hint function 	

	if(pre_check(argc)!=1)
	{
		cout << "EO" << endl;
		exit(1);
	}

	strcpy(size_n,argv[2]);

	
	if(contain_digit(size_n) == false)
	{
		cout << "EO" << endl;
		exit(1);
	}


	size_num = atoi(argv[2]);
	size_num_sub = size_num;


	if(strcmp(argv[1],"-r") == 0 && argc == 3 && (size_num <= 9 && size_num > 0))
	{
		check_m = 1;
	}
	else if(strcmp(argv[1],"-u") == 0 && argc == 3 && size_num > 0)
	{
		while(size_num_sub)
		{
			digit = size_num_sub % 10;

			size_num_sub /= 10;

				if(seen[digit]++)
				{
					cout << "EO" << endl;
					exit(1);
				}
		}
		check_m = 2;

	}
	else
	{
		cout << "EO" << endl;
		exit(1); 
	}
	

	if(check_m == 1)
	{

		s_num = random_num(size_num);
		
		do
		{
			if(turns==100)
			{
				cout << "FAILED" << endl;					//After 100 turns game is over if user couldn't find the secret number
				break;
				exit(1);
			}			

			turns++;

			cin >> guess;

			temp_n = getchar();								//To check the inputs like "12k" Getchar will catch k 

			if(cin.fail() )									//Checks if the input is valid for integers
			{
				cout << "E2" << endl;
				exit(1);
			}
			else if( isdigit(temp_n) && !(isblank(temp_n)) )//Checks if the temporary char is digit and not blank
			{
				cout << "E2" << endl;
				exit(1);
			}
			else if(valid_num_check(guess) == -1)			//Checks if the number is valid as input
			{
				cout << "E1" << endl;
				exit(1);
			}


			global_check = hint(guess, s_num);

				if(global_check != 1)
				{
					exit(1);
				}


		}while(s_num != guess);
		
		if(s_num == guess)
		{
			//WIN
			cout << "FOUND " << turns << endl;
		}

	    
	}
	else if(check_m == 2)
	{
		//cout << "U MODE HERE" << endl;

			s_num = size_num;

		
		do
		{
			if(turns==100)
			{
				cout << "FAILED" << endl;					//After 100 turns game is over if user couldn't find the secret number
				break;
				exit(1);
			}			

		  	turns++;

		  cin >> guess;
			
		  temp_n = getchar();								//To check the inputs like "12k" Getchar will catch "k" 
		
			if(cin.fail() )									//Checks if the input is valid for integers
			{
				cout << "E2" << endl;
				exit(1);
			}
			else if( isdigit(temp_n) && !(isblank(temp_n)) ) //Checks if the temporary char is digit and not blank
			{
				cout << "E2" << endl;
				exit(1);
			}
			else if(valid_num_check(guess) == -1)			//Checks if the number is valid as input
			{
				cout << "E1" << endl;
				exit(1);
			}

				global_check = hint(guess, s_num);

			if(global_check != 1)
			{
				exit(1);
			}


		}while(s_num != guess);
		
		if(s_num == guess)
		{
			//WIN
			cout << "FOUND " << turns << endl;
		}
	}
	
		return 0;
}


int random_num(int secret_size)
{
	int cur_num[max_size] = {0};
	int secret_n;
	int i, k;
	int v_pass = 0;
	int scale = 1;
	int sum_of_digits = 0;


		srand(time(NULL));												//Generates pseudo random numbers for different seeds


	for(k=0;k<secret_size;k++)
	{

		do
		{
			v_pass = 0;

			if(k==0)
				secret_n = (rand() % 9) + 1 ;							//For very first number doesn't include 0 
			else
				secret_n = rand() % 9 ;
			

			for(i=0;i<secret_size-1 && v_pass == 0;i++)
			{
				if(secret_n == cur_num[i])								//If the randomed digit of secret number is same with another digit than rands it again
				{
					v_pass = 1;
				}
			}


		}while(v_pass);
		
		cur_num[k] = secret_n;
				
	}

	for(i=secret_size-1;i > -1;i--)
	{
		sum_of_digits += cur_num[i] * scale;							//Turns the digits to whole number and its secret number
		scale *= 10; 
	}

	return sum_of_digits;												//Secret Number
}

int pre_check(int &c_arg)
{
	if(c_arg!=3)
		return -1;
	else
		return 1;
}

int hint(int user_guess, int secret_num)
{
	int user_guess_ar[max_size] = {0};												//Array to hold individual digits of user's guess 
	int secret_num_ar[max_size] = {0};												//Array to hold individual digits of secret number
	int hold;																		//Dummy variable to assign calculations to the right array
	
	/* Simple variables to create loops */
	int c = 0;
	int k = 0;
	int l = 0;

	int first_c = 0;																//FIRST HINT:The count of digits of the proposed number that match in place of the secret number 
	int second_c = 0;																//SECOND HINT:The count of digits of the proposed number which do exist in the secret number but are not in place
	
	int digit_guess;																//Counts of digits (guessed number) 
	int digit_secret;																//Counts of digits (secret number)

	

	digit_guess = count_digit(user_guess);
	digit_secret = count_digit(secret_num);

		if(user_guess < 0)
		{
			cout << "E2" << endl;
			return -1;
		}
		else if(digit_guess != digit_secret)
		{
			cout << "E1" << endl;
			return -1; 
		}

	//Resolve both numbers and assign them to arrays
	while(user_guess !=0)
	{
		user_guess_ar[c] = user_guess % 10;
										/*
										Resolving happens in the reverse order 
										but its not really important for hint info
										*/
		c++;

		user_guess /= 10;

	}
	
	c = 0;

	while(secret_num !=0)
	{
		secret_num_ar[c] = secret_num % 10;
										/*
										Resolving happens in the reverse order 
										but its not really important for hint info
										*/
		c++;

		secret_num /= 10;

	}



	for(c=0;c<digit_guess;c++)
	{
		if(user_guess_ar[c] == secret_num_ar[c])
		{
			first_c++;												
		}
	}

	for(c=0;c<digit_guess;c++)
	{
		for(k=0;k<digit_guess;k++)
		{
			if(user_guess_ar[c] == secret_num_ar[k])
			{
				  second_c++;
			}
		}
	}

	cout << first_c << " " << second_c << endl;

	return 1;
}

int count_digit(int number)
{
	return int(log10(number) + 1);									// Just some basic math to calculate the number of digits 
}

int valid_num_check(int taken)
{
	int cur_num[max_size];
	int dig;
	int i = 0;
	int res = 1;

		dig = count_digit(taken);	

	while(taken != 0)
	{
		cur_num[i] = taken % 10;										//Extracts the digits one by one to an array
		i++;

			taken /= 10;
	}

	for(int k=0;k<dig;k++)
	{
		for(i=0;i<dig;i++)
		{
			if(i != k)
			{
				if(cur_num[i] == cur_num[k])						    //Searches the string separately to find same digit 
				{
					//Duplication
					res = -1;
					break;
				}
			}
			
		}
	}	
	
	return res;
}

bool contain_digit(string str)
{
	
	for(char const c : str)				//Searches the string char by char 
	{
		if(isdigit(c) == 0)				// if current char is not digit returns false
			return false;
	}
	return true;
}
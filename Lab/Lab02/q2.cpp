#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

const int MAX_DIGITS = 20;


//receive a sequence of digits from the input,
//converts to integer values, archive size
void input(int number[], int& size);


//Displays the integer's in correct order
void output( const int number[], int size);


void add( int first[], int firstSize, int second[], int secondSize, int sum[], int& sumSize);



int main()
{
	// to lower order digits

	int first[MAX_DIGITS+1]; //To prevent glitch
	int firstSize;   //Number of digits 
	int second[MAX_DIGITS+1]; 
	int secondSize;
	int sum[MAX_DIGITS+1];
	int sumSize;

	cout << "========LARGE INTEGER SUMMING PROGRAM========" << endl;
	cout << "Please enter an integer, 20 digits or less " << endl;
	
	input(first,firstSize);
	cout << "You entered " << endl;
	output(first, firstSize);

		cout << endl;

	cout << endl << "Enter another integer, 20 digits or less" << endl;
	input(second, secondSize);
	cout << "You entered " << endl;
	output(second, secondSize);

		for(int j=0;j<2;j++)
		{
			cout << endl;
		}

	cout << "The sum is: " << endl;
	output(first, firstSize);
	cout << endl;
	output(second, secondSize);
	cout << endl;
	cout << "-----------------------------" << endl;
	add(first, firstSize, second, secondSize, sum, sumSize );
	output( sum, sumSize);
	cout << endl;

	return 0;
}


void input(int number[], int& numberSize)
{
	char ch;
	int i = 0;
	numberSize = 0;
	cin.get(ch);
	while( '\n' != ch )
	{
		//Error handling should allow user to
		if( !isdigit(ch) )
		{
			cout << "ERROR--->Non digit...Aborting " << endl;
			exit(1);
		}
		number[i] = int(ch) - int('0');
			numberSize++;
			i++;
			cin.get(ch);
	}

		//More error handling
		if(numberSize > MAX_DIGITS)
		{
			cout << "ERROR--->Number size too large...Aborting " << endl;
			exit(1);
		}

		//Reverse Array
		for( int k = 0; k < numberSize/2; k++ )
		{
			int temp = number[k];
			number[ k ] = number[ numberSize -1 -k ];

		}

}


void output( const int number[], int numberSize )
{
	int i;

		//insert spaces to visually align the output
	for(i = 20; i >= numberSize; i--)
		cout << " ";
	for(i = numberSize -1; i >=0; i--)
		cout << number[i];
}



void add( int first[], int firstSize, int second[], int secondSize, int sum[], int& sumSize)
{
	int carry = 0;
	int largerSize;

	//pad the input with the smaller number of digits to the size of the larger with zeros

	if( firstSize > secondSize)
	{
		for( int i = secondSize; i < firstSize; i++)
			second[i] = 0;

		largerSize = firstSize;
		
	}
	else
	{
		for(int i = firstSize; i < secondSize; i++)
			first[i] = 0;
		largerSize = secondSize;
	}


	//Addition part
	for(int i = 0; i < largerSize; i++)
	{
		sum[i] = first[i] + second[i] + carry;
		if(sum[i] > 9)
		{
			carry = 1;
			sum[i] = sum[i] - 10;
		}
		else
			carry = 0;
	}

	if( carry == 1)
	{
		if( largerSize == 20)   // the carry is out of digit 20
		{
			cout << "An overflow has occured. " << "Result is set to 0" << endl;
			sumSize = 1;
			sum[0] = 0;	
		}
		else					// result is legal
		{
			sum[largerSize] = carry;
			sumSize = largerSize + 1;
		}
	}
	else			//no carry
	sumSize = largerSize;
}
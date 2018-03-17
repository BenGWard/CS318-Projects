//	Class:		CS318
//	Name:		Ben Ward
//	Email:		bward1@my.athens.edu
//	Student ID:	00076160
//	Title:		Base Conversion Program

#include <iostream>
#include <fstream> //for file operations
#include <cmath> //for log and pow
#include <math.h> //for floor function

using namespace std;

ofstream outFile;

//function prototypes
void baseConv(int b, int v);
char menu();
void asciiPrint();

int main()
{
	char selection;
	int number;
	int base;

	outFile.open("WardBaseConv.txt");
	
	do
	{
		selection = menu(); //run main menu fuction and set selection

		if (selection == 'A' || selection == 'a')
		{
			cout << "Please enter the number you wish to be converted: ";
			cin >> number;

			do
			{
				cout << endl << "Please enter the new base you wish to convert to: ";
				cin >> base;
				if (base < 2 || base > 9)
					cout << endl << "Error. New base must be between 2 and 9." << endl;
			} while (base < 2 || base > 9);

			
			//printing output to both the screen and file
			cout << endl << number << " in base 10 is ";
			outFile << endl << number << " in base 10 is ";
			baseConv(base, number);
			cout << " in base " << base;
			outFile << " in base " << base;
		}

		else if (selection == 'B' || selection == 'b')
			asciiPrint();
		
		//separating output on various runs of the output file 
		outFile << endl << endl;
	} while (selection == 'A' || selection == 'a' || selection == 'B' || selection == 'b');
	
	outFile.close();
	
	return 0;
}

//function to convert from base 10 to base 2 - 9
void baseConv(int b, int v)
{
	int k; //number of digits in the converted number
	int d; //to store digit

	k = floor(log10(v) / log10(b)) + 1;
	
	//this if statement is due to the case of log10(0) being -infinity and causing havoc
	//this happens when converting 0 to other bases
	if (k < 1)
		k = 1;

	while (k > 0)
	{
		d = v / pow(b, (k - 1));
		//printing output to both the screen and file
		cout << d;
		outFile << d;
		v = v % static_cast<int>(pow(b, (k - 1)));
		k -= 1;
	}
}

//menu function, returns user selection
char menu()
{
	char selection;
	
	cout << endl << endl;
	cout << "\t\tBase Conversion Calculator" << endl << endl << endl;
	cout << "A. Enter a number and a new base to convert from base 10 to new base." << endl;
	cout << "B. Print ASCII table in base 10 and binary." << endl;
	cout << "Press any other key to exit." << endl;
	cout << "Your selection: ";
	
	cin >> selection;
	
	cout << endl;

	return selection;
}

//function for ASCII  loop
void asciiPrint()
{
	char ch;

	for (int i = 0; i < 128; i++)
	{
		ch = i;
		//printing output to both the screen and file
		cout << i << " in base 10 is ";
		outFile << i << " in base 10 is ";
		baseConv(2, i);
		cout << " in binary. In ASCII it is " << ch << endl;
		outFile << " in binary. In ASCII it is " << ch << endl;
	}
}
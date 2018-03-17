//	Class:		CS318
//	Name:		Ben Ward
//	Title:		Multiplication Table Program

#include <iostream>
#include <fstream> //for file operations
#include <iomanip> //for setw

using namespace std;

void printTable(int);

ofstream outFile;

int main()
{
	int value;
	
	outFile.open("WardMultiTable.txt");
	
	do {
		cout << "Enter value for multiplication table: ";
		cin >> value;
		if (value < 1)
			cout << "Value must be greater than 0" << endl;
	} while (value < 1);
	
	printTable(value);
	
	cout << "Program Complete" << endl;
	cout << "Table written to WardMultiTable.txt" << endl;
	
	outFile.close(); //closing output file
	
	return 0;
}

//function to print the multiplication table
void printTable(int value)
{
	int i = 1;
	
	while(i <= value)
	{
		outFile << endl << setw(14) << i;
		if((i+1) <= value)
			outFile << "\t" << setw(6) << (i+1);
		if((i+2) <= value)
			outFile << "\t" << setw(6) << (i+2);
		if((i+3) <= value)
			outFile << "\t" << setw(6) << (i+3);
		if((i+4) <= value)
			outFile << "\t" << setw(6) << (i+4);
		outFile << endl; 
		outFile << "__________________________________________________" << endl;
		
		for(int j=1; j <= value; j++)
		{
			outFile << "Row " << setw(3) << j << "|";
			outFile << setw(6) << j * i;
			if((i+1) <= value)
				outFile << "\t" << setw(6) << j * (i+1);
			if((i+2) <= value)
				outFile << "\t" << setw(6) << j * (i+2);
			if((i+3) <= value)
				outFile << "\t" << setw(6) << j * (i+3);
			if((i+4) <= value)
				outFile << "\t" << setw(6) << j * (i+4);
			outFile << endl;
		}
		outFile << endl << endl;
		i += 5;
	}
}
//	Class:		CS318
//	Name:		Ben Ward
//	Email:		bward1@my.athens.edu
//	Student ID:	00076160
//	Title:		Bubba Multiply Program

#include <iostream>
#include <fstream> //for file operations

using namespace std;

const int ARRAYSIZESM = 30;
const int ARRAYSIZELG = 60;

ofstream outFile;
ifstream inFile;

//function prototypes
int loadArray(int array[]);
void charToInt(int array[], int size);
void shiftRight(int array[], int size);
void printArray(int array[], int size, int);
void zeroArray(int array[], int size);
void multiplyArray(int [], int , int [], int , int []);
void printLine();
int countArrayLG(int array[]);
bool loadSuccessful(int array[]);

int main()
{
	int firstArray[ARRAYSIZESM];
	int secondArray[ARRAYSIZESM];
	int resultsArray[ARRAYSIZELG];
	int firstSize;
	int secondSize;
	int resultsSize;

	inFile.open("BigNumbersV3.txt");
	outFile.open("WardBubbaMultiply.txt");
	
	while(inFile)
	{
		//zero out and load the two arrays
		zeroArray(firstArray, ARRAYSIZESM);
		firstSize = loadArray(firstArray);
		
		zeroArray(secondArray, ARRAYSIZESM);
		secondSize = loadArray(secondArray);
		
		//check if both arrays are zero, if so the load failed
		//this will allow one array to be zeros to multiply by zero
		if(loadSuccessful(firstArray) || loadSuccessful(secondArray))
		{
			charToInt(firstArray, firstSize);
			shiftRight(firstArray, firstSize);
			outFile << ' ';
			printArray(firstArray, firstSize, ARRAYSIZESM);
			
			charToInt(secondArray, secondSize);
			shiftRight(secondArray, secondSize);
			outFile << 'X';
			printArray(secondArray, secondSize, ARRAYSIZESM);
			
			zeroArray(resultsArray, ARRAYSIZELG);
			multiplyArray(firstArray, firstSize, secondArray, secondSize, resultsArray);
			printLine();
			outFile << ' ';
			printArray(resultsArray, countArrayLG(resultsArray), ARRAYSIZELG);
			
			outFile << endl;
		}
	}
	
	cout << "Program Complete" << endl;

	inFile.close(); //closing input file
	outFile.close(); //closing output file

	return 0;
}

//reads in file data to array and returns the size of the array
int loadArray(int array[])
{
	int i = 0;
	char ch;

	while (inFile && ch != '\n')
	{
		inFile.get(ch);
		
		if(inFile && ch != '\n')
		{
			array[i] = ch;
			i++;
		}
	}

	return i;
}

//function to convert char to int
void charToInt(int array[], int size)
{
	for (int i = 0; i < size; i++)
		array[i] -= '0';
}

//function to shift the numbers to the right of the array
void shiftRight(int array[], int size)
{
	for (int i = 1; i <= size; i++)
	{
		array[ARRAYSIZESM - i] = array[size - i];
		
		//this part will not run if the entire array is full
		if(ARRAYSIZESM != size)
			array[size - i] = 0;
	}
}

//print array function (with ignoring leading 0's)
void printArray(int array[], int size, int arrayType)
{
	bool print = false;
	
	for (int j = 0; j < (ARRAYSIZELG - size); j++)
		outFile << ' ';
	
	for (int i = 0; i < arrayType; i++)
	{
		if(array[i] != 0)
			print = true;
		
		if(print)
			outFile << array[i];
	}
	
	outFile << endl;
}

//function to zero out the array
void zeroArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
		array[i] = 0;
}

//function to multiply arrays
void multiplyArray(int firstArray[], int firstSize, int secondArray[], int secondSize, 
int resultsArray[])
{
	int excess;
	int arraySizeS = ARRAYSIZESM - 1;
	
	for (int i = arraySizeS; i > (arraySizeS - secondSize); i--)
	{
		for (int j = arraySizeS; j > (arraySizeS - firstSize); j--)
		{
			resultsArray[j + i + 1] = resultsArray[j + i + 1] + (secondArray[i] * firstArray [j]);
			
			//this code is to fix having 19 in the results array
			//when you want 9 in the current position and to carry the 1
			excess = 0;
			
			while(resultsArray[j + i + 1] > 9)
			{
				resultsArray[j + i + 1] -= 10;
				excess++;
			}
			
			resultsArray[j + i] += excess;
		}
	}
}

//this prints the line between the two numbers and the result
void printLine()
{
	for (int i = 0; i < (ARRAYSIZELG + 1); i++)
		outFile << '_';
	outFile << endl;
}

//function to count the large array (results array)
int countArrayLG(int array[])
{
	int count = 0;
	bool toCount = false;
	
	for (int i = 0; i < ARRAYSIZELG; i++)
	{
		if(array [i] != 0)
			toCount = true;
		if(toCount)
			count++;
	}
	
	return count;
}

//function to check if an array is simply full of 0's
bool loadSuccessful(int array[])
{
	bool isEmpty = true;
	bool successful;
	
	for (int i = 0; i < ARRAYSIZESM; i++)
	{
		if (array[i] != 0)
			isEmpty = false;
	}
	
	successful = !isEmpty;
	
	return successful;
}

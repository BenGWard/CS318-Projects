//	Class:		CS318
//	Name:		Ben Ward
//	Title:		Statistic with Pointers Program

#include <iostream>
#include <fstream> //for file operations
#include <iomanip> //for setw

using namespace std;

ofstream outFile;

//function prototypes
int loadArray(int *aptr);
void printArray(int *aptr, int size);
void sort(int *aptr, int size);
double median(int *aptr, int size);
void reverse(int *aptr, int size);
int mode(int *aptr, int size);

int main()
{
	int *aptr; //pointer for array
	aptr = new int[100]; //dynamic array

	int size;

	outFile.open("WardPtrPgm.txt");

	//load and sort array
	size = loadArray(aptr);
	sort(aptr, size);

	outFile << "The mode is: \t" << mode(aptr, size) << endl;
	outFile << "The median is: \t" << median(aptr, size) << endl << endl;

	//reverse array and print the first 32 values
	reverse(aptr, size);
	printArray(aptr, size);

	cout << "Program Complete" << endl;

	delete[] aptr; //delete dynamic array
	outFile.close(); //closing output file

	return 0;
}

//reads in file data to array and returns the size of the array
int loadArray(int *aptr)
{
	int size = 0;

	ifstream inFile;
	inFile.open("numbers.txt");

	while (size < 100 && inFile >> *aptr)
	{
		aptr++;
		size++;
	}

	inFile.close();

	return size;
}

//function to print the array (only first 32 values)
void printArray(int *aptr, int size)
{
	int *endCount; //pointer for end of array
	endCount = aptr + 32;

	int i = 0; //counter for new line

	for (; aptr < endCount; aptr++)
	{
		outFile << setw(8) << *aptr;
		i++;

		if ((i % 8) == 0) //to do a new line every 8 numbers
			outFile << endl;
	}

	outFile << endl << endl;
}

//function to sort array
void sort(int *aptr, int size)
{
	int *ptr2; //pointer for walking through inside loop
	int *endCount; //pointer for end of array
	endCount = aptr + size;

	int lowest;
	int *lowPTR;
	int swap;

	while (aptr < endCount)
	{
		lowest = *aptr;
		ptr2 = aptr + 1;

		while (ptr2 < endCount)
		{
			if (*ptr2 < lowest)
			{
				lowest = *ptr2;
				lowPTR = ptr2;
			}
			ptr2++;
		}

		//swap first value with lowest value
		swap = *aptr;
		*aptr = lowest;
		*lowPTR = swap;
		aptr++;
	}
}

//function that returns the median of the array
double median(int *aptr, int size)
{
	double median;
	int *mPTR; //pointer for median value

	if (size % 2 == 1)
	{
		mPTR = aptr + (size / 2);
		median = *mPTR;
	}
	else
	{
		//set mPTR to the lower of the two numbers to be averaged, put that value in median
		//iterate mPTR, put second value also in median, divide median in half
		mPTR = aptr + (size / 2) - 1;
		median = *mPTR;
		mPTR++;
		median += *mPTR;
		median = median / 2;
	}

	return median;
}

//function that returns the mode of the array (value occuring most often)
int mode(int *aptr, int size)
{
	int *ptr2; //pointer for walking through inside loop
	int *endCount; //pointer for end of array
	endCount = aptr + size;

	int curValue;
	int curCount;
	int modeValue;
	int modeCount = 0;

	while (aptr < endCount)
	{
		curValue = *aptr;
		curCount = 1;

		ptr2 = aptr + 1;

		while (ptr2 < endCount)
		{
			//if this element is also the current value we're looking for
			//add one to count
			if (*ptr2 == curValue)
				curCount++;
			
			//if a count becomes the new highest count, set it to mode count
			//and set it's pointer to mode pointer
			if (curCount > modeCount)
			{
				modeValue = curValue;
				modeCount = curCount;
			}

			ptr2++;
		}

		aptr++;
	}

	return modeValue;
}

//function that reverses the values in the array
void reverse(int *aptr, int size)
{
	int *last; //pointer for last element of array
	last = aptr + size - 1;
	int count = size / 2; //variable for counting
	int swap; //variable for swapping

	for (int i = 0; i < count; i++)
	{
		//swap values around
		swap = *aptr;
		*aptr = *last;
		*last = swap;
		//iterate counters
		aptr++;
		last--;
	}

}
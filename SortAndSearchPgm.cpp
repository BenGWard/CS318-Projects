//	Class:		CS318
//	Name:		Ben Ward
//	Title:		Sort & Search Evaluation

#include <iostream>
#include <fstream> //for file operations
#include <string> //for strings
#include <iomanip> //for setprecision
#include <ctime> //for clock

using namespace std;

ofstream outFile;

//function prototypes
string makeString(char charset[]);
void makeStringArray(string *ptr, int size);
void loadAlpha(char *aptr);
void selectionSort(string *aptr, int size);
void bubbleSort(string *aptr, int size);
void swap(string *aptr, string *bptr);
int linearSearch(string *aptr, int size, string target);
int binarySearch(string *aptr, int size, string target);

int main()
{
	outFile.open("WardSaSPgm.txt");

	string array[11000];
	string target;
	int randInx; //variable for random index into array for searches
	int probes; //variable for probes required for searches
	int values; //variable for number of values to sort / search
	clock_t time; //variable for time
	
	//1000 strings sort
	values = 1000;
	makeStringArray(array, values);
	time = clock();
	bubbleSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform bubble sort with " << values << " values." << endl;
	makeStringArray(array, values);
	time = clock();
	selectionSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform selection sort with " << values << " values." << endl << endl;
	
	//3000 strings sort
	values = 3000;
	makeStringArray(array, values);
	time = clock();
	bubbleSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform bubble sort with " << values << " values." << endl;
	makeStringArray(array, values);
	time = clock();
	selectionSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform selection sort with " << values << " values." << endl << endl;

	//5000 strings sort
	values = 5000;
	makeStringArray(array, values);
	time = clock();
	bubbleSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform bubble sort with " << values << " values." << endl;
	makeStringArray(array, values);
	time = clock();
	selectionSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform selection sort with " << values << " values." << endl << endl;

	//7000 strings sort
	values = 7000;
	makeStringArray(array, values);
	time = clock();
	bubbleSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform bubble sort with " << values << " values." << endl;
	makeStringArray(array, values);
	time = clock();
	selectionSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform selection sort with " << values << " values." << endl << endl;

	//9000 strings sort
	values = 9000;
	makeStringArray(array, values);
	time = clock();
	bubbleSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform bubble sort with " << values << " values." << endl;
	makeStringArray(array, values);
	time = clock();
	selectionSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform selection sort with " << values << " values." << endl << endl;
	
	//11000 strings sort
	values = 11000;
	makeStringArray(array, values);
	time = clock();
	bubbleSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform bubble sort with " << values << " values." << endl;
	makeStringArray(array, values);
	time = clock();
	selectionSort(array, values);
	time = clock() - time;
	outFile << "It took " << setprecision(4) << fixed << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds to perform selection sort with " << values << " values." << endl << endl;
	
	//linear search for 3500 random strings in the array of 11000 strings array only and compute the average number of probes(not time) needed to find a match
	probes = 0;

	for (int i = 0; i < 3500; i++)
	{
		randInx = rand() % 11000;
		target = array[randInx];
		probes += linearSearch(array, 11000, target);
	}

	outFile << "The average number of probes required with linear search is:\t" << setprecision(4) << fixed << probes / 3500.0 << endl;

	//binary search for 3500 random strings in the array of 11000 strings array only and compute the average number of probes(not time) needed to find a match
	probes = 0;

	for (int i = 0; i < 3500; i++)
	{
		randInx = rand() % 11000;
		target = array[randInx];
		probes += binarySearch(array, 11000, target);
	}

	outFile << "The average number of probes required with binary search is:\t" << setprecision(4) << fixed << probes / 3500.0 << endl;

	cout << "Program Complete" << endl;

	outFile.close(); //closing output file

	return 0;
}

//function using selection sort 
void selectionSort(string *ptr, int size)
{
	string *ptr2; //pointer for walking through inside loop
	string *lowPTR; //pointer for lowest value in that loop
	string *endCount; //pointer for end of array
	endCount = ptr + size;
	
	while (ptr < endCount)
	{
		lowPTR = ptr;
		ptr2 = ptr + 1;

		while (ptr2 < endCount)
		{
			if (*ptr2 < *lowPTR)
				lowPTR = ptr2;
			ptr2++;
		}
		
		swap(ptr, lowPTR);

		ptr++;
	}
}

//function to sort using bubble sort
void bubbleSort(string *aptr, int size)
{
	string *ptr; //pointer for walking through array
	string *ptr2; //pointer for walking through array
	string *endCount; //pointer for end of array
	endCount = aptr + size;


	for (int pass = 0; pass < (size - 1); pass++)
	{
		//reset positions on pointer and pointer2
		ptr = aptr; 
		ptr2 = ptr + 1;

		while (ptr2 < endCount)
		{
			if (*ptr2 < *ptr)
				swap(ptr, ptr2);
			
			//iterate pointers
			ptr++;
			ptr2++;
	
		}
	}
}

//function to swap two values of an array
void swap(string *aptr, string *bptr)
{
	string swap;

	//swap first value with lowest value
	swap = *aptr;
	*aptr = *bptr;
	*bptr = swap;
}

//function that returns a random 20 character string
string makeString(char charset[])
{
	string  randomstr = ""; //initiaze to blank
	int randomndx;

	for (int i = 0; i < 20; i++)
	{
		randomndx = rand() % 52;   //  random index into array charset
		randomstr = randomstr + charset[randomndx];  //concat a char to the string being built
	}

	return randomstr;
}

void makeStringArray(string *ptr, int size)
{
	char  charset[52];
	string *endCount; //pointer for end of array
	endCount = ptr + size;

	loadAlpha(charset); //load charset array with a-z and A-Z

	while (ptr < endCount)
	{
		*ptr = makeString(charset);
		ptr++;
	}
}

//function to load an array with a-z and A-Z 
void loadAlpha(char *aptr)
{
	//load uppercase
	char ch = 'A';

	while (ch <= 'Z')
	{
		*aptr = ch;

		aptr++; 
		ch++; 
	}

	//load lowercase
	ch = 'a';

	while (ch <= 'z')
	{
		*aptr = ch;

		aptr++; 
		ch++; 
	}
}

//function to search using linear search (N/2 efficiency)
int linearSearch(string *aptr, int size, string target)
{
	int count = 0; //variable for count of probes required to find value
	string *endCount; //pointer for end of array
	endCount = aptr + size;
	bool found = false;

	//checking position first for short circuit to prevent blowing out of array
	//also shuts off once it has passed where the value would be in a sorted array
	while (aptr < endCount && target > *aptr)
	{
		aptr++;
		count++;
	}

	if (*aptr == target)
		found = true;

	return count;
}

//function to search using binary search (log2(N) efficiency)
int binarySearch(string *aptr, int size, string target)
{
	int count = 0; //variable for count of probes required to find value
	string *lowptr;
	string *midptr;
	string *highptr;

	lowptr = aptr;
	highptr = aptr + size - 1;
	midptr = lowptr + ((highptr - lowptr) / 2);

	//checks to see if low pointer and high pointer have swapped, meaning the value is not in the array
	while (lowptr <= highptr && *midptr != target)
	{
		if (target < *midptr)
			highptr = midptr - 1;

		else if (target > *midptr)
			lowptr = midptr + 1;

		midptr = lowptr + ((highptr - lowptr) / 2);
		count++;
	}
	
	return count;
}
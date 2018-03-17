//	Class:		CS318
//	Name:		Ben Ward
//	Title:		Inventory Program

#include <iostream>
#include <fstream> //for file operations
#include <string> //for strings
#include <iomanip> //for setw

using namespace std;

//structure declaration
struct item
{
	string name;
	int itemNum;
	int qty;
	double price;
	int safeQty;
};

//constants
const int ARRAYSIZE = 8;
const int ITEMNAMESIZE = 20;

ofstream outFile;

//function prototypes
void loadInventory(item array[]);
void print(item array[]);
void sort(item array[]);
int search(item array[], int iNum);
void updateInv(item array[]);

int main()
{
	item inventory[ARRAYSIZE];

	outFile.open("WardInvPgm.txt");

	//load, sort and print intial inventory
	loadInventory(inventory);
	sort(inventory);
	print(inventory);

	//update and print inventory
	outFile << "Updating Inventory From File..." << endl << endl;
	updateInv(inventory);
	print(inventory);

	cout << "Program Complete" << endl;

	outFile.close(); //closing output file

	return 0;
}

//function to load inventory into an array of item structures from a file
void loadInventory(item array[])
{
	ifstream inFile;
	inFile.open("inventory data.txt");

	int i = 0; 
	char ch;
	
	while (inFile && i < ARRAYSIZE)
	{
		//get item name
		array[i].name = ""; //blank out name field
		
		for (int j = 0; j < ITEMNAMESIZE; j++)
		{
			inFile.get(ch);
			array[i].name += ch;
		}

		//get numerical values
		inFile >> array[i].itemNum >> array[i].qty >> array[i].price >> array[i].safeQty;
		
		inFile.ignore(); //dumping the newline character

		i++;
	}
}

//function to print inventory
void print(item array[])
{
	outFile << "Item Name" << setw(25) << "Item Number" << setw(10) << "Quantity";
	outFile << setw(10) << "Price" << setw(20) << "Price * Quantity" << setw(6) << "Flag" << endl;

	//loop for line for header
	for (int i = 0; i < 80; i++)
		outFile << '_';
	outFile << endl;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		outFile << setprecision(2) << fixed;
		outFile << setw(20) << array[i].name << setw(8) << array[i].itemNum << setw(16) << array[i].qty;
		outFile << "   $" << setw(6) << array[i].price << "   $ " << setw(15) << array[i].price * array[i].qty;
		
		//check for safe stock
		if (array[i].qty < array[i].safeQty)
			outFile << setw(6) << 'X';
		
		outFile << endl;
	}

	outFile << endl << endl;
}

//function to sort array by item numbers using selection sort
void sort(item array[])
{
	int lowest;
	int lowPos;
	item swap;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		lowest = array[i].itemNum;
		lowPos = i;
		
		for (int j = (i + 1); j < ARRAYSIZE; j++)
		{
			if (array[j].itemNum < lowest)
			{
				lowest = array[j].itemNum;
				lowPos = j;
			}
		}

		swap = array[i];
		array[i]= array[lowPos];
		array[lowPos] = swap;
	}
}

//function to search for an item number and return the position in the array
int search(item array[], int iNum)
{
	bool found = false;
	int i = 0;
	int pos;

	while (i < ARRAYSIZE && !found)
	{
		if (array[i].itemNum == iNum)
		{
			pos = i;
			found = true;
		}

		i++;
	}

	return pos;
}

//function to update inventory from file
void updateInv(item array[])
{
	ifstream inFile;
	inFile.open("invUpdatet.txt");

	int itemNum;
	int qty;
	int pos;

	while (inFile >> itemNum)
	{
		inFile >> qty;

		//find item in array
		pos = search(array, itemNum);

		//update quantity
		array[pos].qty += qty;
	}
}

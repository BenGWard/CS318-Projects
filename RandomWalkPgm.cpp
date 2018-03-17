//	Class:		CS318
//	Name:		Ben Ward
//	Title:		Random Walk Program

#include <iostream>
#include <fstream> //for file operations
#include <cstdlib> //for rand
#include <iomanip> //for setprecision and setw

using namespace std;

//constants
const double PRICEPERFLOWER = 3.00;
const int ISLANDWIDTHROW = 12;
const int ISLANDLENGTHCOL = 16; //actually 14 with a landing on either side of island

ofstream outFile;

//function prototypes
void initArray(int array[][ISLANDLENGTHCOL]);
void walk(int array[][ISLANDLENGTHCOL], int &, int &, int &);
void step(int &posRow, int &posCol);

int main()
{
	outFile.open("WardRandomWalk.txt");

	int island[ISLANDWIDTHROW][ISLANDLENGTHCOL];
	int fallWater = 0;
	int madeBridge = 0;
	int flowersMashed = 0;
	double avgCost;

	for (int i = 0; i < 3500; i++)
	{
		initArray(island);
		walk(island, fallWater, madeBridge, flowersMashed);
	}
	
	avgCost = (flowersMashed * PRICEPERFLOWER) / 3500;

	outFile << setprecision(2) << fixed;
	outFile << "The average cost of Harvey's walk: \t\t\t\t$" << setw(6) << avgCost << endl;
	outFile << "The number of times Harvey made it to the bridge: \t\t" << setw(7) << madeBridge << endl;
	outFile << "The number of times Harvey had to be rescued from the water: \t" << setw(7) << fallWater << endl;
	
	cout << "Program Complete" << endl;

	outFile.close();

	return 0;
}

//function to initialize the array to 2, except for path, and first and last columns
void initArray(int array[][ISLANDLENGTHCOL])
{
	//fill the whole array with 2's
	for (int i = 0; i < ISLANDWIDTHROW; i++)
	{
		for (int j = 0; j < ISLANDLENGTHCOL; j++)
		{
			array[i][j] = 2;
		}
	}

	//remove 2's from first and last column
	for (int i = 0; i < ISLANDWIDTHROW; i++)
	{
		array[i][0] = 0;
	}

	for (int i = 0; i < ISLANDWIDTHROW; i++)
	{
		array[i][ISLANDLENGTHCOL - 1] = 0;
	}

	//remove 2's from middle path
	int middlePath = ISLANDWIDTHROW / 2; //int division

	for (int j = 0; j < ISLANDLENGTHCOL; j++)
	{
		array[middlePath][j] = 0;
	}

}

//function to actually run one of harvey's walks across the island
void walk(int array[][ISLANDLENGTHCOL], int &fallWater, int &madeBridge, int &flowersMashed)
{
	//variable for if Harvey is still walking
	//set to false with fall into water or successful cross
	bool walking = true; 

	int posRow = ISLANDWIDTHROW / 2; //int division
	int posCol = 0;

	while (walking)
	{
		step(posRow, posCol);

		//check to see if he hit first landing for success
		if (posRow == (ISLANDWIDTHROW / 2) && posCol == 0)
		{
			walking = false;
			madeBridge++;
		}

		//check to see if he hit second landing for success
		else if (posRow == (ISLANDWIDTHROW / 2) && posCol == (ISLANDLENGTHCOL - 1))
		{
			walking = false;
			madeBridge++;
		}

		//check to see if he fell in the water
		else if (posRow >= ISLANDWIDTHROW || posRow < 0)
		{
			walking = false;
			fallWater++;
		}

		//check to see if he fell in the water pt 2
		//conditions are slightly different due to first and last column
		//being mostly water, other than the platforms
		else if (posCol >= (ISLANDLENGTHCOL - 1) || posCol < 1)
		{
			walking = false;
			fallWater++;
		}

		//check to see if he mashed a flower
		else if (array[posRow][posCol] > 0)
		{
			array[posRow][posCol] -= 1; //remove a flower
			flowersMashed++; //count a mashed flower
		}
	}
}

//function for taking a step, returns new position via reference variables
void step(int &posRow, int &posCol)
{
	int step;

	step = rand() % 100;

	if (step < 45)
		posCol += 1;
	else if (step < 70)
		posRow += 1;
	else if (step < 90)
		posRow -= 1;
	else
		posCol -= 1;
}
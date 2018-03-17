//	Class:		CS318
//	Name:		Ben Ward
//	Title:		Function Program

#include <iostream>
#include <fstream> //for file operations
#include <cmath> //for pow

using namespace std;

//function prototypes
float readIn();
void print(float);
float add(float, float);
float avg(float, float);
float diff(float, float);
float power(float, float);
float larger(float, float);
float smaller(float, float);

ofstream outFile;
	
int main()
{
	float num1;
	float num2;
	float num3;
	float num4;
	float num5;
	float sum = 0;
	float largest;
	float smallest;
	float runTotal;
	
	outFile.open("WardReport.txt");

	//read in 5 float numbers 
	cout << "Enter 5 numbers. Hit return after each one" << endl;
	num1 = readIn();
	num2 = readIn();
	num3 = readIn();
	num4 = readIn();
	num5 = readIn();
	
	//Print out the 5 float numbers
	outFile << "The five numbers" << endl;
	print(num1);
	print(num2);
	print(num3);
	print(num4);
	print(num5);
	
	//Print out the sum of the five numbers
	outFile << "The sum of the five numbers" << endl;
	sum = add(sum, num1);
	sum = add(sum, num2);
	sum = add(sum, num3);
	sum = add(sum, num4);
	sum = add(sum, num5);
	print(sum);
	
	//Print out the average of the 5 numbers.
	outFile << "The average of the five numbers" << endl;
	print(avg(sum, 5));

	//Print the difference between the first and third number
	outFile << "The difference between the first and third number" << endl;
	print(diff(num1, num3));
	
	//Print the difference between the second and fourth
	outFile << "The difference between the second and fourth number" << endl;
	print(diff(num2, num3));
	
	//Print the first number raised to the third number power
	outFile << "The first number raised to the third number power" << endl;
	print(power(num1, num3));
	
	//Print the second number raised to the fourth number
	outFile << "The second number raised to the fourth number power" << endl;
	print(power(num2, num4));
	
	//Print out the largest of the 5 numbers. 
	outFile << "The largest of the five numbers" << endl;
	largest = larger(num1, larger(larger(num2, num3), larger(num4,num5)));
	print(largest);
	
	//Print out the smallest of the 5 numbers.
	outFile << "The smallest of the five numbers" << endl;
	smallest = smaller(num1, smaller(smaller(num2, num3), smaller(num4,num5)));
	print(smallest);
	
	//Print out the average of the four largest values
	outFile << "The average of the four largest numbers" << endl;
	print(avg ((sum - smallest), 4));
	
	//Print out the average of the four smallest values
	outFile << "The average of the four smallest numbers" << endl;
	print(avg ((sum - largest), 4));
	
	//Print out the running total of the five numbers
	outFile << "Running total of the five numbers" << endl;
	print(runTotal = num1);
	print(runTotal += num2);
	print(runTotal += num3);
	print(runTotal += num4);
	print(runTotal += num5);
	
	cout << "Program Complete" << endl;
	
	outFile.close(); //closing output file
	
	return 0;
}

//read in one float number.  (zero argument function)
float readIn()
{
	float value;
	
	cin >> value;
	
	return value;
}

//print out one float number.  (One argument function)
void print(float num)
{
	outFile << num << endl;
}

//sum two numbers  (two argument function)
float add(float num1, float num2)
{
	return num1 + num2;
}

//average of numbers (two argument function)
float avg(float num1, float num2)
{
	return num1 / num2;
}

//difference between two numbers (two argument function)
float diff(float num1, float num2)
{
	return num1 - num2;
}

//compute first argument raised to the second argument power (two argument function)
float power(float num1, float num2)
{
	return pow(num1, num2);
}

//compute the larger of two numbers (two argument function)
float larger(float num1, float num2)
{
	float answer;
	
	if (num1 > num2)
		answer = num1;
	else
		answer = num2;
	
	return answer;
}

//compute the smaller of two numbers (two argument function)
float smaller(float num1, float num2)
{
	float answer;
	
	if (num1 < num2)
		answer = num1;
	else
		answer = num2;
	
	return answer;
}
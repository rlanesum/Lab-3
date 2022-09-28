/*********************
Anesu Mudzingwa
David Busch
C++ Fall 2022 Lab 3
27 September 2022
**********************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//Declaration of 4 variables where the numbers will be stored 
int a;
int b;
int c;
int d;

float answer;
float answerM;
float answerD;

//Input and Output file variables declared as global variables
ifstream inFile;
ofstream outFile;

void mean();
void standardDeviation();
void outputFileMD();

int main() 
{
	//Get the four values from user input 
	cout << "Please enter the first value: ";
		cin >>  a;

	cout << "Please enter the second value: ";
		cin >>  b;

	cout << "Please enter the third value: ";
		cin >>  c;

	cout << "Please enter the fourth value: ";
		cin >>  d;

		cout << '\n';
		cout << "Here are FOUR chosen Values: ";
		cout << a << " " << b << " " <<  c << " " << d << endl;

		//Call both functions to calculate the mean and standard deviation of the input values
		mean();
		standardDeviation();

		cout << "Mean: " << answerM << endl;
		cout << "Standard Deviation: " << answerD << endl;
		
		inFile.open("inMeanStd.dat");
		
		//if statement to let us know if the input file is opening
		if (!inFile.is_open()) 
		{
			cout << "Can not find input file.";
		}

		//Putting the values we get from the input File into variables
		inFile >> a;
		inFile >> b;
		inFile >> c;
		inFile >> d;

		outFile.open("outMeanStd.dat");

		//if statement to let us know if the input file is opening
		if (!outFile.is_open())
		{

			cout << "Can not find output file";
		}

		//Output the values you got from the input File into the output File
		outFile << a << " " << b << " " << c << " " << d << endl;

		//Function to calculate and output the mean and standard deviation for the values from the input File 
		outputFileMD();

		inFile.close(); 
		outFile.close();
		

	return 0;
}

//Function that will calculate the mean of the 4 Values
void mean()
{ 
	float sum;
	int numberofValueM = 4;
	sum = a + b + c + d;
	answerM = float(sum / numberofValueM);

}

//Function to calculate the standard deviation of the 4 Values
void standardDeviation() 
{
	int numberofValueD = 4;
	answer = (pow((a - answerM),2)+pow((b - answerM),2)+pow((c - answerM),2)+pow((d - answerM),2))/numberofValueD;
	answerD = sqrt(answer);
}

// Function to calculate the mean and deiviation of the input File and output it in the output File
void outputFileMD() 
{
	mean();
	outFile << "Mean: " << answerM << endl;

	standardDeviation();
	outFile << "Standard Deviation: " << answerD << endl;

}
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

int a;
int b;
int c;
int d;

float answer;
float answerM;
float answerD;

ifstream inFile;
ofstream outFile;

void mean();
void standardDeviation();
void outputFileMD();

int main() 
{

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

		mean();
		standardDeviation();

		cout << "Mean: " << answerM << endl;
		cout << "Standard Deviation: " << answerD << endl;
		
		inFile.open("inMeanStd.dat");

		if (!inFile.is_open()) 
		{
			cout << "Can not find input file.";
		}

		inFile >> a;
		inFile >> b;
		inFile >> c;
		inFile >> d;

		outFile.open("outMeanStd.dat");

		if (!outFile.is_open())
		{

			cout << "Can not find output file";
		}

		outFile << a << " " << b << " " << c << " " << d << endl;
		outputFileMD();

	return 0;
}


void mean()
{ 
	float sum;
	int numberofValueM = 4;
	sum = a + b + c + d;
	answerM = float(sum / numberofValueM);

}

void standardDeviation() 
{
	int numberofValueD = 4;
	answer = (pow((a - answerM),2)+pow((b - answerM),2)+pow((c - answerM),2)+pow((d - answerM),2))/numberofValueD;
	answerD = sqrt(answer);
}


void outputFileMD() 
{
	mean();
	outFile << "Mean: " << answerM << endl;

	standardDeviation();
	outFile << "Standard Deviation: " << answerD << endl;
}
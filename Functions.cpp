#include <iostream> //preprocessor directive
#include <fstream>
#include <cmath>
#include "Functions.h"
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

void convert(string fileName, int firstGen[], int x, int y)
{
	// Converts the grid in the text file to an array of 1s and 0s

	int lineNumber = 0;
	string line;
	ifstream myfile (fileName);

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lineNumber ++;

			if(lineNumber > 2 && lineNumber < (3 + y))
			{
				// only look at the grid

				for(int i = 0; i < x; i++)
				{
					if(line[i] == '-')
					{
						firstGen[i + x*(lineNumber - 3)] = 0;
					}
					else if(line[i] == 'X')
					{
						firstGen[i + x*(lineNumber - 3)] = 1;
					}
				}
    	}
		}
		myfile.close();
	}
}

int getX(string fileName)
{
	// gets the width (X) of the grid in the file

	int lineNumber = 0;
	string line;
	string firstLine;
	int x;
	ifstream myfile (fileName);

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lineNumber ++;

			if(lineNumber == 3)
			{
				// stores the length af a line
				firstLine = line;
			}
    }
    myfile.close();
	}
	x = firstLine.length() - 1;
	// grid width = length of the line

	return x;
}

int getY(string fileName)
{
	// gets the height (Y) of the grid in the file

	int lineNumber = 0;
	string line;
	int y;
	ifstream myfile (fileName);

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lineNumber ++;
    }
    myfile.close();
	}

	y = lineNumber - 2;
	// height of the grid = number of lines in the file minus the first two

	return y;
}

void printGen(int currentGen[], int x, int y)
{
	// print the current generation to the console as a grid of 'X's and '-'s

	string line;

	for(int i = 0; i < y; i++)
	{
		line = "";

		for(int j = 0; j < x; j++)
		{
			if(currentGen[j+i*x] == 0)
			{
				line += '-';
			}
			else if(currentGen[j+i*x] == 1)
			{
				line += 'X';
			}
		}

		cout << line << endl;
	}
	cout << endl;
}

void generateFirstGen(double density, int firstGen[], int x, int y)
{
	// uses the given density 0 < d <= 1 to generate a first generation

	double n;

	for(int i = 0; i < x*y; i++)
	{
		n = rand() % 100 + 1;     // number in the range 1 to 100, SOURCE: http://www.cplusplus.com/reference/cstdlib/rand/

		if(density*100 >= n)
		{
			firstGen[i] = 1;
		}
		else
		{
			firstGen[i] = 0;
		}
	}
}

void writeGen(string fileName, int currentGen[], int x, int y, int generationNumber)
{
	// writes the current generation to a file as a grid of 'X's and '-'s

	string line;

	std::ofstream myfile;
	myfile.open(fileName, std::ofstream::app);
	if (myfile.is_open())
	{
		myfile << "\n";
		myfile << "Generation " << generationNumber << "\n";
		myfile << "\n";

		for(int i = 0; i < y; i++)
		{
			line = "";

			for(int j = 0; j < x; j++)
			{
				if(currentGen[j+i*x] == 0)
				{
					line += '-';
				}
				else if(currentGen[j+i*x] == 1)
				{
					line += 'X';
				}
			}
			myfile << line << "\n";
		}
		myfile << "\n";
		myfile.close();
	}
}

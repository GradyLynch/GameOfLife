#include <iostream> //preprocessor directive

using namespace std;

int getX(string fileName);
int getY(string fileName);
void convert(string fileName, int firstGen[], int x, int y);
void printGen(int currentGen[], int x, int y);
void generateFirstGen(double density, int firstGen[], int x, int y);
void writeGen(string fileName, int currentGen[], int x, int y, int generationNumber);

#include <iostream> //preprocessor directive
#include <fstream>
#include "simulation.h"
#include "Functions.h"
#include  <unistd.h>
#include <stdlib.h>

using namespace std;

int main ()
{
  ////////// Get all user input //////////

  cout << endl;
  cout << "Would you like to provide a starting grid or would you like a randomly generated one?" << endl;
  cout << "Enter 'provide' to provide your own or 'random' for a random one" << endl;
  string inputA;
  getline(cin, inputA);
  cout << endl;

  cout << "What type of boundry mode would you like to run?" << endl;
  cout << "Enter 'classic' for classic mode, 'doughnut' for doughnut mode, or 'mirror' for mirror mode" << endl;
  string inputB;
  getline(cin, inputB);
  cout << endl;

  cout << "Would you like a pause between generations, advancement by pressing the enter key, or output to a file?" << endl;
  cout << "Enter 'pause' for a pause, 'enter' for enter key (the word enter NOT the enter key), or 'file' for file output" << endl;
  string inputC;
  getline(cin, inputC);
  cout << endl;

  cout << "You chose " + inputA + ", " + inputB + ", and " + inputC +". Is this Correct?" << endl;
  cout << "Please enter 'yes' or 'no'. If you enter no you will be given all three prompts again." << endl;
  string inputD;
  getline(cin, inputD);
  cout << endl;

  while(inputD == "no")
  {
    cout << "Would you like to provide a starting grid or would you like a randomly generated one?" << endl;
    cout << "Enter 'provide' to provide your own or 'random' for a random one" << endl;
    getline(cin, inputA);
    cout << endl;

    cout << "What type of boundry mode would you like to run?" << endl;
    cout << "Enter 'classic' for classic mode, 'doughnut' for doughnut mode, or 'mirror' for mirror mode" << endl;
    getline(cin, inputB);
    cout << endl;

    cout << "Would you like a pause between generations, advancement by pressing the enter key, or output to a file?" << endl;
    cout << "Enter 'pause' for a pause, 'enter' for enter key (the word enter NOT the enter key), or 'file' for file output" << endl;
    getline(cin, inputC);
    cout << endl;

    cout << "You chose " + inputA + ", " + inputB + ", and " + inputC +". Is this Correct?" << endl;
    cout << "Please enter 'yes' or 'no'. If you enter no you will be given all three prompts again." << endl;
    getline(cin, inputD);
    cout << endl;
  }

  ////////// Set up simulation based on user input //////////

  // establish the following variables
  string fileName;
  int x;
  int y;
  // x and y must be found before arrays can be initialized

  if(inputA == "provide")
  {
    cout << "Please enter the name of a text file that contains a starting grid." << endl;
    getline(cin, fileName);
    cout << endl;

    x = getX(fileName);
    y = getY(fileName);
  }
  else if(inputA == "random")
  {
    cout << "What would you like the width (number of columns) of the grid to be." << endl;
    int inputX;
    cin >> inputX;
    cout << endl;

    x = inputX;

    cout << "What would you like the height (number of rows) of the grid to be." << endl;
    int inputY;
    cin >> inputY;
    cout << endl;

    y = inputY;
  }
  else
  {
    cout << "User input for the question was not either 'provide' or 'random'. Exiting program." << endl;
    exit(1);
  }

  // now that we have x and y we can initialize our arrays
  int firstGen[x*y];
  int currentGen[x*y];
  int nextGen[x*y];
  int previousGen[x*y]; // for determining when the simulation loops

  // Establish first generation based on input
  if(inputA == "provide")
  {
    convert(fileName, firstGen, x, y);
    for(int i = 0; i < x*y; i++)
    {
      currentGen[i] = firstGen[i];
    }
  }
  else if(inputA == "random")
  {
    double d;
    cout << "What would you like the population density per box to be (a number 0 < n <= 1)." << endl;
    cin >> d;
    cout << endl;

    generateFirstGen(d, firstGen, x, y);

    for(int i = 0; i < x*y; i++)
    {
      currentGen[i] = firstGen[i];
    }
  }

  ////////// Run simulation ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  cout << "The simulation will stop when the grid is empty or stablized." << endl;
  cout << endl;

  bool loops = false;
  int generationNumber = 0;

  for(int i = 0; i < x*y; i++)
  {
    previousGen[i] = currentGen[i];
  }

  if(inputC == "pause")
  {
    if(inputB == "classic")
    {
      while(!loops)
      {
        cout << "Generation " << generationNumber << endl;
        cout << endl;
        generationNumber++;

        printGen(currentGen, x, y);
        cout << endl;

        classic(currentGen, nextGen, x, y);

        if(generationNumber > 0)
        {
          // after generation 0, if the previous generation = the next one, it loops
          loops = true;
          for(int i = 0; i < x*y; i++)
          {
            if(previousGen[i] != nextGen[i])
              loops = false;
          }

          // set previous gen to current gen
          for(int i = 0; i < x*y; i++)
          {
            previousGen[i] = currentGen[i];
          }
        }

        // set current gen to next gen
        for(int i = 0; i < x*y; i++)
        {
          currentGen[i] = nextGen[i];
        }

        sleep(1); // one second pause
      }
    }
    else if(inputB == "doughnut")
    {
      while(!loops)
      {
        cout << "Generation " << generationNumber << endl;
        cout << endl;
        generationNumber++;

        printGen(currentGen, x, y);
        cout << endl;

        doughnut(currentGen, nextGen, x, y);

        if(generationNumber > 0)
        {
          // after generation 0, if the previous generation = the next one, it loops
          loops = true;
          for(int i = 0; i < x*y; i++)
          {
            if(previousGen[i] != nextGen[i])
              loops = false;
          }

          // set previous gen to current gen
          for(int i = 0; i < x*y; i++)
          {
            previousGen[i] = currentGen[i];
          }
        }

        // set current gen to next gen
        for(int i = 0; i < x*y; i++)
        {
          currentGen[i] = nextGen[i];
        }

        sleep(1); // one second pause
      }
    }
    else if(inputB == "mirror")
    {
      while(!loops)
      {
        cout << "Generation " << generationNumber << endl;
        cout << endl;
        generationNumber++;

        printGen(currentGen, x, y);
        cout << endl;

        mirror(currentGen, nextGen, x, y);

        if(generationNumber > 0)
        {
          // after generation 0, if the previous generation = the next one, it loops
          loops = true;
          for(int i = 0; i < x*y; i++)
          {
            if(previousGen[i] != nextGen[i])
              loops = false;
          }

          // set previous gen to current gen
          for(int i = 0; i < x*y; i++)
          {
            previousGen[i] = currentGen[i];
          }
        }

        // set current gen to next gen
        for(int i = 0; i < x*y; i++)
        {
          currentGen[i] = nextGen[i];
        }

        sleep(1); // one second pause
      }
    }
    else
    {
      cout << "User input for the question was not either 'classic', 'doughnut', or 'mirror'. Exiting program." << endl;
      exit(1);
    }
  }

  else if(inputC == "enter")
  {
    if(inputB == "classic")
    {
      while(true)
      {
        if(cin.get() == '\n')
        {
          cout << "Generation " << generationNumber << endl;
          cout << endl;
          generationNumber++;

          printGen(currentGen, x, y);
          cout << endl;

          classic(currentGen, nextGen, x, y);

          if(generationNumber > 0)
          {
            // after generation 0, if the previous generation = the next one, it loops
            loops = true;
            for(int i = 0; i < x*y; i++)
            {
              if(previousGen[i] != nextGen[i])
                loops = false;
            }

            if(loops)
              break;

            // set previous gen to current gen
            for(int i = 0; i < x*y; i++)
            {
              previousGen[i] = currentGen[i];
            }
          }

          // set current gen to next gen
          for(int i = 0; i < x*y; i++)
          {
            currentGen[i] = nextGen[i];
          }
          continue;
        }
      }
    }
    else if(inputB == "doughnut")
    {
      while(true)
      {
        if(cin.get() == '\n')
        {
          cout << "Generation " << generationNumber << endl;
          cout << endl;
          generationNumber++;

          printGen(currentGen, x, y);
          cout << endl;

          doughnut(currentGen, nextGen, x, y);

          if(generationNumber > 0)
          {
            // after generation 0, if the previous generation = the next one, it loops
            loops = true;
            for(int i = 0; i < x*y; i++)
            {
              if(previousGen[i] != nextGen[i])
                loops = false;
            }

            if(loops)
              break;

            // set previous gen to current gen
            for(int i = 0; i < x*y; i++)
            {
              previousGen[i] = currentGen[i];
            }
          }

          // set current gen to next gen
          for(int i = 0; i < x*y; i++)
          {
            currentGen[i] = nextGen[i];
          }
          continue;
        }
      }
    }
    else if(inputB == "mirror")
    {
      while(true)
      {
        if(cin.get() == '\n')
        {
          cout << "Generation " << generationNumber << endl;
          cout << endl;
          generationNumber++;

          printGen(currentGen, x, y);
          cout << endl;

          mirror(currentGen, nextGen, x, y);

          if(generationNumber > 0)
          {
            // after generation 0, if the previous generation = the next one, it loops
            loops = true;
            for(int i = 0; i < x*y; i++)
            {
              if(previousGen[i] != nextGen[i])
                loops = false;
            }

            if(loops)
              break;

            // set previous gen to current gen
            for(int i = 0; i < x*y; i++)
            {
              previousGen[i] = currentGen[i];
            }
          }

          // set current gen to next gen
          for(int i = 0; i < x*y; i++)
          {
            currentGen[i] = nextGen[i];
          }
          continue;
        }
      }
    }
    else
    {
      cout << "User input for the question was not either 'classic', 'doughnut', or 'mirror'. Exiting program." << endl;
      exit(1);
    }
  }

  else if(inputC == "file")
  {
    cout << "Please enter the name of the file that you would like the results to go to." << endl;
    cin >> fileName;
    cout << endl;

    if(inputB == "classic")
    {
      while(!loops)
      {
        writeGen(fileName, currentGen, x, y, generationNumber);

        generationNumber++;

        classic(currentGen, nextGen, x, y);

        if(generationNumber > 0)
        {
          // after generation 0, if the previous generation = the next one, it loops
          loops = true;
          for(int i = 0; i < x*y; i++)
          {
            if(previousGen[i] != nextGen[i])
              loops = false;
          }

          // set previous gen to current gen
          for(int i = 0; i < x*y; i++)
          {
            previousGen[i] = currentGen[i];
          }
        }

        // set current gen to next gen
        for(int i = 0; i < x*y; i++)
        {
          currentGen[i] = nextGen[i];
        }
      }
    }
    else if(inputB == "doughnut")
    {
      while(!loops)
      {
        writeGen(fileName, currentGen, x, y, generationNumber);

        generationNumber++;

        doughnut(currentGen, nextGen, x, y);

        if(generationNumber > 0)
        {
          // after generation 0, if the previous generation = the next one, it loops
          loops = true;
          for(int i = 0; i < x*y; i++)
          {
            if(previousGen[i] != nextGen[i])
              loops = false;
          }

          // set previous gen to current gen
          for(int i = 0; i < x*y; i++)
          {
            previousGen[i] = currentGen[i];
          }
        }

        // set current gen to next gen
        for(int i = 0; i < x*y; i++)
        {
          currentGen[i] = nextGen[i];
        }
      }
    }
    else if(inputB == "mirror")
    {
      while(!loops)
      {
        writeGen(fileName, currentGen, x, y, generationNumber);

        generationNumber++;

        mirror(currentGen, nextGen, x, y);

        if(generationNumber > 0)
        {
          // after generation 0, if the previous generation = the next one, it loops
          loops = true;
          for(int i = 0; i < x*y; i++)
          {
            if(previousGen[i] != nextGen[i])
              loops = false;
          }

          // set previous gen to current gen
          for(int i = 0; i < x*y; i++)
          {
            previousGen[i] = currentGen[i];
          }
        }

        // set current gen to next gen
        for(int i = 0; i < x*y; i++)
        {
          currentGen[i] = nextGen[i];
        }
      }
    }
    else
    {
      cout << "User input for the question was not either 'classic', 'doughnut', or 'mirror'. Exiting program." << endl;
      exit(1);
    }
  }

  else
  {
    cout << "User input for the question was not either 'pause', 'enter', or 'file'. Exiting program." << endl;
    exit(1);
  }



}

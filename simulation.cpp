#include <iostream> //preprocessor directive

using namespace std;

void classic(int currentGen[], int nextGen[], int x, int y)
{
  // Funtion that takes in the previous generation and its dimentions and outputs the next generation in classic mode

  int neighbors = 0;

  for(int i = 0; i < x*y; i++)
  {
    neighbors = 0;

    if(i == 0)
    {
      // determines what will happen with the top left corner
      if((currentGen[1] + currentGen[x] + currentGen[x+1]) == 3)
      {
        nextGen[0] = 1;
      }
      else if((currentGen[1] + currentGen[x] + currentGen[x+1]) == 2)
      {
        nextGen[0] = currentGen[0];
      }
      else
      {
        nextGen[0] = 0;
      }
    }

    if(i == x-1)
    {
      // determines what will happen with the top right corner
      if((currentGen[x-2] + currentGen[2*x-2] + currentGen[2*x-1]) == 3)
      {
        nextGen[x-1] = 1;
      }
      else if((currentGen[x-2] + currentGen[2*x-2] + currentGen[2*x-1]) == 2)
      {
        nextGen[x-1] = currentGen[x-1];
      }
      else
      {
        nextGen[x-1] = 0;
      }
    }

    else if(i == x*y-x)
    {
      // determines what will happen with the bottom left corner
      if((currentGen[x*(y-2)] + currentGen[x*(y-2)+1] + currentGen[x*(y-1)]) == 3)
      {
        nextGen[x*y-x] = 1;
      }
      else if((currentGen[x*(y-2)+1] + currentGen[x*(y-2)] + currentGen[x*(y-1)]) == 2)
      {
        nextGen[x*y-x] = currentGen[x*y-x];
      }
      else
      {
        nextGen[x*y-x] = 0;
      }
    }

    else if(i == x*y-1)
    {
      // determines what will happen with the bottom right corner
      if((currentGen[x*y-2] + currentGen[x*(y-1)-1] + currentGen[x*(y-1)-2]) == 3)
      {
        nextGen[x*y-1] = 1;
      }
      else if((currentGen[x*y-2] + currentGen[x*(y-1)-1] + currentGen[x*(y-1)-2]) == 2)
      {
        nextGen[x*y-1] = currentGen[x*y-1];
      }
      else
      {
        nextGen[x*y-1] = 0;
      }
    }

    else
    {
      // if not a corner

      if((i - x) < 0)
      {
        // if in the top row
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i-1];
        neighbors += currentGen[i+1];
      }

      else if((i + x) > x*y)
      {
        // if in the bottom row
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-1];
        neighbors += currentGen[i+1];
      }

      else if(i % x == 0)
      {
        // if in the left column
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i+1];
      }

      else if((i+1) % x == 0)
      {
        // if in the right column
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i-1];
      }

      else
      {
        // if in the middle of the grid
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+1];
        neighbors += currentGen[i-1];
      }

      // determine what will happen with the square
      if(neighbors >= 4)
      {
        nextGen[i] = 0;
      }
      else if(neighbors == 3)
      {
        nextGen[i] = 1;
      }
      else if(neighbors == 2)
      {
        nextGen[i] = currentGen[i];
      }
      else
      {
        nextGen[i] = 0;
      }
    }
  }
}

void doughnut(int currentGen[], int nextGen[], int x, int y)
{
  // Funtion that takes in the previous generation and its dimentions and outputs the next generation in doughnut mode

  int neighbors = 0;

  for(int i = 0; i < x*y; i++)
  {
    neighbors = 0;

    if(i == 0)
    {
      // determines what will happen with the top left corner
      if((currentGen[1] + currentGen[x] + currentGen[x+1])/* actually adjacent boxes */ + (currentGen[x*y-1])/* opposite corner */ + (currentGen[x*(y-1)] + currentGen[x*(y-1)+1])/* boxes wrapped from bottom left */ + (currentGen[x-1] + currentGen[2*x-1])/* boxes wrapped from top right */ == 3)
      {
        nextGen[0] = 1;
      }
      else if((currentGen[1] + currentGen[x] + currentGen[x+1])/* actually adjacent boxes */ + (currentGen[x*y-1])/* opposite corner */ + (currentGen[x*(y-1)] + currentGen[x*(y-1)+1])/* boxes wrapped from bottom left */ + (currentGen[x-1] + currentGen[2*x-1])/* boxes wrapped from top right */ == 2)
      {
        nextGen[0] = currentGen[0];
      }
      else
      {
        nextGen[0] = 0;
      }
    }

    else if(i == x-1)
    {
      // determines what will happen with the top right corner
      if((currentGen[x-2] + currentGen[2*x-1] + currentGen[2*x-2])/* actually adjacent boxes */ + (currentGen[x*y-x])/* opposite corner */ + (currentGen[x*y-1] + currentGen[x*y-2])/* boxes wrapped from bottom right */ + (currentGen[0] + currentGen[x])/* boxes wrapped from top left */ == 3)
      {
        nextGen[x-1] = 1;
      }
      else if((currentGen[x-2] + currentGen[2*x-1] + currentGen[2*x-2])/* actually adjacent boxes */ + (currentGen[x*y-x])/* opposite corner */ + (currentGen[x*y-1] + currentGen[x*y-2])/* boxes wrapped from bottom right */ + (currentGen[0] + currentGen[x])/* boxes wrapped from top left */ == 2)
      {
        nextGen[x-1] = currentGen[x-1];
      }
      else
      {
        nextGen[x-1] = 0;
      }
    }

    else if(i == x*y-x)
    {
      // determines what will happen with the bottom left corner
      if((currentGen[x*(y-2)] + currentGen[x*(y-2)+1] + currentGen[x*y-x+1])/* actually adjacent boxes */ + (currentGen[x-1])/* opposite corner */ + (currentGen[0] + currentGen[1])/* boxes wrapped from top left */ + (currentGen[x*y-1] + currentGen[x*y-x-1])/* boxes wrapped from bottom right */ == 3)
      {
        nextGen[x*y-x] = 1;
      }
      else if((currentGen[x*(y-2)] + currentGen[x*(y-2)+1] + currentGen[x*y-x+1])/* actually adjacent boxes */ + (currentGen[x-1])/* opposite corner */ + (currentGen[0] + currentGen[1])/* boxes wrapped from top left */ + (currentGen[x*y-1] + currentGen[x*y-x-1])/* boxes wrapped from bottom right */ == 2)
      {
        nextGen[x*y-x] = currentGen[x*y-x];
      }
      else
      {
        nextGen[x*y-x] = 0;
      }
    }

    else if(i == x*y-1)
    {
      // determines what will happen with the bottom right corner
      if((currentGen[x*y-2] + currentGen[x*y-x-1] + currentGen[x*y-x-2])/* actually adjacent boxes */ + (currentGen[0])/* opposite corner */ + (currentGen[x-1] + currentGen[x-2])/* boxes wrapped from top right */ + (currentGen[x*y-x] + currentGen[x*(y-2)])/* boxes wrapped from bottom left */ == 3)
      {
        nextGen[x*y-1] = 1;
      }
      else if((currentGen[x*y-2] + currentGen[x*y-x-1] + currentGen[x*y-x-2])/* actually adjacent boxes */ + (currentGen[0])/* opposite corner */ + (currentGen[x-1] + currentGen[x-2])/* boxes wrapped from top right */ + (currentGen[x*y-x] + currentGen[x*(y-2)])/* boxes wrapped from bottom left */ == 2)
      {
        nextGen[x*y-1] = currentGen[x*y-1];
      }
      else
      {
        nextGen[x*y-1] = 0;
      }
    }

    else
    {
      // if not a corner

      if((i - x) < 0)
      {
        // if in the top row
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i-1];
        neighbors += currentGen[i+1];
        //wrapped from bottom
        neighbors += currentGen[x*y-x+i];
        neighbors += currentGen[x*y-x+i-1];
        neighbors += currentGen[x*y-x+i+1];
      }

      else if((i + x) > x*y)
      {
        // if in the bottom row
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-1];
        neighbors += currentGen[i+1];
        //wrapped from top
        neighbors += currentGen[i%x];
        neighbors += currentGen[(i%x)+1];
        neighbors += currentGen[(i%x)-1];
      }

      else if(i % x == 0)
      {
        // if in the left column
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i+1];
        //wrapped from right column
        neighbors += currentGen[i-1];
        neighbors += currentGen[i-1+x];
        neighbors += currentGen[i-1+2*x];
      }

      else if((i+1) % x == 0)
      {
        // if in the right column
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i-1];
        //wrapped from left column
        neighbors += currentGen[i+1];
        neighbors += currentGen[i+1-x];
        neighbors += currentGen[i+1-2*x];
      }

      else
      {
        // if in the middle of the grid
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+1];
        neighbors += currentGen[i-1];
      }

      // determine what will happen with the square
      if(neighbors >= 4)
      {
        nextGen[i] = 0;
      }
      else if(neighbors == 3)
      {
        nextGen[i] = 1;
      }
      else if(neighbors == 2)
      {
        nextGen[i] = currentGen[i];
      }
      else
      {
        nextGen[i] = 0;
      }
    }
  }
}

void mirror(int currentGen[], int nextGen[], int x, int y)
{
  // Funtion that takes in the previous generation and its dimentions and outputs the next generation in mirror mode

  int neighbors = 0;

  for(int i = 0; i < x*y; i++)
  {
    neighbors = 0;

    if(i == 0)
    {
      // determines what will happen with the top left corner
      if((currentGen[1] + currentGen[x] + currentGen[x+1])/* actually adjacent boxes */ + (3*currentGen[0] + currentGen[1] + currentGen[x])/* reflections */ == 3)
      {
        nextGen[0] = 1;
      }
      else if((currentGen[1] + currentGen[x] + currentGen[x+1])/* actually adjacent boxes */ + (3*currentGen[0] + currentGen[1] + currentGen[x])/* reflections */ == 2)
      {
        nextGen[0] = currentGen[0];
      }
      else
      {
        nextGen[0] = 0;
      }
    }

    if(i == x-1)
    {
      // determines what will happen with the top right corner
      if((currentGen[x-2] + currentGen[2*x-2] + currentGen[2*x-1])/* actually adjacent boxes */ + (3*currentGen[x-1] + currentGen[x-2] + currentGen[2*x-1])/* reflections */ == 3)
      {
        nextGen[x-1] = 1;
      }
      else if((currentGen[x-2] + currentGen[2*x-2] + currentGen[2*x-1])/* actually adjacent boxes */ + (3*currentGen[x-1] + currentGen[x-2] + currentGen[2*x-1])/* reflections */ == 2)
      {
        nextGen[x-1] = currentGen[x-1];
      }
      else
      {
        nextGen[x-1] = 0;
      }
    }

    else if(i == x*y-x)
    {
      // determines what will happen with the bottom left corner
      if((currentGen[x*(y-2)+1] + currentGen[x*(y-2)] + currentGen[x*(y-1)])/* actually adjacent boxes */ + (3*currentGen[x*y-x] + currentGen[x*y-x+1] + currentGen[x*y-2*x])/* reflections */ == 3)
      {
        nextGen[x*y-x] = 1;
      }
      else if((currentGen[x*(y-2)+1] + currentGen[x*(y-2)] + currentGen[x*(y-1)])/* actually adjacent boxes */ + (3*currentGen[x*y-x] + currentGen[x*y-x+1] + currentGen[x*y-2*x])/* reflections */ == 2)
      {
        nextGen[x*y-x] = currentGen[x*y-x];
      }
      else
      {
        nextGen[x*y-x] = 0;
      }
    }

    else if(i == x*y-1)
    {
      // determines what will happen with the bottom right corner
      if((currentGen[x*y-2] + currentGen[x*(y-1)-1] + currentGen[x*(y-1)-2])/* actually adjacent boxes */ + (3*currentGen[x*y-1] + currentGen[x*y-2] + currentGen[x*y-x-1])/* reflections */ == 3)
      {
        nextGen[x*y-1] = 1;
      }
      else if((currentGen[x*y-2] + currentGen[x*(y-1)-1] + currentGen[x*(y-1)-2])/* actually adjacent boxes */ + (3*currentGen[x*y-1] + currentGen[x*y-2] + currentGen[x*y-x-1])/* reflections */ == 2)
      {
        nextGen[x*y-1] = currentGen[x*y-1];
      }
      else
      {
        nextGen[x*y-1] = 0;
      }
    }

    else
    {
      // if not a corner

      if((i - x) < 0)
      {
        // if in the top row
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x];
        neighbors += 2*currentGen[i-1];
        neighbors += 2*currentGen[i+1];
        neighbors += currentGen[i];
      }

      else if((i + x) > x*y)
      {
        // if in the bottom row
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i-x];
        neighbors += 2*currentGen[i-1];
        neighbors += 2*currentGen[i+1];
        neighbors += currentGen[i];
      }

      else if(i % x == 0)
      {
        // if in the left column
        neighbors += 2*currentGen[i-x];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i+x+1];
        neighbors += 2*currentGen[i+x];
        neighbors += currentGen[i+1];
        neighbors += currentGen[i];
      }

      else if((i+1) % x == 0)
      {
        // if in the right column
        neighbors += 2*currentGen[i-x];
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i+x-1];
        neighbors += 2*currentGen[i+x];
        neighbors += currentGen[i-1];
        neighbors += currentGen[i];
      }

      else
      {
        // if in the middle of the grid
        neighbors += currentGen[i-x];
        neighbors += currentGen[i-x-1];
        neighbors += currentGen[i-x+1];
        neighbors += currentGen[i+x];
        neighbors += currentGen[i+x+1];
        neighbors += currentGen[i+x-1];
        neighbors += currentGen[i+1];
        neighbors += currentGen[i-1];
      }

      // determine what will happen with the square
      if(neighbors >= 4)
      {
        nextGen[i] = 0;
      }
      else if(neighbors == 3)
      {
        nextGen[i] = 1;
      }
      else if(neighbors == 2)
      {
        nextGen[i] = currentGen[i];
      }
      else
      {
        nextGen[i] = 0;
      }
    }
  }
}

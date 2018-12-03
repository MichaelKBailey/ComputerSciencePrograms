#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

void setTargets(int* x, int* y, int* targets, int no_targets);
void blinkTargets(int* targets, int* x, int* y, int no_targets);

int main()
{
  //Variable Declaration/Intiialization
  int* x = NULL;
  int* y = NULL;
  int* targets = NULL;
  int no_targets = 0;

  //Display Graphics
  displayGraphics();

  //Prompt user for the number of targets
  cout << "Enter # targets to display: ";
  cin >> no_targets;

  //Dynamically allocate the arrays
  x = new int[no_targets];
  y = new int[no_targets];
  targets = new int[no_targets];

  //Pass the arrays by reference as before
  setTargets(x,y,targets,no_targets);

  //Make the targets blink (red-green/green-red)
  blinkTargets(targets,x,y,no_targets);

  //Cleanup memory
  delete[] x;
  delete[] y;
  delete[] targets;

  return 0;
  
   
}

void setTargets(int* x, int* y, int* targets, int no_targets)
{
  //Variable Declaration/Intitialization
  int i = 0;

  //Initialize random # generator
  srand(time(0));

  //Display the targets
  for (i = 0; i < no_targets; i++)  
  {
    //Set x/y coordinates
    x[i] = (rand()%640)-40;
    y[i] = (rand()%480)-40;

    //Set the image
    if ((i%2) == 0)
      targets[i] = displayBMP("target1.bmp",x[i],y[i]);
    else
      targets[i] = displayBMP("target2.bmp",x[i],y[i]);
  }
}

void blinkTargets(int* targets, int* x, int* y, int no_targets)
{
  //Variable Declaration/Initialization
  int i = 0;
  int j = 0;

  for (i = 0; i < 50; i++)
  {
    for (j = 0 ; j < no_targets; j++)
    {
      if ( (i%2 == 0) && (j%2== 0) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target2.bmp",x[j],y[j]);
      }
      else if ( (i%2 == 0) && (j%2== 1) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target1.bmp",x[j],y[j]);
      }       
     else if ( (i%2 == 1) && (j%2== 0) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target1.bmp",x[j],y[j]);
      }
      else if ( (i%2 == 1) && (j%2== 1) )
      {
        //Remove current target
        removeObject(targets[j]);
      
        //Replace with new target
        targets[j] = displayBMP("target2.bmp",x[j],y[j]);
      }       
    }
  }

}
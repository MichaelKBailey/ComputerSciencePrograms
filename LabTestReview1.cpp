#include <iostream>
#include "graph1.h"

using namespace std;

void getData(int* r, int* g, int* b, int* radius, int* no_circles);
int* drawChain(int radius, int no_circles);
void colorChain(int* objects, int no_circles, int r, int g, int b);


int main()
{
int radius = 0;
int no_circles = 0;
int r = 0;
int g = 0;
int b = 0;
int* objects = NULL;
int x = 100;
int y = 100;
//int* chainsCall = NULL;


//Display graphics
displayGraphics();

getData(&r, &g, &b, &radius, &no_circles);

objects = drawChain(radius, no_circles);

colorChain(objects, no_circles, r, g, b);


//Cleanup memory
delete[] objects;

return 0;
}


void getData(int* r, int* g, int* b, int* radius, int* no_circles)
{

do{
cout << "Please enter the number of circles to display: " << endl;
cin >> *no_circles;
if (*no_circles < 3 || *no_circles > 10)
cout << "\nPlease enter a number between 3 and 10. ";
}while (*no_circles < 3 || *no_circles > 10);

do
{
cout << "Please enter the circles radius: " << endl;
cin >> *radius;
if (*radius < 15 || *radius > 25)
cout << "\nPlease enter a number between 15 and 25. ";
}while (*radius < 15 || *radius > 25);

cout << "Please enter the r, g, and b values for the circles: " << endl;
cin >> *r >> *g >> *b;

}


int* drawChain(int radius, int no_circles)
  {
    //Variable Declaration/Intitialization
    int* x = NULL;
    int* y = NULL;
    int* objects = NULL;
    //Dynamically allocate the arrays
    x = new int[no_circles];
    y = new int[no_circles];
    objects = new int[no_circles];
    //Set the x coord for the targets
    for (int i = 0; i < no_circles; i++)
    {
      //Set x/y coordinates
      x[i] = (100 + (i*radius));
      y[i] = (100);
      objects[i] = drawCircle(radius, x[i], y[i]);
    }
      return objects;
}


void colorChain(int* drawChain, int no_circles, int r, int g, int b)
{
  for (int i = 0; i < no_circles; i++)
  {
    //Set the image
    if ((i % 2) == 0)
    setColor(drawChain[i], r, g, b);
    else
    setColor(drawChain[i], 128, 128, 128);
  }
}


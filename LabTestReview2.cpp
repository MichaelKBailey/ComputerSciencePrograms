#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

void getData(int* no_rects);
int* getXCoords(int no_rects);
int* getYCoords(int no_rects);
void displayRectangles(int no_rects, int* x, int* y);


int main()
{

displayGraphics();

  int no_rects = 0;
  int* x = nullptr;
  int* y = nullptr;
  int* rects = nullptr;


getData(&no_rects);
x = new int[no_rects];
y = new int[no_rects];
x = getXCoords(no_rects);
y = getYCoords(no_rects);
displayRectangles(no_rects, x, y); 

delete[]x;
delete[]y;

return 0;
}


void getData(int* no_rects)
{
cout << "Please enter the number of rectangles to display: " << endl;
cin >> *no_rects;
}

int* getXCoords(int no_rects)
  {

    //Variable Declaration/Intitialization
    int* x = NULL;
    //Dynamically allocate the arrays
    x = new int[no_rects];
    //Set the x coord for the targets
    for (int i = 0; i < no_rects; i++)
    {
     cout << "Please enter the x coordinates for box " << i+1 << endl;
     cin >> x[i];
    }
    return x;
  }

int* getYCoords(int no_rects)
{
  {
    //Variable Declaration/Intitialization
    int* y = NULL;
    //Dynamically allocate the arrays
    y = new int[no_rects];
    //Set the x coord for the targets
    for (int i = 0; i < no_rects; i++)
    {
      cout << "Please enter the y coordinates for box " << i + 1 << endl;
      cin >> y[i];
    }
    return y;
  }
}

void displayRectangles(int no_rects, int* x, int* y)
{
int rectColor = 0;
int r = 0;
int g = 0;
int b = 0;

  for (int i = 0; i < no_rects; i++)
  {
   rectColor = drawRect(x[i],y[i],50, 25);

   if ((i % 2) == 0)
{
     setColor(rectColor, 255, 0, 0);
}
   else
     setColor(rectColor, 0, 0, 255);
}
}
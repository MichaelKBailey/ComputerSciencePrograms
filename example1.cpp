#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

int getNoPoints();
void getPoints(int x[], int y[], int no_points);
void getColor(int& r, int& g, int& b);
void drawPoints(int objects[], int x[], int y[], int no_points);
void colorObjects(int objects[], int r, int g, int b, int no_points);
void getWidthAndHeight(int& width, int& height);
void drawRectangles(int objects[], int x[], int y[], int width, int height, int no_points);


int main()
{
  //Variable Declaration/Initialization
  const int MAX_POINTS = 10;
  int no_points = 0;
  int x[MAX_POINTS];
  int y[MAX_POINTS];
  int objects[MAX_POINTS];
  int r = 0;
  int g = 0;
  int b = 0;
  int width = 0;
  int height = 0;
  int rand_point = 0;

  //Display graphics window
  displayGraphics();

  //1. Prompt for the number of points
  no_points = getNoPoints();

  //2. Prompt for the x/y coordinate for each point
  getPoints(x,y,no_points);

  //3. Prompt for the r/g/b color
  getColor(r,g,b);

  //4. Get the width/height for each rectangle
  getWidthAndHeight(width, height);

  //5. Draw a rectangle at each point
  drawRectangles(objects, x, y, width, height, no_points);

  //6. Color the rectangles
  colorObjects(objects, r, g, b, no_points);

  //Randomly select a point
  srand(time(0));
  rand_point = rand()%no_points;

  //Display smiley face at a point
  displayBMP("smiley1.bmp",320,0);

  //Display a caption (left aligned, 15px beneath the image)
  gout << setPos(320,175) << "Smiley Face" << endg;

  

  return 0;
}

//Function implemementation
int getNoPoints()
{
  //Variable Declaration/Initialization
  int no_points = 0;
  
  //Prompt for the number of points to process
  cout << "Enter number of points to process: ";
  cin >> no_points;

  return(no_points);
}

void getPoints(int x[], int y[], int no_points)
{
  //Variable Declaration/Initialization
  int i = 0;

  //Prompt the user for x/y coords of each point
  for (i = 0; i < no_points; i++)
  {
    cout << "Enter the x/y coordinate of point #" << (i + 1) << ": ";
    cin >> x[i] >> y[i];
  }
}

void getColor(int& r, int& g, int& b)
{
  //Prompt for the r/g/b color
  cout << "Enter r/g/b color (Example: 218 192 83): ";
  cin >> r >> g >> b;
}

void drawPoints(int objects[], int x[], int y[], int no_points)
{
  //Variable Declaration/Initialization
  int i = 0;

  //Draw all points
  //Store their object number in an array for later processing
  for (i = 0; i < no_points; i++)
  {
    objects[i] = drawPoint(x[i],y[i]);
  }
}

void colorObjects(int objects[], int r, int g, int b, int no_points)
{
  //Variable Declaration/Initialization
  int i = 0;

  //Color any objects to the desired r/g/b color
  for (i = 0; i < no_points; i++)
  {
    setColor(objects[i],r,g,b);
  }
}

void getWidthAndHeight(int& width, int& height)
{
  //Get the width/height of the rectangle
  cout << "Enter width/height: ";
  cin >> width >> height;
}

void drawRectangles(int objects[], int x[], int y[], int width, int height, int no_points)
{
  //Variable Declaration/Initialization
  int i = 0;

  //Draw all rectangles
  for (i = 0; i < no_points; i++)
  {
    //Store all object numbers in an array
    objects[i] = drawRect(x[i],y[i],width,height);
  }
}





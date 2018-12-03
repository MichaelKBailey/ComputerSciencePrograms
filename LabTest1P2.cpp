/*
Michael Bailey
Assignment: LabTest1
This program will draw a poly-line 
*/

#include <iostream>
#include "graph1.h"

using namespace std;

void getData(int* no_points, int* x, int* y, int*r, int* g, int* b);
int* drawPolyLine(int *x, int *y, int no_points);
void colorPolyLine(int* objects, int no_points, int r, int g, int b);



int main()
{
  const int max_elements = 10;
  int x[max_elements];
  int y[max_elements];
  char repeat = 'y';
  int no_points = 0;
  int* objects = NULL;
  int r = 0;
  int g = 0;
  int b = 0;

  displayGraphics();
  do
  {

getData(&no_points, x, y, &r, &g, &b);
objects = drawPolyLine(x, y, no_points);
colorPolyLine(objects, no_points, r, g, b);

    cout << "Repeat this program?";
    cin >> repeat;
    clearGraphics();
    system("cls");
  } while ((repeat == 'y') || (repeat == 'Y'));

delete[] objects;

  return 0;
}


void getData(int* no_points, int* x, int* y, int*r, int* g, int* b)
{
  int i = 0;
  int j = 0;
do{
  cout << "Please enter the number of points: ";
  cin >> *no_points;
  if (*no_points < 3 || *no_points > 10)
    cout << "\nPlease enter a number between 3 and 10. ";
}while (*no_points < 3 || *no_points > 10);

  do {
    cout << "Please enter the x/y coordinates for the #" << i + 1 << " point: ";
    cin >> x[i] >> y[i];
    i++;
  } while (i < *no_points);

  do {
  cout << "Please enter the r, g, and b values for each line segment #" << j + 1 << endl;
  cin >> r[j] >> g[j] >> b[j];
j++;
}while (j < *no_points);
}


int* drawPolyLine(int *x, int *y, int no_points)
{
  x = new int[no_points];
  y = new int[no_points];
  int* objects = NULL;
  objects = new int[no_points];
  for (int i = 0; i < no_points; i++)
    {
    objects[i] = drawLine(x[i], y[i], x[i + 1], y[i + 1], 1);
    }
  return objects;
}


void colorPolyLine(int* objects, int no_points, int r, int g, int b)
{
  for (int i = 0; i < no_points; i++)
  {
      setColor(objects[i], r, g, b);
  }
}
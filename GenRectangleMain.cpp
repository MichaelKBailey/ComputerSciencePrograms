/*
Michael Bailey - Lab Test Actual
*/

#include <iostream>
#include "graph1.h"
#include "GenRectangle.h"
#include <cstring>
#include <cstdlib>
#include <cmath>


using namespace std;


int main()
{
GenRectangle rect1;
GenRectangle rect2;

displayGraphics();

int x = 0;
int y = 0;
int width = 0;
int height = 0; 
int area = 0;
int perimeter = 0;

area = width * height;
perimeter = (width*2)+(height*2);
rect1.draw2();

gout << setPos(rect1.getX(), rect1.getY() + (rect1.getHeight()+15)) << "rect1" << endg;
gout << setPos(rect1.getX(), rect1.getY() + (rect1.getHeight()+30)) << "Area: " << rect1.getArea() << endg;
gout << setPos(rect1.getX(), rect1.getY() + (rect1.getHeight()+45)) << "Perimeter: " << rect1.getPerimeter() << endg;
gout << setPos(rect1.getX(), rect1.getY() + (rect1.getHeight()+60)) << "Type: " << rect1.getType() << endg;

/////////////////////////////////////////////////////////////////////

cout << "Please enter a second set of X/Y coordinates: ";
cin >> x >> y;
//\\//\\//\\//\\//\\//
rect2.getX();
if (x > 539)
{
  x = 539;
}
else if (x < 100)
{
  x = 100;
}
else
{
x = x; 
}
//\\//\\//\\//\\//\\//
rect2.getY();
if
(y > 455)
{
  y = 455;
}
else if (y < 25)
{
  y = 25;
}
else
{
  y = y;
}
//\\//\\//\\//\\//\\//
cout << "Please enter in a width: ";
cin >> width;
//\\//\\//\\//\\//\\//
rect2.getWidth();

if (width > 50)
{
  width = 50;
}
else if (width < 1)
{
  width = 1;
}
else
{
  width = width;
}
//\\//\\//\\//\\//\\//
cout << "Please enter in a height: ";
cin >> height;
//\\//\\//\\//\\//\\//
rect2.getHeight();
if (height > 50)
{
  height = 50;
}
else if (height < 1)
{
  height = 1;
}
else
{
  height = height;
}
//\\//\\//\\//\\//\\//

rect2.setX(x);
rect2.setY(y);
rect2.setWidth(width);
rect2.setHeight(height);

area = width * height;
perimeter = (width * 2) + (height * 2);

rect2.draw();

gout << setPos(rect2.getX(), rect2.getY() + (rect2.getHeight() + 15)) << "rect2" <<  endg;
gout << setPos(rect2.getX(), rect2.getY() + (rect2.getHeight() + 30)) << "Area: " << rect2.getArea() << endg;
gout << setPos(rect2.getX(), rect2.getY() + (rect2.getHeight() + 45)) << "Perimeter: " << rect2.getPerimeter() << endg;
gout << setPos(rect2.getX(), rect2.getY() + (rect2.getHeight() + 60)) << "Type: " << rect2.getType() << endg;


return 0;
}
/*
Michael Bailey - Lab test Practice
*/

#include <iostream>
#include "graph1.h"
#include "MasterHeader.h"
#include <cstring>
#include <cstdlib>
#include <cmath>


using namespace std;




int main()
{

Circle cir1;
Circle cir2;

displayGraphics();

int x = 0;
int y = 0;
int radius = 0;
int area = 0;
int perimeter = 0;

area = PI * radius * radius;
perimeter = PI * radius *2; 
cir1.draw();
gout << setPos(cir1.getX(), cir1.getY() + cir1.getRadius() + 20) << "The Area: " << cir1.getArea() << endg;
gout << setPos(cir1.getX(), cir1.getY() + cir1.getRadius() + 40) << "The Perimeter: " << cir1.getPerimeter() << endg;
gout << setPos(cir1.getX(), cir1.getY() + cir1.getRadius() + 60) << "Your Circle is: " << cir1.getType() << endg;

/////////////////////////////////////////////////////////////////////

cout << "Please enter a second set of X/Y coordinates: ";
cin >> x >> y;
cir2.getX();
cir2.getY();

if (x > 639 || x < 0 || y > 479 || y < 0)
{
  cout << "Please re-enter your coordinates. " << endl;
}

cout << "Please enter in a radius: ";
cin >> radius;
cir2.getRadius();
if (radius > 20 || radius < 1)
{
  cout << "Please re-enter a value greater than 1 but less than 20" << endl;
}

cir2.setX(x);
cir2.setY(y);
cir2.setRadius(radius);

area = PI * radius * radius;
perimeter = PI * radius * 2;
cir2.draw();
gout << setPos(cir2.getX(), cir2.getY() + cir2.getRadius() + 20) << "The Area: " << cir2.getArea() << endg;
gout << setPos(cir2.getX(), cir2.getY() + cir2.getRadius() + 40) << "The Perimeter: " << cir2.getPerimeter() << endg;
gout << setPos(cir2.getX(), cir2.getY() + cir2.getRadius() + 60) << "Your Circle is: " << cir2.getType() << endg;


return 0;
}
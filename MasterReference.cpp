/*
Michael Bailey - Lab test Practice
*/

#include <iostream>
#include "graph1.h"
#include "MasterHeader.h"
#include <cstring>
#include <cstdlib>


using namespace std;



Circle::Circle()
{
x = 50;
y = 50;
radius = 5;
}

void Circle::setX(int x)
{
this->x = x;
}

void Circle::setY(int y)
{
this->y = y;
}

void Circle::setRadius(int radius)
{
this->radius = radius;
}

string Circle::getType()
{
string type = ""; 
int area = 0;
area = PI * radius * radius;
if (area <= 100)
{
 type = "SMALL CIRCLE";
return type;
}
else if (area > 100 && area <= 300)
{
  type = "MEDIUM CIRCLE";
  return type;
}
else
{
  type = "LARGE CIRCLE";
  return type;
}
}

void Circle::draw()
{
drawCircle(getRadius(), getX(), getY());
}
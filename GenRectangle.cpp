/*
Michael Bailey - Lab Test Actual
*/

#include <iostream>
#include "graph1.h"
#include "GenRectangle.h"
#include <cstring>
#include <cstdlib>


using namespace std;

GenRectangle::GenRectangle()
{
x = 100;
y = 25;
width = 20;
height = 30;
}
void GenRectangle::setWidth(int width)
{
this-> width = width;
}
void GenRectangle::setHeight(int height)
{
this-> height = height;
}
void GenRectangle::setX(int x)
{
this-> x = x; 
}
void GenRectangle::setY(int y)
{
this-> y = y;
}
string GenRectangle::getType()
{
  string type = "";
  int area = 0;
  area = width*height;
  if (area <= 300)
  {
    type = "SMALL RECTANGLE";
    return type;
  }
  else if (area > 300 && area <= 1000)
  {
    type = "MEDIUM RECTANGLE";
    return type;
  }
  else
  {
    type = "LARGE RECTANGLE";
    return type;
  }
}

void GenRectangle::draw()
{
int boxColor = 0;
int boxColor2 = 0;
  if (getType() == "SMALL RECTANGLE")
  {
   boxColor = drawRect(getX(), getY(), getWidth(), getHeight());
    setColor(boxColor, 255, 0, 0);
    boxColor2 = drawRect(getX() + 1, getY() + 1, getWidth() - 2, getHeight() - 2);
    setColor(boxColor2, 0, 0, 0);
  }
  else if (getType() == "MEDIUM RECTANGLE")
  {
    boxColor = drawRect(getX(), getY(), getWidth(), getHeight());
    setColor(boxColor, 0, 255, 0);
    boxColor2 = drawRect(getX() + 1, getY() + 1, getWidth() - 2, getHeight() - 2);
    setColor(boxColor2, 0, 0, 0);
  }
  else if (getType() == "LARGE RECTANGLE")
  {
    boxColor = drawRect(getX(), getY(), getWidth(), getHeight());
    setColor(boxColor,0, 0, 255);
    boxColor2 = drawRect(getX() + 1, getY() + 1, getWidth() - 2, getHeight() - 2);
    setColor(boxColor2, 0, 0, 0);
  }
}
void GenRectangle::draw2()
{
int boxColor = 0;
  drawRect(getX(), getY(), getWidth(), getHeight());
 boxColor = drawRect(getX() + 1, getY() + 1, getWidth() - 2, getHeight() - 2);
setColor(boxColor,0,0,0);
}

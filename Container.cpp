#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"

Container::Container()
{
pos.setPoint(0,0);
color.setColor(0,0,0);
int radius = 0;
int height = 0;
}

void Container::setPosition(GenPoint pos)
{
this->pos = pos;
}

void Container::setRadius(int radius)
{
this->radius = radius;
}

void Container::setHeight(int height)
{
this ->height = height;
}

void Container::setColor(Color color)
{
this ->color = color;
}

GenPoint Container::getPosition()
{
return pos; 
}

int Container::getRadius()
{
return radius;
}

int Container::getHeight()
{
return height;
}

Color Container::getColor()
{
return color;
}

void Container::draw()
{
drawLine(pos.getX(),pos.getY(),pos.getX(),pos.getY() + height, 5);
drawLine(pos.getX(), pos.getY() + height, pos.getX() + radius *2, pos.getY() + height, 5);
drawLine(pos.getX() + radius * 2, pos.getY() + height, pos.getX() + radius * 2, pos.getY(), 5);
}


#include <iostream>
#include <cmath>
#include "graph1.h"
#include "GenLine.h"



GenLine::GenLine()
{
  p1.setPoint(0,0);
  p2.setPoint(0,0);
  desc = "";
 
}





void GenLine::setDesc(string desc)
{
  this->desc = desc;
  
}

string GenLine::getDesc()
{
 

  return(desc);
}





void GenLine::setLine(GenPoint p1, GenPoint p2)
{
  //Set the point
  this->p1.setPoint(p1.getX(), p1.getY());
  this->p2.setPoint(p2.getX(), p2.getY());

}  
  
GenPoint GenLine::getPoint1()
{
  return(p1);
}

GenPoint GenLine::getPoint2()
{
  return(p2);
}

double GenLine::getLength()
{
  double distance = sqrt( pow( (double)p1.getX() - (double)p2.getX(),2.0) + pow((double)p1.getY()-(double)p2.getY(),2.0));
  return(distance);
}

void GenLine::draw()
{
  //draw the line
  int obj_no = drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(), 1);


  //Draw purple circles at end points
  obj_no = drawCircle(5,p1.getX(),p1.getY());
  setColor(obj_no,255,0,255);

 //Draw purple circles at end points
  obj_no = drawCircle(5,p2.getX(),p2.getY());
  setColor(obj_no,255,0,255);

  //Draw purple circle at midpint
  GenPoint mid = getMidPoint();
  obj_no = drawCircle(5,mid.getX(), mid.getY());
  setColor(obj_no,255,0,255);

}

GenPoint GenLine::getMidPoint()
{
  GenPoint mid;
  GenPoint p1 = this->getPoint1();
  GenPoint p2 = this->getPoint2();
  
  mid.setPoint( (p1.getX() + p2.getX())/2.0,(p1.getY() + p2.getY())/2.0);
  return(mid);
}




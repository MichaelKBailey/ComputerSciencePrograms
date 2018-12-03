#ifndef GENLINE_H
#define GENLINE_H
#include "GenPoint.h"


class GenLine
{
  private:
    GenPoint p1;
    GenPoint p2;
    string desc;
   
    
  public:
    GenLine();
    void setLine(GenPoint p1, GenPoint p2);
    void setDesc(string desc);
    string getDesc();
    GenPoint getPoint1();
    GenPoint getPoint2();
    GenPoint getMidPoint();
    double getLength();
    void draw();
};

#endif
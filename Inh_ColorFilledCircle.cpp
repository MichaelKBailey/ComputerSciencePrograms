#include <iostream>
#include "graph1.h"
#include "ColorFilledCircle.h"

ColorFilledCircle::ColorFilledCircle()
{
}



ColorFilledCircle::~ColorFilledCircle()
{
  //Nothing to cleanup yet
}

void ColorFilledCircle::draw()
{
  int i = 0;
  int obj_no = 0;

  for (i = 0; i < radius; i++)
  {
    obj_no = drawCircle(i,x,y);
    setColor(obj_no,r,g,b);
  }
}

void ColorFilledCircle::print()
{
  ColorCircle::print();
  gout << setPos(x-radius,y) << "Filled  Circle" << endg;
}

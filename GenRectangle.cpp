#include "Quadrilateral.h"
#include <cmath>
#include "graph1.h"
#include "GenRectangle.h"



GenRectangle::GenRectangle()
{

}

void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{

  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;

  if (this->a.getX() > 639)
    a.setPoint(639, a.getY());
  if (this->a.getX() < 0)
    a.setPoint(0, a.getY());

  if (this->b.getX() > 639)
    b.setPoint(639, b.getY());
  if (this->b.getX() < 0)
    b.setPoint(0, b.getY());

  if (this->c.getX() > 639)
    c.setPoint(639, c.getY());
  if (this->c.getX() < 0)
    c.setPoint(0, c.getY());

  if (this->d.getX() > 639)
    d.setPoint(639, d.getY());
  if (this->d.getX() < 0)
    d.setPoint(0, d.getY());

}
double GenRectangle::getArea()
{
  double width = 0.0;
  double height = 0.0;
  double area = 0.0;

  width += sqrt(pow(a.getX() - b.getX(), 2.0) + pow(a.getY() - b.getY(), 2.0));
  height += sqrt(pow(b.getX() - c.getX(), 2.0) + pow(b.getY() - c.getY(), 2.0));
  area = width * height;
  return area;
}
void GenRectangle::print()
{
  gout << setPos(0, 400) << "------------------------------- " << endg;
  gout << setPos(200, 405) << "Shape info follows for quadrilateral" << endg;
  gout << setPos(200, 420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
  gout << setPos(200, 420) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
  gout << setPos(200, 420) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
  gout << setPos(200, 420) << "Point d: (" << d.getX() << "," << d.getY() << ")" << endg;
  gout << setPos(200, 480) << " Perimeter: " << getPerimeter() << endg;
}
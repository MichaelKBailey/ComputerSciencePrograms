#ifndef CIRCLE_H
#define CIRCLE_H

const double PI = 3.14159265359;

class Circle
{
private:
  int x;
  int y;
  int radius;

public:
  Circle();
  void setX(int x);
  void setY(int y);
  void setRadius(int radius);
  int getX() const {return x;}
  int getY() const {return y;}
  int getRadius() const {return radius;}
  int getArea() const {return PI*radius*radius;}
  int getPerimeter() const {return 2*PI*radius;}
  string getType();
  void draw();
};

#endif


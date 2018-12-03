#include <iostream>
#include "graph1.h"
#include "Color.h"

Color::Color()
{
r = 0;
g = 0;
b = 0;
}
Color::Color(int r, int g, int b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}
void Color::setColor(int r, int g, int b)
{
this->r = r;
this->g = g;
this->b = b;
}

Color Color::operator+(Color right)
{
  Color result;

  result.r = r + right.r;
  if (result.r > 255)
  {
    result.r = 255;
  }

  result.g = g + right.g;
  if (result.g > 255)
  {
    result.r = 255;
  }

  result.b = b + right.b;
  if (result.b > 255)
  {
    result.b = 255;
  }
return result;
}

Color Color::operator-(Color right)
{
Color result;

result.r = r - right.r; 
if (result.r < 0)
{
  result.r = 0;
}

result.g = g - right.g;
if (result.g < 0)
{
  result.r = 0;
}

result.b = b - right.b;
if (result.b < 0)
{
  result.b = 0;
}
return result;
}

Color Color::operator/(int right)
{
  Color result;

  result.r = r / right;
  if (result.r < 0)
  {
    result.r = 0;
  }

  result.g = g / right;
  if (result.g < 0)
  {
    result.r = 0;
  }

  result.b = b / right;
  if (result.b < 0)
  {
    result.b = 0;
  }
return result;
}

Color Color::operator*(int right)
{
  Color result;

  result.r = r * right;
  if (result.r < 0)
  {
    result.r = 0;
  }

  result.g = g - right;
  if (result.g < 0)
  {
    result.r = 0;
  }

  result.b = b - right;
  if (result.b < 0)
  {
    result.b = 0;
  }
return result;
}

bool Color::operator==(Color right)
{
  bool result = false;

  if (r == right.r)
  {
    result= true;
  }
  else if (g != right.g)
  {
    result =true;
  }
  else if (b != right.b)
  {
    result= true;
  }
  else
{   
 return false;
}
return result;
}

bool Color::operator!=(Color right)
{
bool notequal = true;

if (r != right.r)
{
return notequal;
}
else if (g != right.g)
{
  return notequal;
}
else if (b != right.b)
{
  return notequal;
}
else
return false;
}

void Color::operator=(Color right)
{
  Color result;
r = right.r;
g = right.g;
b = right.b;
}

Color Color::operator!()
{
Color result;
result.r = 255-r;
result.g = 255-g;
result.b = 255-b;
return result;
}

Color Color::operator++()
{
  Color result;

  result.r = r + 25;
  if (result.r > 255)
    result.r = 255;

  result.g = g + 25;
  if (result.g > 255)
    result.g = 255;

  result.b = b + 25;
  if (result.b > 255)
    result.b = 255;

  return result;
}

Color Color::operator++(int dummy)
{
  Color result;

  result.r = r + 25;
  if (result.r > 255)
    result.r = 255;

  result.g = g + 25;
  if (result.g > 255)
    result.g = 255;

  result.b = b + 25;
  if (result.b > 255)
    result.b = 255;

  return result;
}

Color Color::operator--()
{
  Color result;

  result.r = r - 25;
  if (result.r < 0)
    result.r = 0;

  result.g = g - 25;
  if (result.g < 0)
    result.g = 0;

  result.b = b - 25;
  if (result.b < 0)
    result.b = 0;

  return result;
}

Color Color::operator--(int dummy)
{
  Color result;

  result.r = r - 25;
  if (result.r < 0)
    result.r = 0;

  result.g = g - 25;
  if (result.g < 0)
    result.g = 0;

  result.b = b - 25;
  if (result.b < 0)
    result.b = 0;

  return result;
}

bool Color::operator<(Color right)
{
  bool result = true;

  if (r < right.r)
    return result;
  else if (g < right.g)
    return result;
  else if (b < right.b)
    return result;
  else result = false;
  return result;
}

bool Color::operator>(Color right)
{
  bool result = true;

  if (r > right.r)
    return result;
  else if (g > right.g)
    return result;
  else if (b > right.b)
    return result;
  else result = false;
  return result;
}

void Color::draw(int x, int y, int w, int h)
{
int obj = drawRect(x,y,w,h);
::setColor (obj, r, g, b);
}


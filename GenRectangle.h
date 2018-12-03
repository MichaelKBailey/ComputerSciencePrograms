#ifndef GENRECTANGLE_H
#define GENRECTANGLE_H

class GenRectangle
{
private:
int x;
int y;
int width;
int height;

public:
GenRectangle();
int getWidth() const {return width;}
int getHeight() const {return height;}
int getX() const {return x;}
int getY() const {return y;}
int getArea() const {return width*height;}
int getPerimeter() const {return width+width+height+height;}
void setWidth(int width);
void setHeight(int height);
void setX(int x);
void setY(int y);
string getType();
void draw();
void draw2();
};

#endif
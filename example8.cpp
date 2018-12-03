#include <iostream>
#include "graph1.h"


using namespace std;



struct ColorFilledCircle
{
  int x;
  int y;
  int radius;
  int r;
  int g;
  int b;

};


void setColorFilledCircle(ColorFilledCircle& cfc);
ColorFilledCircle setColorFilledCircle();
void draw(ColorFilledCircle cfc);


int main()
{
  //Variable Declaration/Initialization
  ColorFilledCircle cfc1;
  ColorFilledCircle cfc2;
  ColorFilledCircle cfc3 = {100,100,50,255,0,0};
  char repeat = 'y';

  //Display graphics window
  displayGraphics();

  //Repeat as often
  do
  {
    //Prompt the user for color filled circle - pass-by-reference
    setColorFilledCircle(cfc1);
  
    //Prompt the user for color filled circle - return a structure
    cfc2 = setColorFilledCircle();

    //Draw the colored circles
    draw(cfc1);
    draw(cfc2);
    draw(cfc3);
    

    //Repeat program
    cout << "Repeat program? (y/n): ";
    cin >> repeat;

    //Clear console screen/graphics window
    system("cls");
    clearGraphics();

  }while( (repeat == 'y') || (repeat == 'Y') );

  return 0;
}

void setColorFilledCircle(ColorFilledCircle& cfc)
{
  //Prompt the user for the colored circle information
  cout << "Enter x/y coordinates: ";
  cin >> cfc.x >> cfc.y;

  cout << "Enter the radius: ";
  cin >> cfc.radius;

  cout << "Enter the color: ";
  cin >> cfc.r >> cfc.g >> cfc.b;
}

ColorFilledCircle setColorFilledCircle()
{
  //Variable Declaration/Initialization
  ColorFilledCircle cfc;

  //Prompt the user for the colored circle information
  cout << "Enter x/y coordinates: ";
  cin >> cfc.x >> cfc.y;

  cout << "Enter the radius: ";
  cin >> cfc.radius;

  cout << "Enter the color: ";
  cin >> cfc.r >> cfc.g >> cfc.b;

  return(cfc);
}

void draw(ColorFilledCircle cfc)
{
  //Variable Declaration/Initialization
  int i = 0;
  int obj_no = 0;

  //Draw a set of coencentric circles
  for (i = 0; i < cfc.radius; i++)
  {
    //Draw each circle
    obj_no = drawCircle(i,cfc.x,cfc.y);
    setColor(obj_no,cfc.r,cfc.g,cfc.b);
  }
}


  
  
  
  
  
  
  
  
// Graphics window shows a city night view


#include <iostream>
#include "graph1.h"

int main()
{

  //Declare obj_no
  int obj_no = 0;
  double value = 10.234579;

  //Display graphics
  displayGraphics();

  //Display the background
  displayPNG("bg2.png",0,0);

  /*********************************************************/
  //Draw stars given (x,y) coords
  drawPoint(59,59);
  drawPoint(119,179);
  drawPoint(239,19);
  drawPoint(359,79);
  drawPoint(559,39);
  drawPoint(593,179);

  /*********************************************************/
  //Draw building outlines
  drawLine(0,339,59,339,1);
  drawLine(59,339,59,239,1);
  drawLine(59,239,159,239,1);
  drawLine(159,239,159,59,1);
  drawLine(159,59,299,59,1);
  drawLine(299,59,299,279,1);
  drawLine(299,279,399,279,1);
  drawLine(399,279,399,139,1);
  drawLine(399,139,519,139,1);
  drawLine(519,139,519,239,1);
  drawLine(519,239,599,239,1);
  drawLine(599,239,599,339,1);
  drawLine(599,339,693,339,1);

  /*********************************************************/
  //Draw rectangles/windows and color them
  obj_no = drawRect(179,99,10,10);
  setColor(obj_no,255,255,0);

  obj_no = drawRect(179,129,10,10);
  setColor(obj_no,255,255,0);

  obj_no = drawRect(259,179,10,10);
  setColor(obj_no,255,255,0);

  obj_no = drawRect(99,259,10,10);
  setColor(obj_no,255,255,0);

  obj_no = drawRect(239,319,10,10);
  setColor(obj_no,255,255,0);

  obj_no = drawRect(419,179,10,10);
  setColor(obj_no,255,255,0);

  /*********************************************************/
  //Show Moon Image
  displayPNG("moon1.png",400,25);
  displayPNG("target.png", 300,25);
  displayPNG("uca.png",300,300);
 
  gout << setPos(300,450) << setColor(255,0,0) << "The value is: " << setPrecision(2) << value << endg;


  return 0;
}
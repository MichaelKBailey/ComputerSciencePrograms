// Graphics window shows a city night view


#include <iostream>
#include "graph1.h"

int main()
{

  //Declare obj_no
  int i = 0;
  int j = 0;
  int no_stars = 0;
  int no_windows = 0;
  const int MAX_OBJS = 50;
  int stars[MAX_OBJS];
  int windows[MAX_OBJS];
  

  //Display graphics
  displayGraphics();

  /*********************************************************/
  //Draw stars given (x,y) coords
  stars[i++] = drawPoint(59,59);
  stars[i++] = drawPoint(119,179);
  stars[i++] = drawPoint(239,19);
  stars[i++] = drawPoint(359,79);
  stars[i++] = drawPoint(559,39);
  stars[i++] = drawPoint(593,179);

  //Set the # of stars
  no_stars = i;

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
  i = 0;
  windows[i] = drawRect(179,99,10,10);
  setColor(windows[i++],255,255,0);

  windows[i] = drawRect(179,129,10,10);
  setColor(windows[i++],255,255,0);

  windows[i] = drawRect(259,179,10,10);
  setColor(windows[i++],255,255,0);

  windows[i] = drawRect(99,259,10,10);
  setColor(windows[i++],255,255,0);

  windows[i] = drawRect(239,319,10,10);
  setColor(windows[i++],255,255,0);

  windows[i] = drawRect(419,179,10,10);
  setColor(windows[i++],255,255,0);

  //Set the # of windows
  no_windows = i;

  /*********************************************************/

  //Have each star flicker
  for (j = 0; j < 50; j++)
  {
    for (i = 0; i < no_stars; i++)
    {
      //Even iterations of j are black
      //Odd iterations of j are white
      if (j%2 == 0)
        setColor(stars[i],0,0,0);
      else
        setColor(stars[i],255,255,255);

      Sleep(1);
    }
  }

  //Have each window flicker
  for (j = 0; j < 50; j++)
  {
    for (i = 0; i < no_windows; i++)
    {
      //Even iterations of j are midbright yellow
      //Odd iterations of j are bright yellow
      if (j%2 == 0)
        setColor(windows[i],128,128,0);
      else
        setColor(windows[i],255,255,255);

      Sleep(1);
    }
  }

  //Draw Moon
  displayBMP("moon1.bmp",400,25);
  for (i = 0; i < 46; i++)
  {
    drawCircle(i,445,70);
    Sleep(1);
  }

  //Display caption
  gout << setPos(280,420) << "Night Scene" << endg;

  return 0;
}
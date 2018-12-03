#include <iostream>
#include "graph1.h"
#include "GenPolygon.h"

GenPolygon::GenPolygon()
{
  //Set to nulls
  this->lines = NULL;
  this->no_lines = 3;
}

GenPolygon::GenPolygon(int no_lines)
{
  //Set based on no_lines
  this->no_lines = no_lines;
  this->lines = new GenLine[no_lines];
}

GenPolygon::~GenPolygon()
{
  //Cleanup
  delete[] lines;
}

GenPolygon::GenPolygon(const GenPolygon& poly)
{
  //Make a copy of poly to this!
  int i = 0;

  //Copy no_lines first
  this->no_lines = poly.no_lines;

  //Allocate lines for this
  this->lines = new GenLine[this->no_lines];

  //Set each line one at a time
  for (i = 0; i < this->no_lines; i++)
  {
    //Set each line for this!
    this->setLineAt(i,poly.lines[i]);
  }

 

  
}

int GenPolygon::getNoLines()
{
  return(no_lines);
}

void GenPolygon::setNoLines(int no_lines)
{
  //Clip values
  if (no_lines <= 0)
  {
    no_lines = 3;
  }
  else if (no_lines > 10)
  {
    no_lines = 10;
  }

  //Set the lines
  this->no_lines = no_lines;
  
}

GenLine GenPolygon::getLineAt(int index)
{
  //Return the line at the index 
  GenLine line;
  line.setLine(this->lines[index].getPoint1(), this->lines[index].getPoint2());
  return line;
}

void GenPolygon::setLineAt(int index, GenLine line)
{
  //Set this line points
  this->lines[index].setLine(line.getPoint1(), line.getPoint2());

  //Set the description
  this->lines[index].setDesc(line.getDesc());
}

void GenPolygon::draw()
{
  //Draw the lines
  int i = 0;

  //Draw each line
  for (i = 0; i < no_lines; i++)
  {
    //Draw the line
    this->lines[i].draw();
  }
  
}
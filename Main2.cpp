#include <iostream>
#include "graph1.h"
#include "GenPoint.h"
#include "GenLine.h"
#include "GenPolygon.h"

using namespace std;

//Pass by value
void printPolygon(GenPolygon poly);

int main ()
{
  //Variable Declaration/Initialization
  int i = 0;
  int x = 0;
  int y = 0;
  string info;
  char repeat = 'y';
  GenPoint p1;
  GenPoint p2;
  GenLine line;
  GenPolygon poly(4); //Set to Quadrilateral

  //Display graphics
  displayGraphics();

  //Set the line description to "Vertical"
  line.setDesc("Vertical");

  do
  {
    //Prompt for Point 1
    cout << "Enter x/y coords for Point 1: ";
    cin >> x >> y;

    //Set the point 1
    p1.setPoint(x,y);

    //Prompt for Point 2
    cout << "Enter x/y coords for Point 2: ";
    cin >> x >> y;

    //Set the point 2
    p2.setPoint(x,y);

    //Set the line
    line.setLine(p1,p2);

    //Draw the line/circular endpoints
    line.draw();
  
    //Display the length at Point1
    gout << setPos(line.getPoint1().getX()+15,line.getPoint1().getY() + 12) << "Length: " << line.getLength() << endg;
  
    //Display the midpoint at Midpoint
    gout << setPos(line.getMidPoint().getX() + 15, line.getMidPoint().getY() ) << "Mid Point: (" << 
          line.getMidPoint().getX() << "," << line.getMidPoint().getY() << ")" <<  endg;

  
    //Display info at p2
    gout << setPos(line.getPoint2().getX() + 15, line.getPoint2().getY()) << "Info: " << line.getDesc() << endg;

    //Process polygon info
    cout << endl << endl << endl;
    cout << "Processing Polygon Info" << endl << endl;


    //Create Polygon from no_lines
    for (i = 0; i < poly.getNoLines(); i++)
    {
      //Prompt for points for each line
      //Prompt for Point 1
      cout << "Enter x/y coords for Point 1: ";
      cin >> x >> y;

      //Set Point 1
      p1.setPoint(x,y);

      //Prompt for Point 2
      cout << "Enter x/y coords for Point 2: ";
      cin >> x >> y;

      //Set Point 2
      p2.setPoint(x,y);

      //Set the line
      line.setLine(p1,p2);

      //Set the desc
      info += "Line #";
      info += to_string(i);
      line.setDesc(info);

      //Set the Polygon
      poly.setLineAt(i,line);
    }

    //Display info
    printPolygon(poly);

    //Display polygon
    poly.draw();

    printPolygon(poly);

    //Repeat? 
    cout << "Repeat program? (y/n): ";
    cin >> repeat;

    //Clear graphics/console
    system("cls");
    clearGraphics();

    
  }while( (repeat == 'y') || (repeat == 'Y') );

  
  return 0;
	
}

void printPolygon(GenPolygon poly)
{
  //Variable Declaration/Initialization
  int i = 0;

  //Get the lines
  //Print the info to the console
  for (i = 0; i < poly.getNoLines(); i++)
  {
    cout << poly.getLineAt(i).getPoint1().getX() << "," << poly.getLineAt(i).getPoint1().getY() << endl;
  }
 
}



  		 
  
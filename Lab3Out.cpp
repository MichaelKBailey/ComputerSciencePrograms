/*
Michael Bailey
Assignment: Lab 3 Out
bug zapper program
*/

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//protoypes
void initDisplay();
int getNoBugs();
int* getXCoords(int no_bugs);
int* getYCoords(int no_bugs);
int* displayObjects(int* x_coords, int* y_coords, int no_objects);
int zapBugs(int* x, int* y, int* objects, int no_bugs);

int main()
{
	//variable declaration/initialization
	int no_bugs = 0;
	int* x_coords = NULL;
	int* y_coords = NULL;
	int* objects = NULL;
	int score = 0;
	char repeat = 'y';

	//initialize seed
	srand(time(0));

	//display graphics
	displayGraphics();

	do
	{
		//call functions
		initDisplay();
		no_bugs = getNoBugs();
		x_coords = getXCoords(no_bugs);
		y_coords = getYCoords(no_bugs);
		objects = displayObjects(x_coords, y_coords, no_bugs);
		score = zapBugs(x_coords, y_coords, objects, no_bugs);

		//prompt for repeat
		cout << "Run program again? (y/n): ";
		cin >> repeat;
    //clean up
 //   delete[no_bugs] x_coords;
 // delete[no_bugs] y_coords;
 //   delete[no_bugs] objects;
	//	clearGraphics();
//		system("cls");
	} while ((repeat == 'y') || (repeat == 'Y'));

	return 0;
}


//displays grass and header
void initDisplay()
{
  //display background
  displayPNG("Grass.png", 0, 0);

  //display header
  drawRect(250, 0, 200, 40);
  gout << setPos(285, 20) << setColor(0, 0, 0) << "Score: 0" << endg;
  gout << setPos(370, 20) << setColor(0, 0, 0) << "Shots: 0" << endg;
}


//prompt for number of bugs
int getNoBugs()
{
  //variable declaration/initialization
  int no_bugs = 0;

  //prompt for number of bugs to display
  do
  {
    cout << "Enter # of Bugs to Display (between 5 and 20): ";
    cin >> no_bugs;

    //data validation
    if (no_bugs < 5 || no_bugs > 20)
    {
      cout << "Number must be between 5 and 20, inclusively." << endl;
      cout << "Please Re-";
    }
  } while (no_bugs < 5 || no_bugs > 20);

  return(no_bugs);
}


//generate x-coords for each bug
int* getXCoords(int no_bugs)
{
  //variable declaration/initialization
  int i = 0;
  int* x_coords = NULL;

  //dynamically allocate x-coords array
  x_coords = new int[no_bugs];

  //randomly generate x-coords
  for (i = 0; i < no_bugs; i++)
  {
    x_coords[i] = (rand() % 576);
  }

  return(x_coords);
}


//generate y-coords for each bug
int* getYCoords(int no_bugs)
{
  //variable declaration/initialization
  int i = 0;
  int* y_coords = NULL;

  //dynamically allocate y-coords array
  y_coords = new int[no_bugs];

  //randomly generate y-coords
  for (i = 0; i < no_bugs; i++)
  {
    y_coords[i] = (rand() % 336 + 40);
  }

  return(y_coords);
}


//displays bugs at x/y coords
int* displayObjects(int* x_coords, int* y_coords, int no_objects)
{
  //variable declaration/initialization
  int i = 0;
  int* objects;

  //dynamically allocate objects array
  objects = new int[no_objects];

  //display bugs from objects array
  for (i = 0; i < no_objects; i++)
  {
    objects[i] = displayPNG("bugs.png", x_coords[i], y_coords[i]);
  }

  return(objects);
}

int zapBugs(int* x, int* y, int* objects, int no_bugs)
{
int xguess = 0;
 int yguess = 0;
int obj = 0;
int shots = 0;
int score = 0;
int radius = 10;
int circle_obj = 0;
do
{
  do
  {
  cout << "Please enter a guess for the x/y coordinate: ";
	cin >> xguess >> yguess;
  if ((xguess < 0) || (xguess >= 640) || (yguess < 0) || (yguess > 480))
  {
  cout << "Invalid coordinates. Please re-enter your coordinates." << endl;
  }
  } while ((xguess < 0) || (xguess >= 640) || (yguess < 0) || (yguess > 480));

  for (int j = 0; j < radius; radius--)
    {
    circle_obj = drawCircle(radius, xguess, yguess);
    setColor(circle_obj, 0, 0, 0);
    }

  for (int i = 0; i < no_bugs; i++)
  {
    if ((xguess > x[i]) && (xguess < (x[i] + 64)) && (yguess > y[i]) && (yguess < (y[i] + 64)))
    {
      Sleep(1000);
      removeObject(objects[i]);
      x[i] = -999;
      y[i] = -999;
      score++;
      gout << setPos(285, 20) << setColor(0, 0, 0) << "Score: " << score << endg;
    }
    }shots++;
      gout << setPos(370, 20) << setColor(0, 0, 0) << "Shots: " << shots << endg;
    } while ((shots < (no_bugs*2)) && (score != no_bugs));

    if (score == no_bugs)
      gout << setPos(370, 20) << setColor(0, 0, 0) << "Winner!" << endg;
    else
      gout << setPos(370, 20) << setColor(0, 0, 0) << "Game Over" << endg;


return score;
}
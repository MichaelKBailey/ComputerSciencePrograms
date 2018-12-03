//  **************************************************************************************
//  *                           Michael Bailey - CS2 LabTest 1                           *
//  *                              9/28/2018, Friday LAb                                 *
//  *                    This program displays an offset checkerboard                    *
//  **************************************************************************************

#include <iostream>
#include "graph1.h"
#include <ctime>

using namespace std;

//Prototypes go here
void getData(int* no_stairs, int* r, int* g, int* b);
void displayStairs(int no_stairs, int r, int g, int b);


int main()
{
  //displayGraphics function
  displayGraphics();

  //Declair and initialize your variables
  char repeat = 'y';
  int length = 100;
  int width = 20;
  int no_stairs = 0;
  int r = 0;
int g = 0; 
int b = 0;


do
{
getData(&no_stairs, &r, &g, &b);
displayStairs(no_stairs, r, g, b);
 
} while ((repeat == 'y') || (repeat == 'Y'));


  return 0;
}

//Set up your stubs down here
void getData(int* no_stairs, int* r, int* g, int* b)
{
  do
  {
    cout << "\nPlease enter the number of stairs you would like to draw: ";
    cin >> *no_stairs;

    if ((*no_stairs < 3) || (*no_stairs > 6))
    {
      cout << "Invalid input for the number of boxes. Please enter a number between 5 and 10. ";
    }
  } while ((*no_stairs < 3) || (*no_stairs > 6));

  do
  {
    //Prompt for the color
    cout << "Please enter the red color component: ";
    cin >> *r;

    //Check for invalid entries
 if ((*r < 0) || (*r > 255))
    {
      cout << "Invalid Color - value must be between 0 and 255 inclusivly" << endl;
    }
  } while ((*r < 0) || (*r > 255));

  do
  {
    //Prompt for the color
    cout << "Please enter the green color component: ";
    cin >> *g;

    //Check for invalid entries
    if ((*g < 0) || (*g > 255))
    {
      cout << "Invalid Color - value must be between 0 and 255 inclusivly" << endl;
    }
  } while ((*g < 0) || (*g > 255));

  do
  {
    //Prompt for the color
    cout << "Please enter the blue color component: ";
    cin >> *b;

    //Check for invalid entries
    if ((*b < 0) || (*b > 255))
    {
      cout << "Invalid Color - value must be between 0 and 255 inclusivly" << endl;
    }
  } while ((*b < 0) || (*b > 255));
}


void displayStairs(int no_stairs, int r, int g, int b)
  {
    int rectColor = 0;
    int x = 0;
    int y = 400;
    int length = 100;
    int height = 20;


    for (int i = 0; i < no_stairs; i++)
    {
     drawRect(0 + (i*50), 400-(i*20), 100, 20);
     setColor(rectColor, 128, 128, 128);
      if ((i % 2) == 1)
      {
        setColor(rectColor, r, g, b);
      }
    }
  }

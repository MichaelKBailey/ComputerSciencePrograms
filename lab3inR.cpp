/*Michael Bailey
Lab 3 In
Displays a set of images at random location
*/

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
void getData(int* r, int* g, int* b, int* radius, int* no_circles)
int* drawChain(int radius, int no_circles);
int* getXCoords(int no_objects);
int* getYCoords(int no_objects);
void colorChain(int* objects, int no_circles, int r, int g, int b);

int main()
{
  //Variable Declaration/Initialization
  int no_objects = 0;
  int* x_coords = NULL;
  int* y_coords = NULL;
  char repeat = 'y';
  do
  {
 
    //Display graphics
    displayGraphics();

    //1. Get the number of objects to be displayed
    getData(&r, &g, &b, &radius, &no_circles);

    //2. Generate the x-coords for each object
    x_coords = getXCoords(no_objects);

    //3. Generate the y-coords for each object
    y_coords = getYCoords(no_objects);

    //4. Display the objects at the randomly generated coordinates
    displayObjects(x_coords, y_coords, no_objects);

    //prompt for repeat
    cout << "Run program again? (y/n): ";
    cin >> repeat;
    clearGraphics();
    system("cls");
  } while ((repeat == 'y') || (repeat == 'Y'));

  return 0;
}



void getData(int* r, int* g, int* b, int* radius, int* no_circles)
{

  do {
    cout << "Please enter the number of circles to display: " << endl;
    cin >> *no_circles;
    if (*no_circles < 3 || *no_circles > 10)
      cout << "\nPlease enter a number between 3 and 10. ";
  } while (*no_circles < 3 || *no_circles > 10);

  do
  {
    cout << "Please enter the circles radius: " << endl;
    cin >> *radius;
    if (*radius < 15 || *radius > 25)
      cout << "\nPlease enter a number between 15 and 25. ";
  } while (*radius < 15 || *radius > 25);

  cout << "Please enter the r, g, and b values for the circles: " << endl;
  cin >> *r >> *g >> *b;

}




int* drawChain(int no_circles)
{

  //Dynamically allocate the array for x-coords
  int* drawChain = new int[no_circles];

  for (int i = 0; i < no_circles; i++)
  {
    //Generates x-coords for each object randomly
    drawChain[i] += drawChain + radius;
  }

  return (drawChain);
}

void colorChain(int* drawChain, int no_circles, int r, int g, int b)
{
  //Variable declaration/initialization
  int* objects = NULL;

  //Dynamically allocate objects to have no_objects
  objects = new int(no_objects);

  for (int i = 0; i < no_circles; i++)
  {
    //Set the image
    if ((i % 2) == 0)

      objects[i] = drawCircle(radius, drawChain[i], 100);
      setColor(objects[i], r, g, b);
    else
      objects[i] = drawCircle(radius, drawChain[i], 100);
      setColor(objects[i],r,g,b);
  }

  //Display all objects at x/y random positions stored in x_coords/y_coords


}

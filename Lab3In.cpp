/*Michael Bailey
Lab 3 In
Displays a set of images at random location
*/

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
int getNoObjects();
int* getXCoords(int no_objects);
int* getYCoords(int no_objects);
void displayObjects(int* x_coords, int* y_coords, int no_objects);

int main()
{
  //Variable Declaration/Initialization
  int no_objects = 0;
  int* x_coords = NULL;
  int* y_coords = NULL;
  char repeat = 'y';
do
{
  //Initialize random # generator
  srand(time(0));

  //Display graphics
displayGraphics();

  //1. Get the number of objects to be displayed
no_objects = getNoObjects();

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



//Implement functions below
int getNoObjects()
{
int no_objects = 0;
  do
  {
    cout << "Please enter the number of objects to display: ";
    cin >> no_objects;
    if (no_objects > 30 || no_objects < 2)
    {
      cout << "The number of dice must be between 2 and 30." << endl;
    }
  } while (no_objects > 30 || no_objects < 2);

return (no_objects);
}

int* getXCoords(int no_objects)
{

//Dynamically allocate the array for x-coords
int* x_coords = new int[no_objects];

  for (int i = 0; i < no_objects; i++)
  {
//Generates x-coords for each object randomly
    x_coords[i] = rand() % 601;
  }

return (x_coords);
}

int* getYCoords(int no_objects)
{
//Dynamically allocate the array for x-coords
  int* y_coords = new int[no_objects];

  for (int i = 0; i < no_objects; i++)
  {
//Generates x-coords for each object randomly
    y_coords[i] = rand() % 441;
  }
return y_coords;
}

void displayObjects(int* x_coords, int* y_coords, int no_objects)
{
  //Variable declaration/initialization
 int* objects = NULL;

  //Dynamically allocate objects to have no_objects
objects = new int (no_objects);
 
for (int i = 0; i < no_objects; i++)
  {
    //Set the image
    if ((i % 2) == 0)
      objects[i] = displayPNG("even.png", x_coords[i], y_coords[i]);
    else
      objects[i] = displayPNG("odd.png", x_coords[i], y_coords[i]);
  }

  //Display all objects at x/y random positions stored in x_coords/y_coords
  

}

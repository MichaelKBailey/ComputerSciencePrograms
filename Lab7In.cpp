#include "graph1.h"
#include "Simulation.h"

using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int height = 0;
  int radius = 0;
  int r = 0;
  int b = 0;
  int g = 0;
  char repeat;
  Container container;
  Simulation simulation;
  GenPoint position;
  Color col;
  


  //Display the graphics
  displayGraphics();

  //Continually simulate

  do
  {
    //Get the Container's radius/height/color (Add Data Validation)
    do
    {
    cout << " Please enter the radius of the container between 10 and 285:"; 
    cin >> radius;

    if (radius < 10 || radius > 285)
    {
     cout <<"Please enter new radius";
    }

}while (radius <10 || radius > 285);



    //Set the Containers height
do
{
  cout << " Please enter the height of the ocntainer between 10 and 300:";
  cin >> height;

  if (height < 10 || height > 300)
  {
    cout << "Please enter new data";
  }

} while (height < 10 || height > 300);

//Set the Containers color
do
{
  cout << " Please enter the color:";
  cin >> r >> g >> b;

  if (r < 10 || r > 255)
  {
    cout << "Please enter new data";
  }
  if (g < 10 || g > 300)
  {
    cout << "Please enter new data";
  }
  if (b < 10 || b > 300)
  {
    cout << "Please enter new data";
  }

} while (r < 0 || g < 0 || b < 0 || r > 255 || g > 255|| b > 255);


//Set containers color 
col.setColor(r,g,b);
container.setColor(col);

//Set the Container’s position
position.setPoint(57, 400 - height);

    //Compute the Container upper left coordinate based on the height
container.setPosition(position);

    //Set the Container for the Simulation
simulation.setContainer(container);

    //Draw the simulation/container (invoke draw on Simulation)
simulation.draw();


    //Repeat the simulation?
    cout << "Repeat the simulation (y/n)? ";
    cin >> repeat;

    clearGraphics();
    system("cls");

  } while (repeat == 'y');

  return 0;
}
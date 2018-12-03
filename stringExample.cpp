#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "graph1.h"

using namespace std;

int main()
{
  //Variable Declaration/Initializaton
  int card_num = 0;
  int suit_no = 0;
  char suit = ' ';
  string suits = "cdhs";
  string fn = "";
  string info = "";
  
  //Display the graphics window
  displayGraphics();

  //Init the random # generator
  srand(time(0));

  //Generte a random # between 1 and 10 for the 1st deck
  card_num = rand()%10 + 1;

  //Generate the fn based on the random #
  fn = to_string(card_num) + "_Card.png";

  //Display this fn at 100,100
  displayPNG(fn,100,100);

  //Generate a random # for suit and then card
  suit_no = rand()%4;
  suit = suits[suit_no];

  card_num = rand()%13 + 2;
  
  //Generate the fn based on suit and card_no
  fn = suit + to_string(card_num) + ".bmp";

  //Display card at 250,100
  displayBMP(fn,250,100);

  //prompt for a title
  cout << "Enter a string to be displayed in the graphics window:";
  getline(cin, info);

  //Display the info
  gout << setPos(100,350) << setColor(255,0,255) << "Info follows " << info << endg;
  
  return 0;

 
}
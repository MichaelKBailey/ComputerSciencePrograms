#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

const int min_value = 1;
const int max_value = 6;

//Protoypes
void getDiceCount(int* noDice);
void rollDice(int* dice, int noDice);
void computeScore(int* dice, int noDice, int* score);
void displayResults(int* dice, int noDice, int score);

int main()
{
  //Variable Declaration/Initialization
  int noDice = 0;
  const int MAX_DICE = 5;
  int dice[MAX_DICE] = { 0 };
  int score = 0;
  char repeat = 'y';

 do
{
  //Display Graphics
displayGraphics();

  //1. Get the number of dice to roll
getDiceCount(&noDice);

  //2. Roll the Dice (i.e., generates a random number for each dice
rollDice(dice, noDice);

  //3. Compute the score
computeScore(dice, noDice, &score);

  //4. Display the dice and results
displayResults(dice, noDice, score);

  cout << "Repeat the program? [Y/N] ";
  cin >> repeat;
  clearGraphics();
  system("cls");

}while (repeat == 'y' || repeat == 'Y');

  return 0;
}

//Functions
void getDiceCount(int* noDice)
{
  do
  {
   cout << "Please enter the number of dice to display: "; 
   cin >> *noDice;
    if ((*noDice > 5) || (*noDice < 1))
    {
     cout << "The number of dice must be between 1 and 5." << endl;
    }
  } while ((*noDice > 5) || (*noDice < 1));

}


void rollDice(int* dice, int noDice)
{
  //Generates noDice random numbers corresponding to the rolling of the dice
  //Initialize random number generator
  int current_time = 0;
  current_time = (int)time(0);   //current time
  srand(current_time);           //setting the seed
  
  //Randomization math section
 
  //Each random number is stored in the dice parameter
  for (int i = 0; i < noDice; i++)
  {   
   dice[i] = (rand() % (max_value - min_value + 1)) + min_value;  //Generates random values for [i] dice between global defined min and max numbers
  }
}


void computeScore(int* dice, int noDice, int* score)
{
  //Variable Declaration
  int i = 0;
  *score = 0;

  //Adds up each random number stored in the dice array
  for (int i = 0; i < noDice; i++)
  {
   *score += dice[i];
  }
}

void displayResults(int* dice, int noDice, int score)
{
  int x = 100;
  int y = 0; 

  //Display each Die starting at 100,100
  for (int i = 0; i < noDice; i++)
  {
   displayPNG(to_string(dice[i])+ "Die.png", x, 100);
   x += 129;
  }

  //Display the Score at (50,225)
  gout << setColor(255,0,0) << setPos(50,225) << "Score: " << score << endg;
}

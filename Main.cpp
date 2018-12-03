/*
Michael Bailey
Assignment: Lab 6 In
This program is an object oriented card game with pointers and arrays and stuff.
*/

#include <iostream>
#include <ctime>
#include "graph1.h"
#include "CardPlayer.h"

using namespace std;

int main()
{
  //variable declaration/initialization
  int noCards = 0;
  char color = 'r';
  char repeat = 'y';
  CardPlayer player1;
  CardPlayer dealer;

  //seed time
  srand(time(0));

  //display graphics
  displayGraphics();

  do
  {
 //prompt for suit color
    do
    {

    cout << "Enter the suit color (r for red suits, b for black suits): ";
    cin >> color;

      if (color != 'r' && color != 'b')
      { 
       cout << "Color must be r or b. Please Re-";
      }
    } while (color != 'r' && color != 'b');

    //set color
    if (color == 'r')
    {
      player1.setColor(color);
      dealer.setColor('b');
    }
    else
    {
      player1.setColor(color);
      dealer.setColor('r');
    }

    //prompt for the number of cards
    cout << "Enter the number of cards to deal to each player (>= 5 but <= 10): ";
    cin >> noCards;

    //set number of cards
    player1.setNoCards(noCards);
    dealer.setNoCards(noCards);

    //deal cards
    player1.deal();
    dealer.deal();

    //display cards
    player1.displayHand(150, 100);
    dealer.displayHand(250, 100);

    //display score
    gout << setPos(150,85) << "Player 1" << setColor(255, 255, 255) << endg;
    gout << setPos (250,85) << "Dealer " << setColor(255, 255, 255) << endg;
    gout << setPos(150, 85 + 20 * (player1.getNoCards() - 1) + 150) << setColor(255, 255, 255) << "Score: " << player1.computeScore() << endg;
    gout << setPos(250, 85 + 20 * (dealer.getNoCards() - 1) + 150)  << setColor(255, 255, 255) << "Score: " << dealer.computeScore() << endg;

    //prompt for repeat
    cout << "Would you like to repeat the program? [Y/N]: ";
    cin >> repeat;


    clearGraphics();
    system("cls");


  } while (repeat == 'y' || repeat == 'Y');

 return 0;
}
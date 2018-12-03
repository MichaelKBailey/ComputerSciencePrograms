/*
Michael Bailey
Assignment: Lab 2 Out
This is a card game with four suits.
*/

#include <iostream>
#include "graph1.h"
#include <ctime>

// Put the functions here
void getWager(int* wager);                                          //This was void getWager(int& wager);
void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no);  //This was: void deal(int& pc1_no, int& pc2_no, int& deal1_no, int& deal2_no); 
int computeScore(int card1_no, int card2_no);
void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score);

using namespace std;

int main()
{
  int pc1_no = 0;         //Random # for player card1
  int pc2_no = 0;         //Random # for player card2
  int deal1_no = 0;       //Random # for dealer card1
  int deal2_no = 0;       //Random # for dealer card1
  int player_score = 0;
  int dealer_score = 0;
  int wager = 0;
  char repeat = 'y';

  //Display graphics

  displayGraphics();

  do
  {
    //Get the bet
    getWager(&wager);


    //Deal the cards
    deal(&pc1_no, &pc2_no, &deal1_no, &deal2_no);

    //Compute the score
    player_score = computeScore(pc1_no, pc2_no);
    dealer_score = computeScore(deal1_no, deal2_no);

    displayResults(pc1_no, pc2_no, deal1_no, deal2_no, player_score, dealer_score);

    cout << "Repeat the program? ";
    cin >> repeat;
    clearGraphics();

  } while (repeat == 'y' || repeat == 'Y');

  return 0;
}

void getWager(int* wager)
{
  do
  {
    cout << "Please enter your bet (5$ minimum): ";
    cin >> *wager;
    if (*wager < 5)
      cout << "Please place a bet of five dollars or more. \n";
  } while (*wager < 5);
}

void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no)
{
  int seed = 0;
  int rand_number = 0;

  seed = time(0);
  srand(seed);

  *pc1_no = rand() % 13 + 2;
  *pc2_no = rand() % 13 + 2;
  *deal1_no = rand() % 13 + 2;
  *deal2_no = rand() % 13 + 2;
}

int computeScore(int card1_no, int card2_no)
{
  int score = 0;

  //compute the score using if-else if chain or switch
  if (card1_no <= 10)
  {
    score = card1_no;
  }
  else if (card1_no < 14)
  {
    score = 10;
  }
  else
    score = 11;

  if (card2_no <= 10)
  {
    score += card2_no;
  }
  else if (card2_no < 14)
  {
    score += 10;
  }
  else
    score += 11;

  return score;
}


void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score)
{
  int object_number1 = 0;
  int object_number2 = 0;
  int object_number3 = 0;
  int object_number4 = 0;
  int object_number5 = 0;

  gout << setPos(75, 90) << "Your Cards" << endg;
  gout << setPos(400, 90) << "Dealer's Cards" << endg;
  gout << setPos(75, 210) << "Your Total: " << player_score << endg;
  gout << setPos(400, 210) << "Dealer's Total: " << dealer_score << endg;

  // Generate fn of image -> fn = random_num+ ".bmp";
  string filename1 = 'h' + to_string(pc1_no) + string(".bmp");
  string filename2 = 'd' + to_string(pc2_no) + string(".bmp");
  string filename3 = 's' + to_string(deal1_no) + string(".bmp");
  string filename4 = 'c' + to_string(deal2_no) + string(".bmp");

  object_number1 = displayBMP(filename1, 151, 100);
  object_number2 = displayBMP(filename2, 227, 100);
  object_number3 = displayBMP(filename3, 476, 100);
  object_number4 = displayBMP(filename4, 552, 100);
  object_number5 = displayBMP("back.bmp", 75, 100);
  object_number5 = displayBMP("back.bmp", 400, 100);
 
 if (dealer_score > player_score)
  {
    gout << setPos(290, 300) << "You lose. Please try again! " << endg;
  }
  else if (dealer_score < player_score)
  {
    gout << setPos(290, 300) << "You WIN! " << endg;
  }
  else
    gout << setPos(290, 300) << "It's a tie. Please try again! " << endg;
}

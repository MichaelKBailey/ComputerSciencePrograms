#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
  noCards = 0;
  hand = nullptr;
  color = 'r';
}

//destructor for CardPlayer class
CardPlayer::~CardPlayer()
{
  delete[] hand;
}

//card numbers setter
void CardPlayer::setNoCards(int noCards)
{
  if (noCards < 5)
  {
  this-> noCards = 5;
  }
  else if (noCards > 10)
  {
  this-> noCards = 10;
  }
  else
  {
  this-> noCards = noCards;
  }
  
//dynamically allocate hand array
  hand = new int[this->noCards];
}

//card numbers getter
int CardPlayer::getNoCards()
{
 return noCards;
}

//set color
void CardPlayer::setColor(char color)
{
 this->color = color;
}

//display hands
void CardPlayer::displayHand(int x, int y)
{
 string filename;
  for (int i = 0; i < noCards; i++)
  {
    if (color == 'r')
    {
    filename = ("d" + to_string(hand[i]) + ".bmp");
    }
    else
    {
    filename = ("c" + to_string(hand[i]) + ".bmp");
    }
 displayBMP(filename, x, y + i * 20);
  }
}

//compute score
int CardPlayer::computeScore()
{
 int score = 0;
  for (int i = 0; i < noCards; i++)
  {
    if (hand[i] <= 10)
    {
    score = score + hand[i];
    }
    else if (hand[i] < 14)
    {
    score = score + 10;
    }
    else if (hand[i] == 14)
    {
    score = score + 11;
    }  
  }
 return score;
}

//deal cards method
void CardPlayer::deal()
{
 bool duplicate = false;

  for (int i = 0; i < noCards; i++)
  {
   hand[i] = rand() % 13 + 2;
    do
    {
    duplicate = false;
      for (int j = 0; j < i; j++)
      {
        if (hand[i] == hand[j])
        {
          hand[i] = rand() % 13 + 2;
          duplicate = true;
          break;
        }
      }
    } while (duplicate);
  }
sortHand(hand, noCards);
}

//Selection Sort
void CardPlayer::sortHand(int hand[], int noCards)
{
int startScan, minIndex, minValue;

  for (startScan = 0; startScan < (noCards -1); startScan++)
  {
   minIndex = startScan;
   minValue = hand[startScan];
    for (int i = startScan+1; i < noCards; i++)
    {
      if (hand[i] < minValue)
      {
       minValue = hand[i];
       minIndex = i;
      }
    } 
   hand[minIndex] = hand[startScan];
   hand[startScan] = minValue;
  }
}
#ifndef CARDPLAYER_H
#define CARDPLAYER_H
#include <memory>

class CardPlayer
{
private:

  char color;
  int  noCards;
  int *hand = new int [noCards]; 

public:
  CardPlayer();
  ~CardPlayer();
  void setNoCards(int noCards);
  int getNoCards();
  void setColor(char color);
  void displayHand(int x, int y);
  int computeScore();
  void deal();
  void sortHand(int hand[], int noCards);
};

#endif


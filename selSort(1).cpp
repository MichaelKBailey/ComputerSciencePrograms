#include <iostream>
#include <ctime>
#include <conio.h>
#include "graph1.h"

//Prototypes
void shuffle(int* deck, int no_cards);
void displayDeck(int* deck, int no_cards,int x, int y);
void sort(int* a, int no_ele);


int main()
{
 //Variable Declaration/Initialization
  int i = 0;
  int x = 0;
  int y = 0;
  char repeat = 'y';
  const int TOTAL_CARDS = 13;
  int* deck = new int[TOTAL_CARDS];

  //Display Grpaphics
  displayGraphics();
 
  //Shuffle the deck
  shuffle(deck, TOTAL_CARDS);

  //Display the Deck
  displayDeck(deck,TOTAL_CARDS,50,50);
  cout << "Hit y to continue: ";
  cin >> repeat;

  //Sort the cards
  sort(deck,TOTAL_CARDS);

  //Display the deck
  displayDeck(deck,TOTAL_CARDS,150,50);

  return 0;
}

void sort(int* a, int no_ele)
{
  //Variable Declaration/Initialization 
  int n = 0;
  int k = 0;
  int sm_index = 0; 
	int smallest = 0;
  int temp1 = 0;
  int temp2 = 0;
	
  for(k=0; k < no_ele -1; k++)	       // size-1 = number of passes
  {	
    smallest=a[k];
    sm_index=k;

    for(n= k+1; n < no_ele; n++)    // size = # elem. to look at
    {
      if(a[n] < smallest)
      {	
        smallest=a[n];
        sm_index=n;
      }
    }
    
    if (smallest < a[k])
    {
	    temp1=a[k];
	    a[k]=a[sm_index];
      a[sm_index] = temp1;  
    }
  }

}

void shuffle(int* deck, int no_cards)
{
  int i = 0;
  int j = 0;
  bool duplicate = false;


  //Set the seed
  srand(time(0));

  //Generate no_colors random numbers
  for (i = 0; i < no_cards; i++)
  {
    deck[i] = (rand()%no_cards)+2;

    //Check all previous values
    do
    {
      //Set duplicate to false
      duplicate = false;

      //Check prvious values
      for (j = 0; j < i; j++)
      {
        if (deck[i] == deck[j])
        {
          deck[i] = (rand()%no_cards)+2;
          duplicate = true;
        }
      }
    }while(duplicate);
  }
}


void displayDeck(int* deck, int no_cards,int x, int y)
{
  //Work with only hearts
  int i = 0;
  string name;

  for (i = 0; i < no_cards; i++)
  {
    //Use sprintf to combine name info
    name = "h" + to_string(deck[i]) + ".bmp";
    displayBMP(name,x,y);
    
    //Offset card
    y+= 20;
  }
}



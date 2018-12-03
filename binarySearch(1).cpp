#include <iostream>
#include <ctime>
#include "graph1.h"

//Prototypes
void shuffle(int* deck, int no_cards);
void displayHand(int* hand, int no_cards,int x, int y);
void sort(int* a, int no_ele);
int binarySearch(int *list, int no_of_ele, int target);


int main()
{
 //Variable Declaration/Initialization
  int i = 0;
  int x = 0;
  int y = 0;
  int no_cards = 0;
  int search_card = 0;
  char repeat = 'y';
  int index = -1;
  const int TOTAL_CARDS = 13;
  const int CAPACITY = 13;
  int* deck = new int[TOTAL_CARDS];
  int* hand = new int[CAPACITY];

  //Display Grpaphics
  displayGraphics();

  //Shuffle the deck
  shuffle(deck, TOTAL_CARDS);

  cout << "Enter # of cards to deal: ";
  cin >> no_cards;

  for (i = 0; i < no_cards; i++)
  {
    hand[i] = deck[i];
  }

  //Sort the hand
  sort(hand,no_cards);

  //Display the sorted deck
  displayHand(hand,no_cards,150,50);

  //Search for cards
  do
  {

    //Prompt for a card to search for
    cout << "Enter # of card to search for: ";
    cin >> search_card;

    //Perform binary search
    index = binarySearch(hand,no_cards,search_card);

    //Test the search
    if (index == -1)
    {
      cout << "Card not found" << endl;
    }
    else
    {
      cout << "Card found" << endl;
    }

    cout << "Repeat? (y/n): ";
    cin >> repeat;

  }while((repeat == 'y') || (repeat == 'Y') );

 
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


void displayHand(int* hand, int no_cards,int x, int y)
{
  //Work with only hearts
  int i = 0;
  string name;

  for (i = 0; i < no_cards; i++)
  {
    //Use sprintf to combine name info
    name = "h" + to_string(hand[i]) + ".bmp";
    displayBMP(name,x,y);
    
    //Offset card
    y+= 20;
  }
}

int binarySearch(int *list, int no_of_ele, int target)
{
  //Variable Declaration/Initialization
  int low = 0;
  int high = 0;
  int middle = 0;
  bool found = false;
  int index = -1;

  //Initialize low/high
  low = 0;
  high = no_of_ele - 1;

  while((low <= high) && (!found))
  {
    middle = (low + high)/2;

    if (list[middle] == target)
       found = true;
    else if (target > list[middle])
       low = middle + 1;
    else 
      high = middle -1;
  }

  if (!found)
  {
    index = -1;
  }
  else
  {
    index = middle;
  }
  return(index); 

}




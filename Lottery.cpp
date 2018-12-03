//radiance
//lab6out
//lottery sim class

#include <iostream>
#include "graph1.h"
#include "Lottery.h"

//implement default constructor
Lottery::Lottery()
{
	no_balls = 0;
	yourNumbers = NULL;
	winningNumbers = NULL;
	matches = 0;
}

//ball numbers getter
int Lottery::getNoBalls()
{
	return no_balls;
}

//ball numbers setter / allocate arrays
bool Lottery::setNoBalls(int no_balls)
{
	bool result = false;
	if (no_balls < 3)
	{
		no_balls = 3;
	}
	else if (no_balls > 10)
	{
		no_balls = 10;
	}
	else
	{
		no_balls = no_balls;
		result = true;
	}

	//dynamically allocate number arrays
	yourNumbers = new int[this->no_balls];
	winningNumbers = new int[this->no_balls];

	return result;
}

//inserts number into yourNumbers array
bool Lottery::addNumber(int number)
{
	bool result = true;

	for (int i = 0; i < no_balls - 1; i++)
	{
		if (number < 1 || number > 40)
		{
			result = false;
			return result;
		}

		for (int j = 0; j < i; j++)
		{
			if (yourNumbers[i] == yourNumbers[j])
			{
				result = false;
				return result;
			}
		}

		yourNumbers[i] = number;
	}
	return result;
}

//display user lotto balls
void Lottery::displayYourNumbers()
{
	string filename;
	selectionSort();

	for (int i = 0; i < no_balls; i++)
	{
		filename = (to_string(yourNumbers[i]) + ".bmp");
		displayBMP(filename, x, y + i * 20);
	}
}

//generate winning nums / store in array / display
void Lottery::processWinningNumbers()
{
	int score = 0;
  bool duplicate;
  for (int i = 0; i < no_balls; i++)
    {
    winningNumbers[i] = rand() % 40 + 2;
      do
      {
        duplicate = false;
        for (int j = 0; j < i; j++)
        {
          if (winningNumbers[i] == winningNumbers[j])
          {
            winningNumbers[i] = rand() % 40 + 2;            duplicate = true;
            break;
          }
        }
      } while (duplicate);
    do
{
{for (int i = 0; i < no_balls; i++)
{
        filename = (to_string(yourNumbers[i]) + ".bmp");
        displayBMP(filename, x, y + i * 20);
delay 1000
}while ( i < no_balls)
	}
	return score;
}

//perform selection sort on yourNumbers array
void Lottery::selectionSort()
{
	int n = 0;
	int k = 0;
	int sm_index = 0;
	int smallest = 0;
	int temp1 = 0;

	for (k = 0; k < no_balls - 1; k++)
	{
		smallest = yourNumbers[k];
		sm_index = k;

		for (n = k + 1; n < no_balls; n++)
		{
			if (yourNumbers[n] < smallest)
			{
				smallest = yourNumbers[n];
				sm_index = n;
			}
		}

		if (smallest < yourNumbers[k])
		{
			temp1 = yourNumbers[k];
			yourNumbers[k] = yourNumbers[sm_index];
			yourNumbers[sm_index] = temp1;
		}
	}
}

//perform insertion sort on winningNumbers array
void Lottery::insertionSort()
{

}

//return number of balls that match
int Lottery::getMatches()
{
	return matches;
}

//performs binary search on winningNumbers array
int Lottery::binarySearch(int target)
{

}

//determines number of matches
int computeWinnings()
{
	int matches = 0;

	return matches;
}

//destructor for Lottery class
Lottery::~Lottery()
{
	delete[] yourNumbers;
	delete[] winningNumbers;
}
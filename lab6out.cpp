//radiance
//lab6out
//lottery sim main

#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Lottery.h"

using namespace std;

int main()
{
	//variable declaration/initialization
	int no_balls = 0;
	bool result = false;
	int val = 0;
	char repeat = 'y';
	Lottery lottery;

	//initialize rand
	srand(time(0));

	//display graphics
	displayGraphics();

	do
	{

		//prompt for number of lotto balls
		cout << "How many lottery balls do you want to play: ";
		cin >> no_balls;

		//set number of lotto balls / display error message
		result = lottery.setNoBalls(no_balls);
		if (result == false)
			cout << "Number out of range. It has been reset." << endl;

		//prompt for lotto numbers / data validation
		for (int i = 1; i < no_balls; i++)
		{
			do
			{
				cout << "Enter lottery #" << i << " (between 1 and 40): ";
				cin >> val;
				result = lottery.addNumber(val);
				if (result == false)
					cout << "Incorrect input. Please Re-";
			} while (result == false);
		}

		//display user-selected lotto numbers


		//display winning numbers


		//display number of balls, matches, total winnings
		gout << setPos(150, 100) << "Number of Balls Played: " << lottery.getNoBalls() << endg;
		gout << setPos(150, 120) << "Number of Matches: " << lottery.getMatches() << endg;
		gout << setPos(150, 120) << "Your Payout: " << lottery.computeWinnings() << endg;

		//prompt for repeat
		cout << "Would you like to repeat? (y/n): ";
		cin >> repeat;
		clearGraphics();
		system("cls");
	} while (repeat == 'y' || repeat == 'Y');
	return 0;
}
/*
Michael Bailey
Assignment: Letter thing with stamps
This program implements a postage addressing system for letters mailed via USPS.
*/

#include <iostream>
#include "graph1.h"
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight);

int main()
{
    //Variable Declaration/Initialization
string fname = "";
string lname = "";
string address = "";
string city = "";
string state = "";
string zipcode = "";
string upperName = "";
int weight = 0;
const int MAXWEIGHT = 6;
const int MINWEIGHT = 1;
double totalCost = 0;
int darkBox = 0;
double stampRate = 0.47;
string upperState;
bool res = false;
char repeat = 'y';

//Display graphics window
displayGraphics();

do
{
//Get First Name
  do
  {
    //Prompt for First Name 
    fname = getString("Enter First Name: ");

    //validate
    res = validateName(fname);
  } while (!res);

//Get Last Name
  do
  {
    //Prompt for the Last Name 
    lname = getString("Enter Last Name: ");

    //validate
    res = validateName(lname);

  } while (!res);

 //Get Street Address
  do
  {
    //Get Address
    address = getString("Enter Address: ");

    //validate Address
    res = validateAddress(address);

  } while (!res);

  //Get City
  do
  {
    //Get city
    city = getString("Enter City: ");

    //validate City
    res = validateCity(city);

  } while (!res);

//Get State
  do
  {
    //Get State
    state = getString("Enter State: ");
    //validate State
    res = validateState(state);
  } while (!res);

  state = convertToUpper(state);

  //Get Zipcode
  do
  {
    //Get Zip
    zipcode = getString("Enter valid Zipcode: ");

    //validate Zip
    res = validateZip(zipcode);

  } while (!res);

//Get weight
  do
  {
    cout << "Enter weight: ";
    cin >> weight;

    if (weight < MINWEIGHT || weight > MAXWEIGHT)
    {
      cout << "Invalid weight. Please enter a weight from 1 to 6. " << endl;
    }
  }while (weight < MINWEIGHT || weight > MAXWEIGHT);

  //Display the fields
 displayLetter(fname, lname, address, city, state, zipcode, weight);

 drawRect(200, 385, 290, 85);
 darkBox = drawRect(202, 388, 284, 80);
 setColor(darkBox, 0, 0, 0);
 gout << setPos(205, 400) << "Weight: " << weight << " ounces";
 gout << setPos(205, 415) << "Cost of First Class Stamp: " << setPrecision(2) << stampRate << "cents";
 totalCost = weight * stampRate;
 gout << setPos(205, 430) << "Total mailing cost: $" << setPrecision(2) << totalCost << endg;


  cout << "Repeat the program? [y/n]";
  cin >> repeat;
  clearGraphics();
  system("cls");
} while ((repeat == 'y') || (repeat == 'Y'));

return 0;
}


string getString(string prompt)
{
  string userprompt = "";
cout << prompt;
getline(cin, userprompt);

return userprompt;
}

bool validateName(string name)
{
 bool res = true;

//Validate the name as specified

  for (int i = 0; i < name.length(); i++)
  {  
    if (isalpha(name[i]) == 0)
    {
      if (isspace(name[i])==0)
      {
       cout << "Name is not valid. \n";
       res = false;
       break;
      }
    }
  }
return res;
}

bool validateAddress(string address)
{
bool res = true;

//Validate the address

  for (int i = 0; i < address.length(); i++)
  {
    if (isalnum(address[i])==0)
    {
      if (isspace(address[i]) == 0)
      {
      cout << "Address is not valid. \n";
      res = false;
      break;
      }
    }
  }
return res;
}

bool validateCity(string city)
{
bool res = true;

//Validate the city

  for (int j = 0; j < 2; j++)
  {
    convertToUpper(city);

    for (int i = 0; i < city.length(); i++)
    {
      if (isalpha(city[i]) == 0)
      { 
        if (isspace(city[i]) == 0)
        {
        cout << "Not a valid city. \n";
        res = false;
        break;
        }
      }
    }
  }
return res;
}

bool validateState(string state)
{
  bool res = true;

  //Validate the city

  for (int i = 0; i < state.length(); i++)
  {
    if (isalpha(state[i]) == 0)
    {
      cout << "Not a valid state. \n";
      res = false;
      break;
    }
  }
return res;
}

bool validateZip(string zip)
{
  bool res = true;

  //Validate the city

  for (int i = 0; i < zip.length(); i++)
  {
    if (isdigit(zip[i]) == 0 || zip.length() != 5)
    {
      cout << "Not a valid zipcode. \n";
      res = false;
      break;
    }
  }
return res;
}

string convertToUpper(string input)
//Convert input to all uppercase
{
  string convertToUpper(string input);

    for (int i = 0; i < 2; i++)
    {
      input[i] = toupper(input[i]);
    }
    return input;
  }

void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight)
{
  int x = 520;
  int y = 20;
  int no_colums = 3;
  int left_shift = 75;
  int down_shift = 79;
  int i = 0;
  displayBMP("envelope.bmp", 0, 0);
  displayBMP("returnAddress.bmp", 43, 26);
  gout << setPos(315, 210) << fn << " " << ln << endg;
  gout << setPos(315, 220) << addr << endg;
  gout << setPos(315, 230) << city << ", " << state << " " << zip << endg;

  switch (weight)
  {
  case 1:
    displayBMP("stamp.bmp", 520, 20);
    break;

  case 2:
    for (int i = 0; i < weight; i++)
    {
      displayBMP("stamp.bmp", x - (left_shift*i), y);
    }
    break;

  case 3:
    for (int i = 0; i < weight; i++)
    {
      displayBMP("stamp.bmp", x - (left_shift*i), y);
    }
    break;

  case 4:
    for (int i = 0; i < no_colums; i++)
    {
      displayBMP("stamp.bmp", x - (left_shift*i), y);

      if (weight > 3)
      {
        displayBMP("stamp.bmp", x, y + (down_shift));
      }
    }
    break;

  case 5:
    for (int i = 0; i < no_colums; i++)
    {
      displayBMP("stamp.bmp", x - (left_shift*i), y);

      if (weight > 4)
      {
        displayBMP("stamp.bmp", x, y + (down_shift));
        displayBMP("stamp.bmp", x - left_shift, y + down_shift);
      }
    }
    break;

  case 6:
    for (int i = 0; i < no_colums; i++)
    {
      displayBMP("stamp.bmp", x - (left_shift*i), y);

      if (weight > 5)
      {
        displayBMP("stamp.bmp", x, y + (down_shift));
        displayBMP("stamp.bmp", x - left_shift, y + down_shift);
        displayBMP("stamp.bmp", x - (left_shift * 2), y + down_shift);
      }
    }
    break;
  }
}
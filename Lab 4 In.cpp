/*
Michael Bailey
Assignment: Lab 4 In
Converts to upper
*/

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validatePhone(string phone);
string convertToUpper(string string);
void displayFields(string name, string address, string phone);


int main()
{

  //Variable Declaration/Initialization
  string name = "";
  string address = "";
  string phone = "";
  string upperName = "";
  bool res = false;
  char repeat = 'y';

  //Display graphics window
  displayGraphics();

do
 {

  //Process name info
  do
  {
    //Prompt for the name - 
    name = getString("Enter Name: ");

    //validate the name
    res = validateName(name);

  } while (!res);

  //Process the address info
  do
  {
    //Get the address
    address = getString("Enter Address: ");

    //validate the address
    res = validateAddress(address);

  } while (!res);

  //Process phone info
  do
  {
    //Get the phone
    phone = getString("Enter Phone: ");

    //validate the phone
    res = validatePhone(phone);

  } while (!res);



  //Convert the name to all uppercase
  upperName = convertToUpper(name);

  //Display the fields
  displayFields(upperName, address, phone);

  cout << "Repeat the program? [y/n]";
  cin >> repeat;

  } while ((repeat == 'y') || (repeat == 'Y'));

  return 0;
}


//Prompts for input based on input parameter prompt
string getString(string prompt)
{
    string userprompt = "";
    cout << prompt;
    getline(cin, userprompt);

    return userprompt;
}

//Validates characters of name
bool validateName(string name)
{
bool res = true;

 //Validate the name – return true if valid, false if not

for (int i = 0; i < name.length(); i++)
{
  if (isalpha(name[i])==0)
   {
    if (isspace(name[i]) == 0)
    {
    cout << "Name is not valid. ";
    res = false;
break;
    }
  }
return res;
}
}


//Validates characters of address
bool validateAddress(string address)
{
bool res = true; 

  //Validate the address – return true if valid, false if not
  for (int i = 0; i < address.length(); i++)
  {
    if (isalnum(address[i]) == 0)
    {
      if (isspace(address[i]) == 0)
      {
        cout << "Address is not valid. ";
        res = false;
break;
      }
    }
  }
  return res;
}



//Validates characters of phone number
bool validatePhone(string phone)
{
bool res = true;

  //Validate the phone – return true if valid, false if not
if (phone.length()!=10)
   res=false;
for (int i = 0; i < phone.length(); i++)
 { 
 if (isdigit(phone[i])==0)
{
 cout << "Invalid phone number. ";
 res = false;
 break;
}
return res;
}
}

//Converts text to uppercase
string convertToUpper(string input)
  //Convert input to all uppercase
  {
    int i = 0;

    char c;
    while (input[i])
    {

      c = input[i];
      input[i] = (toupper(c));
      i++;
    }
    return input;

  //Return converted input
}

//Displays the information in graphics window
void displayFields(string name, string address, string phone)
{
  int rect_obj1 = 0;
  int rect_obj2 = 0;
  int rect_obj3 = 0;
  int rect_obj4 = 0;

  gout << setPos(150, 100) << "Name:" << endg;
  rect_obj1 = drawRect(230, 85, 170, 20);
  setColor(rect_obj1, 128, 128, 128);
  gout << setPos(230, 100) << name << endg;
  gout << setPos(150, 140) << "Address:" << endg;
  rect_obj2 = drawRect(230, 125, 170, 20);
  setColor(rect_obj2, 128, 128, 128);
  gout << setPos(230, 140) << address << endg;
  gout << setPos(150, 180) << "Phone Number:" << endg;
  rect_obj3 = drawRect(230, 165, 170, 20);
  setColor(rect_obj3, 128, 128, 128);
  gout << setPos(230, 180) << phone << endg;
}

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int value1 = 0;
  double value2 = 0.0;
  char int_array[] = "1023";
  char double_array[] = "232.218";
  string buffer;
  string fn;
  string ln;

  //Prompt for an integer
  cout << "Enter an integer: ";
  getline(cin,buffer);  //Store an int into a string - easy to validate as int!
  value1 = stoi(buffer);  //Convert the string to an int

  //Prompt for a double
  cout << "Enter a double: ";
  getline(cin,buffer); //Store the double into the string - easy to validate as a double
  value2 = stod(buffer); //Convert the string to a double

  //Prompt for fn
  cout << "Enter first name: ";
  getline(cin, fn);

  //prompt for ln
  cout << "Enter last name: ";
  getline(cin, ln);

  //Additional conversion example using atoi/atof
  value1 = atoi("10");
  value1 = atoi(int_array);
  value2 = atof("674232.918765");
  value2 = atof(double_array);

  return 0;
}
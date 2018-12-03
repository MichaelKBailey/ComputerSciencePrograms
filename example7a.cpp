#include <iostream>
#include <string>


using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int value1 = 0;
  double value2 = 0.0;
  string fn;
  string ln;

  //Prompt for an integer
  cout << "Enter an integer: ";
  cin >> value1;

  //Prompt for a double
  cout << "Enter a double: ";
  cin >> value2;

  //Prompt for fn
  cout << "Enter first name: ";
  getline(cin, fn);

  //prompt for ln
  cout << "Enter last name: ";
  getline(cin, ln);

  return 0;
}
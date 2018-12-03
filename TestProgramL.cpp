/*
Michael Bailey
This program deals with rainfall
Not from your class
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int no_months = 12; 

int main()
{
///var dec
double* high = nullptr; 
double* low = nullptr;
double avg = 0;
double total = 0;
char repeat = 'y';
double rain = 0;


double RainfallArray[no_months] = {NULL};


for (int i = 0; i < no_months; i++)
{
cout << "Please enter the rainfall for month number: " << i + 1 << endl;
cin >> rain;
RainfallArray[i] = rain;
if (rain < 0)
{
  cout << "Please enter a positive value for rain ";
}
else
total += rain;
avg = total/no_months;
if (rain > *high)
{
  *high = rain;
}
if (rain < *low)
{
  *low = rain;
}
}
cout << "Total rainfall is: " << total << endl;
cout << "Average rainfall is: " << avg << endl;
cout << "The highest amount of rainfall was: " << high << endl;
cout << "The month with the highest rainfall was: " << *high << endl;
cout << "The month with the highest rainfall was: " << *low << endl;

cout << "Repeat? :";
cin >> repeat;

return 0;
}
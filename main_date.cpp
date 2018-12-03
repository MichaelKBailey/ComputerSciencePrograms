#include <iostream>
#include <cstdlib>
#include "graph1.h"
#include "Date.h"

using namespace std;

Date operator+(double value, Date c);

ostream& operator<<(ostream &out, Date right_side);
istream& operator>>(istream &in, Date& right_side);
Gout& operator<<(Gout& out, Date& right_side); 


int main()
{
  int a = 9;
  Date c1(0,0,0);
  Date c2(1,1,1);
  Date c3(2,2,2);
  Date c4;
  Date c5;
  Date c6(3,3,3);
  Date c7(4,4,4);
  Date c8(5,5,5);
  Date& c9 = c3;
  Date& c13 = c5;
  c9 = c6;
  
  //Display graphics
  displayGraphics();
  
 
  
  c4 = c1 + c2;
  c4 = ((c1 - c2) + c3)+a;
  
  c5 = (c1 + c2)-c3;
  c4 = c1++ + c2;
  c4 = ++c1 + c2;
 
  c5 = c2-c3++ + ++c6+c7;
  Date c10 = 9.0 + c4;

    
  Date& c11 = c2.returnRef(c3);
  
  ((c3.returnRef(c3)).returnRef(c3)).returnRef(c3);
  //cout << c11 << endl;
  cout << &c11 << endl;
  cout.operator<<(9.0).operator<<("Joe").operator<<(endl);
  c4.operator+(c5);

  int aa = 9;
 
  system("cls");
  cin >> c8 >> c4 >> aa;
  
  cout << c1 << c2 << c3 << endl;

  //Display date using gout
  gout << c9 << endg;


  
  return 0;
}

Date operator+(double value, Date c)
{
  Date result;
  result.setDate(c.getDay() + (int)value,c.getMonth(),c.getYear());
  
  return(result);
}
  
ostream& operator<<(ostream &out, Date right_side)
{
  out << "Day: " << right_side.day << " " << "Month: " << right_side.month << endl;
  return (out);
}

istream& operator>>(istream &in, Date& right_side)
{
  int day;
  int month;
  int year;
  cout << "Enter day,month,year:";
  in >> day >> month >> year;
  right_side.day = day;
  right_side.month = month;
  right_side.year = year;
  
  return(in);
} 

Gout& operator<<(Gout& out, Date& right_side)
{
  out << setPos(100,100) << "Day: " << right_side.getDay() << " Month: " << right_side.getMonth() 
      << "Year: " << right_side.getYear()  << endg;
  return(out);
}
  
  
  
  
  
  
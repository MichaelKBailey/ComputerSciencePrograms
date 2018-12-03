// Class definition in "Date.h"
#include <iostream>
#include "Date.h"

using namespace std;


Date::Date::Date()
{
  month = 0;
  day = 0;
  year = 0;
}

Date::Date(int month, int day, int year)
{
  this->month = month;
  this->day = day;
  this->year = year;
}



							
void Date::setDate(int month, int day, int year)
{
  this->month = month;
  this->day = day;
  this->year = year;
}

int Date::getDay()
{
  return day;
}
int Date::getMonth()
{
  return month;
}
int Date::getYear()
{
  return year;
}

							
//-----------------------------------------------------------------------
// Performs assignment of dates
//
void Date::operator=(Date right_side)  
{
  this->month = right_side.month;
  this->day = right_side.day;
  this->year = right_side.year;
}
							


//-----------------------------------------------------------------------
// Overloaded operator for adding dates
//   
//   
//
Date Date::operator+(Date val)
{
  Date result;

  //Add days together first
  result.day = (day + val.day)%31;
  result.month = (month + val.month)%12;
  result.year = year + val.year;

  
  return(result);
}

Date Date::operator-(Date val)
{
  Date result;

  //Eliminates overflow problem
  result.day = abs(day - val.day);
  result.month = abs(month - val.month);
  result.year = abs(year - val.year);
  
  return(result);
} 

Date Date::operator+(int day)
{
  //Add days together
  Date result;

  result.day = this->day + day;
  result.month = month;
  result.year = year;

 
  
  return(result);

}



							

//-----------------------------------------------------------------------
// Increments the date (postfix operator)
//
Date Date::operator++(int dummy)       
{
  dummy = 0;                   // to prevent compiler warning
  // Save old value of date
  Date old_value = *this;
  // Increment date (call prefix operator to do the work)
  ++(*this);
  
  // Return old value  
  return old_value;
}
							
//-----------------------------------------------------------------------
// Increments the date (prefix operator)
//
Date& Date::operator++( )              
{
 
    day++;
  
  // Return new value of date  
  return *this;
}
//-----------------------------------------------------------------------
// Decrements the date (postfix operator)
//
Date Date::operator--(int dummy)       
{
  dummy = 0;                   // to prevent compiler warning
  // Save old value of date
  Date old_value = *this;
  // Decrement date (call prefix operator to do the work)
  --(*this);
  
  // Return old value  
  return old_value;
}
							
//-----------------------------------------------------------------------
// Decrements the date (prefix operator)
//
Date& Date::operator--( )              
{
 
    day--;
  
         
  // Return new value of date  
  return *this;
}
//-----------------------------------------------------------------------
// Increments this date by the specified day_count
//
void Date::operator+=(int day_count)
{
  // Call prefix operator the number of times specified by day_count
  for (int count = 1; count <= day_count; count++)
  {
    ++(*this);
  }
}
							


Date& Date::returnRef(Date& c1)
{
  c1.day++;
  c1.month++;
  c1.year++;
  return c1;
} 



  

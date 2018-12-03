#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
    // Prints the date to screen in the format 1-1-2000
     
    
  private: 		
    int day;                         // 1 to 28-31, depending on month and year
    int month;                       // 1 to 12
    int year;                        // 1000 to 2100 A.D.
    int array[3];
    
                        
  public:
    // ** Constructors and Destructors
    // Default Constructor: Initializes date to 1-1-2000 and weekday = 7 or 
    Date();
    Date( int month, int day, int year) ;		
    void setDate(int month, int day, int year);
    int getDay();
    int getMonth();
    int getYear();
   


    friend ostream& operator<<(ostream& screen_out,  Date date_obj);
    friend istream& operator>>(istream& in, Date& date_obj);
    Date Date::operator+(int day);
   
    void operator=(Date right_side);     // Performs assignment of dates
    // Validates and sets the date.  If date is invalid, sets to default value
    //     of 1-1-00, and weekday = 7.
  \
    Date operator++(int dummy);      // Increments the date (postfix operator)
    Date& operator++();              // Increments the date (prefix operator)
    Date operator--(int dummy);      // Decrements the date (postfix operator)
    Date& operator--( );             // Decrements the date (prefix operator)
    Date operator+(Date val);        // Adds two dates together
    Date operator-(Date val);        // Subtracts two dates
    int& operator[](int index);
    
    Date& returnRef(Date& c1);       // Returns Refernce
    // Increments this date by the specified day_count
    void operator+=(int day_count);
    // Returns the number of days in specified month, or 0 if month is invalid
    //   and an error message     (Note: 2001 is not a leap year)
      
};
#endif


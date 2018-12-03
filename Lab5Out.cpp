/*
Michael Bailey
Assignment: Lab05Out
This program will: Build a clock with hands and a white background using classes and stuff
*/

double const pi = 3.1415926535897932384;

#include <iostream>
#include "graph1.h"

using namespace std;
// ******************* THIS WHOLE SECTION IS THE .H FILE ************
class Clock
{
private: 
int h;
int m;
int s;

public: 
  Clock();
  bool setHour(int hour);
  bool setMin(int min);
  bool setSec(int sec);
  int getHour();
  int getMin();
  int getSec();
  void draw();

};
// ******************* THIS WHOLE SECTION IS THE .H FILE ************

// ************ THIS WHOLE SECTION IS THE IMPLEMENTATION FILE ***********
Clock::Clock()
{
int h = 0;
int m = 0;
int s = 0;
}

bool Clock::setHour(int hour)
{
bool result = false;

if (hour >= 0 && hour <= 11)
{
  h=hour;
result = true;
}
else if (hour < 0)
{
 h = 0;
return true; 
}
else if (hour > 11)
{
  h = 11;
return true;
}
else
{
  return result;
}
return result;
}

int Clock::getHour()
{
  return h;
}

bool Clock::setMin(int min)
{
  bool result = false;

  if (min >= 0 && min <= 59)
  {
    m = min;
    result = true;
  }
  else if (min < 0)
  {
    m = 0;
    return true;
  }
  else if (min > 59)
  {
    m = 59;
    return true;
  }
  else
  {
    return result;
  }
  return result;
}

int Clock::getMin()
{
  return m;
}

bool Clock::setSec(int sec)
{
  bool result = false;

  if (sec >= 0 && sec <= 59)
  {
    s = sec;
    result = true;
  }
  else if (sec < 0)
  {
    s = 0;
    return true;
  }
  else if (sec > 59)
  {
    s = 59;
    return true;
  }
  else
  {
    return result;
  }
  return result;
}

int Clock::getSec()
{
  return s;
}

void Clock::draw()
{
int background;
int hand_color;
int Alpha;
int end_x = 0;
int end_y = 0;
int center_x = 320;
int center_y = 240;

background = drawRect(25,25,419,405);
setColor(background,0,0,0);
displayPNG("clock_face.png",123,50);

// -------Second Hand ----------//
Alpha = s*6;
if (Alpha < 90 && Alpha >= 0)
{
  end_x = center_x + (cos((90 - Alpha)*pi / 180.0))*150;
  end_y = center_y - (sin((90 - Alpha)*pi / 180.0))* 150;
  hand_color = drawLine(center_x,center_y,end_x,end_y,2);
setColor(hand_color, 255,0,0);
}
else if (Alpha >= 90 && Alpha < 180)
{
  end_x = center_x + (cos((Alpha - 90)*pi / 180.0))* 150;
  end_y = center_y + (sin((Alpha - 90)*pi / 180.0))*150;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 255, 0, 0);
}
else if (Alpha >= 180 && Alpha < 270)
{
  end_x = center_x - (cos((270 - Alpha)*pi / 180.0))* 150;
  end_y = center_y + (sin((270 - Alpha)*pi / 180.0))* 150;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 255, 0, 0);
}
else if (Alpha >= 270 && Alpha < 360)
{
  end_x = center_x - (cos((Alpha - 270)*pi / 180.0))*150;
  end_y = center_y - (sin((Alpha - 270)*pi / 180.0))*150;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 255, 0, 0);
}
else
{
  gout << setPos(50,50) << "Error!!!" << endg;
}

// -------Minute Hand ----------//
Alpha = m * 6 + (s / 60.0) * 6;
if (Alpha < 90 && Alpha >= 0)
{
  end_x = center_x + (cos((90 - Alpha)*pi / 180.0)) * 180;
  end_y = center_y - (sin((90 - Alpha)*pi / 180.0)) * 180;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 0, 0, 0);
}
else if (Alpha >= 90 && Alpha < 180)
{
  end_x = center_x + (cos((Alpha - 90)*pi / 180.0)) * 180;
  end_y = center_y + (sin((Alpha - 90)*pi / 180.0)) * 180;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 0, 0, 0);
}
else if (Alpha >= 180 && Alpha < 270)
{
  end_x = center_x - (cos((270 - Alpha)*pi / 180.0)) * 180;
  end_y = center_y + (sin((270 - Alpha)*pi / 180.0)) * 180;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 0, 0, 0);
}
else if (Alpha >= 270 && Alpha < 360)
{
  end_x = center_x - (cos((Alpha - 270)*pi / 180.0)) * 180;
  end_y = center_y - (sin((Alpha - 270)*pi / 180.0)) * 180;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 2);
  setColor(hand_color, 0, 0, 0);
}
else
{
  gout << setPos(50, 50) << "Error!!!" << endg;
}

// -------Hour Hand ----------//
Alpha = h * 30 + (m / 60.0) * 30;
if (Alpha < 90 && Alpha >= 0)
{
  end_x = center_x + (cos((90 - Alpha)*pi / 180.0)) * 133;
  end_y = center_y - (sin((90 - Alpha)*pi / 180.0)) * 133;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 3);
  setColor(hand_color, 0, 0, 0);
}
else if (Alpha >= 90 && Alpha < 180)
{
  end_x = center_x + (cos((Alpha - 90)*pi / 180.0)) * 133;
  end_y = center_y + (sin((Alpha - 90)*pi / 180.0)) * 133;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 3);
  setColor(hand_color, 0, 0, 0);
}
else if (Alpha >= 180 && Alpha < 270)
{
  end_x = center_x - (cos((270 - Alpha)*pi / 180.0)) * 133;
  end_y = center_y + (sin((270 - Alpha)*pi / 180.0)) * 133;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 3);
  setColor(hand_color, 0, 0, 0);
}
else if (Alpha >= 270 && Alpha < 360)
{
  end_x = center_x - (cos((Alpha - 270)*pi / 180.0)) * 133;
  end_y = center_y - (sin((Alpha - 270)*pi / 180.0)) * 133;
  hand_color = drawLine(center_x, center_y, end_x, end_y, 3);
  setColor(hand_color, 0, 0, 0);
}
else
{
  gout << setPos(50, 50) << "Error!!!" << endg;
}
}

// ************ THIS WHOLE SECTION IS THE IMPLEMENTATION FILE ***********


int main()
{
int hour = 0;
int min = 0;
int sec = 0;
bool result;
char repeat;

Clock Clock1;

displayGraphics();

do
{
cout << "Please enter the seconds: ";
cin >> sec;

result = Clock1.setSec(sec);
if (result == false)
{
  cout << "Please re-enter the number of seconds." << endl;
}

cout << "\nPlease enter the minutes: ";
cin >> min;

result = Clock1.setMin(min);
if (result == false)
{
  cout << "Please re-enter the number of minutes." << endl;
}

cout << "\nPlease enter the hour: ";
cin >> hour;

result = Clock1.setHour(hour);
if (result == false)
{
  cout << "Please re-enter the hour." << endl;
}

Clock1.draw();

gout << setPos(280, 440) << "Time: " << Clock1.getHour() << ":" << Clock1.getMin() << ":" << Clock1.getSec() << endg;


cout << "\nWould you like to repeat the program? [Y/N]: ";
cin >> repeat;

} while (repeat == 'y' || repeat == 'Y');

clearGraphics();
system("cls");

return 0; 
}
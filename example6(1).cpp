#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;




int main()
{

  //Variable Declaration/Initialization  
  int i = 0;
  string  str = "7-Eleven";
  string  num_str = "10";
  string copy;
  copy = str;
  string upper = "";
  string copy1;
  string new_string = str + upper;
  const char* str1 = str.c_str(); //Get the array of characters from the string
  
  

  for (i = 0; i < (int)str.length(); i++)
  {
    copy1 += str[i]; //Append a char at a time
  }

  //Need to do this instead
  
  for (i = 0; i < (int)str.length(); i++)
  {
    //Check for alpha
    if (isalpha(str[i]) == 0)
    {
      if (isspace(str[i]) == 0)
      {
        cout << "Bad name" << endl;
        break;
      }
    }
  }

  //Convert to upper case and add characters (assume upper is not initialized with # of characters larger than str
  for (i = 0; i < (int)str.length(); i++)
  {
    str[i]= toupper(str[i]);
  }


 
  cout << upper << endl;



    

 
  return 0;

}


  
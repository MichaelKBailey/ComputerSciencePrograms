#include <iostream>
#include "Array.h"

using namespace std;

void function(Array a,int size);


int main()
{
  //Create an array of size 10
  int i = 0;
  int size = 10;
  Array array1(size);
  Array array2; //What happens here ?
  
  //Initialize the array
  for (i = 0; i < size; i++)
  {
    array1.put(i,i);
  }
    
  //Call function foo
  function(array1,size);

  //display array1
  for (i = 0; i < size; i++)
  {
    cout << "Element no " << i << " " << array1.get(i) << endl;
  }

  
  

  

  return 0;
}

void function(Array a,int size)
{
  //Variable Declaration/Initialization
  int i = 0;
  int total = 0;
  
  //Calculate total
  for (i = 0; i < size; i++)
  {
    total = total + a.get(i);
  }
  
  
  return;
}
    

  

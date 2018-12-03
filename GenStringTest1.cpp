#include <iostream>
#include <iomanip>
#include "GenString1.h"

using namespace std;



// Driver function to test Class String member functions    
int main( void )
{
  // Variable declarations/initializations
  const int SIZE = 5;
  int i = 0;
  int index = 0;
  
  // *** Test the default constructor, setString() and getString()
  // Specify an array of strings with the default constructor
  GenString string_array[SIZE]; 
  GenString gen;
  
  //Test parameterized array
  GenString string_array1[SIZE] = {GenString("Joe Smith"), GenString("Jim Davis"),GenString("joe smith")};
  GenString string_array2[] = {GenString("Jim Johnson"), GenString(), GenString("Joe Smith"), GenString("Jerry Jones")};
  
  GenString gen_string_extra("Joe Smith");
  const char *string3 = gen_string_extra.getString1();
  //string3[0] = 'J';

    
  /**********************************************************************************/
  /*****Additional Tests showing use of Pointers************************************/
  //Allocate space to hold the pointer
  GenString *gen_string_ptr;
  
  
  //Set gen_string_ptr to 3rd element (element of 2) of the array
  gen_string_ptr = &string_array2[2];
  cout << (*gen_string_ptr).getString() << endl;
  cout << gen_string_ptr->getString() << endl;
  cout << gen_string_ptr[0].getString() << endl;
  cout << gen_string_ptr[1].getString() << endl;
  cout << (gen_string_ptr + 1)->getString() << endl;
 
  
  //Allocate gen_string_ptr to a single pointer (use parametrized constructor
  gen_string_ptr = new GenString;  
  delete gen_string_ptr;

  gen_string_ptr = new GenString();
  delete gen_string_ptr;

  gen_string_ptr = new GenString("  The   brown   fox ran     quickly     ");
  
  //Cleanup the memory (destructor called automatically)
  delete gen_string_ptr;
      
  return 0;
}
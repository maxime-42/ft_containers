
#include "vector.hpp"
#include <vector>
using namespace std;

void originalVector()
{
   std::vector<int> foo;
  for (int i=0; i<10; ++i) 
  {
    foo.push_back(i);
    std::cout << "befor : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;
  }
  std::cout << "\n" << std::endl;
  // foo.pop_back();
  // foo.resize(20);
  std::cout << "then : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;
  for (vector<int>::iterator ptr = foo.begin(); ptr != foo.end(); ptr++)
  {
    std::cout << *ptr << "   ";
  }
}

void myVector()
{
  ft::vector<int> foo;
  for (int i=0; i<10; ++i) 
  {
    //&*itertor.mpr
    foo.push_back(i);
    std::cout << "befor : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;
  }
  std::cout << "\n" << std::endl;
  // foo.pop_back();
  std::cout << "then : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;
 
  ft::vector<int>::iterator ptr = foo.begin();
  // ft::vector<int>::iterator ptr2 = ptr+2;

  // if (ptr2 < ptr)
  // {
    std::cout <<  "ptr = " << *ptr+3;
  // }
  // else
  //   std::cout << "ptr2 superieur a ptr\n";

  std::cout << *ptr << "   ";
  (void)ptr;
  &*ptr;
  //  for (;ptr2 != foo.end(); ptr2++)
  // {
  //   std::cout << *ptr2 << "   ";
  // }
}

int main ()
{
  // originalVector();
  std::cout << "\n\n************************************************************************************************************************************************************************* \n" << std::endl;
  myVector();
  return (0);
}
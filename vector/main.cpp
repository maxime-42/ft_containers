
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
  foo.pop_back();

  // foo.resize(20);
  std::cout << "then : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;
  for (size_t i = 0; i <foo.size(); i++)
  {
    std::cout << foo[i] << "   ";

  }
  // std::cout << "\n" << std::endl;
 
}

void myVector()
{
  ft::vector<int> foo;
  for (int i=0; i<10; ++i) 
  {
    foo.push_back(i);
   std::cout << "befor : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;

  }
  std::cout << "\n" << std::endl;

  // foo.resize(20);
  // std::cout << "then : capacity  = " << foo.capacity() << " size : " << foo.size() << std::endl;
  for (size_t i = 0; i <foo.size(); i++)
  {
    std::cout << foo[i] << "   ";

  }

}

int main ()
{
  originalVector();
  std::cout << "\n\n************************************************************************************************************************************************************************* \n" << std::endl;
  // myVector();
  return (0);
}
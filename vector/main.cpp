
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
//   &*ptr;
  //  for (;ptr2 != foo.end(); ptr2++)
  // {
  //   std::cout << *ptr2 << "   ";
  // }
}

// int main ()
// {
//   // originalVector();
//   std::cout << "\n\n************************************************************************************************************************************************************************* \n" << std::endl;
//   myVector();
//   return (0);
// }

#include <bits/stdc++.h>
using namespace std;
  

void print_container(const std::vector<int>& c) 
{
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}
 
int main( )
{
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_container(c);
 
    c.erase(c.begin());
    print_container(c);
 
    std::vector<int>::iterator ret = c.erase(c.begin(), c.begin()+2);
    print_container(c);
	std::cout << "ret = " << *ret << std::endl;
 
    // Erase all even numbers (C++11 and later)
    // for (auto it = c.begin(); it != c.end(); ) {
    //     if (*it % 2 == 0) {
    //         it = c.erase(it);
    //     } else {
    //         ++it;
    //     }
    // }
    // print_container(c);
}
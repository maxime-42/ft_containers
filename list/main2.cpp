#include "list.hpp"
#include <iostream>
#include <list>
#include <string>
#include <cctype>

#ifdef STD
 using namespace std;
 #define NAMESPACE_DEFINED
#endif

#ifdef FT
 using namespace ft;
 #define NAMESPACE_DEFINED
#endif

#ifndef NAMESPACE_DEFINED
 using namespace std;
#endif


void	print_list(list<int> &list)
{
    for (list<int>::iterator x = list.begin() ; x != list.end(); x++)
        std::cout << *x << " address =  " << &*x <<std::endl;
}

void test_remove()
{
  list<int> l1;
  int n = 8;
	l1.push_back(1);
	l1.push_back(8);
	l1.push_back(2);
	l1.push_back(6);
  std::cout << "befor remove " << n << std::endl;
  print_list(l1);
  l1.remove(n);
  std::cout << "after remove " << n << std::endl;
  print_list(l1);
}

int main(void)
{
    test_remove();
    return (0);
}

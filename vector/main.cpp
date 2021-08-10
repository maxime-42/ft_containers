#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>
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



void test_construtor()
{
  std::cout << "test constructeur" << std::endl;
  vector<int> first;                                // empty vector of ints
  vector<int>  second (4,100);                       // four ints with value 100
  vector<int> third (second.begin(),second.end());  // iterating through second
  vector<int> fourth (third);                       // a copy of third  
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  std::cout << "The contents of fifth are:";
  for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}


void  test_operator()
{
   vector<int> foo (3,100);   // three ints with a value of 100
  vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

int main() 
{
	test_operator();


	return 0;
}
#include <stack>
#include <vector>
#include "stack.hpp"
#include <deque>          // std::deque
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


int test_stack()
{
	vector<int> mydeque (3,100);          // deque with 3 elements
	vector<int> myvector (2,200);        // vector with 2 elements

	stack<int> first;                    // empty stack
	stack<int> second (mydeque);         // stack initialized to copy of deque

	stack<int,vector<int> > third;  // empty stack using vector
	stack<int,vector<int> > fourth (myvector);


  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}

int test_pop()
{
	stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  return 0;
}

int test_top ()
{
  stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}

int	main()
{
	// test_stack();
	// test_pop();
	test_top();
	// std::cout << "hellow" << std::endl;
	return (0);
}
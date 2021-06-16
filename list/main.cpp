#include "list.hpp"
#include <iostream>
#include <list>
#define SIZE 5
// using namespace std;

void test_push_front()
{
  ft::list<int> myList;

    std::cout << "push front" << std::endl;
    for (size_t i = 1; i < 5; i++)
    {
        myList.push_front(i * 10);
    }

    ft::list<int>::iterator it = myList.begin();
    std::cout << "1 wsh val = " << *it << std::endl;
    std::cout << "2 wsh val = " << *it << std::endl;

    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it--)
    {
        std::cout << " " << *it << std::endl;
    }
}

void test_push_back()
{
  ft::list<int> myList;

    std::cout << "push back" << std::endl;

    for (size_t i = 1; i < 5; i++)
    {
        myList.push_back(i * 10);
    }
    
    // myList.push_front(2);

    ft::list<int>::iterator it = myList.begin();
    // std::cout << "wsh val = " << *it << std::endl;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it--)
    {
        std::cout << " " << *it << std::endl;
    }
}

void test_swap()
{
  ft::list<int> first (5,100);   // three ints with a value of 100
//   ft::list<int> second (5,200);  // five ints with a value of 200
// 
//   first.swap(second);

  std::cout << "first contains:";
  for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it--)
    std::cout << ' ' << *it;
  std::cout << '\n';
// // 
//   std::cout << "second contains:";
//   for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
}
			// _myAlloc.deallocate(toDel, 1);
void test_sort()
{
  std::list<int> mylist;
  std::list<int>::iterator it;
  mylist.push_back (5);
  mylist.push_back (1);
  mylist.push_back (9);
  mylist.push_back (2);


  std::cout << "befor sort mylist contains:\n";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << *it << " addr = " << &*it << "\n";
  std::cout << "\n\n";

  mylist.sort();

//   mylist.sort(compare_nocase);

  std::cout << "after sor  mylist contains:\n";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << *it << " addr = " << &*it<< "\n";
  std::cout << '\n';
}

void my_test_sort()
{
  ft::list<int> mylist;
  ft::list<int>::iterator it;
  mylist.push_back (5);
  mylist.push_back (1);
//   mylist.push_back (9);
//   mylist.push_back (2);


  std::cout << "befor sort mylist contains:\n";
  for (it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << *it << " addr = " << &*it << "\n";
  std::cout << "\n\n";

  mylist.sort();
    
    it = mylist.begin();it--;
  std::cout << "begin =  " << *it;

    // it = mylist.end();
//     it++;
//   std::cout << "\nend =  " << *it;
    return ;
  std::cout << "after sor  mylist contains:\n";
  for (it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << *it << " addr = " << &*it<< "\n";
  std::cout << '\n';
}


int main(void) 
{
    // test_push_front();
    // test_swap();
    my_test_sort();
    // std::cout << "\n\n" << std::endl;
    // test_push_back();
  
    return (0);
}
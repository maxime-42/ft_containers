#include "list.hpp"
#include <iostream>
#include <list>
#include <string>
#include <cctype>

#define SIZE 5

using namespace std;

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


bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

void my_test_sort()
{
  ft::list<int> mylist;
  ft::list<int>::iterator it;
  mylist.push_back (5);
  mylist.push_back (1);
  mylist.push_back (9);
  mylist.push_back (2);
  mylist.push_back (7);
  mylist.push_back (20);
  mylist.push_back (4);
  mylist.push_back (6);
  mylist.push_back (0);

  std::cout << "size = " << mylist.size() << std::endl;
  std::cout << "befor sort mylist contains:\n";
  for (it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << *it << " addr = " << &*it << "\n";
  std::cout << "\n\n";

  // std::cout << "sort :\n" << std::endl;
  mylist.sort();
  std::cout << "\nafter sort  mylist contains:\n";
  it = mylist.begin();
  for (it=mylist.begin(); it != mylist.end(); it++)
    std::cout << *it << " addr = " << &*it<< "\n";
  std::cout << '\n';
  std::cout << '\n';
}

using namespace std;
  
void  test()
{
    std::list<int> l1;
    std::list<int> l2 ;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    l2.push_back(50);
    l2.push_back(40);
    l2.push_back(50);

    std::cout << "list l1 befor splice:" << std::endl;
    for (std::list<int>::iterator x = l1.begin() ; x != l1.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;

    std::cout << "\nlist l2 befor splice:" << std::endl;
    for (std::list<int>::iterator x = l2.begin() ; x != l2.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;


    // transfer all the elements of l2
    std::list<int>::iterator i = l2.begin();
    i++;
    // std::cout << "i = " << *i << std::endl;
    l1.splice(l1.begin(), l2, i);
  
    // at the beginning of l1
    cout << "\nlist l1 after splice operation" << endl;
    for (std::list<int>::iterator x = l1.begin() ; x != l1.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;
  
}

void  test_splice()
{
    ft::list<int> l1;
    ft::list<int> l2 ;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    l2.push_back(50);
    l2.push_back(40);
    l2.push_back(60);

    // list<int> l3 = { 6, 7, 8 };
    std::cout << "list l1 befor splice:" << std::endl;
    for (ft::list<int>::iterator x = l1.begin() ; x != l1.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;

    std::cout << "\nlist l2 befor splice:" << std::endl;
    for (ft::list<int> ::iterator x = l2.begin() ; x != l2.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;


    // transfer all the elements of l2
    ft::list<int>::iterator i = l2.begin();
    i++;
    // std::cout << "i = " << *i << std::endl;
    l1.splice(l1.begin(), l2);
  
    // at the beginning of l1
    cout << "\nlist l1 after splice operation" << endl;
    for (ft::list<int>::iterator x = l1.begin() ; x != l1.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;

      std::cout << "\nlist l2 after splice:" << std::endl;
    for (ft::list<int> ::iterator x = l2.begin() ; x != l2.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;

}

void  test_2()
{
  ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

int main(void) 
{
    // test_push_front();
    // test_swap();
    // my_test_sort();
    // test_2();
    std::cout << "\nstl splice:\n" << std::endl;
    test();
    std::cout << "\nmy splice:\n" << std::endl;
    test_splice();

    // std::cout << "\n\n" << std::endl;
    // test_push_back();
  
    return (0);
}
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

void	print_list(ft::list<int> &list)
{
    for (ft::list<int>::iterator x = list.begin() ; x != list.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;
}

void	print_list(std::list<int> &list)
{
    for (std::list<int>::iterator x = list.begin() ; x != list.end(); x++)
        cout << *x << " address =  " << &*x <<std::endl;
}

void	print_list_rev(ft::list<int> &list)
{
    // for (ft::list<int>::iterator x = list.end() ; x != list.end(); x--)
    //     cout << *x << " address =  " << &*x <<std::endl;
	// ft::list<int>::iterator x = list.end(); 
	ft::list<int>::iterator x = list.end();
	x--;
	while (x != list.end())
	{
        cout << *x << " address =  " << &*x <<std::endl;
		x--;
	}
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

//   mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void  test_splice_2()
{
    ft::list<int> l1;

    ft::list<int> l2;
    l1.push_back(10);
    l1.push_back(20);
	l1.push_back(30);

    l2.push_back(40);
    l2.push_back(50);
    l2.push_back(60);
    l2.push_back(70);
    l2.push_back(80);
    l2.push_back(90);
    l2.push_back(100);
    l2.push_back(200);
    l2.push_back(300);
    std::cout << "list l1 befor splice:" << std::endl;
	print_list(l1);

    std::cout << "\nlist l2 befor splice:" << std::endl;
	print_list(l2);
    ft::list<int>::iterator position = l1.begin();
    std::cout << "\nposition = " << *position << std::endl;
	std::cout << "\n*************** SPLICE ***************" << std::endl;
	ft::list<int>::iterator elem = l2.begin();
	// elem++;
    l1.splice(position, l2, elem);
    cout << "\nlist l1 after splice operation" << endl;
	print_list(l1);
	std::cout << "\nlist l2 after splice:" << std::endl;
	print_list(l2);

}


void  test_splice_3()
{
    ft::list<int> l1;

    ft::list<int> l2;
    l1.push_back(10);
    l1.push_back(20);
	l1.push_back(30);

    l2.push_back(40);
    l2.push_back(50);
    l2.push_back(60);
    l2.push_back(70);
    l2.push_back(80);
    l2.push_back(90);
    l2.push_back(100);
    l2.push_back(200);
    l2.push_back(300);
    std::cout << "list l1 befor splice:" << std::endl;
	print_list(l1);

    std::cout << "\nlist l2 befor splice:" << std::endl;
	print_list(l2);
    ft::list<int>::iterator position = l1.begin();
    std::cout << "\nposition = " << *position << std::endl;
	std::cout << "\n*************** SPLICE ***************" << std::endl;
	ft::list<int>::iterator first = l2.begin();
	// elem++;
	ft::list<int>::iterator last = l2.begin();
	last++;
	last++;
	std::cout << "last = " << *last << std::endl;
    l1.splice(position, l2, first, last);
    cout << "\nlist l1 after splice operation" << endl;
	print_list(l1);
	std::cout << "\nlist l2 after splice:" << std::endl;
	print_list(l2);

}

void reverse_list()
{
  std::list<int> mylist;

  for (int i=1; i<10; ++i) mylist.push_back(i);

	std::cout << "befor reverse" << std::endl;
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	{
		std::cout << "value = "  << *it << " addresse = " << &*it << std::endl;
	}
  mylist.reverse();

  std::cout << "\nafter reveerse s:\n";
	std::cout << "befor reverse" << std::endl;
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	{
		std::cout << "value = "  << *it << " addresse = " << &*it << std::endl;
	}

  std::cout << '\n';

}


void  test_reverse()
{
    ft::list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
	l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
    l1.push_back(60);
    l1.push_back(70);
    l1.push_back(80);
    l1.push_back(90);
    l1.push_back(100);
    l1.push_back(200);
    l1.push_back(300);
    std::cout << "list l1 befor reverse:" << std::endl;
	print_list(l1);

	std::cout << "\n*************** reverser ***************" << std::endl;
	l1.reverse();
	print_list(l1);

}


void test_merge()
{
  ft::list<int> l1;
	ft::list<int> l2;

	l1.push_back(1);
	l1.push_back(8);
	l1.push_back(2);
	l1.push_back(6);

	l2.push_back(-1);
	l2.push_back(7);
	l2.push_back(5);


	std::cout << "\nl1 : " << std::endl;
	print_list(l1);
	std::cout << "\nl2 : " << std::endl;
	print_list(l2);
	// l1.merge(l2, mycomparison);
	l1.merge(l2);

	std::cout << "\nl1 after merge:" << std::endl;
	print_list(l1);

}
void stl_merge()
{
  	std::list<int> l1;
	std::list<int> l2;

	l1.push_back(1);
	l1.push_back(8);
	l1.push_back(2);
	l1.push_back(6);

	l2.push_back(-1);
	l2.push_back(7);
	l2.push_back(5);

	std::cout << "\nl1 : " << std::endl;
	print_list(l1);
	std::cout << "\nl2 : " << std::endl;
	print_list(l2);
	// l1.merge(l2, mycomparison);
	l1.merge(l2);

	std::cout << "\nl1 after merge:" << std::endl;
	print_list(l1);
}

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void  test_merge_2()
{
  ft::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}


int main(void) 
{
  // test_merge();
  // std::cout << "\n\nstl merge\n" << std::endl;
  // stl_merge();
  test_merge_2();
  return (0);
}
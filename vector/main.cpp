
#include "vector.hpp"
#include <vector>
#include <iostream>
#include <vector>
#define SIZE 5
using namespace std;

void  print(ft::vector<int> &tmp)
{
  std::cout << "\nmy vector vector" << std::endl;

  for (ft::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    std::cout << '|' << *it;
  std::cout << '\n';

}

void  print(std::vector<int> &tmp)
{
  std::cout << "\noriginal vector" << std::endl;
  for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    std::cout << '|' << *it;
  std::cout << '\n';

}

void test_construtor()
{
  std::cout << "test constructeur" << std::endl;
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int>  second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (third);                       // a copy of third  
  int myints[] = {16,2,77,29};
  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void begin ()
{
  std::cout << "test begin:" << std::endl;
  ft::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "\nmyvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

#include <vector>

void  end()
{
  std::cout << "\ntest end : " << std::endl;
  ft::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void  test_rbegin()
{
  ft::vector<int> myvector (SIZE);  
  int i=0;
  std::cout << "test rbegin:" << std::endl;

  print(myvector);
  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  std::cout << "size = " << myvector.size() << std::endl;
  for (; rit!= myvector.rend(); ++rit)
  {
    *rit = ++i;
  }

  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << "item " << *it << '\n';
}

void test_size ()
{
  std::cout << "test size:" << std::endl;
  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}


void  test_max_size()
{
    std::cout << "test max_size:" << std::endl;

    ft::vector<char> s;
    std::cout << "Maximum size of a 'vector' is " << s.max_size() << "\n";
}

void originalVector()
{
  std::cout << "My Vector\n" << std::endl;
  //   &*ptr;
  // initialising the vector

}


void  test_empty()
{
    std::cout << "test empty:" << std::endl;
    std::cout << std::boolalpha;
    ft::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

void test_reserve()
{
  std::cout << "test reserve:" << std::endl;
  ft::vector<int>::size_type sz;

  ft::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
}
  
void test_capacity()
{
    std::cout << "test_capacity : " << std::endl;
    int sz = 200;
    ft::vector<int> v1;
 
    size_t cap = v1.capacity();
    std::cout << "initial capacity=" << cap << '\n';
 
    for (int n = 0; n < sz; ++n) {
        v1.push_back(n);
        if (cap != v1.capacity()) {
            cap = v1.capacity();
            std::cout << "new capacity=" << cap << '\n';
        }
    }
 
    std::cout << "final size=" << v1.size() << '\n';
    std::cout << "final capacity=" << v1.capacity() << '\n';
}

void test_insert()
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

int main ()
{
  //test_rbegin();
  // test_size();
  // test_empty();
  // test_max_size();
  // test_capacity();
  test_insert();

  // int i = 1;
  // int j = 1;


  // std::cout << "i = " << ++i << std::endl;
  // std::cout << "j = " << j++ << std::endl;

  return 0;
}

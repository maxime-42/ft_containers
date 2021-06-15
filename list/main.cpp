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

int main(void) 
{
    test_push_front();
    std::cout << "\n\n" << std::endl;
    // test_push_back();
  
    return (0);
}
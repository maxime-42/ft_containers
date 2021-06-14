#include "list.hpp"
#include <iostream>
#include <list>
#define SIZE 5
// using namespace std;

int main(void) 
{
    ft::list<int>myList;

    myList.push_front(1);
    // myList.push_front(2);

    ft::list<int>::iterator it = myList.begin();
    std::cout << "wsh val = " << *it << std::endl;
    // for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
    // {
    //     std::cout << " " << *it << std::endl;
    // }
    return (0);
}
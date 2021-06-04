
#include "vector.hpp"
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

void  print(std::vector<int> &tmp)
{
  for (unsigned i=0; i<tmp.size(); i++)
    std::cout << ' ' << tmp[i];
  std::cout << '\n';
}

void  print(ft::vector<int> &tmp)
{
  for (unsigned i=0; i<tmp.size(); i++)
    std::cout << ' ' << tmp[i];
  std::cout << '\n';

}

// void myVector()
// {
//    // initialising the vector
//     ft::vector<int> vec1;
//     ft::vector<int> vec2;

//     vec1.push_back(10);
//     vec1.push_back(20);
//     vec1.push_back(30);
//     vec1.push_back(40);

//     vec2.push_back(500);
//     vec2.push_back(600);
//     vec2.push_back(700);
//     vec2.push_back(800);
  
//     // inserts at the beginning of vec2
//     vec2.insert(vec2.begin() + 2, vec1.begin(), vec1.end());
  
//     cout << "The vector2 elements are: ";
//     for (ft::vector<int>:: iterator it = vec2.begin(); it != vec2.end(); ++it)
//         cout << *it << " ";
// }

void originalVector()
{
  std::cout << "My Vector\n" << std::endl;

//   &*ptr;
   // initialising the vector
    vector<int> vec1;
    vector<int> vec2;

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    vec1.push_back(40);

    vec2.push_back(500);
    vec2.push_back(600);
    vec2.push_back(700);
    vec2.push_back(800);
  
    // inserts at the beginning of vec2
    vec2.insert(vec2.begin() + 2, vec1.begin(), vec1.end());
  
    cout << "The vector2 elements are: ";
    for (std::vector<int>:: iterator it = vec2.begin(); it != vec2.end(); ++it)
        cout << *it << " ";
}


// int main ()
// {
//   std::cout << "\noriginal vector" << std::endl;
//   originalVector();
//   std::cout << "\nmyvector" << std::endl;
//   myVector();
//   // ft::vector<int> a = { 10, 20, 30};
// }

// inserting into a vector
#include <iostream>
#include <vector>

// int main ()
// {
//   // originalVector();
//   std::cout << "\n" << std::endl;
//   myVector();

//   return 0;
// }

using namespace std;
  
int main()
{
  originalVector();
  // myVector();
  ft::vector<int> vect(5, 10);
  return (0);
}

#include "vector.hpp"
#include <vector>
using namespace std;

// int main(void)
// {
// 	// size_t size=5;
// 	ft::vector<int> tab;
// 	// ft::vector<int> first;
// 	// std::cout << "salut lenox" << std::endl;
// 	tab.push_back(15);
// 	tab.push_back(20);
// 	tab.push_back(25);
// 	tab.push_back(30);
// 	tab.push_back(35);


// 	for (size_t i = 0; i < tab.size(); i++)
// 	{
// 		std::cout << " " << tab[i] << std::endl;
// 	}
// 	return (0);
// }

int main ()
{
  std::vector<int> myvector(10, 3);

  // set some initial content:
//   for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
//   myvector.resize(8,100);
//   myvector.resize(12);
  std::cout << " size = " << myvector.size();

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
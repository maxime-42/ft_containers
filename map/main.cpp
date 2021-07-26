#include "map.hpp"
#include <map>

// int main(void)
// {
// 	std::map<int, int> mymap;
// 	std::pair<int,int> p1(1,100);
// 	std::pair<int,int> p2(2,200);
// 	std::pair<int,int> p3(3,300);
// 	std::pair<int,int> p4(4,400);
// 	std::pair<int,int> p5(0,000);
// 	std::pair<int,int> p6(30,3000);
// 	std::pair<int,int> p7(12,1300);
// 	std::pair<int,int> p8(220,2000);



// 	mymap.insert(p1);
// 	mymap.insert(p2);
// 	mymap.insert(p3);
// 	mymap.insert(p4);
// 	// mymap.insert(p5);
// 	mymap.insert(p6);
// 	mymap.insert(p7);
// 	mymap.insert(p8);

// 	// int i = 0;
	
// 	// for( ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
// 	// {
// 	// 	std::cout << it->first << " => " << it->second << '\n';
// 	// }

// 	std::map<int, int>::iterator it = mymap.end();
// 	it--;
// 	std::cout << it->first << " => " << it->second << '\n';
// 	it--;
// 	std::cout << it->first << " => " << it->second << '\n';
// 	return (0);
// }

int	main(void)
{
	// ft::map<int, int> obj;
	// ft::mappair<int,int> p(1,100);
	// obj.insert();
	ft::map<int, int> mymap;
	ft::pair<int,int> p1(1,100);
	ft::pair<int,int> p2(2,200);
	ft::pair<int,int> p3(3,300);
	ft::pair<int,int> p4(4,400);
	ft::pair<int,int> p5(0,000);
	ft::pair<int,int> p6(30,3000);
	ft::pair<int,int> p7(12,1200);
	ft::pair<int,int> p8(220,2000);
	// p7 = p8;
	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	mymap.insert(p5);
	mymap.insert(p6);
	mymap.insert(p7);
	mymap.insert(p8);

	// for( ft::map<int, int>::iterator it = mymap.end(); it != mymap.begin(); it--)
	// {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }
	// mymap.delete_one_node_by_key(.0)
	ft::map<int, int>::iterator it = mymap.begin(); 
	it++;
	mymap.erase(it);
	// for( ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	// {
		// std::cout << it->first << " => " << it->second << '\n';
	// }

	// ft::map<int, int>::iterator it = mymap.end();
	// std::cout << it->first << " => " << it->second << '\n';
	// it--;
	// std::cout << it->first << " => " << it->second << '\n';
	// it--;
	// std::cout << it->first << " => " << it->second << '\n';
	// it--;
	// std::cout << it->first << " => " << it->second << '\n';

	return (0);
}

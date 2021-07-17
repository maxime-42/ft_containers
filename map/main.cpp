#include "map.hpp"
#include <map>

int	main(void) 
{
	// ft::map<int, int> obj;
	// ft::mappair<int,int> p(1,100);
	// obj.insert();
	std::map<int,int> mymap;
	std::pair<int,int> p1(1,100);
	std::pair<int,int> p2(2,200);
	std::pair<int,int> p3(3,300);
	// first insert function version (single parameter):
	mymap.insert (p1);
	mymap.insert (p2);
	mymap.insert (p3);

	// mymap.insert ( std::pair<char,int>('b',200) );
	// mymap.insert ( std::pair<char,int>('c',400) );
	// mymap.insert ( std::pair<char,int>('d',400) );


	// std::cout << "size = " << mymap.size() << std::endl;
	std::map<int, int>::iterator it=mymap.begin();
	it++;
	// for (std::map<int, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	return (0);
}

// int	main(void)
// {
// 	// ft::map<int, int> obj;
// 	// ft::mappair<int,int> p(1,100);
// 	// obj.insert();
// 	ft::map<int, int> mymap;
// 	ft::pair<int,int> p1(1,100);
// 	ft::pair<int,int> p2(2,200);
// 	ft::pair<int,int> p3(2,200);


// 	// ft::pair<char,int> p1(p);
// 	// std::cout << "first " << p1.second << std::endl;
// 	// first insert function version (single parameter):
// 	mymap.insert(p1);
// 	mymap.insert(p2);
// 	mymap.insert(p3);
// 	ft::map<int,int>::iterator it = mymap.begin();
// 	std::cout << "data (first) = " << it->first << "data (value) = " << it->second << std::endl;
// 	 // mymap.insert ( std::pair<char,int>('b',200) );
// 	// mymap.insert ( std::pair<char,int>('c',400) );
// 	// mymap.insert ( std::pair<char,int>('d',400) );
// 	// std::cout << "size = " << mymap.size() << std::endl;
// 	// for (std::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// 		// std::cout << it->first << " => " << it->second << '\n';
// 	return (0);
// }
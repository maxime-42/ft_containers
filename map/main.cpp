#include "map.hpp"
#include <map>

// int	main(void) 
// {
// 	// ft::map<int, int> obj;
// 	// ft::mappair<int,int> p(1,100);
// 	// obj.insert();
// 	std::map<char,int> mymap;
// 	std::pair<char,int> p('a',100);
// 	// first insert function version (single parameter):
// 	mymap.insert (p);
// 	// mymap.insert ( std::pair<char,int>('b',200) );
// 	// mymap.insert ( std::pair<char,int>('c',400) );
// 	// mymap.insert ( std::pair<char,int>('d',400) );


// 	// std::cout << "size = " << mymap.size() << std::endl;
// 	for (std::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';
// 	return (0);
// }

int	main(void)
{
	// ft::map<int, int> obj;
	// ft::mappair<int,int> p(1,100);
	// obj.insert();
	ft::map<char, int> mymap;
	ft::pair<char,int> p('a',100);
	// ft::pair<char,int> p1(p);
	// std::cout << "first " << p1.second << std::endl;
	// first insert function version (single parameter):
		mymap.insert (p);
	// mymap.insert ( std::pair<char,int>('b',200) );
	// mymap.insert ( std::pair<char,int>('c',400) );
	// mymap.insert ( std::pair<char,int>('d',400) );
	// std::cout << "size = " << mymap.size() << std::endl;
	// for (std::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// std::cout << it->first << " => " << it->second << '\n';
	return (0);
}
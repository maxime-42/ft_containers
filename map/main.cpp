#include "map.hpp"
#include <map>

int  main(void) 
{
	// ft::map<int, int> obj;
	std::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('b',200) );
	mymap.insert ( std::pair<char,int>('c',400) );
	mymap.insert ( std::pair<char,int>('d',400) );


	std::cout << "size = " << mymap.size() << std::endl;
	for (std::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';
	return (0);
}
#include "map.hpp"
#include <map>

// int	main(void) 
// {
// 	// ft::map<int, int> obj;
// 	// ft::mappair<int,int> p(1,100);
// 	// obj.insert();
// 	std::map<int,int> mymap;
// 	std::pair<int,int> p1(1,100);
// 	std::pair<int,int> p2(2,200);
// 	std::pair<int,int> p3(3,300);
// 	// first insert function version (single parameter):
// 	mymap.insert (p1);
// 	mymap.insert (p2);
// 	mymap.insert (p3);

// 	// mymap.insert ( std::pair<char,int>('b',200) );
// 	// mymap.insert ( std::pair<char,int>('c',400) );
// 	// mymap.insert ( std::pair<char,int>('d',400) );

// 	// std::cout << "size = " << mymap.size() << std::endl;
// 	std::map<int, int>::iterator it=mymap.begin();
// 	std::map<int, int>::iterator it1 = ++it;
// 	// for (std::map<int, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// 		std::cout << "it : first " << it->first << " second = " << it->second << '\n';
// 		std::cout << "it1 : first " << it1->first << " second = " << it1->second << '\n';

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
	ft::pair<int,int> p7(12,1300);
	ft::pair<int,int> p8(220,2000);



	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	mymap.insert(p5);
	mymap.insert(p6);
	mymap.insert(p7);
	mymap.insert(p8);

	// int i = 0;
	
	// for( ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++ )
	// {
	// 	std::cout << it->first << " => " << it->second << '\n';

	// 	if (i == 3)
	// 		break;
	// 	i++;

	// }


	// it++;
	// std::cout << "data (first) = " << it->first << "data (value) = " << it->second << std::endl;
	 // mymap.insert ( std::pair<char,int>('b',200));
	// mymap.insert ( std::pair<char,int>('c',400));
	// mymap.insert ( std::pair<char,int>('d',400));
	// std::cout << "size = " << mymap.size() << std::endl;
	// for (std::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// std::cout << it->first << " => " << it->second << '\n';
	return (0);
}

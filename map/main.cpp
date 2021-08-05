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
/*

// */
// int	main(void)
// {
	// ft::map<int, int> obj;
	// ft::pair<int,int> p1(1,100);
	// // obj.insert();
	// ft::pair<int,int> p2(2,200);

	// // ft::map<int, int> mymap;
	// mymap.insert(p1);
	// mymap.insert(p2);

	// ft::pair<int,int> p7(7,700);
	// ft::pair<int,int> p9(9,900);
	// ft::pair<int,int> p8(8,800);
	// ft::pair<int,int> p10(10,10000);
	// ft::pair<int,int> p11(11,111);
	// ft::pair<int,int> p12(12,1200);
	// ft::pair<int,int> p17(17, 1700);
	// ft::pair<int,int> p13(13, 1300);
	// ft::pair<int,int> p15(15,1400);
	// ft::pair<int,int> p19(19,19000);

	// mymapert(p1);
	// mymap.insert(p7);
	// mymap.insert(p12);
	// mymap.insert(p5);
	// mymap.insert(p9);
	// mymap.insert(p8);
	// mymap.insert(p13);
	// mymap.insert(p17);
	// mymap.insert(p10);
	// mymap.insert(p15);
	// mymap.insert(p19);
	// for( ft::map<int, int>::iterator it = mymap.end(); it != mymap.begin(); it--)
	// {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }
	// mymap.delete_one_node_by_key(.0)
	// ft::map<int, int>::iterator it = mymap.begin();
	// 	std::cout << it->first << " => " << it->second << '\n';
	// mymap.erase(12);
	// for( ft::map<int, int>::iterator it1 = mymap.begin(); it1 != mymap.end(); it1++)
	// {
	// 	std::cout << it1->first << " => " << it1->second << '\n';
	// }
	// ft::map<int, int>::iterator it = mymap.end();
	// std::cout << it->first << " => " << it->second << '\n';
	// it--;
	// std::cout << it->first << " => " << it->second << '\n';
	// it--;

	// std::cout << it->first << " => " << it->second << '\n';
	// it--;
	// std::cout << it->first << " => " << it->second << '\n';

// 	return (0);
// }


//  int main ()
// {
//   ft::map<char,std::string> mymap;

//   mymap['a']="an element";
//   mymap['b']="another element";
//   mymap['c']=mymap['b'];

//   std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//   std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//   std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//   std::cout << "mymap['d'] is " << mymap['d'] << '\n';

//   std::cout << "mymap now contains " << mymap.size() << " elements.\n";
//   std::cout << "hellow" << std::endl;

//   return 0;
// }

// int test_insert ()
// {
//   ft::map<char,int> mymap;

//   // first insert function version (single parameter):
//   mymap.insert ( ft::pair<char,int>('a',100) );
//   mymap.insert ( ft::pair<char,int>('z',200) );

//   ft::pair<ft::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( ft::pair<char,int>('z',500) );
//   if (ret.second==false) 
//   {
//  	std::cout << "element 'z' already existed";
// 	std::cout << " with a value of " << ret.first->second << '\n';
//   }

//   // second insert function version (with hint position):
//   ft::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   ft::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

// //   // showing contents:
//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

// int test_swap ()
// {
//   ft::map<char,int> foo,bar;

//   foo['x']=100;
//   foo['y']=200;

//   bar['a']=11;
//   bar['b']=22;
//   bar['c']=33;

//   foo.swap(bar);

//   std::cout << "foo contains:\n";
//   for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "bar contains:\n";
//   for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::map<char,int> mymap;
//   ft::map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

// //   it=mymap.find('b');
// //   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');          // erasing by key

// //   it=mymap.find ('e');
// //   mymap.erase ( it, mymap.end() );    // erasing by range

// //   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

// bool fncomp (char lhs, char rhs) {return lhs<rhs;}

// struct classcomp {
//   bool operator() (const char& lhs, const char& rhs) const
//   {return lhs<rhs;}
// };

void	print_map(ft::map<char,int> &myMap)
{
for (ft::map<char,int>::iterator it = myMap.begin(); it !=myMap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
}

// int main ()
// {
//   ft::map<int,int> first;

//   first[11]=111;
//   first[6]=666;
//   first[5]=55;
//   first[7]=777;
//   first[8]=88;
//   first[9]=99;
//   first[12]=1220;
// //   first[17]=1777;
// //   first[9]=999;
// //   first[10]=1000;

// 	std::cout << "first befor delete 6" << std::endl;
// 	// print_map(first);
// 	// std::cout << "\nfirst after delete" << std::endl;
// 	print_map(first);

// 	first.erase(6);

// 	print_map(first);

// //   ft::map<char,int> second (first.begin(),first.end());
// 	// std::cout << "second " << std::endl;

// 	// print_map(second);

// //   ft::map<char,int> third (second);

// //   std::map<char,int,classcomp> fourth;                 // class as Compare

// //   bool(*fn_pt)(char,char) = fncomp;
// //   std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
//   return 0;
// }

int test_erase ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
  mymap['f']=60;
	
	std::cout << "befor erase : " << std::endl;
	print_map(mymap);

	
	// mymap.erase ('a');                   // erasing by iterator
	// mymap.erase ('b');                   // erasing by iterator
// 	std::cout << "\nafter erase b:" << std::endl;
// 	print_map(mymap);
	

// 	std::cout << "\nafter erase c: " << std::endl;
// 	print_map(mymap);

//   it  = mymap.find ('b');
    // std::cout << it->first << " => " << it->second << '\n';
	// mymap.erase (it);                   // erasing by iterator

	// mymap.erase (mymap.find ('a'), mymap.end());    // erasing by range
	// std::cout << "after delete  : " << std::endl;
	// print_map(mymap);
	std::cout << "after delete last element : " << std::endl;

	mymap.erase ('f');                   // erasing by iterator
	print_map(mymap);



// 
//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
    // std::cout << it->first << " => " << it->second << '\n';
  return 0;
}

int main()
{
	 test_erase();
	return 0;
}
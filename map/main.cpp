#include <map>
#include "map.hpp"
#include <iostream>
#include <string>
#ifdef STD
 using namespace std;
 #define NAMESPACE_DEFINED
#endif

#ifdef FT
 using namespace ft;
 #define NAMESPACE_DEFINED
#endif

#ifndef NAMESPACE_DEFINED
 using namespace std;
#endif


void	print_map(map<char,int> &myMap)
{
for (map<char,int>::iterator it = myMap.begin(); it !=myMap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
}

int test_insert ()
{
  map<char,int> mymap;

  mymap.insert ( pair<char,int>('a',100) );
  mymap.insert ( pair<char,int>('z',200) );

	std::cout << "first insert function version (single parameter):" << std::endl;
	print_map(mymap);
  pair<map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( pair<char,int>('z',500) );
  if (ret.second==false) 
  {
 	std::cout << "element 'z' already existed";
	std::cout << " with a value of " << ret.first->second << '\n';
  }

//   // second insert function version (with hint position):
  map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting
	std::cout << "second insert function version (with hint position):" << std::endl;
	print_map(mymap);

  // third insert function version (range insertion):
  map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}

int test_swap ()
{
  map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}


int test_erase ()
{
	map<char,int> mymap;
	map<char,int>::iterator it;

  // insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

 it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
	return 0;
}



int test_clear()
{
  map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}

int test_find ()
{
  map<char,int> mymap;
  map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  return 0;
}


int test_count ()
{
  map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }

  return 0;
}

int test_lower_bound ()
{
  map<char,int> mymap;
  map<char,int>::iterator itlow,itup;

 mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
  // if (itlow == mymap.end())
  // {
  //   std::cout << "THE END" << std::endl;
  //   return 0;
  // }
  std::cout << "itlow : first = " << itlow->first << " second = " << itlow->second << std::endl;
  std::cout << "itup : first = " << itup->first << " second = " << itup->second << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)
  // print content:
  for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}

int test_equal_range ()
{
  map<char,int> mymap;

  mymap['c']=60;
  mymap['d']=80;
  mymap['a']=20;
  mymap['e']=100;
  mymap['b']=40;

  pair<map<char,int>::iterator, map<char,int>::iterator> ret;
  ret = mymap.equal_range('a');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}

int test_empty ()
{
  map<char,int> mymap;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }

  return 0;
}

int test_operator ()
{
  map<char,int> first;
  map<char,int> second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  std::cout << "first:" << std::endl;
  print_map(first);
  second=first;                // second now contains 3 ints
  first=map<char,int>();  // and first is now empty
  std::cout << "second:" << std::endl;
  // print_map(first);

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
  return 0;
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int test_constructeur()
{
  map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  map<char,int> second (first.begin(),first.end());

std::cout << "first:" << std::endl;
	print_map(first);
  map<char,int> third (second);

  map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  return 0;
}

int test_begin ()
{
  map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}


int test_rbegin()
{
  map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';

  return 0;
}
int  main(int argc, const char** argv) {

	//  test_erase();
	// test_insert();
	// test_clear();
	// test_find();
  // test_count();
  // test_lower_bound();
	// std::cout << "salut" << std::endl;
  // test_equal_range();
  // test_empty();
  // test_operator();
//   test_swap();
	// test_constructeur();
	// test_begin();
	test_rbegin();
  (void)argc;
  (void)argv;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_map.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:29:09 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/03/08 15:29:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map.hpp>
#include <test_header.hpp>

#include <map>

# define KEY_TYPE char
# define VALUE_TYPE int
# define KEY 'z'

// int main(void) {
// 	map<KEY_TYPE, VALUE_TYPE> test;

// 	test[KEY] = 53060;
// 	map<KEY_TYPE, VALUE_TYPE>::iterator it = test.find(KEY);
// 	std::cout << "Key: " << it->first << std::endl << "Value: " << it->second << std::endl;
// 	test[KEY] = 420;
// 	std::cout << "Key: " << it->first << std::endl << "Value: " << it->second << std::endl;
// 	std::cout << test.size() << std::endl;
// }

// accessing mapped values
// #include <iostream>
// #include <map>
// #include <string>
// #include <map.hpp>
// #include <test_header.hpp>

// int main ()
// {
// 	map<char,int> mymap;

// 	std::cout << mymap.size() << std::endl;
// 	std::cout << mymap.empty() << std::endl;
// 	std::cout << mymap.max_size() << std::endl;

// 	for (char it = 'a'; it <= 'z'; it++)
// 		mymap[it] = (it - 96) * 100;

// 	for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
// 		std::cout << it->first << " => " << it->second << std::endl;

// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
// 	mymap.clear();
// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	
// 	for (char it = 'a'; it <= 'z'; it++)
// 		mymap[it] = (it - 96) * 100;

// 	for (map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
// 		std::cout << it->first << " => " << it->second << std::endl;
// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

// 	std::cout << mymap.count('a') << std::endl;
// 	return 0;
// }

// erasing from map
#include <iostream>
#include <unistd.h>
#include <map>

// int main ()
// {
//   map<char,int> mymap;
//   map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

int main ()
{
  int psize;
  map<char,int> mymap;
  pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(std::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);

  return 0;
}

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
#include <iostream>
#include <map>
#include <string>
#include <map.hpp>
#include <test_header.hpp>

int main ()
{
	map<char,int> mymap;

	std::cout << mymap.size() << std::endl;
	std::cout << mymap.empty() << std::endl;
	std::cout << mymap.max_size() << std::endl;

	for (char it = 'a'; it <= 'z'; it++)
		mymap[it] = (it - 96) * 100;

	for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	mymap.clear();
	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	
	for (char it = 'a'; it <= 'z'; it++)
		mymap[it] = (it - 96) * 100;

	for (map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	return 0;
}

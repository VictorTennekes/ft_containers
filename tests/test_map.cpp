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
	map<char,std::string> mymap;

	std::cout << mymap.size() << std::endl;
	std::cout << mymap.empty() << std::endl;
	std::cout << mymap.max_size() << std::endl;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

	return 0;
}

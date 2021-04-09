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

template <class Container>
void print_map(Container& cont, std::string name) {
  std::cout << name << " ";
	std::cout << "[";
	for (typename Container::iterator it = cont.begin(); it != cont.end();)
		std::cout << SIDE << it->first << ":" << it->second << RESET << (++it != cont.end() ? ", " : "");
	std::cout << "]" << std::endl << std::endl;
}

template <class Container>
void print_map_reverse(Container& cont, std::string name) {
  std::cout << name << " ";
	std::cout << "[";
	for (typename Container::reverse_iterator it = cont.rbegin(); it != cont.rend();)
		std::cout << SIDE << it->first << ":" << it->second << RESET << (++it != cont.rend() ? ", " : "");
	std::cout << "]" << std::endl << std::endl;
}

int main(void) {
  print_env();
  print_container_title("Map");

  // INITIALIZERS
  print_title_saber("Map initializers/iterators checks");

	map<KEY_TYPE, VALUE_TYPE> mymap;

	for (char it = 'a'; it <= 'z'; it++)
		mymap[it] = (it - 96) * 100;
  map<KEY_TYPE, VALUE_TYPE> mymaprev(mymap.rbegin(), mymap.rend());
  map<KEY_TYPE, VALUE_TYPE> mymapcpy(mymap);
  print_map(mymap, "MyMap");
  print_map(mymaprev, "MyMapRev");
  print_map(mymapcpy, "MyMapCpy");

  // CAPACITY
  print_title_saber("Map capacity checks");
  std::cout << "MyMap is {" << (mymap.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
  std:: cout << mymap.size() << std::endl;
  std::cout << "Cleared MyMap" << std::endl;
  mymap.clear();
  print_map(mymap, "MyMap");
  std::cout << "MyMap is {" << (mymap.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
  std::cout << std::endl;

	// std::cout << mymap.size() << std::endl;
	// std::cout << mymap.empty() << std::endl;
	// std::cout << mymap.max_size() << std::endl;


	return 0;
}

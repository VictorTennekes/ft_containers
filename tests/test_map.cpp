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
  print_title_saber("Initializers/iterators");

	map<KEY_TYPE, VALUE_TYPE> mymap;

	for (char it = 'a'; it <= 'z'; it++)
		mymap[it] = (it - 96) * 100;
  map<KEY_TYPE, VALUE_TYPE> mymaprev(mymap.rbegin(), mymap.rend());
  map<KEY_TYPE, VALUE_TYPE> mymapcpy(mymap);
  print_map(mymap, "MyMap");
  print_map(mymaprev, "MyMapRev");
  print_map(mymapcpy, "MyMapCpy");

  // CAPACITY
  print_title_saber("Capacity");
  std::cout << "MyMap is {" << (mymap.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
  std:: cout << mymap.size() << std::endl;
  std::cout << "Cleared MyMap" << std::endl;
  mymap.clear();
  print_map(mymap, "MyMap");
  std::cout << "MyMap is {" << (mymap.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
  std::cout << std::endl;

	std::cout << "MyMap has a size of: " << mymap.size() << std::endl;
	std::cout << "MyMap has a max_size of: " << mymap.max_size() << std::endl;

  // Modifiers
  print_title_saber("Modifiers");
  std::cout << "Insert 'a' till 'z' in mymap" << std::endl;
	for (char it = 'a'; it <= 'z'; it++)
    mymap.insert(ft::pair<KEY_TYPE, VALUE_TYPE>(it, (it - 96) * 100));
  print_map(mymap, "MyMap");
  mymapcpy.clear();
  mymapcpy.insert(mymap.find('d'), mymap.find('x'));
  print_map(mymapcpy, "MyMapCpy");

  mymapcpy.erase('e');
  print_map(mymapcpy, "MyMapCpy");

  map<KEY_TYPE, VALUE_TYPE>::iterator it = mymapcpy.find('f');
  mymapcpy.erase(it);
  print_map(mymapcpy, "MyMapCpy");

  std::cout << "Swapping contents MyMap and MyMapCpy" << std::endl;
  mymap.swap(mymapcpy);
  print_map(mymap, "MyMap");
  print_map(mymapcpy, "MyMapCpy");

  // Operations
  print_title_saber("Operations");
  std::cout << "Does MyMap include 'a': " << (mymap.count('a') == 1 ? GREEN "Yes" : RED "No") << RESET << std::endl;
  std::cout << "Does MyMapCpy include 'a': " << (mymapcpy.count('a') == 1 ? GREEN "Yes" : RED "No") << RESET << std::endl;

  it = mymapcpy.lower_bound('d');
  std::cout << "Lower bound mymapcpy for 'd': " << SIDE << it->first << " => " << it->second << RESET << std::endl;
  it = mymapcpy.upper_bound('d');
  std::cout << "Upper bound mymapcpy for 'd': " << SIDE << it->first << " => " << it->second << RESET << std::endl;

  pair<map<char,int>::iterator,map<char,int>::iterator> ret;
  ret = mymapcpy.equal_range('d');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  print_title_saber("Operators");
  comparison_operator_container(mymap, mymapcpy, "MyMap", "MyMapCpy");
	return 0;
}


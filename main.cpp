/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 13:44:07 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/01/29 13:44:07 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list/list.hpp"
#include "iterators/BidirectionalIterator.hpp"
#include "iterators/iterator_utils.hpp"
#include <list>

using namespace std;

int main(void) {
	list<int>	test;
	list<int>::iterator it1,it2;

	for (size_t i = 0; i < 9; i++) {
		test.push_back(i);
	}

	it1 = test.begin();
	advance(it1, 4);
	it2 = test.begin();
	test.erase(it2, it1);

	for (list<int>::iterator it = test.begin(); it != test.end(); it++) {
		std::cout << *it << std::endl;
	}
	return (0);
}

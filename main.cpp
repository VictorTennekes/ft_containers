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

using namespace ft;

int main(void) {
	int			nums[] = {1, 2, 3, 4, 5, 6, 7};
	list<int>	test;

	for (size_t i = 0; i < 7; i++) {
		test.push_back(nums[i]);
	}
	for (list<int>::iterator it = test.begin(); it != test.end(); it++) {
		std::cout << *it << std::endl;
	}
	return (0);
}

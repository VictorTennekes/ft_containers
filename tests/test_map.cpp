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

int main(void) {
	map<char, int> test;

	test['a'] = 300;
	map<char, int>::iterator it = test.find('a');
	std::cout << it->first << std::endl;
}

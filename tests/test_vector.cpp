/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_vector.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 16:51:12 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/02/17 16:51:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector.hpp>
#include <test_header.hpp>

#define victor vector

int main(void) {
	print_env();
	print_container_title("Vector");
	print_title_saber("Vector initializers/iterators checks");

	victor<VALUE> v1;

	std::cout << "Max size: " << v1.max_size() << std::endl;
}

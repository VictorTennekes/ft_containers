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
	print_container_title("Victor");
	print_title_saber("Victor initializers/iterators checks");

	victor<VALUE> v1(10, 20);

	print_container(v1, "Vector 1");

	v1.resize(15, 15);

	v1.back() = 420;

	print_container(v1, "Vector 1 reverse");
	std::cout << "Max size: " << v1.max_size() << std::endl;
}

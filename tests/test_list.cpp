/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_list.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 13:44:07 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/01/29 13:44:07 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <BidirectionalIterator.hpp>
#include <iterator_utils.hpp>
#include <list.hpp>
#include <list>

using namespace ft;

template <class Container>
void print_container(Container& cont, std::string name) {
	std::cout << std::endl << name << std::endl;
	std::cout << "[";
	for (typename Container::iterator it = cont.begin(); it != cont.end();)
		std::cout << *it << (++it != cont.end() ? ", " : "");
	std::cout << "]" << std::endl << std::endl;
}

// HEAD NODE NODE NODE TAIL

int main(void) {
	list<int>	l1;

	list<int>::reverse_iterator it;
	it = l1.rbegin();

	for (int i = 1; i < 11; i++)
		l1.push_back(i * 10);


	// std::cout << it.ptr << " / " << l1.rbegin().ptr << std::endl;
	// std::cout << it.ptr->next << " / " << l1.rbegin().ptr->next << std::endl;
	// std::cout << it.ptr->prev << " / " << l1.rbegin().ptr->prev << std::endl;

	// std::cout << "l1 front: " << l1.front() << std::endl;
	// std::cout << *++l1.begin() << std::endl;
	print_container(l1, "List 1");
	list<int>	l2(it, l1.rend());
	print_container(l2, "List 2");
}

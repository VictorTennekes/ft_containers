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
#include <vector>
#include <vector.hpp>
#include <test_header.hpp>

#define victor vector

int main(void) {
	print_env();
	print_container_title("Victor");

	// INITIALIZERS
	print_title_saber("Victor initializers/iterators checks");

	victor<int> v1;
	std::cout << "Pushing values into v1" << std::endl;
		for (int i = 1; i < 11; i++)
			v1.push_back(i * 10);
	print_container(v1, "Victor 1");

	std::cout << "v2 with four ints value 100" << std::endl;
	victor<int> v2(4,100);
	print_container(v2, "Victor 2");

	std::cout << "v3 iterates over v2" << std::endl;
	victor<int> v3(v2.begin(),v2.end());
	print_container(v3, "Victor 3");

	std::cout << "Set v4 to reverse v1" << std::endl;
	victor<VALUE> v4(v1.rbegin(), v1.rend());
	print_container(v4, "Victor 4");

	std::cout << "Initalize v5 to v3" << std::endl;
	victor<int> v5(v3);
	print_container(v5, "Victor 5");


	std::cout << "v6 constructed of int array" << std::endl;
	int myints[] = {16,2,77,29};
	victor<int> v6 (myints, myints + sizeof(myints) / sizeof(int));
	print_container(v6, "Victor 6");

	std::cout << "Set v1 = v6 with overloaded operator" << std::endl;
	v1 = v6;
	print_container(v1, "Victor 1");

	// CAPACITY
	print_title_saber("Victor capacity checks");
	std::cout << "Victor 1 is: {" << (v1.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << "Cleared victor 1" << std::endl;
	v1.clear();
	std::cout << "Victor 1 is: {" << (v1.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "Victor 2 has a size of: {" << SIDE << v2.size() << RESET << "}" << std::endl;
	print_container(v2, "Victor 2");
	std::cout << "Resizing victor 2 to 6" << std::endl;
	v2.resize(6);
	std::cout << "Victor 2 has a size of: {" << SIDE << v2.size() << RESET << "}" << std::endl;
	print_container(v2, "Victor 1");

	std::cout << "Victor 2 has a capacity of: {" << SIDE << v2.capacity() << RESET << "}" << std::endl;
	std::cout << "reserve victor 2 to 16" << std::endl;
	v2.reserve(16);
	std::cout << "Victor 2 has a capacity of: {" << SIDE << v2.capacity() << RESET << "}" << std::endl;
	std::cout << std::endl;


	std::cout << "Victor 1 has a max size of: {" << YELLOW << v1.max_size() << RESET << "}" << std::endl;
	std::cout << "Victor 2 has a max size of: {" << YELLOW << v2.max_size() << RESET << "}" << std::endl;

	// ACCESS
	print_title_saber("Element access checks");
	std::cout << "First element of victor 6:		{" << SIDE << v6.front() << RESET << "}" << std::endl;
	std::cout << "Last element of victor 6:		{" << SIDE << v6.back()  << RESET<< "}" << std::endl;

	std::cout << "Element of victor 6 with [2] operator:	{" << SIDE << v6[2] << RESET << "}" << std::endl;
	std::cout << "Element of victor 6 with at(2):		{" << SIDE << v6.at(3) << RESET << "}" << std::endl;

	// MODIFIERS
	print_title_saber("Modifers checks");

	std::cout << "Assign victor 1 to 7 * 100" << std::endl;
	v1.assign(7,100);
	print_container(v1, "Victor 1");

	std::cout << "Assign victor 2 to 5 central values victor 1" << std::endl;
	vector<int>::iterator it = v1.begin() + 1;
	v2.assign(it, v1.end()-1);
	print_container(v2, "Victor 2");

	std::cout << "Assign victor 1 to array" << std::endl;
	v1.assign(myints, myints+3);
	print_container(v1, "Victor 1");

	std::cout << "Push 97 to back victor 1" << std::endl;
	v1.push_back(97);
	print_container(v1, "Victor 1");

	std::cout << "Pop back victor 1" << std::endl;
	v1.pop_back();
	print_container(v1, "Victor 1");

	std::cout << "Insert {101, 102, 103} at begin of victor 1" << std::endl;
	int myarr[] = {101, 102, 103};
	v1.insert(v1.begin(), myarr, myarr+3);
	print_container(v1, "Victor 1");

	std::cout << "Insert 3 * 98 at ++begin of victor 1" << std::endl;
	v1.insert(++v1.begin(), 3, 98);
	print_container(v1, "Victor 1");

	std::cout << "Insert 97 at begin of victor 1" << std::endl;
	v1.insert(v1.begin(), 97);
	print_container(v1, "Victor 1");

	std::cout << "Insert victor 2 at begin of victor 1" << std::endl;
	v1.insert(v1.begin(), v2.begin(), v2.end());
	print_container(v1, "Victor 1");

	std::cout << "Erase begin of victor 1" << std::endl;
	v1.erase(v1.begin());
	print_container(v1, "Victor 1");

	it = v1.begin();
	ft::advance(it, v2.size() - 1);
	std::cout << "Erase first " << v2.size() - 1 << " of l2" << std::endl;
	v1.erase(v1.begin(), it);
	print_container(v1, "Victor 1");

	std::cout << "Swap victor 1 and 2" << std::endl;
	v2.swap(v1);
	print_container(v1, "Victor 1");
	print_container(v2, "Victor 2");

	print_title_saber("Operators");
	comparison_operator_container(v1, v2, "Victor 1", "Victor 2");
}

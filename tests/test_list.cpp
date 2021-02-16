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
#include <test_header.hpp>

bool is_even(int num) {return(num%2 == 0);}

int main(void) {
	print_env();
	print_container_title("List");
	print_title_saber("List initializers/iterators checks");
	list<VALUE>	l1;
	
	std::cout << "Pushing values into l1" << std::endl;
	for (int i = 1; i < 11; i++)
		l1.push_back(i * 10);
	print_container(l1, "List 1");
	
	std::cout << "Set l2 to reverse l1" << std::endl;
	list<VALUE>	l2(l1.rbegin(), l1.rend());
	print_container(l2, "List 2");

	std::cout << "Inititalize l3 to l2" << std::endl;
	list<VALUE>	l3(l2);
	print_container(l3, "List 3");
	
	std::cout << "Set l3 = l1 with overloaded operator" << std::endl;
	l3 = l1;
	print_container(l3, "List 3");

	print_title_saber("List capacity checks");
	std::cout << "List 1 is: {" << (l1.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;

	l1.clear();
	std::cout << "List 1 is: {" << (l1.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "List 2 has a size of: {" << l2.size() << "}" << std::endl;
	print_container(l2, "list 2");
	std::cout << "List 1 has a size of: {" << l1.size() << "}" << std::endl;
	print_container(l1, "list 1");

	std::cout << "List 1 has a max size of: {" << YELLOW << l1.max_size() << RESET << "}" << std::endl;
	std::cout << "List 2 has a max size of: {" << YELLOW << l2.max_size() << RESET << "}" << std::endl;

	std::cout << std::endl;
	print_title_saber("Element access checks");
	std::cout << "First element of list 2: {" << l2.front() << "}" << std::endl;
	std::cout << "Last element of list 2: {" << l2.back() << "}" << std::endl;
	print_container(l2, "List 2");

	print_title_saber("Modifiers checks");
	std::cout << "Assign list 2 to 7 * 100" << std::endl;
	l2.assign(7, 100);
	print_container(l2, "List 2");

	std::cout << "Push 97 to front of l2" << std::endl;
	l2.push_front(97);
	print_container(l2, "List 2");

	std::cout << "Pop front of l2" << std::endl;
	l2.pop_front();
	print_container(l2, "List 2");
	
	std::cout << "Push 97 to back of l2" << std::endl;
	l2.push_back(97);
	print_container(l2, "List 2");
	
	std::cout << "Pop back of l2" << std::endl;
	l2.pop_back();
	print_container(l2, "List 2");
	
	std::cout << "Insert 3 * 98 at ++begin of l2" << std::endl;
	l2.insert(++l2.begin(), 3, 98);
	print_container(l2, "List 2");

	std::cout << "Insert 97 at begin of l2" << std::endl;
	l2.insert(l2.begin(), 97);
	print_container(l2, "List 2");

	std::cout << "Insert l3 at begin of l2" << std::endl;
	l2.insert(l2.begin(), l3.begin(), l3.end());
	print_container(l2, "List 2");

	std::cout << "Erase begin of l2" << std::endl;
	l2.erase(l2.begin());
	print_container(l2, "List 2");

	list<VALUE>::iterator it = l2.begin();
	for (unsigned long i = 1; i < l3.size(); i++)
		it++;
	std::cout << "Erase first " << l3.size() - 1 << " of l2" << std::endl;
	l2.erase(l2.begin(), it);
	print_container(l2, "List 2");

	std::cout << "Swap list 1 and 2" << std::endl;
	l2.swap(l1);
	print_container(l1, "List 1");
	print_container(l2, "List 2");

	std::cout << "Resize list 1 to 3" << std::endl;
	l1.resize(3);
	print_container(l1, "List 1");
	
	std::cout << "Clear list 1" << std::endl;
	l1.clear();
	print_container(l1, "List 1");

	// std::cout << WHITE << "[ Operation checks ]" << RESET << std::endl;
	print_title_saber("Operation checks");
	std::cout << "Pushing values into l1" << std::endl;
	for (int i = 1; i < 11; i++)
		l1.push_back(i * 10);
	print_container(l1, "List 1");
	print_container(l3, "List 3");
	
	std::cout << "Splicing list 3 into beginning of list1" << std::endl;
	l1.splice(l1.begin(), l3);
	print_container(l1, "List 1");
	print_container(l3, "List 3");

	std::cout << "Splicing element 1 of list 1 into list 3" << std::endl;
	l3.splice(l3.begin(), l1, l1.begin());
	print_container(l1, "List 1");
	print_container(l3, "List 3");

	std::cout << "Splicing element 1-5 of list 1 into list 3 at position 1" << std::endl;
	it = l1.begin();
	advance(it, 5);
	l3.splice(++l3.begin(), l1, l1.begin(), it);
	print_container(l1, "List 1");
	print_container(l3, "List 3");

	std::cout << "Removing 100 from list 1" << std::endl;
	l1.remove(100);
	print_container(l1, "List 1");

	std::cout << "Unique list 1" << std::endl;
	l1.unique();
	print_container(l1, "List 1");

	std::cout << "Pushing uneven values into l1" << std::endl;
	for (int i = 1; i < 11; i+=2)
		l1.push_back(i * 11);
	print_container(l1, "List 1");

	std::cout << "Removing nums if even from list 1" << std::endl;
	l1.remove_if(is_even);
	print_container(l1, "List 1");

	std::cout << "inserting values into l1" << std::endl;
	l1.insert(l1.begin(), 120);
	l1.insert(++++++++l1.begin(), 69);
	print_container(l1, "List 1");
	l1.sort();
	print_container(l1, "List 1");

	l3.clear();
	l2.clear();

	print_title_saber("Operators");
	comparison_operator_container(l2, l3, "List 2", "List 3");
	// std::cout << "== operator:	list2 == list3 == " << ((l2 == l3) ? "True" : "False") << std::endl;
	// std::cout << "!= operator:	list2 != list3 == " << ((l2 != l3) ? "True" : "False") << std::endl;
	// std::cout << "List 2 " << " operator == " << "List 3" << " = " << ((l2 == l3) ? "True" : "False") << std::endl;
}

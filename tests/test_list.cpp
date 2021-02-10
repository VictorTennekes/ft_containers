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

#ifdef STD_TEST 
	using namespace std;
	#define ENV "STD"
#else
	using namespace ft;
	#define ENV "FT"
#endif

#define WHITE "\033[37;01m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[m"

#define VALUE int

bool is_even(int num) {return(num%2 == 0);}

template <class Container>
void print_container(Container& cont, std::string name) {
	std::cout << name << " ";
	std::cout << "[" << BLUE;
	for (typename Container::iterator it = cont.begin(); it != cont.end();)
		std::cout << *it << (++it != cont.end() ? ", " : "");
	std::cout << RESET << "]" << std::endl << std::endl;
}

int main(void) {
	std::cout << WHITE << "[" ENV "]" << RESET << std::endl;
	std::cout << WHITE << "[ List initializers/iterators checks ]" << RESET << std::endl;
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

	std::cout << WHITE << "[ List capacity checks ]" << RESET << std::endl;
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
	std::cout << WHITE << "[ Element access checks ]" << RESET << std::endl;
	std::cout << "First element of list 2: {" << l2.front() << "}" << std::endl;
	std::cout << "Last element of list 2: {" << l2.back() << "}" << std::endl;
	print_container(l2, "List 2");

	std::cout << WHITE << "[ Modifiers checks ]" << RESET << std::endl;
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

	std::cout << WHITE << "[ Operation checks ]" << RESET << std::endl;
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

	std::cout << "Removing nums if even from list 1" << std::endl;
	l1.remove_if(is_even);
	print_container(l1, "List 1");
}

// // a binary predicate implemented as a function:
// bool same_integral_part (double first, double second)
// { return ( int(first)==int(second) ); }

// // a binary predicate implemented as a class:
// struct is_near {
//   bool operator() (double first, double second)
//   { return (fabs(first-second)<5.0); }
// };

// int main ()
// {
// 	list<double> mylist;

// 	mylist.push_back(12.15);
// 	mylist.push_back(2.72);
// 	mylist.push_back(73.0);
// 	mylist.push_back(12.77);
// 	mylist.push_back(3.14);
// 	mylist.push_back(12.77);
// 	mylist.push_back(73.35);
// 	mylist.push_back(72.25);
// 	mylist.push_back(15.3);
// 	mylist.push_back(72.25);
	
// 	//   mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
// 	//                              // 15.3,  72.25, 72.25, 73.0,  73.35

// 	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
// 								// 15.3,  72.25, 73.0,  73.35
// 	print_container(mylist, "list after unique");

// 	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
// 										// 15.3,  72.25, 73.0

// 	mylist.unique (is_near());           //  2.72, 12.15, 72.25

// 	std::cout << "mylist contains:";
// 	for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// bool mycomparison (double first, double second)
// { return ( int(first)<int(second) ); }

// int main ()
// {
//   std::list<double> first, second;

//   first.push_back (3.1);
//   first.push_back (2.2);
//   first.push_back (2.9);

//   second.push_back (3.7);
//   second.push_back (7.1);
//   second.push_back (1.4);

//   first.sort();
//   second.sort();

//   first.merge(second);

//   // (second is now empty)

// 	print_container(first, "first");
// 	print_container(second, "second");

//   second.push_back (2.1);

// //   first.merge(second,mycomparison);

//   std::cout << "first contains:";
//   for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

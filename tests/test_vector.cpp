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

// int main(void) {
// 	print_env();
// 	print_container_title("Victor");
// 	print_title_saber("Victor initializers/iterators checks");

// 	victor<VALUE> v1(10, 20);

// 	print_container(v1, "Vector 1");

// 	v1.resize(15, 15);

// 	v1.back() = 420;

// 	print_container(v1, "Vector 1 reverse");
// 	std::cout << "Max size: " << v1.max_size() << std::endl;
// }

int main ()
{
	vector<int> myvector (3,100);
	vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	vector<int> myvector2;

	int myarr[] = {101, 102, 103};
	myvector.insert (myvector.begin(), myarr, myarr+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}

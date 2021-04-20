/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_queue.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 15:13:57 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/04/20 15:13:57 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <queue.hpp>
#include <queue>
#include <test_header.hpp>

template <class Type>
Type	generate_key()
{
	return (rand() % 300);
}

template <>
std::string	generate_key<std::string>()
{
	const size_t		length = 10;
	const std::string	characters("abcdefghijklmnopqrstuvwxyz");
	std::string			key(10, '\0');

	for (size_t i = 0; i < length; i++)
		key[i] = characters[rand() % characters.size()];
	return (key);
}

template <class Value>
void	init_queue_random(queue<Value>& c, size_t amount)
{
	for (size_t i = 0; i < amount; i++)
		c.push(generate_key<Value>());
}

template <class Container>
void	queue_print(const Container& c, std::string title, std::string delim = ",")
{
	Container copy(c);

	std::cout << "Printing " << title << " of size " << c.size() << std::endl;

	std::cout << "[" << SIDE;
	for (; copy.size();)
	{
		std::cout << copy.front();
		copy.pop();
		std::cout << (copy.empty() ? "" : delim); 
	}
	std::cout << RESET << "]\n\n";
}

void	init_queue_incremental(queue<int>& c, size_t amount)
{
	for (size_t i = 0; i < amount; i++)
		c.push(i);
}


template <class Container>
void	empty_queue(Container& c)
{
	while (!c.empty())
		c.pop();
}

template <class Container>
void	queue_info(const Container& c, std::string title)
{
	std::cout << "Size of " << title << " is " << c.size() << std::endl;
}

int main(void)
{
	print_env();
	print_title_saber("Queue");

	// INITIALIZERS
	print_title_saber("Initializers");
	queue<int>		queue_default;
//	init_queue_random(queue_default, 30);
	init_queue_incremental(queue_default, 30);
	queue<int>		queue_copy(queue_default);
	queue_print(queue_default, "Queue default");

	queue<int>		queue_assigned = queue_default;

	// ELEMENT ACCESS
	print_title_saber("Element access");
	queue_print(queue_default, "queue_default");
	queue_print(queue_copy, "queue_copy");
	queue_print(queue_assigned, "queue_assigned");

	// CAPACITY
	print_title_saber("Capacity");
	queue_print(queue_default, "queue_default");
	std::cout << "queue_default is: {" << (queue_default.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << "Size of queue_default: " << SIDE << queue_default.size() << RESET << std::endl;
	empty_queue(queue_default);
	std::cout << "queue_default is: {" << (queue_default.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << "Size of queue_default: " << SIDE << queue_default.size() << RESET << std::endl;
	queue_print(queue_default, "queue_default");
	
	// MODIFIERS
	print_title_saber("Modifiers");
	queue_copy.push(50);
	// queue_default.pop();
	queue_print(queue_default, "queue_default");
	queue_print(queue_copy, "queue_copy");

	// COMPARISON OPERATORS
	print_title_saber("Comparison operators");
	comparison_operator_container(queue_default, queue_copy, "queue_default", "queue_copy");
}

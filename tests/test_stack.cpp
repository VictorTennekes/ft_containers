/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_stack.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 14:09:06 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/04/20 14:09:06 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack.hpp>
#include <stack>
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
void	init_stack_random(stack<Value>& c, size_t amount)
{
	for (size_t i = 0; i < amount; i++)
		c.push(generate_key<Value>());
}

void	init_stack_incremental(stack<int>& c, size_t amount)
{
	for (size_t i = 0; i < amount; i++)
		c.push(i);
}

template <class Container>
void	stack_print(const Container& c, std::string title, std::string delim = ",")
{
	Container copy(c);

	std::cout << "Printing " << title << " of size " << c.size() << std::endl;

	std::cout << "[" << SIDE;
	for (; copy.size();)
	{
		std::cout << copy.top();
		copy.pop();
		std::cout << (copy.empty() ? "" : delim); 
	}
	std::cout << RESET << "]\n\n";
}

template <class Container>
void	empty_stack(Container& c)
{
	while (!c.empty())
		c.pop();
}

int main(void) {
	print_env();
	print_title_saber("Stack");

	// INITIALIZERS
	print_title_saber("Initializers");
	stack<int>		stack_default;
//	init_stack_random(stack_default, 30);
	init_stack_incremental(stack_default, 30);
	stack<int>		stack_copy(stack_default);
	stack_print(stack_default, "stack default");

	stack<int>		stack_assigned = stack_default;

	// ELEMENT ACCESS
	print_title_saber("Element access");
	stack_print(stack_default, "stack_default");
	stack_print(stack_copy, "stack_copy");
	stack_print(stack_assigned, "stack_assigned");

	// CAPACITY
	print_title_saber("Capacity");
	stack_print(stack_default, "stack_default");
	std::cout << "stack_default is: {" << (stack_default.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << "Size of stack_default: " << SIDE << stack_default.size() << RESET << std::endl;
	empty_stack(stack_default);
	std::cout << "stack_default is: {" << (stack_default.empty() ? RED "empty" : GREEN "filled") << RESET << "}" << std::endl;
	std::cout << "Size of stack_default: " << SIDE << stack_default.size() << RESET << std::endl;
	stack_print(stack_default, "stack_default");
	
	// MODIFIERS
	print_title_saber("Modifiers");
	stack_copy.push(50);
	stack_print(stack_default, "stack_default");
	stack_print(stack_copy, "stack_copy");

	// COMPARISON OPERATORS
	print_title_saber("Comparison operators");
	comparison_operator_container(stack_default, stack_copy, "stack_default", "stack_copy");
}

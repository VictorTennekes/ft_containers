/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   traits.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 15:44:41 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/01/27 15:44:41 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAGS_HPP
# define TAGS_HPP

// Tags
namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// Enable if
	template<bool B, typename T = void>
	struct enable_if {};
 
	template<typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	// Is iterator
	template<typename T>
	struct is_iterator {
		static const bool result = false;
	};
	
	template<>
	struct is_iterator<ft::bidirectional_iterator_tag> {
		static const bool result = true;
	};

	template<>
	struct is_iterator<ft::random_access_iterator_tag> {
		static const bool result = true;
	};
}

#endif

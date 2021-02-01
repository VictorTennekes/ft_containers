/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 16:40:44 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/01/27 16:40:44 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <traits.hpp>
# include <list>

namespace ft {
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
} // ft

#endif

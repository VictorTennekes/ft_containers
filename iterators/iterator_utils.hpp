/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator_utils.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 15:28:01 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/02/01 15:28:01 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_UTILS_HPP
# define ITERATOR_UTILS_HPP

# include <cstddef>

namespace ft {
	template<class InputIterator>
	size_t	distance(InputIterator first, InputIterator last) {
		size_t n = 0;
		while(first != last) {
			n++;
			first++;
		}
		return (n);
	}

	template<class InputIterator, class Distance>
	void	advance(InputIterator& it, Distance n) {
		while (n > 0) {
			it++;
			n--;
		}
	}
}

#endif

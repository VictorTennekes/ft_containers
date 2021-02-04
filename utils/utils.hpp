/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 13:10:18 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/02/02 13:10:18 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
	template<class T>
	void swap(T& a, T& b) {
		T tmp = a;
		a = b;
		b = tmp;
	}
}

#endif

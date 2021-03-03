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
	struct enable_if<true, T> { typedef T type; };

	template<class T>
	struct has_iterator_category {
		private:
			typedef char	true_type;
			typedef int		false_type;

			template<class U>
				static true_type	_test(typename U::iterator_category* = 0);
			template<class U>
				static false_type	_test(...);
		public:
			static const bool result = (sizeof(true_type) == sizeof(_test<T>(0)));
	};

	template<typename T>
	struct iterator_traits : public enable_if<has_iterator_category<T>::result, T> {};

	template<typename T>
	struct iterator_traits<T*> {
		typedef random_access_iterator_tag type;
	};
}

#endif

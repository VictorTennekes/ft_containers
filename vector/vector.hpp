/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 16:37:38 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/02/15 16:37:38 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>
# include <cmath>
# include <traits.hpp>
# include <iterator_utils.hpp>
# include <utils.hpp>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {
		typedef T					value_type;
		typedef Alloc				allocator_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef value_type*			pointer;
		typedef const value_type*	const_pointer;
		// typedef RandomAccesIterator iterator
		// typedef RandomAccesIterator const_iterator
		// typedef ReverseRandomAccesIterator reverse_iterator
		// typedef ReverseRandomAccesIterator const_reverse_iterator
		typedef ptrdiff_t			difference_type;
		typedef size_t				size_type;

		private:
			pointer		_data;
			size_type	_size;
			size_type	_capacity;
			Alloc		_alloc;

		public:
			// Constructors / Destructors
			explicit vector(const Alloc& alloc = Alloc()) : _size(0), _alloc(alloc) {
				_capacity = get_capacity();
				_data =  new T[_capacity];
			}

			explicit vector(size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : _size(n), _alloc(alloc) {
				_capacity = get_capacity();
				_data = new T[_capacity];
				for (size_type i = 0; i < n; i++)
					_data[i] = val;
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, typename enable_if<is_iterator<typename InputIterator::iterator_category>::result,
				InputIterator>::type* = NULL, const Alloc& alloc = Alloc()) : _alloc(alloc) {
				_size = ft::distance(first, last);
				_capacity = get_capacity();
				_data = new T[_capacity];
				for (int i = 0; first != last; first++, i++)
					_data[i] = *first;
			}

			vector(const vector& other) : _data(0), _size(0), _capacity(0), _alloc(other._alloc)  {
				*this = other;
			}

			~vector() {
				delete [] _data;
			}

			// Capacity

			size_type size() const {
				return(_size);
			}

			size_type max_size() const {
				return(_alloc.max_size());
			}

			void resize(size_type n, value_type val = value_type()) {
				(void)n;
				(void)val;
				// need to write realloc
			}

			size_type capacity() const {
				return(_capacity);
			}

			bool empty() const {
				return(_size == 0);
			}

			void reserve(size_type n) {
				(void)n;
				// need to write realloc
			}

			// Element access

			reference operator[] (size_type n) {
				return(_data[n]);
			}

		private:
			int get_capacity() {
				return(pow(2, ceil(log2(_size))));
			}
	};
}

#endif

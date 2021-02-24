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
# include <cmath>
# include <vector>
# include <traits.hpp>
# include <RandomAccessIterator.hpp>
# include <iterator_utils.hpp>
# include <utils.hpp>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T					value_type;
			typedef Alloc				allocator_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			typedef RandomAccessIterator<T*, T&> iterator;
			typedef RandomAccessIterator<const T*, const T&> const_iterator;
			typedef ReverseRandomAccessIterator<T*, T&> reverse_iterator;
			typedef ReverseRandomAccessIterator<const T*, const T&> const_reverse_iterator;
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
				_capacity = calc_capacity();
				_data =  new T[_capacity];
			}

			explicit vector(size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : _size(n), _alloc(alloc) {
				_capacity = calc_capacity();
				_data = new T[_capacity];
				for (size_type i = 0; i < n; i++)
					_data[i] = val;
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, typename enable_if<is_iterator<typename InputIterator::iterator_category>::result,
				InputIterator>::type* = NULL, const Alloc& alloc = Alloc()) : _alloc(alloc) {
				_size = ft::distance(first, last);
				_capacity = calc_capacity();
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

			// Iterators

			iterator begin() {
				return(iterator(_data));
			}

			const_iterator begin() const {
				return(const_iterator(_data));
			}

			iterator end() {
				return(iterator(_data + _size));
			}

			const_iterator end() const {
				return(const_iterator(_data + _size));
			}

			reverse_iterator rbegin() {
				return(reverse_iterator(_data + _size - 1));
			}

			const_reverse_iterator rbegin() const {
				return(const_reverse_iterator(_data + _size - 1));
			}

			reverse_iterator rend() {
				return(reverse_iterator(_data - 1));
			}

			const_reverse_iterator rend() const {
				return(const_reverse_iterator(_data - 1));
			}

			// Capacity

			size_type size() const {
				return(_size);
			}

			size_type max_size() const {
				return(_alloc.max_size());
			}

			void resize(size_type n, value_type val = value_type()) {
				if (n > _capacity)
					reallocate(n);
				while (n < _size)
					pop_back();
				while (n > _size)
					push_back(val);
			}

			size_type capacity() const {
				return(_capacity);
			}

			bool empty() const {
				return(_size == 0);
			}

			void reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("length error");
				if (n > _capacity)
					reallocate(calc_capacity(n));
			}

			// Element access

			reference operator[] (size_type n) {
				return(_data[n]);
			}

			T& at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("out of range");
				return (_data[n]);
			}
			
			const T& at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("out of range");
				return (_data[n]);
			}

			// Modifiers

			void push_back(const value_type& val) {
				if (_size == _capacity)
					reallocate(_capacity * 2);
				_data[_size] = val;
				_size++;
			}

			void pop_back() {
				_data[_size - 1] = T();
				_size--;
			}

		private:
			int calc_capacity() {
				return(pow(2, ceil(log2(_size))));
			}

			int calc_capacity(size_type size) {
				return(pow(2, ceil(log2(size))));
			}

			void reallocate(size_type new_cap){
				T* new_data = new T[new_cap];

				_capacity = new_cap;
				for (size_type i = 0; i < _size; i++)
					new_data[i] = _data[i];
				delete [] _data;
				_data = new_data;
			}
	};
}

#endif

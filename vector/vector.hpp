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
# include <limits>
# include <cmath>
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
				_capacity = 1;
				_data = _alloc.allocate(_capacity);
			}

			explicit vector(size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : _size(n), _alloc(alloc) {
				if (n == 0)
					_capacity = 1;
				else
					_capacity = calc_capacity();
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_data[i], val);
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last,
				typename iterator_traits<InputIterator>::type* = 0, const Alloc& alloc = Alloc()) : _alloc(alloc) {
				_size = ft::distance(first, last);
				_capacity = calc_capacity();
				_data = _alloc.allocate(_capacity);
				for (int i = 0; first != last; first++, i++)
					_alloc.construct(&_data[i], *first);
			}

			vector(const vector& other) : _data(NULL), _size(0), _capacity(0), _alloc(other._alloc) {
				*this = other;
			}

			~vector() {
				_alloc.deallocate(_data, _capacity);
			}

			vector& operator=(const vector& other) {
				clear();
				_capacity = other._capacity;
				_size = other._size;
				_data = _alloc.allocate(_capacity);
				int i = 0;
				for (const_iterator it = other.begin(); it != other.end(); i++, it++)
					_data[i] = *it;
				return(*this);
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
					reallocate(calc_capacity(n));
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

			const_reference operator[] (size_type n) const {
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

			T& front() {
				return(_data[0]);
			}

			const T& front() const {
				return(_data[0]);
			}

			T& back() {
				return(_data[_size - 1]);
			}

			const T& back() const {
				return(_data[_size - 1]);
			}

			// Modifiers
			template<class InputIterator>
			void assign(InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0) {
				size_type len = ft::distance(first, last);

				if (len > _capacity)
					reallocate(len);
				for (size_t i = 0; first != last; first++, i++)
					_alloc.construct(&_data[i], *first);
				_size = len;
			}

			void assign(size_type n, const value_type& val) {
				if (n > _capacity)
					reallocate(n);
				for (size_t i = 0; i < n; i++)
					_alloc.construct(&_data[i], val);
				_size = n;
			}

			void push_back(const value_type& val) {
				if (_size == _capacity)
					reallocate(_capacity * 2);
				_alloc.construct(&_data[_size], val);
				_size++;
			}

			void pop_back() {
				_alloc.destroy(&_data[_size - 1]);
				_size--;
			}

			iterator insert(iterator position, const value_type& val) {
				size_type pos = ft::distance(begin(), position);

				reallocate(_size + 1, pos, 1);
				_alloc.construct(&_data[pos], val);
				_size++;
				return(iterator(_data + pos));
			}

			void insert(iterator position, size_type n, const value_type& val) {
				size_type pos = ft::distance(begin(), position);
				
				reallocate(_size + n, pos, n);
				for (size_type i = pos; i < pos + n; i++)
					_alloc.construct(&_data[i], val);
				_size += n;
			}

			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0) {
				size_type pos = ft::distance(begin(), position);
				size_type n = ft::distance(first, last);
				
				reallocate(_size + n, pos, n);
				for (; first != last; pos++, first++)
					_alloc.construct(&_data[pos], *first);
				_size += n;
			}

			iterator erase(iterator position) {
				size_type pos = ft::distance(begin(), position);

				if (pos > _size)
					throw std::out_of_range("out of range");
				reallocate(_size - 1, pos, 1, true);
				return(begin() + pos);
			}

			iterator erase(iterator first, iterator last) {
				size_type pos = ft::distance(begin(), first);
				size_type gap = ft::distance(first, last);

				if (pos > _size)
					throw std::out_of_range("out of range");
				reallocate(_size - gap, pos, gap, true);
				return(begin() + pos);
			}

			void swap(vector& x) {
				ft::swap(_data, x._data);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
			}

			void clear() {
				reallocate(0);
			}

			allocator_type get_allocator() const {
				return (_alloc);
			}

		private:
			int calc_capacity() {
				return(pow(2, ceil(log2(_size))));
			}

			int calc_capacity(size_type size) {
				return(pow(2, ceil(log2(size))));
			}

			void reallocate(size_type new_cap, size_type pos = std::string::npos, size_type gap = 0, bool erase = false) {
				T*			new_data = _alloc.allocate(new_cap);
				size_type	j = pos;
				size_type i = 0;

				_capacity = new_cap;
				for (; i < pos && i < _size; i++)
					_alloc.construct(&new_data[i], _data[i]);
				erase == true ? i += gap : j += gap;
				for (; i < _size; i++, j++)
					_alloc.construct(&new_data[j], _data[i]);
				_alloc.deallocate(_data, _capacity);
				_data = new_data;
				if (_size > _capacity)
					_size = _capacity;
			}
	};

	template<class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return(false);
	}

	template<class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template<class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif

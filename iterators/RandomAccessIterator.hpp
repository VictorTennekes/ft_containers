/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 15:00:14 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/02/18 15:00:14 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <traits.hpp>
# include <iterator>

namespace ft {
	template<class pointer, class reference, class category = ft::random_access_iterator_tag>
	class RandomAccessIterator {
		protected:
			pointer ptr;
		public:
			typedef category iterator_category;

			RandomAccessIterator(pointer ptr = NULL) : ptr(ptr) {}
			~RandomAccessIterator() {}

			RandomAccessIterator(const RandomAccessIterator& other) {
				*this = other;
			}

			RandomAccessIterator& operator=(const RandomAccessIterator& other) {
				ptr = other.ptr;
				return(*this);
			}

			RandomAccessIterator operator++() {
				ptr++;
				return(*this);
			}

			RandomAccessIterator operator++(int) {
				RandomAccessIterator old_state(*this);
				++(*this);
				return (old_state);
			}

			RandomAccessIterator operator+(int val) {
				RandomAccessIterator tmp(*this);
				tmp += val;
				return(tmp);
			}

			RandomAccessIterator& operator+=(int val) {
				ptr += val;
				return(*this);
			}
			
			RandomAccessIterator operator--() {
				ptr--;
				return(*this);
			}
			
			RandomAccessIterator operator--(int) {
				RandomAccessIterator old_state(*this);
				--(*this);
				return(old_state);
			}

			RandomAccessIterator operator-(int val) {
				RandomAccessIterator tmp(*this);
				tmp -= val;
				return(tmp);
			}

			RandomAccessIterator& operator-=(int val) {
				ptr -= val;
				return(*this);
			}

			reference operator*() {
				return *(ptr);
			}

			pointer operator->() {
				return(ptr);
			}

			reference operator[](int index) {
				return *(ptr + index);
			}

			bool operator==(const RandomAccessIterator& other) {
				return (ptr == other.ptr);
			}

			bool operator!=(const RandomAccessIterator& other) {
				return !(ptr == other.ptr);
			}

			bool operator<(const RandomAccessIterator other) {
				return(ptr < other.ptr);
			}
			
			bool operator<=(const RandomAccessIterator other) {
				return(ptr <= other.ptr);
			}

			bool operator>(const RandomAccessIterator other) {
				return(ptr > other.ptr);
			}

			bool operator>=(const RandomAccessIterator other) {
				return(ptr >= other.ptr);
			}
	};

	template<class pointer, class reference, class category = ft::random_access_iterator_tag>
	class ReverseRandomAccessIterator {
		protected:
			pointer ptr;
		public:
			typedef category iterator_category;

			ReverseRandomAccessIterator(pointer ptr = NULL) : ptr(ptr) {}
			~ReverseRandomAccessIterator() {}

			ReverseRandomAccessIterator(const ReverseRandomAccessIterator& other) {
				*this = other;
			}

			ReverseRandomAccessIterator& operator=(const ReverseRandomAccessIterator& other) {
				ptr = other.ptr;
				return(*this);
			}

			ReverseRandomAccessIterator operator++() {
				ptr--;
				return(*this);
			}

			ReverseRandomAccessIterator operator++(int) {
				ReverseRandomAccessIterator old_state(*this);
				++(*this);
				return (old_state);
			}

			ReverseRandomAccessIterator operator+(int val) {
				ReverseRandomAccessIterator tmp(*this);
				tmp += val;
				return(tmp);
			}

			ReverseRandomAccessIterator& operator+=(int val) {
				ptr -= val;
				return(*this);
			}
			
			ReverseRandomAccessIterator operator--() {
				ptr++;
				return(*this);
			}

			ReverseRandomAccessIterator operator--(int) {
				ReverseRandomAccessIterator old_state(*this);
				--(*this);
				return(old_state);
			}

			ReverseRandomAccessIterator operator-(int val) {
				ReverseRandomAccessIterator tmp(*this);
				tmp -= val;
				return(tmp);
			}

			ReverseRandomAccessIterator& operator-=(int val) {
				ptr += val;
				return(*this);
			}

			reference operator*() {
				return *(ptr);
			}

			pointer operator->() {
				return(ptr);
			}

			reference operator[](int index) {
				return *(ptr + index);
			}

			bool operator==(const ReverseRandomAccessIterator& other) {
				return (ptr == other.ptr);
			}

			bool operator!=(const ReverseRandomAccessIterator& other) {
				return !(ptr == other.ptr);
			}

			bool operator<(const ReverseRandomAccessIterator other) {
				return(ptr < other.ptr);
			}
			
			bool operator<=(const ReverseRandomAccessIterator other) {
				return(ptr <= other.ptr);
			}

			bool operator>(const ReverseRandomAccessIterator other) {
				return(ptr > other.ptr);
			}

			bool operator>=(const ReverseRandomAccessIterator other) {
				return(ptr >= other.ptr);
			}
	};
}

#endif

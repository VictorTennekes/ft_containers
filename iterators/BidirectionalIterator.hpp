/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 15:54:18 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/01/27 15:54:18 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

// # include <Iterator.hpp>
# include "../traits/traits.hpp"
// # include <list>

namespace ft {
	template<class node, class pointer, class reference, class iterator_category = ft::bidirectional_iterator_tag>
	class BidirectionalIterator {

		private:
			node* ptr;

		public:
			BidirectionalIterator(node* ptr = NULL) : ptr(ptr) {}
			~BidirectionalIterator() {}

			BidirectionalIterator(const BidirectionalIterator& other) {
				*this = other;
			}

			BidirectionalIterator& operator=(const BidirectionalIterator& other) {
				ptr = other.ptr;
				return (*this);
			}

			BidirectionalIterator operator++(int) {
				BidirectionalIterator old_state(*this);
				++(*this);
				return (old_state);
			}

			BidirectionalIterator& operator++() {
				this->ptr = this->ptr->next;
				return (*this);
			}

			BidirectionalIterator operator--(int) {
				BidirectionalIterator old_state(*this);
				--(*this);
				return (old_state);
			}

			BidirectionalIterator& operator--() {
				this->ptr = this->ptr->prev;
				return (*this);
			}

			pointer		operator->() {
				return (&ptr->element);
			}

			reference	operator*() {
				return (ptr->element);
			}

			bool	operator==(const BidirectionalIterator& other) {
				return (ptr == other.ptr);
			}

			bool	operator!=(const BidirectionalIterator& other) {
				return (ptr != other.ptr);
			}
	};

	template<class node, class pointer, class reference, class iterator_category = ft::bidirectional_iterator_tag>
	class ReverseBidirectionalIterator : public BidirectionalIterator<node, pointer, reference, iterator_category> {

		public:
			ReverseBidirectionalIterator& operator++() {
				this->ptr = this->ptr->prev;
				return (*this);
			}
			
			ReverseBidirectionalIterator& operator--() {
				this->ptr = this->ptr->next;
				return (*this);
			}
	};
} // ft

#endif

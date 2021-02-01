/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 14:01:50 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/01/26 14:01:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "../traits/traits.hpp"
# include "../iterators/BidirectionalIterator.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class list {
		public:
			class node {
				public:
					node() : prev(NULL), next(NULL) {}
					node(const T& element, node* prev = NULL, node* next = NULL) : element(element), prev(prev), next(next) {}

					node& operator =(const node& second) {
						if (this != &second) {
							this->element = second.element;
							this->prev = second.prev;
							this->next = second.next;
						}
						return (*this);
					}

					~node() {}
					T		element;
					node	*prev;
					node	*next;
			};

		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef value_type&												reference;
			typedef const value_type&										const_reference;
			typedef value_type*												pointer;
			typedef const pointer	 										const_pointer;
			typedef BidirectionalIterator<node, T*, T&>						iterator;
			typedef BidirectionalIterator<node, const T*, const T&>			const_iterator;
			typedef ReverseBidirectionalIterator<node, T*, T&>				reverse_iterator;
			typedef ReverseBidirectionalIterator<node, const T*, const T&>	const_reverse_iterator;
			typedef ptrdiff_t												difference_type;
			typedef size_t													size_type;

		private:
			size_type					_size;
			node*						head;
			node*						tail;
			Alloc						alloc;

		public:
			explicit list(const Alloc& alloc = Alloc()) : _size(0), head(new node()), tail(new node()), alloc(alloc) {
				head->next = tail;
				tail->prev = head;
			}

			explicit list(size_type n, const T& val = T(), const Alloc& alloc = Alloc()) : _size(0), head(new node()), tail(new node()), alloc(alloc) {
				head->next = tail;
				tail->prev = head;
				for (size_type i = 0; i < n; i++)
					newNode(val, i);
			}

			template <class InputIterator>
			list(InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::result(), InputIterator>::type* == NULL,
				const Alloc& alloc = Alloc()) : _size(0), head(new node()), tail(new node()), alloc(alloc) {
				head->next = tail;
				tail->prev = head;
				for (; first != last; first++)
					newNode(*first);
			}

			// list(const list& other) : _size(0), head(new node()), tail(new node()), alloc(other.alloc) {
			// 	head->next = tail;
			// 	tail->prev = head;
			// 	for (con)
			// }

			~list() {
				clear();
				delete this->head;
				delete this->tail;
			}

			// Iterators
			iterator begin() {
				return (iterator(head->next));
			}

			const_iterator begin() const {
				return (const_iterator(head->next));
			}

			iterator end()  {
				return (iterator(tail));
			}

			const_iterator end() const {
				return (const_iterator(head->next));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(tail->prev));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(tail->prev));
			}

			reverse_iterator rend() {
				return (reverse_iterator(head));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(head));
			}

			// Capacity
			bool empty() const {
				return (!_size);
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (alloc.max_size());
			}

			// Element access
			T& front() {
				return (head->next->element);
			}

			const T& front() const {
				return (head->next->element);
			}

			T& back() {
				return (tail->prev->element);
			}

			const T& back() const {
				return (tail->prev->element);
			}

			// Modifiers

			void push_back(const T& val) {
				newNode(val);
			}

			void clear() {
				size_type size = _size;
				for (size_type i = 0; i < size; i++)
					delNode();
			}

		private:
			void	delNode(size_type pos = std::numeric_limits<size_type>::max()) {
				node* ptr = this->head->next;

				if (!this->_size)
					return ;
				for (size_type i = 0; i < pos && ptr && ptr->next != this->tail; i++)
					ptr = ptr->next;
				if (!ptr || ptr == this->tail)
					return ;
				node* prev = ptr->prev;
				ptr->prev->next = ptr->next;
				ptr->next->prev = prev;
				this->_size--;
				delete ptr;
			}

			node*	newNode(const T& value, size_type pos = std::numeric_limits<size_type>::max()) {
				node* ptr = this->head;

				for (size_type i = 0; i < pos && ptr && ptr->next != this->tail; i++)
					ptr = ptr->next;
				if (!ptr)
					return (NULL);
				ptr->next = new node(value, ptr, ptr->next);
				ptr = ptr->next;
				ptr->next->prev = ptr;
				this->_size++;
				return (ptr);
			}
	};	
}

#endif

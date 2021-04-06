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
# include <limits>
# include <traits.hpp>
# include <BidirectionalIterator.hpp>
# include <iterator_utils.hpp>
# include <utils.hpp>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
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
			Alloc						_alloc;

		public:
			explicit list(const Alloc& alloc = Alloc()) : _size(0), head(new node()), tail(new node()), _alloc(alloc) {
				head->next = tail;
				tail->prev = head;
			}

			explicit list(size_type n, const T& val = T(), const Alloc& alloc = Alloc()) : _size(0), head(new node()), tail(new node()), _alloc(alloc) {
				head->next = tail;
				tail->prev = head;
				for (size_type i = 0; i < n; i++)
					newNode(val, i);
			}

			template<class InputIterator>
			list(InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0, const Alloc& alloc = Alloc()): _size(0), head(new node()), tail(new node()), _alloc(alloc) {
				head->next = tail;
				tail->prev = head;
				for (; first != last; first++) {
					newNode(*first);
				}
			}

			list(const list& other) : _size(0), head(new node()), tail(new node()), _alloc(other._alloc) {
				head->next = tail;
				tail->prev = head;
				for (const_iterator it = other.begin(); it != other.end(); it++)
					newNode(*it);
			}

			~list() {
				clear();
				delete this->head;
				delete this->tail;
			}

			list& operator=(const list& other) {
				clear();
				for (const_iterator it = other.begin(); it != other.end(); it++)
					newNode(*it);
				return(*this); 
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
				return (const_iterator(tail));
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
				return (_alloc.max_size() / (24 / sizeof(value_type)));
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

			void assign(size_type count, const T& value) {
				clear();
				for (size_type i = 0; i < count; i++)
					newNode(value);
			}

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0) {
				clear();
				for (; first != last; first++)
					newNode(*first);
			}

			void push_front(const T& val) {
				newNode(val, 0);
			}

			void pop_front() {
				delNode(0);
			}

			void push_back(const T& val) {
				newNode(val);
			}

			void pop_back() {
				delNode();
			}

			iterator insert(iterator position, const value_type& val) {
				size_type pos = ft::distance(begin(), position);
				return(iterator(newNode(val, pos)));
			}

			void insert(iterator position, size_type n, const value_type& val) {
				size_type pos = ft::distance(begin(), position);

				for (size_type i = 0; i < n; i++)
					newNode(val, pos + i);
			}

			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0) {
				size_type pos = ft::distance(begin(), position);

				for (; first != last; first++)
					newNode(*first, pos++);
			}

			iterator erase(iterator position) {
				size_type pos = ft::distance(begin(), position++);

				delNode(pos);
				return(position);
			}

			iterator erase(iterator first, iterator(last)) {
				size_type pos = ft::distance(begin(), first);
				size_type len = ft::distance(first, last);
				
				for (; len > 0; len--)
					delNode(pos);
				return(++last);
			}

			void swap(list& x) {
				ft::swap(head, x.head);
				ft::swap(tail, x.tail);
				ft::swap<size_type>(_size, x._size);
			}

			void resize(size_type n, value_type val = value_type()) {
				while (_size > n)
					delNode();
				while (_size < n)
					newNode(val);
			}

			void clear() {
				size_type size = _size;
				for (size_type i = 0; i < size; i++)
					delNode();
			}

			// Operations
			void splice(iterator position, list& other) {
				splice(position, other, other.begin(), other.end());
			}

			void splice(iterator position, list& other, iterator element) {
				splice(position, other, element, ++iterator(element));
			}

			void splice (iterator position, list& other, iterator first, iterator last) {
				if (first == last)
					return;
				size_type len = ft::distance(first, last);

				connect(--iterator(position), first--);
				connect(first, last--);
				connect(last, position);

				_size += len;
				other._size -= len;
			}

			void remove (const value_type& val) {
				for (iterator it = begin(); it != end();) {
					if (*it == val)
						it = erase(it);
					else
						it++;
				}
			}

			template<class Predicate>
			void	remove_if(Predicate pred) {
				for (iterator it = begin(); it != end();) {
					if (pred(*it))
						it = erase(it);
					else
						it++;
				}
			}

			void unique() {
				for (iterator it = begin(); it != end(); it++) {
					for (iterator jt = ++iterator(it); jt != end() && *it == *jt; jt++)
							erase(jt);
				}
			}

			template<class BinaryPredicate>
			void unique(BinaryPredicate binary_pred) {
				for (iterator it = begin(); it != end(); it++) {
					for (iterator jt = ++iterator(it); jt != end() && binary_pred(*it, *jt); jt++)
							erase(jt);
				}
			}

			void merge(list& other) {
				iterator it = begin();
				for (iterator jt = other.begin(); jt != other.end() && it != end();) {
					for (; *jt > *it && it != end(); it++);
					splice(it, other, jt++);
				}
			}

			template<class Compare>
			void merge(list& other, Compare comp) {
				iterator it = begin();
				for (iterator jt = other.begin(); jt != other.end() && it != end();) {
					for (; comp(*jt, *it) && it != end(); it++);
					splice(it, other, jt++);
				}
			}

			void sort() {
				if (size() <= 1)
					return ;
				list<value_type> left;
				list<value_type> right;
				iterator middle = begin();
				advance(middle, size() / 2);
				left.splice(left.begin(), *this, begin(), middle);
				right.splice(right.begin(), *this);
				left.sort();
				right.sort();
				right.merge(left);
				splice(begin(), right);
			}
			
			template<class Compare>
			void sort(Compare comp) {
				if (size() <= 1)
					return ;
				list<value_type> left;
				list<value_type> right;
				iterator middle = begin();
				advance(middle, size() / 2);
				left.splice(left.begin(),*this, begin(), middle).sort(comp);
				right.splice(right.begin(),*this).sort(comp);
				right.merge(left, comp);
				splice(begin(), right);
			}

			void reverse() {
				for (iterator it = ++begin(); it != end();)
					splice(begin(), *this, it++);
			}

			allocator_type get_allocator() const {
				return (_alloc);
			}

		private:
			void connect(iterator front, iterator back) {
				front.ptr->next = back.ptr;
				back.ptr->prev = front.ptr;
			}

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

			node* newNode(const T& value, size_type pos = std::numeric_limits<size_type>::max()) {
				node *ptr = this->head;
				for (size_type i = 0; i < pos && ptr && ptr->next != this->tail; i++)
					ptr = ptr->next;
				if (!ptr)
					return (NULL);
				ptr->next = new node(value, ptr, ptr->next);
				ptr = ptr->next;
				ptr->next->prev = ptr;
				this->_size++;
				return(ptr);
			}
	};

	template<class T, class Alloc>
	bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template<class T, class Alloc>
	bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	
	template<class T, class Alloc>
	bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template<class T, class Alloc>
	bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}
	
	template<class T, class Alloc>
	bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (rhs < lhs);
	}
	
	template<class T, class Alloc>
	bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void swap(list<T,Alloc>& x, list<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif

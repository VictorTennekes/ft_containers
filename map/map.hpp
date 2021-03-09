/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 13:26:12 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/03/08 13:26:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <limits>
# include <utils.hpp>
# include <traits.hpp>
# include <iterator_utils.hpp>
# include <map>

namespace ft {
	template<class Value>
	class node {
		public:
			Value value;
			node *parent;
			node *left;
			node *right;

			node(const Value& value = Value(), node* parent = NULL, node* left = NULL, node* right = NULL) : value(value), parent(parent), left(left), right(right) {}
			node(const node& other) {
				*this = other;
			}
			node &operator=(const node& other) {
				if (this != &other) {
					value = other.value;
					parent = other.parent;
					left = other.left;
					right = other.right;
				}
				return (*this);
			}
			~node() {}

			node *next() {
				node *iter = this;
				if (iter->right) {
					iter = iter->right;
					while (iter->left)
						iter = iter->left;
				} else {
					while (iter->parent && iter->parent->right == iter)
						iter = iter->parent;
					iter = iter->parent;
				}
				return(iter);
			}

			node *prev() {
				node *iter = this;
				if (iter->left) {
					iter = iter->left;
					while (iter->right)
						iter = iter->right;
				} else {
					while (iter->parent && iter->parent->left == iter)
						iter = iter->parent;
					iter = iter->parent;
				}
				return(iter);
			}
	};

	template<class value, class pointer, class reference, class category = ft::bidirectional_iterator_tag>
	class BidirectionalIterator {
		public:
			typedef ft::node<value>	node;
			typedef category		iterator_category;
			node	*ptr;

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
				ptr = ptr->next();
				return (*this);
			}

			BidirectionalIterator operator--(int) {
				BidirectionalIterator old_state(*this);
				--(*this);
				return (old_state);
			}

			BidirectionalIterator& operator--() {
				ptr = ptr->prev();
				return (*this);
			}

			pointer		operator->() {
				return (&ptr->value);
			}

			reference	operator*() {
				return (ptr->value);
			}

			bool	operator==(const BidirectionalIterator& other) {
				return (ptr == other.ptr);
			}

			bool	operator!=(const BidirectionalIterator& other) {
				return (ptr != other.ptr);
			}
	};

	template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const Key, mapped_type>					value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			typedef value_type*											pointer;
			typedef const value_type*									const_pointer;
			typedef ft::BidirectionalIterator<value_type, pointer, reference> iterator;
			typedef ft::BidirectionalIterator<value_type, const_pointer, const_reference> const_iterator;
			// typedef ft::ReverseBidirectionalIterator<value_type, pointer, reference> reverse_iterator;
			// typedef ft::ReverseBidirectionalIterator<value_type, const_pointer, const_reference> const_reverse_iterator;
			typedef ptrdiff_t											difference_type;
			typedef size_t												size_type;

			class value_compare : public ft::binary_function<value_type, value_type, bool> {
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return(comp(x.first, y.first));
					}
			};
		
		private:
			typedef		ft::node<value_type> node;
			node 		*first;
			node 		*last;
			node		*root;
			size_type	_size;
			Compare		compare;
			Alloc		_alloc;

		public:
			map(const Compare& compare = Compare(), const Alloc& alloc = Alloc()): first(new node()), last(new node()), root(NULL), _size(0), compare(compare), _alloc(alloc) {
				first->parent = last;
				last->parent = first;
			};

			ft::pair<iterator, bool>insert(const value_type& value) {
				iterator it = find(value.first);
				if (it != end() && it != begin())
					return (ft::pair<iterator, bool>(it, false));
				if (_size == 0) {
					root = new node(value, NULL, first, last);
					first->parent = root;
					last->parent = root;
					return(ft::pair<iterator, bool>(root, true));
				}
				node *iter = root;
				node *parent = NULL;
				while (iter && iter != first && iter != last) {
					parent = iter;
					if (compare(value.first, iter->value.first))
						iter = iter->left;
					else if (compare(iter->value.first, value.first))
						iter = iter->right;
				}
				iter = new node(value, parent, NULL, NULL);
				if (last->parent == this->first || compare(iter->value.first, value.first))
					connect_node(iter, &parent->right, this->last);
				if (this->first->parent == this->last || compare(value.first, iter->value.first))
					connect_node(iter, &parent->left, this->first);
				this->_size++;
				return (ft::pair<iterator, bool>(iterator(iter), true));
			}

			mapped_type& operator[](const key_type& k) {
				iterator res = find(k);
				if (res == end() || res == begin())
					insert(value_type(k, T()).first);
				return (res.ptr->value.second);
			}

			iterator find(const key_type& k) {
				if (!root)
					return(end());
				iterator iter = iterator(root);
				while (iter != first && iter != last) {
					if (compare(k, iter.ptr->value.first))
						iter = iter.ptr->left;
					else if (compare(iter.ptr->value.first, k))
						iter = iter.ptr->right;
					else
						return (iter);
				}
				return(end());
			}

			iterator begin() {
				return (iterator(first->parent));
			}

			const_iterator begin() const {
				return (const_iterator(first->parent));
			}

			iterator end() {
				return (iterator(last));
			}
			const_iterator end() const {
				return(const_iterator(last));
			}

		private:
			void connect_node(node *child, node** parent_childptr, node *parent) {
				if (child)
					child->parent = parent;
				if (parent_childptr)
					*parent_childptr = child;
			}
	};
}

#endif

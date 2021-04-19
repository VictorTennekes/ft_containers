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
# include <utils.hpp>

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

	template<class value, class pointer, class reference, class category = ft::bidirectional_iterator_tag>
	class ReverseBidirectionalIterator {
		public:
			typedef ft::node<value>	node;
			typedef category		iterator_category;
			node	*ptr;

			ReverseBidirectionalIterator(node* ptr = NULL) : ptr(ptr) {}
			~ReverseBidirectionalIterator() {}

			ReverseBidirectionalIterator(const ReverseBidirectionalIterator& other) {
				*this = other;
			}

			ReverseBidirectionalIterator& operator=(const ReverseBidirectionalIterator& other) {
				ptr = other.ptr;
				return (*this);
			}

			ReverseBidirectionalIterator operator++(int) {
				ReverseBidirectionalIterator old_state(*this);
				++(*this);
				return (old_state);
			}

			ReverseBidirectionalIterator& operator++() {
				ptr = ptr->prev();
				return (*this);
			}

			ReverseBidirectionalIterator operator--(int) {
				ReverseBidirectionalIterator old_state(*this);
				--(*this);
				return (old_state);
			}

			ReverseBidirectionalIterator& operator--() {
				ptr = ptr->next();
				return (*this);
			}

			pointer		operator->() {
				return (&ptr->value);
			}

			reference	operator*() {
				return (ptr->value);
			}

			bool	operator==(const ReverseBidirectionalIterator& other) {
				return (ptr == other.ptr);
			}

			bool	operator!=(const ReverseBidirectionalIterator& other) {
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
			typedef ft::ReverseBidirectionalIterator<value_type, pointer, reference> reverse_iterator;
			typedef ft::ReverseBidirectionalIterator<value_type, const_pointer, const_reference> const_reverse_iterator;
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
			node 		*head;
			node 		*tail;
			node		*root;
			size_type	_size;
			Compare		compare;
			Alloc		_alloc;

		public:
			explicit map(const Compare& compare = Compare(), const Alloc& alloc = Alloc()) : head(new node()), tail(new node()), root(NULL), _size(0), compare(compare), _alloc(alloc) {
				head->parent = tail;
				tail->parent = head;
			};

			template<class InputIterator>
			map(InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0, const Compare& compare = Compare(), const Alloc& alloc = Alloc()) : head(new node()), tail(new node()), root(NULL), _size(0), compare(compare), _alloc(alloc) {
				head->parent = tail;
				tail->parent = head;
				insert(first, last);	
			}
			
			map(const map& other) : head(new node()), tail(new node()), root(NULL), _size(0), compare(other.compare), _alloc(other._alloc) {
				head->parent = tail;
				tail->parent = head;
				*this = other;
			}

			~map() {
				clear();
				delete head;
				delete tail;
			}

			map& operator=(const map& other) {
				if (this != &other) {
					clear();
					insert(other.begin(), other.end());
				}
				return (*this);
			}

			iterator begin() {
				return (iterator(head->parent));
			}

			const_iterator begin() const {
				return (const_iterator(head->parent));
			}
			
			iterator end() {
				return (iterator(tail));
			}

			const_iterator end() const {
				return (const_iterator(tail));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(tail->parent));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(tail->parent));
			}

			reverse_iterator rend() {
				return (reverse_iterator(head));
			}
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(head));
			}

			bool empty() const {
				return (_size == 0);
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size() / 2);
			}

			mapped_type& operator[] (const key_type& k) {
				iterator it = find(k);
				if (it == end() || it == iterator(head))
					it = insert(value_type(k, T())).first;
				return(it->second);
			}

			ft::pair<iterator, bool> insert(const value_type& val) {
				if (empty())
					return(ft::pair<iterator, bool>(insert_root(val), true));
				node *iter = root;
				node *parent = NULL;
				while (iter && iter != head && iter != tail) {
					parent = iter;
					if (compare(val.first, iter->value.first))
						iter = iter->left;
					else if (compare(iter->value.first, val.first))
						iter = iter->right;
					else
						return(ft::pair<iterator, bool>(iterator(iter), false));
				}
				node *res = new node(val, parent, NULL, NULL);
				if (iter == head || compare(val.first, parent->value.first)) {
					connect_node(parent, &parent->left, res);
					connect_node(res, &res->left, iter);
				}
				else if (iter == tail || compare(parent->value.first, val.first)) {
					connect_node(parent, &parent->right, res);
					connect_node(res, &res->right, iter);
				}
				_size++;
				return(ft::pair<iterator, bool>(iterator(res), true));
			}

			iterator insert(iterator position, const value_type& val) {
				(void)position;
				return(insert(val).first);
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type* = 0) {
				for (;first != last; first++)
					insert(*first);
			}

		private:
			void delete_root(node *pos) {
				reset_node_pos(head);
				reset_node_pos(tail);
				head->parent = tail;
				tail->parent = head;
				delete (pos);
			}

			void delete_node(node *pos) {
				node **child_ptr = pos->parent->right == pos ? &pos->parent->right : &pos->parent->left;
				*child_ptr = NULL;
				delete(pos);
			}

			node* replacement(node* pos, bool min) {
				if (min) {
					pos = pos->right;
					while(pos->left)
						pos = pos->left;
					return (pos);
				}
				pos = pos->left;
				while(pos->right)
					pos = pos->right;
				return (pos);
			}
			
			void delete_one_child(node* pos) {
				node **child_ptr = pos->parent->right == pos ? &pos->parent->right : &pos->parent->left;
				node *child = pos->right ? pos->right : pos->left;
				connect_node(pos->parent, child_ptr, child);
				if (pos == root)
					root = child;
				delete (pos);
			}

			void delete_two_children(node *pos) {
				node *rep = replacement(pos, true);
				if (rep == tail)
					return delete_root(pos);
				node **child_ptr;
				if (pos->parent)
					child_ptr = pos->parent->right == pos ? &pos->parent->right : &pos->parent->left;
				else
					child_ptr = &root;
				*child_ptr = rep;
				ft::swap(rep->parent, pos->parent);
				ft::swap(rep->right, pos->right);
				ft::swap(rep->left, pos->left);
				if (rep->right == rep)
					rep->right = pos;
				rep->right->parent = rep;
				rep->left->parent = rep;
				if (pos->left || pos->right)
					delete_one_child(pos);
				else 
					delete_node(pos);
			}

		public:

			//erase
			void erase(iterator position) {
				if (!size())
					return;
				node *pos = position.ptr;
				bool left_child = (pos->left != NULL);
				bool right_child = (pos->right != NULL);
				if (left_child && right_child)
					delete_two_children(pos);
				else if (left_child || right_child) {
					delete_one_child(pos);
				} else
					delete_node(pos);
				_size--;
			}

			size_type erase (const key_type& k) {
				iterator pos = find(k);
				if (pos != end()) {
					erase(pos);
					return (1);
				}
				return (0);
			}

			void erase (iterator first, iterator last) {
				bool has_root = false;
				for (; first != last;) {
					if (first == iterator(root))
						has_root = true;
					erase(first++);
				}
				if (has_root && last != iterator(root))
					erase(iterator(root));
			}

			void swap(map& x) {
				ft::swap(head, x.head);
				ft::swap(tail, x.tail);
				ft::swap(root, x.root);
				ft::swap(_size, x._size);
				ft::swap(compare, x.compare);
				ft::swap(_alloc, x._alloc);
			}

			void clear() {
				erase(begin(), end());
			}

			key_compare key_comp() const {
				return(compare);
			}

			value_compare value_comp() const {
				return (value_compare(compare));
			}

			iterator find (const key_type& k) {
				if (empty())
					return (end());
				node* iter = root;
				while (iter && iter != head && iter != tail) {
					if (compare(k, iter->value.first))
						iter = iter->left;
					else if (compare(iter->value.first, k))
						iter = iter->right;
					else
						return (iterator(iter));
				}
				return(end());
			}

			const_iterator find(const key_type& k) const {
				return (const_iterator(const_cast<map *>(this)->find(k).ptr));
			}

			size_type count(const key_type &k) const {
				return (find(k) == end() ? 0 : 1);
			}

			iterator lower_bound (const key_type& k) {
				iterator it = find(k);
				if (it == end())
					for (it = begin(); it != end() && compare(it->first,k); it++) {}
				else
					--it;
				return (it);
			}

			const_iterator lower_bound(const key_type& k) const {
				return (const_iterator(const_cast<map *>(this)->lower_bound(k).ptr));
			}

			iterator upper_bound(const key_type& k) {
				iterator it = find(k);
				if (it == end())
					for (; it != end() && compare(it->first,k); it--) {}
				else
					++it;
				return (it);
			}

			const_iterator upper_bound(const key_type& k) const {
				return (const_iterator(const_cast<map *>(this)->upper_bound(k).ptr));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
				return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

			ft::pair<iterator, iterator> equal_range(const key_type& k) {
				return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			allocator_type get_allocator() const {
				return(_alloc);
			}

		private:
			void reset_node_pos(node *target) {
				target->parent = NULL;
				target->left = NULL;
				target->right = NULL;
			}

			void		connect_node(node *parent, node **parent_childptr, node *child) {
				if (child)
					child->parent = parent;
				if ((child == head || child == tail) && (parent == head || parent == tail))
					return ;
				if (parent_childptr)
					*parent_childptr = child;
			}

			iterator	insert_root(const value_type& val) {
				root = new node(val, NULL, NULL, NULL);
				connect_node(root, &root->left, head);
				connect_node(root, &root->right, tail);
				_size++;
				return(iterator(root));
			}
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
		x.swap(y);
	}
}

#endif

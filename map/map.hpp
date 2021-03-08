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
# include <BidirectionalIterator.hpp>
# include <iterator_utils.hpp>
# include <map>

namespace ft {
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
			// typedef ft::BidirectionalIterator<value_type, pointer, reference> iterator;
			// typedef ft::BidirectionalIterator<value_type, const_pointer, const_reference> const_iterator;
			// typedef ft::ReverseBidirectionalIterator<value_type, pointer, reference> reverse_iterator;
			// typedef ft::ReverseBidirectionalIterator<value_type, const_pointer, const_reference> const_reverse_iterator;
			typedef ptrdiff_t											difference_type;
			typedef size_t												size_type;

			class node {
				public:
					value_type value;
					node* parent;
					node* left;
					node* right;

					node(const value_type& value = value_type(), node* parent = NULL, node* left = NULL, node* right = NULL) : value(value), parent(parent), left(left), right(right) {}
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
			};

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
			node 		*first;
			node 		*last;
			node		*root;
			size_type	_size;
			Compare		compare;
			Alloc		_alloc;

		public:
			map(const Compare& compare = Compare(), const Alloc& alloc = Alloc()): first(new node()), last(new node()), _size(0), compare(compare), _alloc(alloc) {
				first->parent = last;
				last->parent = first;
			};
	};
}

#endif

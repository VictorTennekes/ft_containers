/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 13:21:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/04/20 13:21:45 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <list.hpp>

namespace ft {

	template<class T, class Container>
	class stack;

	template<class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template<class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template<class T, class Container = list<T> >
	class stack {
		public:
			friend bool operator< <>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator== <>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type ctnr;

		public:
			explicit stack(const container_type& ctnr = container_type()) : ctnr(ctnr) {}
			stack(const stack& other) : ctnr(other.ctnr) {}
			~stack() {}

			stack& operator=(const stack& other) {
				if (this != &other)
					ctnr = other.ctnr;
				return(*this);
			}

			bool empty() const {
				return(ctnr.empty());
			}

			size_type size() const {
				return(ctnr.size());
			}

			value_type& top() {
				return(ctnr.back());
			}

			const value_type& top() const {
				return(ctnr.back());
			}

			void push(const value_type& val) {
				ctnr.push_back(val);
			}

			void pop() {
				ctnr.pop_back();
			}
	};

	template<class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ctnr == rhs.ctnr);
	}

	template<class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ctnr < rhs.ctnr);
	}

	template<class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(rhs < lhs);
	}

	template<class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (rhs < lhs);
	}

	template<class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs < rhs);
	}
}

#endif

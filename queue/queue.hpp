/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 13:21:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/04/20 13:21:45 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <list.hpp>

namespace ft {

	template<class T, class Container>
	class queue;

	template<class T, class Container>
	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template<class T, class Container>
	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

	template<class T, class Container = list<T> >
	class queue {
		public:
			friend bool operator< <>(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
			friend bool operator== <>(const queue<T,Container>& lhs, const queue<T,Container>& rhs);

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type ctnr;

		public:
			explicit queue(const container_type& ctnr = container_type()) : ctnr(ctnr) {}
			queue(const queue& other) : ctnr(other.ctnr) {}
			~queue() {}

			queue& operator=(const queue& other) {
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

			value_type& front() {
				return(ctnr.front());
			}

			const value_type& front() const {
				return(ctnr.front());
			}

			value_type& back() {
				return(ctnr.back());
			}

			const value_type& back() const {
				return(ctnr.back());
			}

			void push(const value_type& val) {
				ctnr.push_back(val);
			}

			void pop() {
				ctnr.pop_front();
			}
	};

	template<class T, class Container>
	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs.ctnr == rhs.ctnr);
	}

	template<class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Container>
	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs.ctnr < rhs.ctnr);
	}

	template<class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return !(rhs < lhs);
	}

	template<class T, class Container>
	bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (rhs < lhs);
	}

	template<class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return !(lhs < rhs);
	}
}

#endif

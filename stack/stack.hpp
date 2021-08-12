#ifndef STACK_HPP
# define STACK_HPP
#include <memory>
#include <iostream>
#include <limits>
#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T						value_type;
			typedef size_t					size_type;
			typedef Container				container_type;

		private:
			container_type _container;

		public:
			explicit stack (const container_type& ctnr = container_type()):_container(ctnr){}
			stack (const stack &cp):_container(cp._container){}
			stack& operator=(const stack& cp)
			{
				if (this != &cp)
					this->_container = cp._container;
				return (*this);
			}

			void pop(){_container.pop_back();}
			bool empty() const{return _container.empty();}
			size_type size() const{return _container.size();}
			void push (const value_type& val){_container.push_back(val);}
			const value_type& top() const{return _container.back();}
			value_type& top(){return _container.back();}

			~stack(){}
	
	 	friend bool operator== (const stack& lhs, const stack& rhs) { return lhs._container == rhs._container; }
		friend bool operator!= (const stack& lhs, const stack& rhs) { return lhs._container != rhs._container; }
		friend bool operator<  (const stack& lhs, const stack& rhs) { return lhs._container < rhs._container; }
		friend bool operator<= (const stack& lhs, const stack& rhs) { return lhs._container <= rhs._container; }
		friend bool operator>  (const stack& lhs, const stack& rhs) { return lhs._container > rhs._container; }
		friend bool operator>= (const stack& lhs, const stack& rhs) { return lhs._container >= rhs._container; }
	};
}

#endif

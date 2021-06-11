#ifndef LIST_HPP
# define LIST_HPP
#include <iostream>
#include <memory>
#include <iostream>
#include <limits>
#include <type_traits>


namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class list
	{
	public:
        /************************************************************************ Typedef ************************************************************************/
		typedef T							value_type;
		typedef T& 							reference;            
		typedef Alloc						allocator_type;
		typedef const T&					const_reference;
		typedef T* 							pointer;
		typedef T* const 					const_pointer;
		typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;

        typdef struct s_node
        {
            T data;
            struct s_list next;
            struct s_list prev;
        }               t_node;
        

    protected:
		Alloc _myAlloc;
		size_type _capacity;
		size_type _dataCounter;
		T *head;
    
    public:
        void push_front (const value_type& val)
        {
            
        }

	};
}


#endif
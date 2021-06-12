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
	protected:
        typdef struct s_node
        {
            T data;
            struct s_node *next;
            struct s_node *prev;
        }               t_node;
		size_type		_size;
		Alloc 			_myAlloc;
		t_node			_control;
    
    public:
		list (const allocator_type& alloc = allocator_type()):_control{}, _size(0)
		{

		}

		void push_front(const value_type& val)
		{
			t_node *new_node = _alloc_node.allocate(1);
			_myAlloc.construct(new_node, val);
			node->data = val;
			_myAlloc.construct(node->data, val;
			_myAlloc.construct(new_node->next NULL);
			_myAlloc.construct(new_node->prev, NULL);
			new_node->next = _control.next;
			_control.next->prev = new_node;
			_control.next = new_node;
			_size++;
        }
		void push_back(const value_type& val)
		{
			t_node *new_node = _alloc_node.allocate(1);
			_myAlloc.construct(new_node, val);
			node->data = val;
			_myAlloc.construct(node->data, val;
			_myAlloc.construct(new_node->next NULL);
			_myAlloc.construct(new_node->prev, NULL);

			new_node->next = 0;
			_control.next->next = new_node;
			_control.prev = new_node;
			_size--;
        }
	};
}


#endif
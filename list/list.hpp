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
        typedef struct s_node
        {
            T data;
            struct s_node *next;
            struct s_node *prev;
        }               t_node;
		t_node			*_head;
		size_type		_size;
		Alloc 			_myAlloc;
        std::allocator<struct s_node> _alloc_node;

    
    public:
		list (const allocator_type& alloc = allocator_type()):_head(0), _size(0)	
		{
			_head = _alloc_node.allocate(1);
			_myAlloc.construct(&_head->data, 555);
			_head->next = NULL;
			_head->prev = NULL;
			 (void)alloc;
		}

/************************************************************************  iterator ************************************************************************/
		class  iterator 
		{
		public:
		    typedef t_node *                           pointeur;

		/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
			iterator():m_ptr(0){}
			// iterator(pointer ptr) : m_ptr(ptr) {}
			iterator(t_node *ptr) : m_ptr(ptr) {}

			// iterator(iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}
			~iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			// value_type *operator*() const { return (&m_ptr->data); }
			value_type		&operator*()const {return m_ptr->data;}

			value_type operator->() { return (&m_ptr); }

			// /*********************mutable iterators********************/
			// iterator operator=(const   iterator& a){m_ptr = a.m_ptr; return (*this);}

			// /*********************incrementation******************/
			// /* Prefix increment	*/
			iterator&	operator++() { m_ptr->next; return (*this);	}
			// /* Postfix increment*/
			iterator	operator++(int) { ++(*this); return (*this); }
			// iterator	operator+(const difference_type& movement)	{m_ptr+= movement; return (*this);	}

			// /*****************Can be decremented*************************/
			// iterator &	operator--(){--m_ptr;return (*this);}
			// iterator &	operator--(int){--m_ptr; return (*this);}
			// iterator	operator-(const int& movement){pointer oldPtr = this->m_ptr; this->m_ptr+=movement; this->m_ptr = oldPtr;return *this;}

			// /***************assignment operations += and -= ************ */
		    // iterator &  operator+=(const difference_type& movement){this->m_ptr += movement;return (*this);}
			// iterator &  operator-=(const difference_type& movement){this->m_ptr -= movement;return (*this);}

			// /***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!=(const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };
			// friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };
			
			// /*****************Can be compared with inequality relational operators (<, >, <= and >=).*********/
			// friend bool operator<(const   iterator& a, const   iterator& b) { return (a.m_ptr < b.m_ptr); };
			// friend bool operator>(const   iterator& a, const   iterator& b) { return (a.m_ptr > b.m_ptr); };
 			// friend bool operator<=(const  iterator& a, const   iterator& b) { return (a.m_ptr <= b.m_ptr); };
			// friend bool operator>=(const  iterator& a, const   iterator& b) { return (a.m_ptr >= b.m_ptr); };

		private:
			pointeur m_ptr;
		};
		iterator begin() {return   iterator(_head->next); }
		// iterator end()   { return  iterator(_head); }
		void push_back(const value_type& val)
		{
			t_node **last = _&head->next;
			t_node *new_node = _alloc_node.allocate(1);
			// _alloc_node.construct(&new_node->data, val);
			_myAlloc.construct(&new_node->data, val)
			new_node->next = _head;
			new_node->prev = _head->next;
			_head->prev = new_node;
			_head->next = new_node;
			*last->next = new_node;
			_size++;
        }

		size_type	size(void){return (_size);}
		// void push_back(const value_type& val)
		// {
		// 	t_node *new_node = _alloc_node.allocate(1);
		// 	_myAlloc.construct(new_node, val);
		// 	node->data = val;
		// 	_myAlloc.construct(node->data, val;
		// 	_myAlloc.construct(new_node->next NULL);
		// 	_myAlloc.construct(new_node->prev, NULL);

		// 	new_node->next = 0;
		// 	_control.next->next = new_node;
		// 	_control.prev = new_node;
		// 	_size--;
        // }
		
	};
}


#endif
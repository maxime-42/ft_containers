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
			_head->next = _head;
			_head->prev = _head;
			 (void)alloc;
		}

		list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			while (n > 0)
			{
				this->push_back(val);
				n--;
			}
		}
		list (const list& x)
		{
				this->push_back(x);
		}

		template <typename T, typename Alloc> template <class InputIterator>
		list<T, Alloc>::list(typename std::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) :_head(0), _size(0)
		{
			_head = _alloc_node.allocate(1);
			_head->prev = _head;
			_head->next = _head;
    		while (first != last)
    		{
        		push_back(*first);
        		first++;
    		}
		}
		void delete_one_Node()
		{
			
		}
		~list()
		{

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

			// /*********************incrementation******************/
			// /* Prefix increment	*/
			iterator&	operator++(int) { m_ptr = m_ptr->next; return (*this);	}

			// /* Postfix increment*/
			// iterator	operator++(int) { ++(*this); return (*this); }
			// iterator	operator+(const difference_type& movement)	{m_ptr+= movement; return (*this);	}

			// /*****************Can be decremented*************************/        
			iterator        &operator--() { m_ptr = m_ptr->prev; return *this; }; // --a
        	iterator        operator--(int) { iterator it = *this; --(*this); return it; }; // a--
			// iterator	operator-(const int& movement){pointer oldPtr = this->m_ptr; this->m_ptr+=movement; this->m_ptr = oldPtr;return *this;}

			// /***************assignment operations += and -= ************ */
		    // iterator &  operator+=(const difference_type& movement){this->m_ptr += movement;return (*this);}
			// iterator &  operator-=(const difference_type& movement){this->m_ptr -= movement;return (*this);}

			// /***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!=(const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };
			
			/*****************Can be compared with inequality relational operators (<, >, <= and >=).*********/
			friend bool operator<(const   iterator& a, const   iterator& b) { return (a.m_ptr < b.m_ptr); };
			friend bool operator>(const   iterator& a, const   iterator& b) { return (a.m_ptr > b.m_ptr); };
 			friend bool operator<=(const  iterator& a, const   iterator& b) { return (a.m_ptr <= b.m_ptr); };
			friend bool operator>=(const  iterator& a, const   iterator& b) { return (a.m_ptr >= b.m_ptr); };

		private:
			pointeur m_ptr;
		};
		iterator begin() {return   iterator(_head->next); }
		iterator end()   { return  iterator(_head); }

		void push_back(const value_type& val)
		{
			t_node *new_node = _alloc_node.allocate(1);
			_myAlloc.construct(&new_node->data, val);
			new_node->next = _head;
			new_node->prev = _head->prev;
			_head->prev->next = new_node;
			_head->prev = new_node;
			_size++;
        }

		void push_front(const value_type& val)
		{
			t_node *new_node = _alloc_node.allocate(1);
			_myAlloc.construct(&new_node->data, val);
			new_node->prev = _head;
			new_node->next = _head->next;
			_head->next->prev = new_node;
			_head->next = new_node;
			_size++;
        }

		size_type	size(void){return (_size);}
		
	};
}


#endif
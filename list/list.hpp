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
			// size_type lenght;
            struct s_node *next;
            struct s_node *prev;
        }               t_node;
		t_node			*_head;
		size_type		_size;
		Alloc 			_myAlloc;
        std::allocator<struct s_node> _alloc_node;
	    typedef t_node *  pointer_node;

    
    public:
		list (const allocator_type& alloc = allocator_type()):_head(0), _size(0)	
		{
			_head = _alloc_node.allocate(1);
			_myAlloc.construct(&_head->data, T());
			_head->next = _head;
			_head->prev = _head;
			// _head->lenght = 0;
			 (void)alloc;
		}

		list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):_head(0), _size(0)	
		{
			(void)alloc;
			_head = _alloc_node.allocate(1);
			_myAlloc.construct(&_head->data, 555);
			_head->next = _head;
			_head->prev = _head;
			// _head->lenght = 0;
			std::cout<< "hellow world\n";
			while (n > 0)
			{
				this->push_back(val);
				n--;
			}
		}
		list (const list& x)
		{
			_head = _alloc_node.allocate(1);
			_head->prev = _head;
			_head->next = _head;
			// _head->lenght = 0;
			this->push_back(x);
		}
		
		template <class InputIterator>
		list(typename std::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) :_head(0), _size(0)
		{
			(void)alloc;
			_head = _alloc_node.allocate(1);
			_head->prev = _head;
			_head->next = _head;
    		while (first != last)
    		{
        		push_back(*first);
        		first++;
    		}
		}

		void delete_one_Node(t_node *toDel)
		{
			t_node *prev = toDel->prev;
			t_node *next = toDel->next;

			prev->next = next;
			next->prev = prev;
			toDel->next = 0;
			toDel->prev = 0;
			_alloc_node.deallocate(toDel, 1);
			_alloc_node.destroy(toDel);
		}
		


		~list()
		{
			for (size_t i = 0; i < _size; i++)
			{
				this->delete_one_Node(_head->next);
			}
			_alloc_node.deallocate(_head, 1);
			_alloc_node.destroy(_head);
			_head = 0;
			_size = 0;
		}
/************************************************************************  iterator ************************************************************************/
		class  iterator 
		{
		public:

		/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
			iterator():m_ptr(0){}
			// iterator(pointer ptr) : m_ptr(ptr) {}
			iterator(t_node *ptr) : m_ptr(ptr) {}

			// iterator(iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}
			~iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			// value_type *operator*() const { return (&m_ptr->data); }
			value_type		&operator*()const {return m_ptr->data;}

			pointer_node operator->() { return (m_ptr); }

 			iterator        &operator++() { m_ptr = m_ptr->next; return *this; }; // ++a
        	iterator        operator++(int) { iterator it = *this; ++(*this); return it; }; // a++
			
			// /* Postfix increment*/
			// iterator	operator++(int) { ++(*this); return (*this); }
			// iterator	operator+(const difference_type& movement)	{m_ptr+= movement; return (*this);	}

			// /*****************Can be decremented*************************/        
			iterator        &operator--() { m_ptr = m_ptr->prev; return *this; }; // --a
        	iterator        operator--(int) { iterator it = *this; --(*this); return it; }; // a--
			// iterator	operator-(const int& movement){pointer oldPtr = this->m_ptr; this->m_ptr+=movement; this->m_ptr = oldPtr;return *this;}

			// /***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!=(const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };
			
			/*****************Can be compared with inequality relational operators (<, >, <= and >=).*********/
			friend bool operator<(const   iterator& a, const   iterator& b) { return (a.m_ptr < b.m_ptr); };
			friend bool operator>(const   iterator& a, const   iterator& b) { return (a.m_ptr > b.m_ptr); };
 			friend bool operator<=(const  iterator& a, const   iterator& b) { return (a.m_ptr <= b.m_ptr); };
			friend bool operator>=(const  iterator& a, const   iterator& b) { return (a.m_ptr >= b.m_ptr); };

		private:
			pointer_node m_ptr;
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
			// _head->lenght++;
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

		template <class M>
		void ft_swap(M &a, M &b)
		{
			M tmp = a;
			a = b;
			b = tmp;
		}

		void swap (list& x)
		{
			ft_swap(_head, x._head);
			ft_swap(_size, x._size);
			ft_swap(_myAlloc, x._myAlloc);
			ft_swap(_alloc_node, x._alloc_node);
		}

		void	swap_node(t_node *a, t_node *b)
		{
			t_node *prev_a = a->prev;
			t_node *next_b = b->next;
			a->prev = a->next;
			a->next = b->next;
			b->prev = prev_a;
			b->next = a;
			prev_a->next = b;
			next_b->prev = a;
		}

		void	updateHead(t_node *a, t_node *b)
		{
			if (_head->prev == b)
			{
				_head->prev = a;
			}
		}

		void sort()
		{
			if (_size > 1)
			{
				size_type count = -1;
				t_node *it = _head->next;
				while (++count < this->size() - 1)
				{
					if (it->data > it->next->data)
					{
						updateHead(it, it->next);
						swap_node(it, it->next);
						it = _head->next;
						count = -1;
					}
					else
						it = it->next;
				}
			}
		}
		
		template <class Compare>
	 	void sort (Compare comp)
		{
			if (_size > 1)
			{
				size_type count = -1;
				t_node *it = _head->next;
				while (++count < this->size() - 1)
				{
					if (comp(it->data , it->next->data) == false)
					{
						updateHead(it, it->next);
						swap_node(it, it->next);
						it = _head->next;
						count = -1;
					}
					else
						it = it->next;
				}
			}
		}
		
		void insert(pointer_node currentList, pointer_node toInsert)
		{
			pointer_node prevCurrent = currentList->prev;
			prevCurrent->next = toInsert;
			currentList->prev = toInsert;
			toInsert->prev = prevCurrent;
			toInsert->next = currentList;
		}
		
		void	detachNode(pointer_node listX, pointer_node a)
		{
			pointer_node prev_a = a->prev;
			pointer_node next_a = a->next;
			prev_a->next = next_a;
			next_a->prev = prev_a;
			if (a->next == listX)
				listX->prev = prev_a;
		}

		void splice (iterator position, list& x)
		{
			iterator it;
			pointer_node headX = x.end().operator->();
			pointer_node toDetach = NULL;
			pointer_node where_to_insert = NULL;
			while (x._size)
			{
				it = x.begin();
				toDetach =  it.operator->();
				where_to_insert = position.operator->();
				detachNode(headX, toDetach);
				x._size--;
				insert(where_to_insert, toDetach);
				_size++;
			}
		}

		void splice(iterator position, list& x, iterator i)
		{
			pointer_node headX = x.end().operator->();
			pointer_node  toDetach =  i.operator->();
			pointer_node where_to_insert = position.operator->();
			detachNode(headX, toDetach);
			x._size--;
			insert(where_to_insert, toDetach);
			_size++;
		}

		void splice(iterator position, list& x, iterator first, iterator last)
		{
			while (first != last)
			{
				splice(position, x, first++);
			}
		}
		void reverse()
		{
			pointer_node next_current;
			pointer_node prev_current;
			pointer_node current = _head;
			for (size_type i = 0; i <= _size; i++)
			{
				next_current = current->next;
				prev_current = current->prev;
				current->next = prev_current;
				current->prev = next_current;
				current = current->prev;
			}
			
		}

	};
}


#endif
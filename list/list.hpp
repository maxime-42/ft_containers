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
	    typedef t_node *  pointer_node;

    
    public:
		void	init_head()
		{
			_head = _alloc_node.allocate(1);
			_myAlloc.construct(&_head->data, T());
			_head->next = _head;
			_head->prev = _head;
		}


/************************************************************************  const_iterator ************************************************************************/

class  const_iterator 
		{
		public:

			/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
			const_iterator():m_ptr(0){}
			const_iterator(pointer_node ptr) : m_ptr(ptr) {}

			const_iterator(const_iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}

			~const_iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			// value_type *operator*() const { return (&m_ptr->data); }
			value_type		&operator*()const {return m_ptr->data;}

			pointer_node operator->() { return (m_ptr); }

 			const_iterator        &operator++() { m_ptr = m_ptr->next; return *this; }; // ++a
        	const_iterator        operator++(int) { const_iterator it = *this; ++(*this); return it; }; // a++
			
			/*****************Can be decremented*************************/        
			const_iterator        &operator--() { m_ptr = m_ptr->prev; return *this; }; // --a
        	const_iterator        operator--(int) { const_iterator it = *this; --(*this); return it; }; // a--

			/***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!=(const   const_iterator& a, const   const_iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   const_iterator& a, const   const_iterator& b) { return a.m_ptr == b.m_ptr; };

		private:
			pointer_node m_ptr;
		};
		const_iterator cbegin() const {return   const_iterator(_head->next); }
		const_iterator cend()   const { return  const_iterator(_head); }


/************************************************************************  iterator ************************************************************************/
		class  iterator 
		{
		public:
			iterator():m_ptr(0){}
			iterator(pointer_node ptr) : m_ptr(ptr) {}

			iterator(iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}

			~iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			// value_type *operator*() const { return (&m_ptr->data); }
			value_type		&operator*()const {return m_ptr->data;}

			pointer_node operator->() { return (m_ptr); }

 			iterator        &operator++() { m_ptr = m_ptr->next; return *this; }; // ++a
        	iterator        operator++(int) { iterator it = *this; ++(*this); return it; }; // a++
			
			// /*****************Can be decremented*************************/        
			iterator        &operator--() { m_ptr = m_ptr->prev; return *this; }; // --a
        	iterator        operator--(int) { iterator it = *this; --(*this); return it; }; // a--

			// /***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!=(const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };

		private:
			pointer_node m_ptr;
		};
		iterator begin() {return   iterator(_head->next); }
		iterator end()   { return  iterator(_head); }



/************************************************************************  reverse_iterator ************************************************************************/

		class  reverse_iterator
		{
		public:
			reverse_iterator():m_ptr(0){}
			reverse_iterator(pointer_node ptr) : m_ptr(ptr) {}

			reverse_iterator(reverse_iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}

			~reverse_iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			// value_type *operator*() const { return (&m_ptr->data); }
			value_type		&operator*()const {return m_ptr->data;}

			pointer_node operator->() { return (m_ptr); }

 			reverse_iterator        &operator++() { m_ptr = m_ptr->prev; return *this; }; // ++a
        	reverse_iterator        operator++(int) { reverse_iterator it = *this; ++(*this); return it; }; // a++
			
			// /*****************Can be decremented*************************/  
			reverse_iterator        &operator--() { m_ptr = m_ptr->next; return *this; }; // --a
			reverse_iterator        operator--(int) { reverse_iterator it = *this; --(*this); return it; }; // a--

			// /***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!=(const   reverse_iterator& a, const   reverse_iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   reverse_iterator& a, const   reverse_iterator& b) { return a.m_ptr == b.m_ptr; };

		private:
			pointer_node m_ptr;
		};
		reverse_iterator  rbegin() {return   reverse_iterator(_head->prev); }
		reverse_iterator rend()   { return  reverse_iterator(_head); }


/************************************************************************  const_reverse_iterator ************************************************************************/

		class  const_reverse_iterator 
		{
			public:

				/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
				const_reverse_iterator():m_ptr(0){}
				const_reverse_iterator(pointer_node ptr) : m_ptr(ptr) {}

				const_reverse_iterator(const_reverse_iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}

				~const_reverse_iterator(){}

				/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
				// value_type *operator*() const { return (&m_ptr->data); }
				value_type		&operator*()const {return m_ptr->data;}

				pointer_node operator->() { return (m_ptr); }

				const_reverse_iterator        &operator++() { m_ptr = m_ptr->prev; return *this; }; // ++a
				const_reverse_iterator        operator++(int) { const_reverse_iterator it = *this; ++(*this); return it; }; // a++

				/*****************Can be decremented*************************/        
				const_reverse_iterator        &operator--() { m_ptr = m_ptr->prev; return *this; }; // --a
				const_reverse_iterator        operator--(int) { const_reverse_iterator it = *this; --(*this); return it; }; // a--

				/***************** compared for equivalence using the equality/inequality operators***********/
				friend bool operator!=(const   const_reverse_iterator& a, const   const_reverse_iterator& b) { return a.m_ptr != b.m_ptr; };
				friend bool operator== (const   const_reverse_iterator& a, const   const_reverse_iterator& b) { return a.m_ptr == b.m_ptr; };

			private:
				pointer_node m_ptr;
		};
		const_reverse_iterator rbegin() const { return   const_reverse_iterator(_head->prev); }
		const_reverse_iterator rend()   const { return  const_reverse_iterator(_head); }


		list (const allocator_type& alloc = allocator_type()):_head(0), _size(0)	
		{
			init_head();
			 (void)alloc;
		}

		list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):_head(0), _size(0)	
		{
			(void)alloc;
			init_head();
			while (n > 0)
			{
				this->push_back(val);
				n--;
			}
		}
		
		template <class InputIterator>
		list(typename std::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()):_head(0), _size(0)
		{
			(void)alloc;
			init_head();
    		while (first != last)
    		{
        		push_back(*first);
        		first++;
    		}
		}
	/*
	** this function delete one node and update the header of circuar list if it is need
	*/
		void delete_one_Node(t_node *toDel)
		{
			t_node *prev = toDel->prev;
			t_node *next = toDel->next;

			prev->next = next;
			next->prev = prev;
			toDel->next = 0;
			toDel->prev = 0;
			if (_head->prev == toDel)// condition to allow to update the _header 
				_head->prev = prev;
			_alloc_node.deallocate(toDel, 1);
			_alloc_node.destroy(toDel);
		}
		


		~list()
		{
			// for (size_t i = 0; i < _size; i++)
			// {
			// 	this->delete_one_Node(_head->next);
			// }
			clear();
			_alloc_node.deallocate(_head, 1);
			_alloc_node.destroy(_head);
			_head = 0;
			_size = 0;
		}

		void clear()
		{
			for (size_t i = 0; i < _size; i++)
			{
				this->delete_one_Node(_head->next);
			}
			_size = 0;
		}

		list (const list & x):_head(0), _size(0)
		{
			// _head = 0;
			// _size = 0;
			*this = x;
		}

		list & operator=(const list& x)
		{
			if (this != &x)
			{
				std::cout << "********* quel by, operator= *********" << std::endl;
				clear();
				_head = _alloc_node.allocate(1);
				_myAlloc.construct(&_head->data, T());
				_head->next = _head;
				_head->prev = _head;
				// init_head();
				for (const_iterator it = x.cbegin() ; it != x.cend() ; it++)
				{
					push_back(*it);
				}
			}
			return (*this);
		}







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
		
		void	detachNode(pointer_node head, pointer_node a)
		{
			pointer_node prev_a = a->prev;
			pointer_node next_a = a->next;
			prev_a->next = next_a;
			next_a->prev = prev_a;
			if (a->next == head)
				head->prev = prev_a;
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
		

		/*
		*Transfers elements from x (l2) into l1.
		exemple:
			l1 = 1-3-4
			l2 = 0-6-7
			this function going to transfer 0 at the first position in l1 : 
			l1 = 0-1-3-4
			l2 = 6-7
		*/
		void	transfers_elements(iterator l1, iterator l2, list & x)
		{
				pointer_node headX = x.end().operator->();
				detachNode(headX, l2.operator->());
				insert(l1.operator->(), l2.operator->());
				_size++;
				x._size--;
		}

		void merge (list& x)
		{
			iterator l1 = begin();
			iterator l2 = x.begin();
			while (l2 != x.end())
			{
				if (*l2 < *l1 || l1 == end())
				{
					transfers_elements(l1, l2++, x);
				}
				else if (*l2 > *l1)
					l1++;
			}
		}

		template <class Compare>
		void merge(list& x, Compare comp)
		{
			iterator l1 = begin();
			iterator l2 = x.begin();
			while (l2 != x.end())
			{
				if (comp(*l1, *l2) == false || l1 == end())
				{
					transfers_elements(l1, l2++, x);
				}
				else if (*l2 > *l1)
					l1++;
			}
		}
		
		void remove (const value_type& val)
		{
			pointer_node node;
			for (iterator it = begin(); it != end(); it++)
			{
				if (*it == val)
				{
					node = it.operator->();
					delete_one_Node(node);
					_size--;
					return ;
				}
			}
		}

		template <class Predicate>
		void remove_if (Predicate pred)
		{
			pointer_node node;
			for (iterator it = begin(); it != end(); it++)
			{
				if (pred(*it) == true)
				{
					node = it.operator->();
					it--;
					delete_one_Node(node);
					_size--;
				}
			}
		}

		void unique()
		{
			pointer_node next;
			pointer_node it  = _head->next;
			while (it != _head->prev)
			{
				next = it->next;
				if (it->data == next->data)
				{
					delete_one_Node(next);
					_size--;
				}
				else
					it = it->next;			
			}
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			bool state;
			pointer_node next;
			pointer_node it  = _head->next;
			while (it != _head->prev)
			{
				next = it->next;
				state = binary_pred(it->data, next->data);
				if (state == true)
				{
					delete_one_Node(next);
					_size--;
				}
				else
					it = it->next;			
			}
		}

		iterator erase (iterator position)
		{
			pointer_node node = position.operator->();
			position++;
			delete_one_Node(node);
			_size--;
			return (position);
		}

		iterator erase (iterator first, iterator last)
		{
			pointer_node node;
			while (first != last)
			{
				node = first.operator->();
				first++;
				delete_one_Node(node);
				_size--;

			}
			return (first);
		}

		void assign (size_type n, const value_type& val)
		{
			for (; _size != 0; _size--)
			{
				delete_one_Node(_head->next);
			}
			for (; n ; n--)
			{
				push_back(val);
			}
		}

		template <class InputIterator>
		void assign(typename std::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			for (; _size != 0; _size--)
			{
				delete_one_Node(_head->next);
			}
			for (; first != last; first++)
			{
				push_back(*first);
			}
		}

		bool empty() const
		{
			return (_size == 0);
		}

		void pop_front()
		{
			delete_one_Node(_head->next);
			_size--;
		}
	
		void pop_back()
		{
			delete_one_Node(_head->prev);
			_size--;
		}

      	reference back()
		{
			return(_head->prev->data);
		}
		const_reference back() const
		{
			return(_head->prev->data);
		}

      reference front()
	  {
		return(_head->next->data);
	  }
		
		iterator insert(iterator position, const value_type& val)
		{
			pointer_node where_add = position.operator->();
			pointer_node toAdd = _alloc_node.allocate(1);
			_myAlloc.construct(&toAdd->data, val);
			insert(where_add,toAdd);
			return (--toAdd);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			while (n)
			{
				insert(position, val);
				n--;
			}
		}

		template <class InputIterator>
		void insert(iterator position, typename std::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				first++;
			}
		}

		void resize (size_type n, value_type val = value_type())
		{
			while (n > _size)
			{
				push_back(val);
			}
			while(n < _size)
			{
				pop_back();
			}
		}
		size_type max_size() const{return _alloc_node.max_size();}
	};
}
#endif
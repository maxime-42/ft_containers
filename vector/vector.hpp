#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <memory>
#include <iostream>
#include <limits>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
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
		typedef std::forward_iterator_tag	iterator_category;
		

	protected:
		Alloc _myAlloc;
		size_type _capacity;
		size_type _dataCounter;
		T *_data;
	public:
		vector(void):_capacity(0),  _dataCounter(0), _data(0){}

		vector(size_type size, T elem):_capacity(size), _dataCounter(size)
		{
			_data = _myAlloc.allocate(_capacity);
			for (size_type i = 0; i < _dataCounter; i++)
			{
				_data[i] = elem;
			}
		}
		~vector()
		{
			this->clear();
		}
		pointer	getData()const {return (_data);}
/************************************************************************  iterator ************************************************************************/
		class  iterator 
		{
		public:
		/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
			iterator(){}
			iterator(pointer ptr) : m_ptr(ptr) {}
			iterator(iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}
			~iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			reference operator*() const { return *m_ptr; }
			pointer operator->() { return m_ptr; }

			/*********************mutable iterators********************/
			iterator operator=(const   iterator& a){m_ptr = a.m_ptr; return (*this);}

			/*********************incrementation******************/
			/* Prefix increment	*/
			iterator&	operator++() { m_ptr++; return (*this);	}
			/* Postfix increment*/
			iterator	operator++(int) { ++(*this); return (*this); }
			iterator	operator+(const difference_type& movement)	{m_ptr+= movement; return (*this);	}

			/*****************Can be decremented*************************/
			iterator &	operator--(){--m_ptr;return (*this);}
			iterator &	operator--(int){--m_ptr; return (*this);}
			iterator	operator-(const int& movement){pointer oldPtr = this->m_ptr; this->m_ptr+=movement; this->m_ptr = oldPtr;return *this;}

			/***************assignment operations += and -= ************ */
		    iterator &  operator+=(const difference_type& movement){this->m_ptr += movement;return (*this);}
			iterator &  operator-=(const difference_type& movement){this->m_ptr -= movement;return (*this);}

			/***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!= (const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };
			
			/*****************Can be compared with inequality relational operators (<, >, <= and >=).*********/
			friend bool operator<(const   iterator& a, const   iterator& b) { return (a.m_ptr < b.m_ptr); };
			friend bool operator>(const   iterator& a, const   iterator& b) { return (a.m_ptr > b.m_ptr); };
 			friend bool operator<=(const  iterator& a, const   iterator& b) { return (a.m_ptr <= b.m_ptr); };
			friend bool operator>=(const  iterator& a, const   iterator& b) { return (a.m_ptr >= b.m_ptr); };

		private:
			pointer m_ptr;
		};
		iterator begin() {return   iterator(&_data[0]); }
		iterator end()   { return  iterator(&_data[_dataCounter]); }


/************************************************************************  const_iterator ************************************************************************/
		class  const_iterator 
		{
		public:
		/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
			const_iterator(){}
			const_iterator(pointer ptr) : m_ptr(ptr) {}
			const_iterator(const_iterator const &toCopy)	{m_ptr = toCopy.m_ptr;}
			~const_iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			reference operator*() const { return *m_ptr; }
			pointer operator->() const { return m_ptr; }

			/*********************mutable const_iterators********************/
			const_iterator operator=(const   const_iterator& a){m_ptr = a.m_ptr; return (*this);}

			/*********************incrementation******************/
			/* Prefix increment	*/
			const_iterator&	operator++() const { m_ptr++; return (*this);	}
			/* Postfix increment*/
			const_iterator	operator++(int) const { ++(*this); return (*this); }
			const_iterator	operator+(const difference_type& movement)	const {m_ptr+= movement; return (*this);	}

			/*****************Can be decremented*************************/
			const_iterator &	operator--() const {--m_ptr;return (*this);}
			const_iterator &	operator--(int) const {--m_ptr; return (*this);}
			const_iterator	operator-(const int& movement) const {pointer oldPtr = this->m_ptr; this->m_ptr+=movement; this->m_ptr = oldPtr;return *this;}

			/***************assignment operations += and -= ************ */
		    const_iterator &  operator+=(const difference_type& movement) const {this->m_ptr += movement;return (*this);}
			const_iterator &  operator-=(const difference_type& movement) const {this->m_ptr -= movement;return (*this);}

			/***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!= (const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };
			
			/*****************Can be compared with inequality relational operators (<, >, <= and >=).*********/
			friend bool operator<(const   const_iterator & a, const   const_iterator& b) { return (a.m_ptr < b.m_ptr); };
			friend bool operator>(const   const_iterator & a, const   const_iterator& b) { return (a.m_ptr > b.m_ptr); };
 			friend bool operator<=(const   const_iterator & a, const   const_iterator& b) { return (a.m_ptr <= b.m_ptr); };
			friend bool operator>=(const   const_iterator & a, const   const_iterator& b) { return (a.m_ptr >= b.m_ptr); };
		private:
			pointer const m_ptr;
		};
		const_iterator cbegin() const {return   const_iterator(&_data[0]); }
		const_iterator cend()   const { return  const_iterator(&_data[_dataCounter]); }


/************************************************************************  reverse Iterator ************************************************************************/
		class  rev_iterator 
		{
		public:
		/***************Is default-constructible, copy-constructible, copy-assignable and destructible	******************/
			rev_iterator(){}
			rev_iterator(pointer ptr) : m_ptr(ptr) {}
			rev_iterator(rev_iterator const & toCopy)	{m_ptr = toCopy.m_ptr;}
			~rev_iterator(){}

			/*********************Can be dereferenced as an rvalue (if in a dereferenceable state)***********************************/
			reference operator*() const { return *m_ptr; }
			pointer operator->() { return m_ptr; }

			/*********************mutable rev_iterators********************/
			rev_iterator operator=(const   rev_iterator& a){m_ptr = a.m_ptr; return (*this);}

			/*********************incrementation******************/
			/* Prefix increment	*/
			rev_iterator&	operator++() { m_ptr--; return (*this);	}
			/* Postfix increment*/
			rev_iterator	operator++(int) { --(*this); return (*this); }
			rev_iterator	operator+(const difference_type& movement)	{m_ptr-= movement; return (*this);	}

			/*****************Can be decremented*************************/
			rev_iterator &	operator--(){++m_ptr;return (*this);}
			rev_iterator &	operator--(int){++m_ptr; return (*this);}
			rev_iterator	operator-(const int& movement){pointer oldPtr = this->m_ptr; this->m_ptr+=movement; this->m_ptr = oldPtr;return *this;}

			/***************assignment operations += and -= ************ */
		    rev_iterator &  operator+=(const difference_type& movement){this->m_ptr -= movement;return (*this);}
			rev_iterator &  operator-=(const difference_type& movement){this->m_ptr += movement;return (*this);}

			/***************** compared for equivalence using the equality/inequality operators***********/
			friend bool operator!= (const   rev_iterator& a, const   rev_iterator& b) { return a.m_ptr != b.m_ptr; };
			friend bool operator== (const   rev_iterator& a, const   rev_iterator& b) { return a.m_ptr == b.m_ptr; };
			
			/*****************Can be compared with inequality relational operators (<, >, <= and >=).*********/
			friend bool operator<(const   rev_iterator& a, const   rev_iterator& b) { return (a.m_ptr < b.m_ptr); };
			friend bool operator>(const   rev_iterator& a, const   rev_iterator& b) { return (a.m_ptr > b.m_ptr); };
 			friend bool operator<=(const   rev_iterator& a, const   rev_iterator& b) { return (a.m_ptr <= b.m_ptr); };
			friend bool operator>=(const   rev_iterator& a, const   rev_iterator& b) { return (a.m_ptr >= b.m_ptr); };

		private:
			pointer m_ptr;
		};

		rev_iterator rend() 	{return   rev_iterator(&_data[0]); }
		rev_iterator rbegin()	{ return  rev_iterator(&_data[_dataCounter]); }

/************************************************************************ utile ************************************************************************/

		void	sizeCompute(void)
		{
			if (_capacity == 0)
				_capacity++;
			else
				this->_capacity = _dataCounter * 2;
		}

		pointer	tubTab(size_type size)
		{
			pointer newTab = _myAlloc.allocate(size);
			for (size_type i = 0; i < _dataCounter; i++)
			{
				_myAlloc.construct(newTab + i, _data[i]);
			}
			return (newTab);
		}

/************************************************************************ Capacity ************************************************************************/

		size_type size() const {return (_dataCounter);}

		size_type capacity() const {return (_capacity);}

		size_type max_size() const {return (_myAlloc.max_size());}

		void resize (size_type n, value_type val = value_type())
		{
			if (n > _dataCounter)
			{
				this->_capacity *= 2 ;
				pointer newTab = this->tubTab(_capacity);
				this->clear();
				while (_dataCounter < n)
				{
					_myAlloc.construct(newTab + _dataCounter, val);
					_dataCounter++;
				}
				_data = newTab;
			}
		}

		bool empty() const{return (_capacity == 0);}

		void reserve (size_type n)
		{
			if (n > _capacity)
			{
				_capacity = n;
				pointer newTab = this->tubTab(n * 2);
				this->clear();
				_data = newTab;
			}
		}

/************************************************************************ Modifier ************************************************************************/
		void push_back(T elem)
		{
			if (_dataCounter < _capacity)
			{
				_data[_dataCounter++] = elem;
			}
			else
			{
				sizeCompute();
				pointer newTab = tubTab(this->_capacity);
				_myAlloc.construct(newTab + _dataCounter, elem);
				_dataCounter++;
				this->clear();
				_data = newTab;
			}
		}

		void pop_back()
		{
			if (this->empty())
			{
				_dataCounter -= 1;
			}
		}

		void clear()
		{
			for (size_type i = 0; i < _capacity; i++)
			{
				_myAlloc.destroy(_data + i);
			}
			_myAlloc.deallocate(_data, _capacity);
			_data = 0;
		}


		iterator erase(iterator &pos)
		{
			_dataCounter = 0;
			_capacity -= 1;
			iterator ret;
			pointer newData = _myAlloc.allocate(_capacity);
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (it != pos)
				{
					_myAlloc.construct(newData + _dataCounter, *it);
					_dataCounter++;
				}
				else if (it == pos)
					ret = newData + _dataCounter;

			}
			this->clear();
			_data = newData;
			return (ret);
		}

		iterator erase(iterator &start, iterator &end)
		{
			iterator ret;
			_dataCounter = 0;
			_capacity = _capacity - (end - start);
			pointer newData = _myAlloc.allocate(_capacity);
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (it != start)
				{
					_myAlloc.construct(newData + _dataCounter, *it);
					_dataCounter++;
				}
				else if (it == start)
				{
					while (it != end)
						it++;
					ret = newData + _dataCounter;
					it++;
				}
			}
			return (ret);
		}

	
/************************************************************************ OPERATOR ************************************************************************/
		T & operator[](size_type index)
		{
			if (index >= this->_dataCounter || index < 0)
				throw vector::OutOfLimit();
			return (this->_data[index]);
		}

		vector & operator=(vector const & toCopy)
		{
			if (this != &toCopy)
			{
				if (this->_data != NULL)
					this->clear();
				this->_data = new T [toCopy.size()];
				this->_size = toCopy.size();
				this->_dataCounter = toCopy._dataCounter;
				this->_data = tubTab(toCopy.size());
			}
			return (*this);
		}
		
/**************************************Element access****************************************************/

			reference front() {return(_data[0]);}
			const_reference front() const {return(_data[0]);}

			reference	at(n) 
			{
				if (n > _dataCounter)
					throw vector::OutOfLimit();
				return (_data[n]);
			}

			const_reference	at(n) const
			{
				if (n > _dataCounter)
					throw vector::OutOfLimit();
				return (_data[n]);
			}

		reference back(){return (_data[_dataCounter]);}
		const_reference back()const {return (_data[_dataCounter]);}


/************************************************************************ EXCEPTION ************************************************************************/

		struct OutOfLimit : std::exception 
		{
			const char* what() const throw()
			{
				return ("This element is out of the limits");
			}
		};
	};
}



#endif // DEBUG
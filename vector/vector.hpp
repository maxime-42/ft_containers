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
		typedef Alloc const &				const_reference;
    	typedef T* 							pointer;
		typedef T* const 					const_pointer;
    	typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;
		typedef std::forward_iterator_tag	iterator_category;
		

	protected:
		Alloc _myAlloc;
		size_type _capacity;
		size_type _countTab;
		T *_tab;
	public:
		vector(void):_capacity(0),  _countTab(0), _tab(0){}

		vector(size_type size, T elem):_capacity(size), _countTab(size)
		{
			_tab = _myAlloc.allocate(_capacity);
			for (size_type i = 0; i < _countTab; i++)
			{
				_tab[i] = elem;
			}
		}
		~vector()
		{
			this->clear();
		}
/************************************************************************  iterator ************************************************************************/
		class  iterator 
		{
		public:
			iterator(){}
			iterator(pointer ptr) : m_ptr(ptr) {}
			reference operator*() const { return *m_ptr; }
			pointer operator->() { return m_ptr; }
			// Prefix increment
			iterator& operator++() { m_ptr++; std::cout << "QUEL BY 1" << std::endl; return *this; }  
			// Postfix increment
			iterator	operator++(int) {iterator tmp = *this; ++(*this); std::cout << "QUEL BY 2 " << std::endl; return tmp;  }

			iterator	operator+(const difference_type& movement)
			{
				std::cout << "salut" << std::endl;
				// pointer oldPtr = m_ptr ;
				m_ptr+= movement;
				// iterator temp = (*this);
				// m_ptr = oldPtr;
				return (*this);
			}
			friend bool operator== (const   iterator& a, const   iterator& b) { return a.m_ptr == b.m_ptr; };
			friend bool operator!= (const   iterator& a, const   iterator& b) { return a.m_ptr != b.m_ptr; };     
		private:
			pointer m_ptr;
		};
   	  	iterator begin() {return   iterator(&_tab[0]); }
   	  	iterator end()   { return  iterator(&_tab[_countTab]); }
/************************************************************************ utile ************************************************************************/

		void clear()
		{
			for (size_type i = 0; i < _capacity; i++)
			{
				_myAlloc.destroy(_tab + i);
			}
			_myAlloc.deallocate(_tab, _capacity);
			_tab = 0;
		}

		void	sizeCompute(void)
		{
			if (_capacity == 0)
				_capacity++;
			else
				this->_capacity = _countTab * 2;
		}

		pointer	tubTab(size_type size)
		{
			pointer newTab = _myAlloc.allocate(size);
			for (size_type i = 0; i < _countTab; i++)
			{
				_myAlloc.construct(newTab + i, _tab[i]);
			}
			return (newTab);
		}
/************************************************************************ Capacity ************************************************************************/

		size_type size() const {return (_countTab);}

		size_type capacity() const {return (_capacity);}

		size_type max_size() const {return (_myAlloc.max_size());}

		void resize (size_type n, value_type val = value_type())
		{
			if (n > _countTab)
			{
				this->_capacity *= 2 ;
				pointer newTab = this->tubTab(_capacity);
				this->clear();
				while (_countTab < n)
				{
					_myAlloc.construct(newTab + _countTab, val);
					_countTab++;
				}
				_tab = newTab;
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
				_tab = newTab;
			}
		}

/************************************************************************ Modifier ************************************************************************/
		void push_back(T elem)
		{
			if (_countTab < _capacity)
			{
				_tab[_countTab++] = elem;
			}
			else
			{
				sizeCompute();
				pointer newTab = tubTab(this->_capacity);
				_myAlloc.construct(newTab + _countTab, elem);
				_countTab++;
				this->clear();
				_tab = newTab;
			}
		}

	void pop_back()
	{
		if (this->empty())
		{
			_countTab -= 1;
		}
	}

/************************************************************************ OPERATOR ************************************************************************/
		T & operator[](size_type index)
		{
			if (index >= this->_countTab || index < 0)
				throw vector::OutOfLimit();
			return (this->_tab[index]);
		}

		vector & operator=(vector const & toCopy)
		{
			if (this != &toCopy)
			{
				if (this->_tab != NULL)
					this->clear();
				this->_tab = new T [toCopy.size()];
				this->_size = toCopy.size();
				this->_countTab = toCopy._countTab;
				this->_tab = tubTab(toCopy.size());
			}
			return (*this);
		}

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
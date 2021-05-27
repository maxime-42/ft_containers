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
    	typedef T				value_type;
   		typedef T& 				reference;            
		typedef Alloc const &	const_reference;
    	typedef T* 				pointer;
		typedef T* const 		const_pointer;
    	typedef std::ptrdiff_t	difference_type;
		typedef size_t			size_type;		

	private:
		Alloc _myAlloc;
		size_type _sizeTab;
		size_type _countTab;
		T *_tab;
	public:
		vector(void):_sizeTab(0),  _countTab(0), _tab(0){}

		vector(size_type size, T elem):_sizeTab(size), _countTab(size)
		{
			_tab = _myAlloc.allocate(_sizeTab);
			for (size_type i = 0; i < _countTab; i++)
			{
				_tab[i] = elem;
			}
		}
		~vector()
		{
			this->clear();
		}
/************************************************************************ Capacity ************************************************************************/

		size_type size() const {return (_countTab);}

		size_type capacity() const {return (_sizeTab);}

		size_type max_size() const {return (_myAlloc.max_size());}

		void resize (size_type n, value_type val = value_type())
		{
			(void)vald;
			if (n < _countTab || n > _countTab)
			{
				pointer newTab = this->tubTab(_countTab);
				this->clear();
				_countTab = n;
				_sizeTab = n;
				_tab = newTab;
				for (size_t i = _countTab ; i < n; i++)
				{
					_tab[i] = val;
				}
			}
		}

	bool empty() const{return (_sizeTab == 0);}

/************************************************************************ utile ************************************************************************/

		void clear()
		{
			for (size_type i = 0; i < _sizeTab; i++)
			{
				_myAlloc.destroy(_tab + i);
			}
			_myAlloc.deallocate(_tab, _sizeTab);
			_tab = 0;
		}

		size_type	sizeCompute(void)
		{
			if (!_sizeTab)
			{
				return (1);
			}
			return (_sizeTab * 2);
		}

		pointer	tubTab(size_type size)
		{
			pointer newTab = _myAlloc.allocate(size);
			for (size_type i = 0; i < _countTab; i++)
			{
				newTab[i] = _tab[i];
			}
			return (newTab);
		}

/************************************************************************ Push BACK ************************************************************************/
		void push_back(T elem)
		{
			if (_countTab < _sizeTab)
				_tab[_countTab++] = elem;
			else
			{
				size_type newSize = this->sizeCompute();
				pointer newTab = tubTab(newSize);
				this->clear();
				_tab = newTab;
				_tab[_countTab++] = elem;
				_sizeTab = newSize;
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
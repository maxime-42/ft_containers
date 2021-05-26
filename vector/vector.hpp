#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <memory>
#include <iostream>
#include <limits>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > // generic template
	class vector
	{
	private:
		size_t _sizeTab;
		T *_tab;
		Alloc _myAlloc;
	public:
		vector(/* args */):_sizeTab(0), _tab(0)
		{
			std::cout << "Hellow" << std::endl;
		}
		vector(size_t size, T elem):_sizeTab(size)
		{
			_tab = myAlloc.allocate(_sizeTab);
			for (size_t i = 0; i < _sizeTab; i++)
			{
				_tab[i] = elem;
			}
		}
		~vector()
		{
			// for (size_t i = 0; i < _sizeTab; i++)
			// {
			// 	Alloc.destroy(tab[i]);
			// }
			// Alloc.deallocate(tab, _sizeTab);
		}
		// push_back(T elem)
		// {
		// 	for (size_t i = 0; i < _size; i++)
		// 	{
		// 		_tab[i] = elem;
		// 	}
		// }
	};
}



#endif // DEBUG
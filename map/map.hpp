#ifndef MAP
#define MAP
#include <iostream>

namespace ft
{
	template <typename T1, typename T2> 
	class pair
	{
		public:
		// ******** Data ********
			T1	first;
			T2	second;
		// ******** Member function ********
			pair() : first(T1()), second(T2()) { };
			template<class U, class V>
			pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) { };
			pair (const T1& a, const T2& b) : first(a), second(b) { };
			pair (T1& a, T2& b) : first(a), second(b) { };

			~pair() {};
			pair& operator=(const pair & pr)
			{
				if (this != &pr)
				{
					first = pr.first;
					second = pr.second;
				}
				return (*this);
			}
	};

	template <	class Key,                                        // map::key_type
			class T,                                             // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >   // map::allocator_type
			>

	class map
	{
		public:
			typedef pair<const Key, T>					value_type;
			typedef T& 									reference;
			typedef Compare								key_compare;
			typedef Alloc								allocator_type;
			typedef const T&							const_reference;
			typedef value_type*							pointer;
			typedef T* const 							const_pointer;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;
			typedef std::forward_iterator_tag			iterator_category;

			typedef struct								s_node
			{
				value_type								data;
				struct s_node							*left;
				struct s_node							*right;
			}											t_node;
		protected:
			t_node										*_root;
			size_type									_size;
			std::allocator<struct s_node>				_alloc_node;
			Alloc										_myAlloc;
		public:
		///////////////////////iterator/////////////////////////////////
 			class iterator
			{
				private:
					t_node								_ptr; 
				public:
					typedef t_node						*pointeur;
					// typedef ptrdiff_t					difference_type;

					iterator(pointeur ptr = 0): _ptr(ptr){}
					// iterator(iterator const &cp){_ptr = cp.get_ptr();}
					// iterator operator=(MapIterator const &cp)
					// {
						// if (this != &cp)
							// this->_ptr = cp.get_ptr();
						// return *this;
					// }
					~iterator(){}
					value_type		&operator*()const {return _ptr->data;}
					value_type		*operator->()const {return &(_ptr->data);}
					// MapIterator	&operator++(){_ptr = _ptr->getnext(); return *this;}
					// MapIterator	operator++(int){iterator it = *this; _ptr = _ptr->getnext(); return it;}
					// MapIterator	&operator--(){ _ptr = _ptr->getprev(); return *this;}
					// MapIterator	operator--(int){iterator it = *this; _ptr = _ptr->getprev(); return it;}
					// pointeur        get_ptr()const{return _ptr;}

					// bool			operator==(const iterator &it){ return _ptr == it.get_ptr();}
					// bool			operator!=(const iterator &it){ return _ptr != it.get_ptr();}

			};
			t_node *get_begin(t_node *node)
			{
				if (_node)
				{
					get_begin(node->left);
					return (node);
				}
				return (0);
			}

			t_node *get_next_node(t_node *node)
			{
				if (node)
				{
					get_next_node(node->left);
					return (node);
				}
				return (0);
			}

			iterator begin()
			{
				return (get_begin(_root));
			}

			map():_root(0), _size(0)
			{
				std::cout << "hellow world\n" << std::endl;
			}

			~map()
			{
				print_tree(_root);
				std::cout << "destructeur" << std::endl;
			}

 			void my_insert (const value_type & val, t_node **node, key_compare cmp)
			{
				if (!*node)
				{
					_size++;
					*node = _alloc_node.allocate(1);
					_myAlloc.construct(&(*node)->data, val);
				}
				else if (cmp((*node)->data.first, val.first))
				{
					my_insert(val, &(*node)->right, cmp);
				}
				else if (cmp((*node)->data.first, val.first) == false)
				{
					if (cmp(val.first, (*node)->data.first) == false)
						return ;
					my_insert(val, &(*node)->left, cmp);
				}
			}

			void insert (const value_type & val)
			{
				(void)val;
				my_insert (val, &_root, key_compare());
			}

			void	print_tree(t_node *node)
			{
				if (node)
				{
					print_tree(node->left);
					std::cout << "first = " << node->data.first << " second = " << node->data.second << "\n" ;
					print_tree(node->right);
				}
			}

	};
}

#endif

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
				bool	is_leaf(struct s_node *node)
				{
					if (node->left == NULL && node->right == NULL )
						return (true);
					return (false);
				}
				
				struct s_node *get_next_node(struct s_node *node)
				{
					if (is_leaf(node))
					{
						// std::cout << " parent " ;
						// if (node->data.first > node->parent->data.first)
						// 	get_next_node(node->parent);
							node = node->parent;
					}
					else 
						node = node->right;
					return (node);
				}

				value_type								data;
				struct s_node							*parent;
				struct s_node							*left;
				struct s_node							*right;
			}											t_node;
		protected:
			t_node										*_root;
			t_node										*_end;
			size_type									_size;
			std::allocator<struct s_node>				_alloc_node;
			Alloc										_myAlloc;
		public:
		///////////////////////iterator/////////////////////////////////

 			class iterator
			{
				private:
					t_node								*_ptr; 
				public:
					typedef t_node						*pointeur;
					// typedef ptrdiff_t					difference_type;


					iterator(t_node *ptr = 0): _ptr(ptr){}
					// iterator(iterator const &cp){_ptr = cp.get_ptr(	);}
					iterator operator=(iterator const &cp)
					{
						if (this != &cp)
							this->_ptr = cp.get_ptr();
						return *this;
					}

					~iterator(){}
					value_type							&operator*()const {return _ptr->data;}
					value_type							*operator->()const {return &(_ptr->data);}
					iterator							&operator++(){_ptr = _ptr->get_next_node(_ptr); return *this;}//++a
					iterator							operator++(int)	{iterator it = *this; _ptr = _ptr->get_next_node(_ptr); return (it);}//a++
					// MapIterator	&operator--(){ _ptr = _ptr->getprev(); return *this;}
					// MapIterator	operator--(int){iterator it = *this; _ptr = _ptr->getprev(); return it;}
					pointeur        get_ptr()const{return _ptr;}

					// bool			operator==(const iterator &it){ return _ptr == it.get_ptr();}
					// bool			operator!=(const iterator &it){ return _ptr != it.get_ptr();}
					friend bool operator!=(const   iterator& a, const   iterator& b) { return a._ptr != b._ptr; };

			};

			t_node *get_begin(t_node *node)
			{
				t_node *node_begin = 0;
				if (node)
				{
					node_begin = get_begin(node->left);
					if (!node_begin)
						return (node);
				}
				return (node_begin);
			}


			iterator begin()
			{
				return (get_begin(_root));
			}

			iterator end()
			{
				return (_end);
			}

			map():_root(0), _end(0), _size(0)
			{
				std::cout << "hellow world\n" << std::endl;
			}

			~map()
			{
				print_tree(_root);
				std::cout << "\n" << std::endl;
				std::cout << "first = " << _root->data.first << " second = " <<  _root->data.second << "\n" ;
				_root = _root->right;
				std::cout << "first = " << _root->data.first << " second = " <<  _root->data.second << "\n" ;
				_root = _root->right;
				std::cout << "first = " << _root->data.first << " second = " <<  _root->data.second << "\n" ;
				_root = _root->right;
				std::cout << "first = " << _root->data.first << " second = " <<  _root->data.second << "\n" ;
				_root = _root->right;
				std::cout << "first = " << _root->data.first << " second = " <<  _root->data.second << "\n" ;
				_root = _root->left;
				std::cout << "first = " << _root->data.first << " second = " <<  _root->data.second << "\n" ;


				// std::cout << "destructeur" << std::endl;
			}

			void	updte_end(t_node *new_node)
			{
				if (!_end)
				{
					_end = _alloc_node.allocate(1);
 					_myAlloc.construct(&_end->data, value_type());
					new_node->right = _end;
					_end->parent = new_node;
				}
				else if (new_node->parent->right == new_node && new_node->parent == _end->parent)
				{
					new_node->right = _end;
					_end->parent = new_node;
				}
			}

 			void my_insert (const value_type & val, t_node **node, t_node *parent, key_compare cmp)
			{
				if (!*node || *node == _end)
				{
					_size++;
					*node = _alloc_node.allocate(1);
 					_myAlloc.construct(&(*node)->data, val);
					(*node)->parent = parent;
					(*node)->left = 0;
					(*node)->right = 0;
					// updte_end(*node);
				}
				else if (cmp((*node)->data.first, val.first))
				{
					my_insert(val, &(*node)->right, *node, cmp);
				}
				else if (cmp((*node)->data.first, val.first) == false)
				{
					if (cmp(val.first, (*node)->data.first) == false)
						return ;
					my_insert(val, &(*node)->left, *node, cmp);
				}
			}

			void insert (const value_type & val)
			{
				(void)val;
				my_insert (val, &_root, _root, key_compare());
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

			// void	clear_tree(t_node *node)
			// {
				// clear_tree(node->left);
				// _myAlloc.destroy(_data + i);
// 
				// clear_tree(node->right);
// 
// 
			// }
	};
}

/*
	is left child ,backtrack to find the greater than current node
	other is right child , backtrack to the greater than current node then try to go on the left
*/

#endif

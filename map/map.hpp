#ifndef MAP
#define MAP
#define TYPE_LEAF 1

#include <iostream>
#include <stdlib.h>

namespace ft
{
	template <typename T1, typename T2> 
	class pair
	{
		public:
		// ******** Data ********
			T1	  first;
			T2	 second;
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
					std::cout << " dans operator=" << std::endl;
					// T1 *ptr = const_cast <T1 *> (&pr.first); 
					this->first = pr.first;
					// *ptr = pr.first;
					this->second = pr.second;
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
			typedef Key									key_type;
			typedef T									mapped_type;
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
				int										type_node;
				value_type								data;
				struct s_node							*parent;
				struct s_node							*left;
				struct s_node							*right;
				bool	is_leaf(struct s_node *node)
				{
					if (node->left == NULL && node->right == NULL )
						return (true);
					return (false);
				}
				/*
				to increment there are mains two cases:
				** one -> leaf or node don't have child on the right
						 do to : backtrack to find greater parent
				** interior node
						do to : one step on the right then forward on the left
				*/
				struct s_node *get_next_node()
				{
					key_compare cmp;
					t_node	*node = this;
					if (is_leaf(node) || !node->right)
					{
						while (cmp(this->data.first, node->data.first) == false)
						{
							node = node->parent;
						}
					}
					else
					{
						node = node->right;
						while (node->left)
						{
							node = node->left;
						}
					}
					return (node);
				}

				struct s_node *get_prev_node()
				{
					key_compare cmp;
					t_node	*node = this;
					if (is_leaf(node) || !node->left)
					{
						node = node->parent;
						while (cmp(this->data.first, node->data.first) == true)
						{
							node = node->parent;
						}
					}
					else
					{
						node = node->left;
						while (node->right)
						{
							node = node->right;
						}
					}
					return (node);
				}
			}											t_node;
		protected:
			t_node										*_root;
			t_node										*_end;
			t_node										*_begin;
			size_type									_size;
			t_node 										*_parent_root;

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
					iterator(iterator const &cp){_ptr = cp.get_ptr(	);}
					iterator operator=(iterator const &cp)
					{
						if (this != &cp)
							this->_ptr = cp.get_ptr();
						return *this;
					}

					~iterator(){}
					value_type							&operator*()const {return _ptr->data;}
					value_type							*operator->()const {return &(_ptr->data);}
					iterator							&operator++(){_ptr = _ptr->get_next_node(); return *this;}//++a
					iterator							operator++(int)	{iterator it = *this; _ptr = _ptr->get_next_node(); return (it);}//a++
					iterator							&operator--(){ _ptr = _ptr->get_prev_node(_ptr); return (*this);}//--a
					iterator							operator--(int){iterator it = *this; _ptr = _ptr->get_prev_node(); return it;} //a--
					pointeur        					get_ptr()const{return _ptr;}
					bool								operator==(const iterator &it){ return _ptr == it.get_ptr();}
					bool								operator!=(const iterator &it){ return _ptr != it.get_ptr();}
					friend bool 						operator!=(const iterator& a, const   iterator& b) { return a._ptr != b._ptr; };
			};

			iterator begin()
			{
				return (_begin->parent);
			}

			iterator end()
			{
				return (_end);
			}
			void	init_node(t_node **node, t_node *parent ,const value_type & val)
			{
				*node = _alloc_node.allocate(1);
 				_myAlloc.construct(&(*node)->data, val);
				(*node)->parent = parent;
				(*node)->left = 0;
				(*node)->right = 0;
				(*node)->type_node = 0;

			}

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(0), _end(0), _begin(0), _size(0), _parent_root(0)
			{
				(void)comp;
				(void)alloc;
				if (_root == NULL)
				{
					init_node(&_root, _root, value_type());
				}
			}




			~map()
			{
				// print_tree(_root);
				// t_node *node = _root;
				// std::cout << "first = " << node->data.first << " second = " <<  node->data.second << "\n" ;
				// node = _root->left;
				// std::cout << "destructor : first = " << _root->right->parent->data.first << " second = " << _root->right->parent->data.second << "\n" ;

				my_clear_tree(_root);

			}

			size_type size() const {return (_size);}
			


			void	updte_end(t_node *new_node)
			{
				if (!_end)
				{
					init_node(&_end, new_node, value_type());
					new_node->right = _end;
					_end->parent = new_node;
				}
				else if (new_node->parent->right == new_node && new_node->parent == _end->parent)
				{
					new_node->right = _end;
					_end->parent = new_node;
				}
			}

			void	updte_begin(t_node *new_node)
			{
				if (!_begin)
				{
					init_node(&_begin, new_node, value_type());
					new_node->left = _begin;
					_begin->parent = new_node;
				}
				else if (new_node->parent->left == new_node && new_node->parent == _begin->parent)
				{
					new_node->left = _begin;
					_begin->parent = new_node;
				}
			}

			void my_insert (const value_type & val, t_node **node, t_node *parent, key_compare cmp)
			{
				if (!*node || *node == _end || *node == _begin)
				{
					_size++;
					init_node(node, parent, val);
					updte_end(*node);
					updte_begin(*node);
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
		template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(0), _end(0), _begin(0), _size(0)
			{
				while (first != last)
				{
					t_node *node = first.get_ptr();
					value_type val = node->data;
					my_insert (val, &_root, _root, comp);
					(void)alloc;
					first++;
				}
			}

			void insert (const value_type & val)
			{
				(void)val;
				my_insert (val, &_root, _root, key_compare());
				// if (_parent_root->right == 0)
				// 	_parent_root->right = _root;
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

	

			void	my_clear_tree(t_node *node)
			{
				(void)node;

				if (node)
				{
					my_clear_tree(node->left);
					my_clear_tree(node->right);
					_alloc_node.destroy(node);
					_alloc_node.deallocate(node, 1);
				}
				_size = 0;
				_end = 0;
				_begin = 0;
			}

	
			void delete_node(t_node *node)
			{
				_size--;
				_alloc_node.destroy(node);
				_alloc_node.deallocate(node, 1);
			}

			/* If one of the children is empty*/
			t_node *delete_children_is_empty(t_node *to_delete)
			{
				t_node* temp = NULL;
				if (to_delete->left == NULL)
				{
					temp = to_delete->right;
				}
				else if (to_delete->right == NULL) 
				{
					std::cout << "im in the right null\n";
					temp = to_delete->left;
					if (temp == _begin)
						_begin->parent = to_delete->parent;
				}	
				delete_node(to_delete);
				return (temp);
			}

			t_node *deleted_has_two_children(t_node *to_delete)
			{
				if (to_delete->parent->right == to_delete)
				{
					to_delete->parent->right = to_delete->left;
				}
				else if (to_delete->parent->left == to_delete)
					to_delete->parent->left = to_delete->left;
				to_delete->left->parent = to_delete->parent;
				t_node *tmp = to_delete->left;
				t_node *ret = tmp;
				while (tmp->right && tmp->right != _end && tmp->right != _begin)
				{
					tmp = tmp->right;
				}
				tmp->right = to_delete->right;
				to_delete->right->parent = tmp;
				delete_node(to_delete);
				return (ret);
			}

			t_node	*delete_one_node_by_key(t_node *root, Key toFind)
			{
				key_compare cmp;
				if (!root || root == _end || root == _begin)
					return (root);
				if (cmp(root->data.first, toFind))
				{
					root->right = delete_one_node_by_key(root->right, toFind);
				}
				else if (!cmp(root->data.first, toFind) && cmp(toFind, root->data.first) )
				{
					root->left = delete_one_node_by_key(root->left, toFind);
				}
				else
				{
					if (root->right == NULL || root->left == NULL)/* If one of the children is empty*/
						root = delete_children_is_empty(root);
					else
					{
						root = deleted_has_two_children(root);
					}
				}
				return (root);
			}

			void erase (iterator position)
			{
				std::cout << "to delete : " << position->first << " => " << position->second << '\n';

				(void)delete_one_node_by_key(_root, position->first);
	
				(void)position;
			}

			size_type erase (const key_type & k)
			{
				(void)delete_one_node_by_key(_root, k);
				return (1);
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					(void)delete_one_node_by_key(_root, first->first);
					first++;					
				}
			}

			t_node	*find_key(t_node *node, const key_type& toFind)
			{
				key_compare cmp;
				if ( node == _end)
					return (0);
				if (node && node != _begin)
				{
					if (cmp(node->data.first, toFind) == false && cmp(toFind, node->data.first) == false)
					{
						return (node);
					}
					node = find_key(node->right, toFind);
				}
				return (node);
			}

			// t_node	*find_key( const key_type& toFind)
			// {
			// 	for (iterator it = begin(); it != end(); it++)
			// 	{
			// 		if (cmp(node->data.first, toFind) == false && cmp(toFind, node->data.first) == false)

			// 	}
				
			// }
			mapped_type& operator[] (const key_type& k)
			{
				t_node *node = find_key(_root->right, k);
				if (node == NULL)
				{
					value_type val(k, mapped_type());
					my_insert (val, &_root, _root, key_compare());
					node = find_key(_root->right, k);
					// std::cout << "insert key == " << node->data.first << std::endl;

				}
				else
				{
					// std::cout << "not null key == " << k << std::endl;

					// std::cout << "not null key == " << node->data.first << std::endl;

				}
				// std::cout << "first =  " << _root->right->data.first << " second = " << _root->right->data.second << std::endl;
				// std::cout << "first =  " << node->data.first << " second = " << node->data.second << std::endl;
				return (node->data.second);
				// return (_root->right->data.second);
			}

	};
}
#endif

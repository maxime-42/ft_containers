#ifndef MAP
#define MAP
#define TYPE_LEAF 1
#include <iostream>
#include <stdlib.h>

namespace ft{
    template <bool B, class T = void>
    struct Enable_if
    {
    };

    template <class T>
    struct Enable_if<true, T>
    {
        typedef T type;
    };

	template<typename T>
    void ft_swap(T &arg1, T &arg2)
    {
        T temp = arg1;
        arg1 = arg2;
        arg2 = temp;
    }

}

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
					this->first = pr.first;
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
				value_type								*data;
				struct s_node							*parent;
				struct s_node							*left;
				struct s_node							*right;
				bool	is_leaf(struct s_node *node)
				{
					if (node && node->left == NULL && node->right == NULL)
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
						while (cmp(this->data->first, node->data->first) == false)
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
						while (cmp(this->data->first, node->data->first) == true)
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
			key_compare									_comp;
			std::allocator<struct s_node>				_alloc_node;
			allocator_type								_alloc_pair;

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
					value_type							&operator*()const {return (*_ptr->data);}
					value_type							*operator->()const {return &(*_ptr->data);}
					iterator							&operator++(){_ptr = _ptr->get_next_node(); return *this;}//++a
					iterator							operator++(int)	{iterator it = *this; _ptr = _ptr->get_next_node(); return (it);}//a++
					iterator							&operator--(){ _ptr = _ptr->get_prev_node(_ptr); return (*this);}//--a
					iterator							operator--(int){iterator it = *this; _ptr = _ptr->get_prev_node(); return it;} //a--
					pointeur        					get_ptr()const{return _ptr;}
					bool								operator==(const iterator &it){ return _ptr == it.get_ptr();}
					bool								operator!=(const iterator &it){ return _ptr != it.get_ptr();}
					friend bool 						operator!=(const iterator& a, const   iterator& b) { return a._ptr != b._ptr; };
			};

			iterator begin(){return (_begin->parent);}

			iterator end()	{return (_end);	}

			void	init_node(t_node **node, t_node *parent ,const value_type & val)
			{
				*node = _alloc_node.allocate(1);
				(*node)->data = _alloc_pair.allocate(1);
 				_alloc_pair.construct((*node)->data, val);
				(*node)->parent = parent;
				(*node)->left = 0;
				(*node)->right = 0;
				(*node)->type_node = 0;

			}

			size_type size() const {return (_size);}


///////////////////////constructor////////////////////////////////


			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(0), _end(0), _begin(0), _size(0), _comp(comp), _alloc_pair(alloc)
			{
				(void)comp;
				(void)alloc;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(0), _end(0), _begin(0), _size(0),  _comp(comp),  _alloc_pair(alloc)
			{
				while (first != last)
				{
					my_insert (*first, &_root, _root);
					(void)alloc;
					first++;
				}
			}
			// map (const map& x):_root(x._root), _end(x._end), _begin(x._begin), _size(x._size), _comp(x._comp), _alloc_pair(x._alloc_pair)
			// {
			// 	insert(x.begin(), x.end());
			// }

			~map()
			{
				// ft_swap(_root->data, _root->right->data);
				// print_tree(_root);

				// t_node *node = _root;
				// std::cout << "first = " << node->data->first << " second = " <<  node->data->second << "\n" ;
				// node = _root->left;
				// std::cout << "first = " << node->data->first << " second = " <<  node->data->second << "\n" ;

				// node = node->left;
				// std::cout << "first = " << node->data->first << " second = " <<  node->data->second << "\n" ;
				// if (node->right == NULL)
				// {
				// 	std::cout << "right is  nulll" << std::endl;
				// }
				// node = _root->right;
				// std::cout << "first = " << node->data->first << " second = " <<  node->data->second << "\n" ;
				// node = node->right;
				// std::cout << "first = " << node->data->first << " second = " <<  node->data->second << "\n" ;

				// std::cout << "size = " << _size << std::endl;
				// std::cout << "destructor : first = " << _root->right->parent->data.first << " second = " << _root->right->parent->data.second << "\n" ;

				my_clear_tree(_root);

			}


//////////////////////////Modifiers////////////////////////////

			void	print_tree(t_node *node)
			{
				if (node)
				{
					print_tree(node->left);
					std::cout << "first = " << node->data->first << " second = " << node->data->second << "\n" ;
					print_tree(node->right);
				}
			}

			void	my_clear_tree(t_node *node)
			{
				if (node)
				{
					my_clear_tree(node->left);
					my_clear_tree(node->right);
					_alloc_pair.destroy(node->data);
					_alloc_pair.deallocate(node->data, 1);
					_alloc_node.destroy(node);
					_alloc_node.deallocate(node, 1);
				}
				_root = 0;
				_size = 0;
				_end = 0;
				_begin = 0;
			}


/////////////////////////////Element access////////////////////////////

			t_node	*find_key(t_node *node, const key_type& toFind)
			{
				t_node *ret = 0;
				if (node && node != _begin && node != _end)
				{
					if (node && _comp(node->data->first, toFind) == false && _comp(toFind, node->data->first) == false)
						return (node);
					else
					{
						ret = find_key(node->left, toFind);
						if (!ret)
							ret = find_key(node->right, toFind);
					}
				}
				return (ret);
			}

			mapped_type& operator[] (const key_type& k)
			{
				t_node *node = find_key(_root, k);
				if (node == NULL)
				{
					value_type val(k, mapped_type());
					my_insert (val, &_root, _root);
					node = find_key(_root, k);
				}
				return (node->data->second);
			}

			iterator find (const key_type& k)
			{
				t_node *node = find_key(_root, k);
				if (node)
				{
					// std::cout << "trouveeer" << std::endl;
					return (iterator(node));
				}
				// std::cout << "pas trouveeer" << std::endl;
				return (iterator(_end));
			}

// ///////////////////////////modify//////////////////////////////////////
			void delete_node(t_node *node)
			{
				_size--;
				_alloc_node.destroy(node);
				_alloc_pair.destroy(node->data);
				_alloc_pair.deallocate(node->data, 1);
				_alloc_node.deallocate(node, 1);
			}

			t_node *has_only_one_child(t_node *to_delete)
			{
				t_node* temp = NULL;
				if (to_delete->left == NULL)
				{
					temp = to_delete->right;
				}
				else if (to_delete->right == NULL)
				{
					temp = to_delete->left;
				}
				if (temp)
					temp->parent = to_delete->parent;
				delete_node(to_delete);
				return (temp);
			}

			void	has_two_children(t_node *root)
			{
				t_node *succesor = root->get_next_node();
				if (succesor->parent != root)
				{
					succesor->parent->left = succesor->right;
					if (succesor->right)
						succesor->right->parent = succesor->parent;
				}
				else
				{
					succesor->parent->right = succesor->right;
					if (succesor->right)
						succesor->right->parent = succesor->parent;
				}
				ft_swap(succesor->data, root->data);
				delete_node(succesor);
			}

			t_node	*delete_one_node_by_key(t_node *root, Key toFind)
			{
				if (!root )
					return (root);
				// if (_size == 1)
				// {
				// 	my_clear_tree(_root);
				// 	return (0);
				// }
				if (_comp(root->data->first, toFind))
				{
					root->right = delete_one_node_by_key(root->right, toFind);
				}
				else if (!_comp(root->data->first, toFind) && _comp(toFind, root->data->first) )
				{
					root->left = delete_one_node_by_key(root->left, toFind);
				}
				else
				{
					if (root->right == NULL || root->left == NULL )/* If one of the children is empty*/
						root = has_only_one_child(root);
					else
					{
						has_two_children(root);
					}
				}
				return (root);
			}

			

			void erase (iterator position)
			{
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
				int i = 0;
				// last--;
				t_node *node = last.get_ptr();
				mapped_type toFind = node->data->first;
				while (first->first != toFind)
				{
					// toFind = *first;
					// find_key(_root, current->data->first);
					std::cout << "i = " << i << " first->first = " << first->first << " first->second = " << first->second  << std::endl;
				
					if (delete_one_node_by_key(_root, first->first) == NULL)
						return ;
					if (_size == 0)
						return ;
					i++;
				}
			}

			void	update_node_end(t_node *new_node)
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

			void	update_node_begin(t_node *new_node)
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


			void my_insert (const value_type & val, t_node **node, t_node *parent)
			{
				if (!*node || *node == _end || *node == _begin)
				{
					_size++;
					init_node(node, parent, val);
					update_node_end(*node);
					update_node_begin(*node);
				}
				else if (_comp((*node)->data->first, val.first))
				{
					my_insert(val, &(*node)->right, *node);
				}
				else if (_comp((*node)->data->first, val.first) == false)
				{
					if (_comp(val.first, (*node)->data->first) == false)
						return ;
					my_insert(val, &(*node)->left, *node);
				}
			}

// 			pair<iterator,bool> insert (const value_type& val)
// 			{
// 				ft::pair<iterator,bool> ret;
// 				ret.second = (find_key(_root->right, val.first) == NULL);
// 				if (ret.second == true)
// 				{
// 					my_insert (val, &_root->right, _root);
// 				}
// 				ret.first = iterator(find_key(_root->right, val.first));
// 				return (ret);
// 			}

// 			template <class InputIterator>
// 			void insert (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
// 			{
// 				while (first != last)
// 				{
// 					value_type val = *first;
// 					// std::cout << "first = " << val.first << " second "  << val.second << std::endl;
// 					my_insert(*first, &_root->right, _root);
// 					first++;
// 				}

// 			}

			// iterator insert (iterator position, const value_type& val)
			// {
			// 	t_node *node = find_key(_root->right, val.first);
			// 	if (!node)
			// 	{
			// 		my_insert(val, &_root->right, _root);
			// 		node = find_key(_root->right, val.first);
			// 	}

			// 	(void)position;
			// 	(void)val;
			// 	return iterator(node);
			// }




	};
}

#endif

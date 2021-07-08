#ifndef MAP
#define MAP

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

		pair() : first(), second() { };
		template<class U, class V>
		pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) { };
		pair (const T1& a, const T2& b) : first(a), second(b) { };
		~pair() { };
		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

	template <	class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
		>

	class map
	{
/************************************************************************ Typedef ************************************************************************/
	public:
		typedef T				value_type;
		typedef pair<const key_type,mapped_type>value_type;
		typedef T& 				reference;            
		typedef Alloc				allocator_type;
		typedef const T&			const_reference;
		typedef T* 				pointer;
		typedef T* const 			const_pointer;
		typedef std::ptrdiff_t			difference_type;
		typedef size_t				size_type;
		typedef std::forward_iterator_tag	iterator_category;
		
		struct					s_struct
		{
			pair				data;
			struct s_struct			*left;
			struct s_struct			*right;
		}					t_struct;

	}
}

#endif

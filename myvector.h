__pragma(once)
#include <iostream>
template<typename T>
struct myallocator
{
	// 内存开辟
	T* allocate(size_t size)
	{
		return (T*)malloc(size * sizeof(T));
	}

	// 内存释放
	void deallocate(T *ptr)
	{
		free(ptr);
	}

	// 对象构造 1.new 2.new const 3.定位new
	void construct(T *ptr, const T &obj)
	{
		new (ptr) T(obj); // 定位new
	}

	// 对象析构
	void destroy(T *ptr)
	{
		ptr->~T();
	}
};

template<typename T = int, typename _Alloc = myallocator<T>>
class Vector
{
public:
	Vector();
	~Vector();
	Vector(const Vector<T> &vec);
	Vector(Vector<T> &&vec);
	void operator=(const Vector<T> &vec);
	void operator=(Vector<T> &&vec);

	void reserve(int size); // 预留函数

	void push_back(const T &val); // 末尾添加元素
	void pop_back(); // 末尾删除元素
	bool empty()const; // 判空
	bool full()const; // 判满

	void show()const; // 打印vector容器的所有元素
private:
	T *mpvec;
	int mcur;
	int msize;
	_Alloc malloctor; // 定义空间配置器对象 

	void resize(); // vector容器底层默认2倍扩容
};

template<typename T, typename _Alloc>
inline Vector<T, _Alloc>::Vector() :mpvec(nullptr),mcur(0),msize(0)
{
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline Vector<T, _Alloc>::~Vector()
{
	for (int i = 0; i < mcur; ++i)
	{
		// 析构容器中有效的对象
		malloctor.destroy(mpvec + i);
	}
	// 把容器内存释放掉
	malloctor.deallocate(mpvec);
	mpvec = nullptr;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline Vector<T, _Alloc>::Vector(const Vector<T>& vec) :mcur(vec.mcur), msize(vec.msize)
{
	mpvec = malloctor.allocate(msize);
	for (int i = 0; i < vec.mcur; i++)
	{
		malloctor.construct(mpvec + i, vec.mpvec[i]);
	}
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline Vector<T, _Alloc>::Vector(Vector<T>&& vec) :mcur(vec.mcur), msize(vec.msize)
{
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::operator=(const Vector<T>& vec)
{
	if (this == &vec) return;
	ptem = malloctor.allocate(msize);
	for (int i = 0; i < vec.mcur; i++)
	{
		malloctor.construct(ptem + i, vec.mpvec[i]);
	}
	for (int i = 0; i < mcur; ++i)
	{
		malloctor.destroy(mpvec + i);
	}
	malloctor.deallocate(mpvec);
	mpvec = ptem;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::operator=(Vector<T>&& vec)
{
	for (int i = 0; i < mcur; ++i)
	{
		malloctor.destroy(mpvec + i);
	}
	malloctor.deallocate(mpvec);
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
	mcur = vec.mcur;
	msize = vec.msize;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::reserve(int size)
{
	if (size < mcur) return;
	T* ptem = malloctor.allocate(size);
	for (int i = 0; i < mcur; ++i)
	{
		malloctor.construct(ptem + i, mpvec[i]);
	}
	for (int i = 0; i < mcur; ++i)
	{
		malloctor.destroy(mpvec + i);
	}
	malloctor.deallocate(mpvec);
	mpvec = ptem;
	msize = size;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::push_back(const T & val)
{
	if (full()) resize();
	malloctor.construct(mpvec + mcur++, val);
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::pop_back()
{
	if (empty()) return;
	malloctor.destroy(mpvec + --mcur);
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline bool Vector<T, _Alloc>::empty() const
{
	return 0 == mcur;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline bool Vector<T, _Alloc>::full() const
{
	return msize == mcur;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::show() const
{
	for (int i = 0; i < mcur; ++i)
	{
		std::cout << mpvec[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T = int, typename _Alloc = myallocator<T>>
inline void Vector<T, _Alloc>::resize()
{
	int size = 0;
	if (0 == mcur)
	{
		size = 1;
	}
	else
	{
		size = msize * 2;
	}
	reserve(size);
}

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <cassert>
#include <iterator>

template <typename T>
class MyArray
{
public:
	using size_type = size_t;

private:
	T* m_data{};
	size_type m_size{};

public:
	MyArray(const MyArray& src) // copy constructor
		: m_data{ new T[src.m_size] }, m_size{ src.m_size }
	{
		for (int k = 0; k < m_size; ++k)
			m_data[k] = src.m_data[k];
	}
	MyArray& operator=(const MyArray& src)
	{ // copy assignment
		if (this != &src)
		{
			delete[] m_data;
			m_size = src.m_size;
			m_data = new T[src.m_size];
		}
		return *this;
	}
	MyArray(MyArray&& src) : m_size{ src.m_size }, m_data{ src.m_data }
	{ // move constructor
		src.m_data = nullptr;
		src.m_size = 0;
	}
	explicit MyArray(size_type size) : m_size(size), m_data{ new T[size] } {} // normal constructor

	MyArray& operator=(MyArray&& src)
	{ // move assignment
		if (this != &src)
		{
			delete[] m_data;
			// move src's resources
			m_data = src.m_data;
			m_size = src.m_size;
			// reset src to a stable state
			src.m_data = nullptr;
			src.m_size = 0;
		}
		return *this; // return the invoking object (the left-hand operand)
	}
	~MyArray() { delete[] m_data; } // destructor

	size_type size() const { return m_size; }

	T& operator[](size_type index)
	{
		assert(index < m_size);
		return m_data[index];
	}

	const T& operator[](size_type index) const
	{
		assert(index < m_size);
		return m_data[index];
	}

	class iterator
	{
	public:
		using self_type = iterator;
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using iterator_category = std::forward_iterator_tag;
		using difference_type = int;

		iterator(pointer ptr) : m_ptr(ptr) {}
		self_type operator++()
		{
			m_ptr++;
			return *this;
		} // PREFIX
		self_type operator++(int)
		{
			self_type it = *this;
			m_ptr++;
			return it;
		} // POSTFIX

		reference operator*() { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		bool operator==(const self_type& rhs) { return m_ptr == rhs.m_ptr; }
		bool operator!=(const self_type& rhs) { return !(*this == rhs); }

	private:
		pointer m_ptr;
	};

	class const_iterator
	{
	public:
		using self_type = const_iterator;
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using iterator_category = std::forward_iterator_tag;
		using difference_type = int;

		const_iterator(pointer ptr) : m_ptr(ptr) {}
		self_type operator++()
		{
			self_type it = *this;
			m_ptr++;
			return it;
		}
		self_type operator++(int junk)
		{
			m_ptr++;
			return *this;
		}
		const reference operator*() { return *m_ptr; }
		const pointer operator->() { return m_ptr; }
		bool operator==(const self_type& rhs) { return m_ptr == rhs.m_ptr; }
		bool operator!=(const self_type& rhs) { return !(*this == rhs); }

	private:
		pointer m_ptr;
	};

	iterator begin() { return iterator(m_data); }

	iterator end() { return iterator(m_data + m_size); }

	const_iterator begin() const { return const_iterator(m_data); }

	const_iterator end() const { return const_iterator(m_data + m_size); }
};
#endif
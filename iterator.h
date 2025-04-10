#pragma once

#include <cstddef>

template <class T> class Vector;

template <class T>
class Iterator
{
public:
	using diff_type     = std::ptrdiff_t;
	using value_type    = T;
	using pointer       = const T*;
	using reference     = const T&;

private:
	pointer ptr_;

	friend class Vector<T>;

public:
	Iterator(pointer ptr) : ptr_(ptr) {}

	reference operator*() const 
	{
		return *ptr_;
	}

	reference operator->() const
	{
		return *ptr_;
	}

	Iterator& operator++() 
	{
		++ptr_;
		return *this;
	}

	Iterator& operator--()
	{
		--ptr_;
		return *this;
	}

	Iterator operator+(diff_type offset) const
	{
		return Iterator(ptr_ + offset);
	}

	Iterator operator+(const Iterator& other) const
	{
		return Iterator(ptr_ + (other.ptr_ - ptr_));
	}

	Iterator& operator+=(diff_type offset)
	{
		ptr_ += offset;
		return *this;
	}

	bool operator==(const Iterator& other) const
	{
		return ptr_ == other.ptr_;
	}

	bool operator<(const Iterator& other) const
	{
		return ptr_ < other.ptr_;
	}
};
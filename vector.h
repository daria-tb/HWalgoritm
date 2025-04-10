#pragma once

#include <stdexcept>
#include <utility>
#include <algorithm>

template <class T>
class Vector
{
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t new_capacity)
    {
        T* new_data = new T[new_capacity];

        if (data_ != nullptr)
        {
            try
            {
                std::copy(data_, data_ + size_, new_data);
            }
            catch (...)
            {
                delete[] new_data;
                throw;
            }
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    ~Vector()
    {
        delete[] data_;
    }

    size_t size() const
    {
        return size_;
    }

    size_t capacity() const
    {
        return capacity_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

    void reserve(size_t new_capacity)
    {
        if (new_capacity > capacity_)
        {
            reallocate(new_capacity);
        }
    }

    void push_back(const T& value)
    {
        if (size_ == capacity_)
        {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(new_capacity);
        }
        data_[size_] = value;
        size_++;
    }

    void push_back(T&& value)
    {
        if (size_ == capacity_)
        {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(new_capacity);
        }
        data_[size_] = std::move(value);
        size_++;
    }

    void pop_back()
    {
        if (size_ > 0)
        {
            size_--;
        }
    }

    void clear()
    {
        size_ = 0;
    }

    T& operator[](size_t index)
    {
        return data_[index];
    }

    const T& operator[](size_t index) const
    {
        return data_[index];
    }

    T& at(size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Vector::at() index out of range");
        }
        return data_[index];
    }

    const T& at(size_t index) const
    {
        if (index >= size_)
        {
            throw std::out_of_range("Vector::at() index out of range");
        }
        return data_[index];
    }

    Vector(const Vector& other) : data_(nullptr), size_(0), capacity_(0)
    {
        if (other.capacity_ > 0)
        {
            data_ = new T[other.capacity_];
            capacity_ = other.capacity_;
            size_ = other.size_;

            try
            {
                std::copy(other.data_, other.data_ + other.size_, data_);
            }
            catch (...)
            {
                delete[] data_;
                data_ = nullptr;
                size_ = 0;
                capacity_ = 0;
                throw;
            }
        }
    }

    Vector& operator=(Vector other)
    {
        swap(*this, other);
        return *this;
    }

    //rонструктор переміщення, переміщає дані з іншого вектора в поточний
    //без винятків (noexcept) і переназначення пам'яті вектора
    Vector(Vector&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    //оператор переміщення, замінює поточний вектор даними з іншого
    Vector& operator=(Vector&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    friend void swap(Vector& first, Vector& second)
    {
        using std::swap;
        swap(first.size_, second.size_);
        swap(first.capacity_, second.capacity_);
        swap(first.data_, second.data_);
    }

    //метод для зменшення виділеної пам'яті, щоб вона відповідала фактичному розміру
    void shrink_to_fit()
    {
        if (size_ < capacity_)
        {
            reallocate(size_);
        }
    }

    //доступ до першого елемента
    T& front()
    {
        if (size_ > 0)
            return data_[0];
        throw std::out_of_range("Vector is empty");
    }

    const T& front() const
    {
        if (size_ > 0)
            return data_[0];
        throw std::out_of_range("Vector is empty");
    }

    //доступ до останнього елемента
    T& back()
    {
        if (size_ > 0)
            return data_[size_ - 1];
        throw std::out_of_range("Vector is empty");
    }

    const T& back() const
    {
        if (size_ > 0)
            return data_[size_ - 1];
        throw std::out_of_range("Vector is empty");
    }

    //вставка елемента на вказану позицію
    void insert(size_t index, const T& value)
    {
        if (index > size_)
        {
            throw std::out_of_range("Insert index out of range");
        }

        if (size_ == capacity_)
        {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        // Переміщаємо елементи після індексу на одну позицію вправо
        for (size_t i = size_; i > index; --i)
        {
            data_[i] = std::move(data_[i - 1]);
        }
        data_[index] = value;
        size_++;
    }

    //видалення елемента за індексом
    void erase(size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Erase index out of range");
        }

        //переміщаємо елементи після індексу на одну позицію вліво
        for (size_t i = index; i < size_ - 1; ++i)
        {
            data_[i] = std::move(data_[i + 1]);
        }
        size_--;
    }
};

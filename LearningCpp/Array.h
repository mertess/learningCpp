#pragma once
#include "ICloneable.h"

template <typename T>
class Array : ICloneable
{
public:
    explicit Array(size_t size = 0, const T& value = T()) : size_(size), array_(new T[size_])
    {
        for (int i = 0; i < size; i++)
            this->array_[i] = value;
    }
    Array(const Array& array) : size_(array.size()), array_(new T[size_])
    {
        for (int i = 0; i < this->size_; i++)
            this->array_[i] = array[i];
    }
    ~Array()
    {
        delete[] this->array_;
    }
    Array& operator=(const Array& other)
    {
        if (this != &other) {
            this->size_ = other.size();
            delete[] this->array_;
            this->array_ = new T[this->size_];
            for (int i = 0; i < this->size_; i++)
                this->array_[i] = other[i];
        }
        return *this;
    }
    size_t size() const
    {
        return this->size_;
    }
    T& operator[](size_t index)
    {
        return this->array_[index];
    }
    const T& operator[](size_t index) const
    {
        return this->array_[index];
    }

    Array<T>* clone() const
    {
        return new Array<T>(this->size());
    }
private:
    size_t size_;
    T* array_;
};
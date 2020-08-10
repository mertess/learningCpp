#pragma once
#include <vector>
#include <list>
#include <iterator>

template<class T>
class VectorList
{
private:
    using VectT = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    using value_type = T;

    VectorList() = default;
    VectorList(VectorList const&) = default;
    VectorList(VectorList&&) = default;

    VectorList& operator=(VectorList&&) = default;
    VectorList& operator=(VectorList const&) = default;

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    //template<class It>
    //void append(It p, It q); // определена снаружи

    bool empty() const { return size() == 0; }

    size_t size() const
    {
        int size = 0;
        for (VectT vector in data_)
        {
            size += vector.size();
        }
        return size;
    }

    //const_iterator begin() const { return ; }
    //const_iterator end()   const { return ...; }

    //... const_reverse_iterator ...

    //const_reverse_iterator rbegin() const { return ...; }
    //const_reverse_iterator rend()   const { return ...; }

private:
    ListT data_;
};
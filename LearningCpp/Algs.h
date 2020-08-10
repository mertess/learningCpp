#pragma once
#include <algorithm>
#include <functional>
#include <vector>

template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n)
{
    auto func = [&n](typename FwdIt::value_type x)
    {
        static int count = 0;
        if (count == n)
            return true;
        count++;
        return false;
    };
    return std::remove(p, q, *std::find_if(p, q, func));
}

template<class FwdIt>
FwdIt remove_nthv2(FwdIt p, FwdIt q, size_t n)
{
    auto func = [&n](typename FwdIt::value_type x)
    {
        static int count = 0;
        if (count == n)
            return true;
        count++;
        return false;
    };
    auto iter = std::find_if(p, q, func);
    if (iter != q)
    {
        while(std::distance(iter, q) > 1)
        {
            typename FwdIt::value_type& n = *iter;
            iter++;
            std::swap(n, *iter);
        }
        return iter;
    }
    return q;
}

template<class FwdIt>
FwdIt remove_nthv3(FwdIt p, FwdIt q, size_t n)
{
    auto iter = p;
    int count = 0;
    while (std::distance(iter, q) > 0)
    {
        if (count != n)
        {
            iter++;
            count++;
        }
        else
            break;
    }
    while (std::distance(iter, q) > 1)
    {
        typename FwdIt::value_type& n = *iter;
        iter++;
        std::swap(n, *iter);
    }
    return iter;
}
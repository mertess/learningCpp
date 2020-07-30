#pragma once

template<class T, class G>
bool compare(T const& a, T const& b, G (T::*method)() const)
{
    return (a.*method)() < (b.*method)();
}
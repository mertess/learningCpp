#pragma once
#include<utility>
#include<tuple>

template<size_t I1, size_t I2, typename... TupleArgs>
auto to_pair(std::tuple<TupleArgs...>& tuple) -> decltype(std::make_pair(std::get<I1>(tuple), std::get<I2>(tuple)))
{
	return std::make_pair(std::get<I1>(tuple), std::get<I2>(tuple));
}
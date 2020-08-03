#pragma once
#include<type_traits>

template<typename T>
typename std::remove_reference<T>::type&& myMove(T&& value)
{
	typedef typename std::remove_reference<T>::type&& RetType;
	return static_cast<RetType>(value);
}

template<typename T>
T&& myForward(typename std::remove_reference<T>& value)
{
	return static_cast<T&&>(value);
}

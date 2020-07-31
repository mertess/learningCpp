#pragma once
#include <iostream>
#include <typeinfo>

inline void print_values(std::ostream& os) {}

template<typename T, typename... Args>
void print_values(std::ostream& os, T const& value, Args const&... args)
{
	os << typeid(value).name() << ": " << value << endl;
	print_values(os, args...);
}

class TestDefaultDelete
{
public:
	TestDefaultDelete() = default; //подключение конструктора по умолчанию
	TestDefaultDelete(int a){}
	~TestDefaultDelete() = delete; //отключение деструктора по умолчанию
	TestDefaultDelete& operator=(TestDefaultDelete const& other) = delete; //отключение оператора присваивания по умолчанию 
};
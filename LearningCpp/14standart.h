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

class Base
{
public:
	Base() = default;
	Base(int a, int b) {}
	virtual ~Base();
	virtual void func() {}
};

//final - аналог sealed в C#
class Child final : public Base
{
public:
	//подключаем конструкторы базового класса (имеется в виду, что нам достаточно таких конструкторов и мы не хотим создавать
	//"прокси" конструкторы, передающие параметры в базовые конструкторы
	using Base::Base;
	//появилось явное переопределение, позволяющее проверять, а действительно есть данный виртуальный метод с данной сигнатурой 
	//а так же аналог модификатора sealed в C#, запрещающий переопределение метода в производных классах
	void func() override final{}
};

//конструктор перемещения и оператор перемещения
class TransferExample
{
public: //&& - rvalue reference обычные конструкторы копирования и т.д. lvalue 
	TransferExample(TransferExample&& other){}
	TransferExample& operator=(TransferExample && other){}
};
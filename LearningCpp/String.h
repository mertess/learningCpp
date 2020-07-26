#pragma once
#include <iostream>

struct String
{
	String(const char* str = "");
	String(size_t n, char c);
	//copy при остутствии экземляра в который будет произведено копирование (например - передача параметра по значению)
	String(String const& other);
	//copy при присутствии экземпляра в который будет произведено копирование (String str = str2)
	String& operator=(String const& other);
	~String();
	void append(String& other);
	//ключ. слово const означает, что данный метод не может изменять значение полей объекта
	//из за const в методе вместо указателя на текущ экзем. класса стоит указатель на конст. экз. класса
	//через конст. экземпляр класса можно обращаться только к константным методам
	size_t Size() const;
	size_t& Size();
	String const& operator [](int i) const;
	char* get_str() const;
	const char* l_ptr = 0;
	int index_substr;
private:
	size_t size;
	char* str;
	void swap(String& str);
};
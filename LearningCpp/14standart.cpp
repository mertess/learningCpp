#include <string>
#include <typeinfo>

namespace Standart14
{

	std::string s("Hallo");

	auto sz = s.size(); //size_t
	auto c1 = s[0]; //char
	//decltype(s[0]) c2 = s[7]; //char&
	//decltype(s[0] + s[7]) c3 = s[1]; //int
	decltype(s) sa = s; //string 
	decltype((s)) sb = s; //string&
	//проблема auto заключается в том, что если тип возвращаемого значения из функции или тип переменной 
	//является & или const & то оно откинет это, и вернет просто тип (произойдет копирование)
	//SomeType .. SomeType const &
	//	auto s = someClass.get();

	//C++11
	template<class A, class B>
	auto get_sum(A a, B b) -> decltype(a + b)
	{
		return a + b;
	}
	//C++14
	template<class A, class B>
	auto get_sum(A a, B b)
	{
		return a + b;
	}
	//или через правила вывода типов decltype (без потери ссылки)
	template<class A, class B>
	decltype(auto) get_sum(A a, B b)
	{
		return a + b;
	}

	//шаблонная функция с переменным числом аргументов различных типов
	template<typename T, typename... Args>
	void read(T const& value, Args const&... args)
	{
		//some code 
		//первое значение из args "дергается" в переменную value (через вывод типов определяется её тип)
		//после - размер args само-собой уменьшается на 1
	}

	void test()
	{
		read(5, 7, 6.5);
	}
}
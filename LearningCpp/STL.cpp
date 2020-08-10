#include "STL.h"
#include <type_traits>
#include <typeinfo>

void main_method()
{
	std::list<int> list = { 5, 1 };
	std::cout << "max_increasing = " << max_increasing_len(list.begin(), list.end()) << std::endl;
	list.pop_front();
	std::cout << "list_size = " << list.size() << std::endl;

	std::list<int> l = { 1,2,3 };
	l.insert(l.begin(), 4);
	l.insert(l.end(), 5);

	auto it = l.begin();
	++it;
	++it;

	l.insert(it, 6);

	auto rit1 = l.rbegin();
	++rit1;
	++rit1;
	l.insert(rit1.base(), 7);

	auto rit2 = l.rbegin();
	++rit2;
	++rit2;
	l.insert(rit2.base(), 8);

	for (auto a : l)
		std::cout << "a = " << a << std::endl; 
}
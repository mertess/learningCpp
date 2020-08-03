// LearningCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "Point.h"
#include "Smthing.h"
#include <cstdlib>
#include "String.h"
#include "SharedPtr.h"
#include "Array.h"
#include "PartialSpecializationTemplates.h"
#include "MultiInheritance.h"
#include "MethodAndFieldsPtrs.h"
#include "14standart.h"
#include <memory> //unique_ptr
#include "cpp14tupletopair.h" //func to_pair
#include <tuple>
#include <functional> //std::function
#include "MyStdMoveAndForward.h"
using namespace std;
#define MAX(x, y, r){ int sx = x; int sy = y; if (sx > sy) r = sx; else r = sy }

int someMethod(int x, int y) { return x * y; }

template<typename TFunc, typename... TArgs>
auto apply(TFunc const& func, TArgs&&... args) -> decltype(func(std::forward<TArgs>(args)...))
{
    return func(std::forward<TArgs>(args)...);
}

int main()
{
   /* Array<int> arr(5);
    Array<int>* new_arr = arr.clone();
    for (int i = 0; i < 5; i++)
        cout << new_arr->operator[](i) << endl;*/
    //--------------------------------------------------------
    SomeClass<int> arr;
    method(arr, 5.1);
    //--------------------------------------------------------
    //cout << SameType<int, int>::value << endl; //true
    //cout << SameType<float, int>::value << endl; //false
    //cout << SameType<int, int&>::value << endl; //false
    //cout << SameType<int, const int>::value << endl; //false
    //--------------------------------------------------------
    int a = 27;
    int const b = 412;
    int* pa = &a;
    int const c = a;
    int d = b;
    int const* p1 = pa;
    int* const* p2 = &pa;
    int const** p3 = const_cast<int const**>(&pa);
    int const* const* p4 = &pa;
    double* double_arr = new double[10];
    char* ch_arr = reinterpret_cast<char*>(double_arr);
    //int a = reinterpret_cast<int&>(arr);
    //--------------------------------------------------------
    /*
     *Тип ComplexFunction, является указателем на функцию, которая принимает int и указатель
     *на функцию, принимающую double и возвращающую int, и возвращает указатель на функцию, которая принимает char const * и возвращает int *.
     */
    typedef int (*out)(char const*);
    typedef out (*ComplexFunction)(int, int* (*)(double));
    //Функция принимающая 2 параметра и возвращающая указатель на функцию принимающую 4 параметра и возвращающая указатель на void
    void* (*MyFunc(int, int))(int, int, int, int);
    //указатель на констанстный метод класса SharedStringPtr, который возвращает String* и ничего не принимает
    typedef String* (SharedStringPtr::* SharedStringMethod)() const; 
    //вызов ощуствляется через экземпляр класса SSPtr, например: (s->*method)(params)
    String s1(5, 'a');
    String s2(6, 'b');
    //cout << compare(s1, s2, &String::Size) << " compare" << endl;
    //--------------------------------------------------------
    cpp14::print_values(std::cout, 0, 3.5);
    //--------------------------------------------------------
    //test def base construct
    cpp14::Child* child = new cpp14::Child();
    //--------------------------------------------------------
    //явный вызов конструктора перемещения или оператора - std::move(some instance);
    //unique_ptr не имеет констукторов копирования и операторов копирования, оно горантирует, что будет единственный указатель
    unique_ptr<cpp14::Child> ptr(new cpp14::Child());
    unique_ptr<cpp14::Child> ptr2(std::move(ptr)); //указатель переходит к ptr2
    ptr = std::move(ptr2); //указатель переходит к ptr
    //--------------------------------------------------------
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const*> p = to_pair<1, 2>(t);
    cout << p.first << " first" << endl;
    cout << p.second << " second" << endl;
    // p содержит 3.5 и "Hello"
    //--------------------------------------------------------
    //std:;initializer_list
    cpp14::Array<int> arrInitConstr = { 1, 2, 3, 4 };
    //--------------------------------------------------------
    //тупо delegate, класс обертка над указателем на методы классов или указателем на функции
    std::function<int(int, int)> delegate_ = &someMethod;
    //лямбда
    auto square_fun = [](int& x) { x *= x; };
    std::function<void(int, int)> lambda_func = [](auto a, auto b) {};
    //--------------------------------------------------------
    myMove(new String("hi"));
    //--------------------------------------------------------
    auto fun = [](std::string a, std::string const& b) { return a += b; };
    std::string s("world!");
    // s передаётся по lvalue ссылке,
    // а временный объект по rvalue ссылке 
    s = apply(fun, std::string("Hello, "), s);
    cout << "s = " << s << endl;
    //--------------------------------------------------------
    SharedStringPtr pt;
    {
        String* hello = new String("Hello");
        pt.reset(hello);
        cout << pt.get_counter()->get_value() << endl;
        SharedStringPtr pt2 = pt;
        cout << pt.get_counter()->get_value() << endl;
        {
            SharedStringPtr pt3 = pt;
            cout << pt.get_counter()->get_value() << endl;
        }
        cout << pt.get_counter()->get_value() << endl;
    }
    cout << pt.get_counter()->get_value() << endl;
	return 0;
}
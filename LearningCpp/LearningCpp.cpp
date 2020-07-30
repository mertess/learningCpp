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
using namespace std;
#define MAX(x, y, r){ int sx = x; int sy = y; if (sx > sy) r = sx; else r = sy }

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
    cout << SameType<int, int>::value << endl; //true
    cout << SameType<float, int>::value << endl; //false
    cout << SameType<int, int&>::value << endl; //false
    cout << SameType<int, const int>::value << endl; //false
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
    cout << compare(s1, s2, &String::Size) << " compare" << endl;
    //--------------------------------------------------------
    SharedStringPtr pt;
    SharedStringPtr* ptr = new SharedStringPtr();
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
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
    int a = reinterpret_cast<int&>(arr);
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
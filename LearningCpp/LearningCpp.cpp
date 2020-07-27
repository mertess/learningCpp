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
using namespace std;
#define MAX(x, y, r){ int sx = x; int sy = y; if (sx > sy) r = sx; else r = sy }

int main()
{
    Array<int> arr(5);
    Array<int>* new_arr = arr.clone();
    for (int i = 0; i < 5; i++)
        cout << new_arr->operator[](i) << endl;
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
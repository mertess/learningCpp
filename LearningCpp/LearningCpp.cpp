// LearningCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "Point.h"
#include "Smthing.h"
#include <cstdlib>
using namespace std;
#define MAX(x, y, r) int sx = x; int sy = y; if (sx > sy) r = sx; else r = sy;


int main()
{
    Cls cl('a', 6, 7);
    get_c(cl);
    get_d(cl);
    get_i(cl);

    /*my_struct s(5, 6);
    getA(s);
    getB(s);*/

    /*int a[] = { 1, 2, 3, 4, 5 };
    rotate(a, 5, 2);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }*/

    /*const char text[] = "Hello world";
    const char pattern[] = "";
    cout << strLenght(text, pattern);*/

   /* int* m[3] = { new int[3] { 5, 7 ,8 }, new int[3] { 4, 2, 6 }, new int[3] { 9, 0, 1 } };
    swap_min(m, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }*/


	return 0;
}
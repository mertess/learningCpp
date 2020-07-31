#include <iostream>
#include "Smthing.h"
using namespace std;

int& getA(my_struct& st)
{
    /*
    *структура никак не записывается в объектный файл, она представляет собой способ управления последоавательностями байт
    *фактически структура my_struct представляет собой последовательность из 8 байт - 4 байта на int a, и 4 на int b
    *если разрядность системы 64 бит то 8 байт - машинное слово, то всего данные поля int a, b будут уже занимать 16 байт (выравнивание памяти!)
    */
    int* ptr = (int*)&st;
    cout << *ptr << endl;
    return *ptr;
}

static int func()
{
    return 0;
}

int& getB(my_struct& st)
{
    int* ptr = (int*)((char*)&st + 4);
    cout << *ptr << endl;
    return *ptr;
}

void get_c(Cls& cls) {

    cout << *((char*)&cls) << endl;
}

void get_d(Cls& cls) {
    cout << *((double*)((char*)&cls + 8)) << endl;
}


void get_i(Cls& cls) {
    cout << *((int*)((char*)&cls + 16)) << endl;
}

void swap_min(int* m[], unsigned rows, unsigned cols)
{
    int* min_row = 0;
    int min_value = m[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (m[i][j] < min_value)
            {
                min_value = m[i][j];
                min_row = m[i];
            }
        }
    }
    int* tmp = new int[cols];
    memcpy(tmp, m[0], sizeof(int) * cols);
    memcpy(m[0], min_row, sizeof(int) * cols);
    memcpy(min_row, tmp, sizeof(int) * cols);
}


int strLenght(const char* text, const char* pattern)
{
    if (*pattern == 0) return 0;
    int index = 0;
    while (*text != '\0')
    {
        const char* pattPointer = pattern;
        const char* sub_text = text;
        while (*sub_text == *pattPointer)
        {
            if (*sub_text == '\0')
                return index;
            pattPointer++;
            sub_text++;
            if (*pattPointer == '\0')
                return index;
        }
        index++;
        text++;
    }
    return -1;
}

unsigned gcd(unsigned a, unsigned b, unsigned x)
{
    if (a % x != 0 || b % x != 0)
    {
        gcd(a, b, --x);
    }
    else
        return x;
    return 0;
}

unsigned gcd(unsigned a, unsigned b)
{
    return gcd(a, b, a > b ? a : b);
}
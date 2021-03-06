﻿#pragma once
#include <string>
using namespace std;

struct Point
{
	//explicit - запрещает использование неявного пользовательского
	//преобразования при конструкторе с одним аргументом (например Point p = 10)
	explicit Point(double x = 0, double y = 0) : x(x), y(y) {} //при использовании списков инициализации 
															   //- последовательность инициализации зависит от порядка объявления переменных
	//если не имеется конструктора по умолчанию, и вообще конструктора, который может не принимать какие либо параметры (но есть другие конструкторы)
	//то при Point p; - error; 
	double x;
	double y;
	string getStr();
};
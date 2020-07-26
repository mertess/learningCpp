#include "Inheritance.h"
#include <iostream>

void Cat::move()
{
	Animal::move();
	std::cout << "dvigaetca";
}

void Cat::do_voice()
{
	std::cout << "voice";
}

void Cat::eat()
{
	std::cout << "eat";
}

Cat::Cat(Cat const& other)
{
	this->age = other.age;
	this->speed = other.speed;
}

Cat* Cat::clone()
{
	return new Cat(*this);
}

void Animal::move()
{
	//стандартная релизация чистого виртуального метода (вызывается как невиртуальный)
}
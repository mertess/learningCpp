#pragma once

//aka interface
struct IClonable
{
	virtual ~IClonable(){}
	virtual IClonable* clone() = 0;
};
//aka abstract class
class Animal
{
public:
	virtual void move() = 0;
	virtual void eat() = 0;
	virtual void do_voice() = 0;
	int age;
	int speed;
};

class Cat : Animal, IClonable
{
public:
	Cat(Cat const& other);
	void move();
	void eat();
	void do_voice();
	Cat* clone();
};

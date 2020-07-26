#include "SharedPtr.h"

CounterPtr::CounterPtr() : counter(0){}
void CounterPtr::increase_counter() { this->counter++; }
void CounterPtr::decrease_counter() { this->counter--; }
int CounterPtr::get_value() const
{
	return this->counter;
}

SharedStringPtr::SharedStringPtr(String* ptr)
{
	//проверка на пустой String*
	this->ptr_ = ptr;
	if (this->ptr_ != 0) {
		this->counter_ptr = new CounterPtr();
		this->counter_ptr->increase_counter();
	}
	else
		this->counter_ptr = 0;
}

SharedStringPtr::~SharedStringPtr()
{
	if (this->counter_ptr != 0) {
		this->counter_ptr->decrease_counter();
		if (this->counter_ptr->get_value() == 0) {
			delete this->ptr_;
			delete this->counter_ptr;
			return;
		}
	}
}

SharedStringPtr::SharedStringPtr(const SharedStringPtr& ptr)
{
	this->counter_ptr = ptr.get_counter();
	if (this->counter_ptr != 0) {
		this->counter_ptr->increase_counter();
		this->ptr_ = ptr.get();
	}
}

SharedStringPtr& SharedStringPtr::operator=(const SharedStringPtr& ptr)
{
	//проверка равенства на самого себя
	if (this != &ptr) {
		this->counter_ptr = ptr.get_counter();
		if (this->counter_ptr != 0) {
			this->counter_ptr->increase_counter();
			this->ptr_ = ptr.get();
		}
	}
	return *this;
}

String* SharedStringPtr::get() const
{
	return this->ptr_;
}

CounterPtr* SharedStringPtr::get_counter() const
{
	return this->counter_ptr;
}

void SharedStringPtr::reset(String* ptr)
{
	if (this->counter_ptr != 0) {
		this->counter_ptr->decrease_counter();
		if (this->counter_ptr->get_value() == 0)
		{
			delete this->ptr_;
			delete this->counter_ptr;
		}
		this->ptr_ = ptr;
	}
	else
	{
		this->ptr_ = ptr;
		if (this->ptr_ != 0)
		{
			this->counter_ptr = new CounterPtr();
			this->counter_ptr->increase_counter();
		}
	}
}

String& SharedStringPtr::operator*() const
{
	return *this->ptr_;
}

String* SharedStringPtr::operator->() const
{
	return this->ptr_;
}



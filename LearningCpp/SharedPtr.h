#pragma once
#include "String.h"

struct CounterPtr
{
	CounterPtr();
	void increase_counter();
	void decrease_counter();
    int get_value() const;
private:
	int counter; 
};

struct SharedStringPtr
{
    explicit SharedStringPtr(String* ptr = 0);
    ~SharedStringPtr();
    SharedStringPtr(const SharedStringPtr&);
    SharedStringPtr& operator=(const SharedStringPtr&);
    String* get() const;
    CounterPtr* get_counter() const;
    void reset(String* ptr = 0);
    String& operator*() const;
    String* operator->() const;
private:
    String* ptr_;
    CounterPtr* counter_ptr;
};
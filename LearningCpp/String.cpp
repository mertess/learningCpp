#include "String.h"
#include <cstring>
#include <algorithm>

String::String(const char* str) : size(strlen(str)), str(new char[size + 1])
{
    strcpy_s(this->str, strlen(str) + 1, str);
    this->str[size] = '\0';
}

String::String(size_t n, char c) : size(n), str(new char[size + 1])
{
    for (int i = 0; i < n; i++)
        this->str[i] = c;
    this->str[size] = '\0';
}

String::~String() {
    delete[] str;
}

void String::append(String& other)
{
    char* new_str = new char[size + other.size + 1];
    strcpy_s(new_str, strlen(this->str) + 1, this->str);
    for (int i = 0; i < other.size; i++)
        new_str[size + i] = other.str[i];
    new_str[size + other.size] = '\0';
    delete[] this->str;
    this->str = new_str;
    size += other.size;
}

//будет вызываться только у константных экземпляров класса string
size_t String::Size() const
{
    return this->size;
}

size_t& String::Size()
{
    return this->size;
}

String::String(String const& str) : size(str.size), str(new char[size + 1])
{
    for (int i = 0; i < size + 1; i++)
        this->str[i] = str.str[i];
}

String& String::operator=(String const& str)
{
    if (this != &str)
        String(str).swap(*this);
    return *this;
}

void String::swap(String& str)
{
    std::swap(this->size, str.size);
    std::swap(this->str, str.str);
}

//memory leaks
String const& String::operator[](int i) const
{
    if (this->l_ptr == 0)
    {
        String* str = new String(&this->str[i]);
        str->l_ptr = str->get_str();
        str->index_substr = i;
        return *str; 
    } 
    char* new_str = new char[i - this->index_substr];
    for (int j = 0; j < i - this->index_substr; j++)
    {
        new_str[j] = this->l_ptr[j];
    }
    delete this;
    String* str = new String(new_str);
    return *str;
}

char* String::get_str() const
{
    return this->str;
}


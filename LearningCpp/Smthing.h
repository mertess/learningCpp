#pragma once

unsigned gcd(unsigned a, unsigned b, unsigned x);
unsigned gcd(unsigned a, unsigned b);
int strLenght(const char* text, const char* pattern);
void swap_min(int* m[], unsigned rows, unsigned cols);

struct my_struct
{
    my_struct(int a, int b) : a(a), b(b) {}
private:
    int a;
    int b;
};

struct Cls {
    Cls(char c, double d, int i) : c(c), d(d), i(i) {}
private:
    char c;
    double d;
    int i;
};

int& getA(my_struct& st);
int& getB(my_struct& st);
void get_c(Cls& cls);
void get_d(Cls& cls);
void get_i(Cls& cls);

static int func();
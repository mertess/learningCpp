#pragma once
#include <list>
#include <string>
#include <iostream>
#include <deque>

template<class It>
size_t max_increasing_len(It p, It q)
{
    if (p == q)
        return 0;
    int max_len = 1;
    --q;
    for (; p != q;)
    {
        int curr_len = 0;
        It tmp_p = p;
        if (*tmp_p < *(++p))
        {
            curr_len += 2;
            It pp = p;
            //std::cout << "p = " << *p << std::endl;
            for (; pp != q;)
                if (*pp < *(++pp))
                    ++curr_len;
                else
                    break;
            //std::cout << "p = " << *p << std::endl;
        }
        if (curr_len > max_len)
            max_len = curr_len;
    }
    return max_len;
}

void main_method();
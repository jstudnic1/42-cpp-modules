#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

template <typename T, typename F>
void iter(T *array, size_t length, F f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif

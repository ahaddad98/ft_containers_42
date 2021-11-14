#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

int main () 
{
    enable_if<true, int>::type a = 1;
    std::cout << a << std::endl;
    return 0;
}
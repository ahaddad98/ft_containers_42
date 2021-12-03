#include <iostream>

void fun(int n)
{
    if (n > 0)
    {
        std::cout << n << " " ;
        fun(n-1);
        fun(n-1);
    }
}

int main()
{
    fun(3);
}
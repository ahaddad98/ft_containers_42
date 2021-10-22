/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/22 14:04:09 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>

template<typename T>

void printVector(const ft::Vector<T>& vect)
{
    int i = 0;
    while (i <vect.Size())
    {
        std::cout << vect[i] << std::endl;
        i++;
    }
}


int main()
{
    // std::vector<int>::iterator it;
    // it.__i = 13;
    ft::Vector<std::string> vector;
    std::cout << "amine" << std::endl;
    // ft::Vector<int>::Iterator it;
    // vector.PushBack("amine");
    // vector.PushBack("amine1");
    // vector.PushBack("amine2");
    //  vector.PopBack();
    //  vector.clear();
    // printVector(vector);
    // std::vector<int> vect(10, 0);
    // vect.assign("","");
    // std::allocator<int> alloc;
    // int *p = alloc.allocate(1);
    // p[4] = 4;
    // vect.
    // alloc.deallocate(); 
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/20 17:39:47 by ahaddad          ###   ########.fr       */
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
     ft::Vector<std::string> vector;
     vector.PushBack("amine");
     vector.PushBack("amine1");
     vector.PushBack("amine2");
    //  vector.PopBack();
    //  vector.clear();
    printVector(vector);
    // std::vector<int> vect(10, 0);
    // vect.assign("","");
    // std::allocator<int> alloc;
    // int *p = alloc.allocate(1);
    // p[4] = 4;
    // vect.
    // alloc.deallocate(); 
    return 0;
}
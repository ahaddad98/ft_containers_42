/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/28 16:12:11 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>
#include "Vector/iterator.hpp"

// template<typename T>

// void printVector(const ft::Vector<T>& vect)
// {
//     int i = 0;
//     // ft::vector_iterator<int> it;
//     // std::vector<int> vect;
//     // vect.PushBack(12);
//     // vect.PushBack(122);
//     // vect.PushBack(123);
//     // vect.PushBack(124);
//     // vect.PushBack(125);
//     while (i <vect.Size())
//     {
//         std::cout << vect[i] << std::endl;
//         i++;
//     }
// }

int main()
{
    ft::vector<std::string> point3d(3);
    point3d[0] = "2";
    point3d[1] = "3";
    point3d[2] = "4";

    for (ft::vector<std::string>::iterator i = point3d.begin(); i != point3d.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    // std::vector<int>::iterator it;
    // it.__i = 13;
    // ft::vector_iterator<int> iter;
    // std::vector<int> vect;
    // vect.push_back(12);
    // vect.push_back(122);
    // vect.push_back(123);
    // vect.push_back(124);
    // vect.push_back(125);
    // // iter = vect.begin();
    // std::cout << "amine" << std::endl;
    // ft::Vector<int> vector;
    // vector.PushBack(2);
    // vector.PushBack(3);
    // vector.PushBack(4);
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
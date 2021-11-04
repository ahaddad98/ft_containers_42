/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/04 20:55:51 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>
#include "Vector/iterator.hpp"

int main()
{
    ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);

    // vect.insert(vect.begin(), 2, 3);
    // vect.insert(vect.begin(), 1, 3);
    // vect.insert(vect.begin(), 2, 4);
    // vect.insert(it, 2, 4);
    // for (ft::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    // {
    //     std::cout << *i << " ";
    // }
    // vect.insert(vect.begin(), 2 , 6);
    // vect.insert(vect.begin(), 2);
    // std::cout << "amine haddad" << std::endl;
    // vect.insert(vect.begin() , 6);
    // vect.insert(vect.begin() , 7);
    // std::cout << "after insert" << std::endl;
    // for (ft::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    // {
    //     std::cout << *i << " ";
    // }
    size_t sz = vect.capacity_;
    vect.reserve(100);
    std::cout << "making bar grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        vect.push_back(i);
        if (sz != vect.capacity_)
        {
            sz = vect.capacity_;
            std::cout << "capacity changed: " << sz << '\n';
        }
    }
    return 0;
}
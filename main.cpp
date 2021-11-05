/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/05 14:43:25 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>
#include "Vector/iterator.hpp"

int main()
{
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);


    // std::vector<int> first;                                // empty vector of ints
    // std::vector<int> second (4,100);                       // four ints with value 100
    // std::vector<int> third (second.begin(),second.end());  // iterating through second
    // std::vector<int> fourth (third);                       // a copy of third
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
    // size_t sz = vect.capacity_;
    // vect.reserve(100);
    // std::cout << "making bar grow:\n";
    // for (int i = 0; i < 100; ++i)
    // {
    //     vect.push_back(i);
    //     if (sz != vect.capacity_)
    //     {
    //         sz = vect.capacity_;
    //         std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }
    
    std::cout << "========== ft::vector =======" << std::endl;

    ft::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(20);
    vec.push_back(20);
    vec.push_back(20);
    vec.push_back(20);
    vec.resize(50, 100);
    for (ft::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
    
    


    std::cout << "============ std::vector =========" << std::endl;

    std::vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(20);
    vect.push_back(20);
    vect.push_back(20);
    vect.push_back(20);
    vect.resize(50, 100);
    for (std::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << vect.size() << std::endl;
    std::cout << vect.capacity() << std::endl;
    
    return 0;
}
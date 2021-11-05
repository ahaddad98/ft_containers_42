/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/05 20:50:14 by ahaddad          ###   ########.fr       */
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
    
    // std::cout << "========== ft::vector =======" << std::endl;

    // ft::vector<int> vec;
    // vec.push_back(10);
    // vec.push_back(20);
    // vec.push_back(20);
    // vec.push_back(20);
    // vec.push_back(20);
    // vec.push_back(20);
    // int j = 0;
    // for (ft::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
    // {
        
    //     vec.at(j) = j;
    //     j++;
    // }
    // for (ft::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
    // {
        
    //     std::cout << *i << std::endl;
    //     j++;
    // }
    // std::cout << std::endl;
    // std::cout << vec.size() << std::endl;
    // std::cout << vec.capacity() << std::endl;
    
    


    // std::cout << "============ std::vector =========" << std::endl;

    // std::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(20);
    // vect.push_back(20);
    // vect.push_back(20);
    // vect.push_back(20);
    
    // j = 0;
    // for (std::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    // {
        
    //     vect.at(j) = j;
    //     j++;
    // }
    // std::cout << std::endl;
    // it=first.begin()+1;

    // second.assign (it,first.end()-1); // the 5 central values of first

    // int myints[] = {1776,7,4};
    // third.assign (myints,myints+3);   // assigning from array.

    // std::cout << "Size of first: " << int (first.size()) << '\n';
    // std::cout << "Size of second: " << int (second.size()) << '\n';
    // std::cout << "Size of third: " << int (third.size()) << '\n';
    
    
    
    
    std::cout << "============ ft::vector =========" << std::endl;
    ft::vector<int> first;
    first.push_back(10);
    first.push_back(20);
    first.push_back(20);
    first.push_back(20);
    first.push_back(20);
    first.push_back(20);
    first.push_back(20);
    first.push_back(20);
    first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    first.assign(8,100);
    // ft::vector<int>::iterator it;
    for (ft::vector<int>::iterator i = first.begin(); i != first.end(); i++)
    {
        
        std::cout << *i << std::endl;
        // j++;
    }
    std::cout << "size = " <<  first.size() << std::endl;
    std::cout << "capacity = " <<first.capacity() << std::endl;
    
    std::cout << "============ std::vector =========" << std::endl;
    std::vector<int> first1;
    // first1.push_back(10);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    // first1.push_back(20);
    first1.assign(8,100);
    std::vector<int>::iterator it;
    for (std::vector<int>::iterator i = first1.begin(); i != first1.end(); i++)
    {
        
        std::cout << *i << std::endl;
        // j++;
    }
    std::cout << "size = " <<  first1.size() << std::endl;
    std::cout << "capacity = " <<first1.capacity() << std::endl;
    return 0;
}
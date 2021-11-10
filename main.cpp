/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/10 17:38:13 by ahaddad          ###   ########.fr       */
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

    // std::cout << "============ ft::vector =========" << std::endl;
    // ft::vector<int> first;
    // first.push_back(10);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.push_back(20);
    // first.assign(8,100);
    // ft::vector<int>::iterator it;
    // for (ft::vector<int>::iterator i = first.begin(); i != first.end(); i++)
    // {

    //     std::cout << *i << std::endl;
    //     // j++;
    // }
    // std::cout << "size = " <<  first.size() << std::endl;
    // std::cout << "capacity = " <<first.capacity() << std::endl;

    // std::cout << "============ std::vector =========" << std::endl;
    // std::vector<int> first1;
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
    // first1.assign(8,100);
    // std::vector<int>::iterator it;
    // for (std::vector<int>::iterator i = first1.begin(); i != first1.end(); i++)
    // {

    //     std::cout << *i << std::endl;
    //     // j++;
    // }
    // std::cout << "size = " <<  first1.size() << std::endl;
    // std::cout << "capacity = " <<first1.capacity() << std::endl;

    // vector assign

    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> first1;
    // ft::vector<int> second1;
    // second1.push_back(10);
    // second1.push_back(10);
    // second1.push_back(10);
    // second1.push_back(10);
    // second1.push_back(10);
    // second1.push_back(10);
    // second1.push_back(10);
    // second1.push_back(10);
    // // second1.push_back(10);
    // // std::vector<int> third;
    // first1.assign (7,100);             // 7 ints with a value of 100
    // ft::vector<int>::iterator it=first1.begin()+1;
    // it=first1.begin()+1;
    // second1.assign (it,first1.end()-1); // the 5 central values of first
    // for (ft::vector<int>::iterator it = second1.begin(); it != second1.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << second1.size() << std::endl;
    // std::cout << "capacity = " << second1.capacity() << std::endl;
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> first;
    // std::vector<int> second;
    // second.push_back(10);
    // second.push_back(10);
    // second.push_back(10);
    // second.push_back(10);
    // second.push_back(10);
    // second.push_back(10);
    // second.push_back(10);
    // second.push_back(10);
    // // second.push_back(10);
    // // std::vector<int> third;
    // first.assign (7,100);             // 7 ints with a value of 100
    // std::vector<int>::iterator it1;
    // it1=first.begin()+1;
    // second.assign (it1,first.end()-1); // the 5 central values of first
    // for (std::vector<int>::iterator it = second.begin(); it != second.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << second.size() << std::endl;
    // std::cout << "capacity = " << second.capacity() << std::endl;

    // int myints[] = {1776,7,4};
    // third.assign (myints,myints+3);   // assigning from array.

    // std::cout << "Size of first: " << int (first.size()) << '\n';
    // std::cout << "Size of second: " << int (second.size()) << '\n';
    // std::cout << "Size of third: " << int (third.size()) << '\n';
    // erase vector
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // ft::vector<int>::iterator it = vect.begin();
    // vect.erase(it+2);
    // for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // std::vector<int>::iterator it1 = vect1.begin();
    // vect1.erase(it1 + 2);
    // for (std::vector<int>::iterator it1 = vect1.begin(); it1 != vect1.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // erase fill
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(40);
    // vect.push_back(50);
    // vect.push_back(60);
    // vect.push_back(70);
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // ft::vector<int>::iterator it = vect.begin();
    // vect.erase(it + 1, vect.end()-2);
    // for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;

    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(40);
    // vect1.push_back(50);
    // vect1.push_back(60);
    // vect1.push_back(70);
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // std::vector<int>::iterator it1 = vect1.begin();
    // vect1.erase(it1 + 1, vect1.end()-2);
    // for (std::vector<int>::iterator it1 = vect1.begin(); it1 != vect1.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;

    // pop_back()
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(40);
    // vect.push_back(50);
    // vect.push_back(60);
    // vect.push_back(70);
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // ft::vector<int>::iterator it = vect.begin();
    // vect.pop_back();
    // vect.pop_back();
    // vect.pop_back();
    // vect.pop_back();

    // for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;

    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(40);
    // vect1.push_back(50);
    // vect1.push_back(60);
    // vect1.push_back(70);
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // std::vector<int>::iterator it1 = vect1.begin();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.pop_back();
    // for (std::vector<int>::iterator it1 = vect1.begin(); it1 != vect1.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    std::cout << "=================== ft::vector ====================" << std::endl;
    ft::vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(40);
    vect.push_back(50);
    vect.push_back(60);
    vect.push_back(70);
    vect.push_back(80);
    vect.push_back(90);
    vect.push_back(100);
    vect.push_back(110);
    vect.push_back(120);
    vect.push_back(130);
    vect.push_back(140);
    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    ft::vector<int>::iterator it = vect.begin();
    // vect.pop_back();
    // vect.pop_back();
    // vect.pop_back();
    // vect.pop_back();
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    // vect.insert(vect.begin()+2, 5);
    vect.insert(vect.begin()+2, 5, 5);
    for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;

    std::cout << "=================== std::vector ====================" << std::endl;
    std::vector<int> vect1;
    vect1.push_back(10);
    vect1.push_back(20);
    vect1.push_back(30);
    vect1.push_back(40);
    vect1.push_back(50);
    vect1.push_back(60);
    vect1.push_back(70);
    vect1.push_back(80);
    vect1.push_back(90);
    vect1.push_back(100);
    vect1.push_back(110);
    vect1.push_back(120);
    vect1.push_back(130);
    vect1.push_back(140);
    std::cout << "size = " << vect1.size() << std::endl;
    std::cout << "capacity = " << vect1.capacity() << std::endl;
    std::vector<int>::iterator it1 = vect1.begin();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.pop_back();
    vect1.insert(vect1.begin()+2, 5, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    for (std::vector<int>::iterator it1 = vect1.begin(); it1 != vect1.end(); it1++)
    {
        std::cout << *it1 << std::endl;
    }
    std::cout << std::endl;
    std::cout << "size = " << vect1.size() << std::endl;
    std::cout << "capacity = " << vect1.capacity() << std::endl;

    return 0;
}
// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/22 20:27:44 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include "Vector/iterator.hpp"
#include <vector>
#include <stack>
#include <map>
#include "Map/pair.hpp"

int main()
{
    // test operators overloaded 
    ft::vector<int> foo(3, 100); // three ints with a value of 100
    ft::vector<int> bar(foo); // two ints with a value of 200
    for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    // foo.erase(foo.begin() , foo.end()-1);
    // std::cout << "---------------- after erase --------------- " << foo.size() << std::endl; 
    // for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // if (foo == bar)
    //     std::cout << "foo and bar are equal\n";
    // if (foo != bar)
    //     std::cout << "foo and bar are not equal\n";
    // if (foo < bar)
    //     std::cout << "foo is less than bar\n";
    // if (foo > bar)
    //     std::cout << "foo is greater than bar\n";
    // if (foo <= bar)
    //     std::cout << "foo is less than or equal to bar\n";
    // if (foo >= bar)
    //     std::cout << "foo is greater than or equal to bar\n";
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
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(40);
    // vect.push_back(50);
    // vect.push_back(60);
    // vect.push_back(70);
    // vect.push_back(80);
    // vect.push_back(90);
    // vect.push_back(100);
    // vect.push_back(110);
    // vect.push_back(120);
    // vect.push_back(130);
    // vect.push_back(140);
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // ft::vector<int>::iterator it = vect.begin();
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
    // vect.insert(vect.begin()+2, 5, 5);
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
    // vect1.push_back(80);
    // vect1.push_back(90);
    // vect1.push_back(100);
    // vect1.push_back(110);
    // vect1.push_back(120);
    // vect1.push_back(130);
    // vect1.push_back(140);
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // std::vector<int>::iterator it1 = vect1.begin();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.pop_back();
    // vect1.insert(vect1.begin()+2, 5, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // vect1.insert(vect1.begin()+2, 5);
    // for (std::vector<int>::iterator it1 = vect1.begin(); it1 != vect1.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // insert fill from vector to another
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vec;
    // vec.push_back(10);
    // vec.push_back(20);
    // vec.push_back(30);
    // vec.push_back(40);
    // ft::vector<int> vec21;

    // // inserts at the beginning of vec2
    // vec21.insert(vec21.begin(), vec.begin(), vec.end());

    // std::cout << "The vector2 elements are: ";
    // for (ft::vector<int>::iterator it = vec21.begin(); it != vec21.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vec1;
    // vec1.push_back(10);
    // vec1.push_back(20);
    // vec1.push_back(30);
    // vec1.push_back(40);
    // std::vector<int> vec2;

    // // inserts at the beginning of vec2
    // vec2.insert(vec2.begin(), vec1.begin(), vec1.end());

    // std::cout << "The vector2 elements are: ";
    // for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
    //     std::cout << *it << " ";

    // clear

    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(40);
    // vect.push_back(50);
    // vect.clear();
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // std::cout << "=================== std::vector ====================" << std::endl;
    // ft::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(40);
    // vect1.push_back(50);
    // vect1.clear();
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;

    // non member funtions

    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> my_vect;
    // my_vect.push_back(10);
    // my_vect.push_back(20);
    // my_vect.push_back(30);
    // my_vect.push_back(30);
    // // my_vect.push_back(50);
    // ft::vector<int> my_vect1;
    // my_vect1.push_back(10);
    // my_vect1.push_back(20);
    // my_vect1.push_back(30);
    // my_vect1.push_back(30);
    // my_vect1.push_back(50);
    // if (my_vect == my_vect1)
    // {
    //     std::cout << "the same vectors" << std::endl;
    // }
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(30);
    // // vect.push_back(50);
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(30);
    // vect1.push_back(50);
    // if (vect == vect1)
    // {
    //     std::cout << "the same vectors" << std::endl;
    // }
    // operator !=
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> my_vect;
    // my_vect.push_back(10);
    // my_vect.push_back(20);
    // my_vect.push_back(30);
    // my_vect.push_back(30);
    // // my_vect.push_back(50);
    // ft::vector<int> my_vect1;
    // my_vect1.push_back(10);
    // my_vect1.push_back(20);
    // my_vect1.push_back(30);
    // my_vect1.push_back(30);
    // my_vect1.push_back(50);
    // if (my_vect <=  my_vect1)
    // {
    //     std::cout << "not same vectors" << std::endl;
    // }
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect;
    // vect.push_back(10);
    // // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(30);
    // vect.push_back(50);
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(30);
    // vect1.push_back(50);
    // if (vect <= vect1)
    // {
    //     std::cout << "not same vectors" << std::endl;
    // }
    // resize
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect .push_back(20);
    // vect.push_back(30);
    // vect.push_back(40);
    // vect.push_back(50);
    // vect.resize(10);
    // for (ft::vector<int>::iterator it = vect.begin() ; it != vect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(40);
    // vect1.push_back(50);
    // vect1.resize(10);
    // for (std::vector<int>::iterator it = vect1.begin() ; it != vect1.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;
    // operator [] in iterator
    // std::cout << "=================== ft::vector ====================" << std::endl;
    // ft::vector<int> vect;
    // vect.push_back(10);
    // vect.push_back(20);
    // vect.push_back(30);
    // vect.push_back(40);
    // vect.push_back(50);
    // // vect.resize(10);
    // // ft::vector<int>::reverse_iterator re_it = vect.rbegin();
    // for (ft::vector<int>::reverse_iterator it = vect.rbegin();  it != vect.rend(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << "size = " << vect.size() << std::endl;
    // std::cout << "capacity = " << vect.capacity() << std::endl;
    // std::cout << "=================== std::vector ====================" << std::endl;
    // std::vector<int> vect1;
    // vect1.push_back(10);
    // vect1.push_back(20);
    // vect1.push_back(30);
    // vect1.push_back(40);
    // vect1.push_back(50);
    // std::vector<int>::iterator re_it1 = vect1.begin();
    // // vect1.resize(10);
    // // for (std::vector<int>::iterator it = vect1.begin() ; it != vect1.end(); it++)
    // // {
    //     std::cout << re_it1[-1] << std::endl;
    // // }
    // std::cout << "size = " << vect1.size() << std::endl;
    // std::cout << "capacity = " << vect1.capacity() << std::endl;

    // int array[] = {1,2, 3, 4, 5 , 6};
    // ft::vector<int> vect;
    // vect.insert(vect.begin(), array, array + 5);
    // for (ft::vector<int>::iterator it = vect.begin() ; it != vect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    // ft::vector<int> vect;
    // // int array[] = {1,2, 3, 4, 5 , 6};
    // // vect.assign(&array[0], &array[4]);
    // vect.assign(10, 20);

    // ft::vector<int>::iterator it = vect.begin();

    // for (ft::vector<int>::iterator it = vect.begin() ; it != vect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    // stack
    // ft::Stack a;
    // ft::stack<int> mystack;
    // int sum (0);

    // for (int i=1;i<=11;i++) mystack.push(i);

    // while (!mystack.empty())
    // {
    //     std::cout <<  mystack.top() << std::endl;
    //     mystack.pop();
    // }

    // std::cout << "total: " << mystack.size() << '\n';
    // return 0;

    // ft::map<int , char> a;
    // std::map<char , int> my_map;
    // std::map<char , int>::iterator it;
    // my_map.insert (std::pair<char,int>('a',100));
    // for ( it = my_map.begin(); it != my_map.end(); it++)
    // {
    //     std::cout << "key = " << it->first << std::endl;
    //     std::cout << "value = " << it->second << std::endl;
    // }
    // std::vector<int> vect;
    // std::vector<int>::iterator it;
    // it = vect.begin();
    // std::cout << *it << std::endl;
    // ft::map<int, int> mymap;
    // ft::map<int, int> mymap1;
    // mymap.insert(pair<int,int>(1,2));
    // mymap.insert(pair<int,int>(1,20));
    // // std::cout << "1 inserted\n";
    // mymap.insert(pair<int,int>(12,2));
    // // std::cout << "12 inserted\n";
    // mymap.insert(pair<int, int>(10, 2));
    // mymap.insert(pair<int, int>(0, 2));
    // mymap.insert(pair<int, int>(15, 2));
    // mymap.insert(pair<int, int>(12, 2));
    // mymap1.insert(std::pair<int,int>(10,2));
    // mymap1.insert(std::pair<int,int>(0,2));
    // mymap1.insert(std::pair<int,int>(15,2));
    // mymap1.insert(std::pair<int,int>(12,2));
    // ft::map<int , int>::iterator it = mymap.find(10);
    // std::cout << it->first << std::endl;
    // // std::cout << "13 inserted\n";
    // mymap.insert(pair<int,int>(14,2));
    // // std::cout << "14 inserted\n";
    // mymap.insert(pair<int,int>(15,2));
    // for(int i = 0; i < 10000000; i++)
    //     mymap1.insert(pair<int,int>(i, 125));
    // mymap1.clear();
    // mymap.delete_(pair<int , int>(15, 125));
    // mymap.delete_(pair<int , int>(12, 125));
    // mymap.delete_(pair<int , int>(10, 125));
    // mymap.delete_(pair<int , int>(0, 125));
    // mymap.delete_(pair<int , int>(10, 125));
    // mymap.delete_(pair<int , int>(15, 125));
    // mymap.delete_(pair<int , int>(12, 125));
    // mymap.delete_(pair<int , int>(0, 125));
    // std::cout << "asa" << std::endl;
    // ft::map<int , int>::const_iterator it
    // for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << it->first << " ==> " << it->second << std::endl;
    // }
    // // equale range
    // pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> pr;
    // // pair<int, int> pr;
    // pr = mymap.equal_range(15);
    // std::cout << "lower bound points to: ";
    // std::cout << pr.first->first << " => " << pr.first->second << '\n';

    // std::cout << "upper bound points to: ";
    // std::cout << pr.second->first << " => " << pr.second->second << '\n';

    // std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> pr1;
    // // pair<int, int> pr;
    // std::map<int, int>::iterator iit;
    // // iit = mymap1.lower_bound(15);
    // // std::cout << "std lower bound " << iit->first << " ==> " << iit->second << std::endl;
    // pr1 = mymap1.equal_range(15);
    // std::cout << "std lower bound points to: ";
    // std::cout << pr1.first->first << " => " << pr1.first->second << '\n';

    // std::cout << "std upper bound points to: ";
    // std::cout << pr1.second->first << " => " << pr1.second->second << '\n';

    // lowerbound
    // ft::map<int , int>::iterator it = mymap.lower_bound(15);
    // std::cout << it->first  << " ==> "  << it->second << std::endl;
    // lowerbound
    // std::cout << "upper bound test" << std::endl;
    // ft::map<int , int>::const_iterator it;
    // it = mymap.upper_bound(0);
    // if (it != mymap.end())
    //     std::cout << it->first  << " ==> "  << it->second << std::endl;
    // std::cout << it->first << std::endl;
    // if (mymap.count(245465) == 0)
    //     std::cout << "element not found" << std::endl;
    // else
    //     std::cout << "element found" << std::endl;
    // std::cout << "after erase" << std::endl;
    // mymap.erase(mymap.begin(), mymap.end());
    // for (ft::map<int , int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << it->first  << " ==> "  << it->second << std::endl;
    // }
    // for (ft::map<int , int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << it->first  << " ==> "  << it->second << std::endl;
    // }
    // mymap.delete_(pair<int , int>(9, 125));
    // std::cout << "delete last node 9, 125" << std::endl;
    // for (ft::map<int , int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << it->first  << " ==> "  << it->second << std::endl;

    // }
    // mymap.delete_(pair<int , int>(8, 125));
    // std::cout << "delete last node 8, 125" << std::endl;
    // for (ft::map<int , int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << it->first  << " ==> "  << it->second << std::endl;

    // }

    // mymap->insert(15);
    // mymap->insert(25);
    // mymap->insert(85);
    // mymap->insert(75);
    // mymap->insert(65);
    // mymap->insert(95);
    // mymap->insert(55);

    // it = mymap.end();

    // std::cout << mymap.size() << std::endl;
    // std::map<int , int> map;
    // map.insert(std::pair<int , int>(1,1));
    // map.insert(std::pair<int , int>(1,12));
    // map.insert(std::pair<int , int>(12,13));
    // map.insert(std::pair<int , int>(1,14));
    // std::map<int, int>::iterator it1;
    // for ( it1 = map.begin(); it1 != map.end(); it1++)
    // {
    //     std::cout << it1->first << " ==> " << it1->second <<std::endl;
    // }
}

// to test our stack

/* cout<<"Instructions: \n";
    cout<<"Type add to push onto stack"<<endl;
    cout<<"Type del to pop from stack"<<endl;
    cout<<"Type top to check the top element in stack"<<endl;
    cout<<"Type exit to stop using the stack"<<endl;
    Stack S;
    int top;
    while(1){
        string instruction;
        cout<<"Instruction: ";
        cin>>instruction;
        if(instruction=="exit"){
            break;
        }else if(instruction=="add"){
            cout<<"Enter the element top be pushed"<<endl;
            int push; //element to be pushed
            cin>>push;
            S.Push(push);
                cout<<"Element successfully pushed"<<endl;
                if(S.Top(top)==true){
                    cout<<"Top Element is:"<<top<<endl;
                }
 
        }else if(instruction=="del"){
            if(S.Pop()==true){
                cout<<"Element was successfully popped"<<endl;
                if(S.Top(top)==true){
                    cout<<"Top Element is:"<<top<<endl;
                }else{
                    cout<<"Stack is now Empty!"<<endl;
                }
            }else{
                cout<<"ERROR : Stack is empty!"<<endl;
            }
        }else if(instruction=="top"){
                if(S.Top(top)==true){
                    cout<<"Top Element is:"<<top<<endl;
                }else{
                    cout<<"ERROR : Stack is empty!"<<endl;
                }
        }else{
            cout<<"ERROR : Unknown operation! Please try again"<<endl;
        }
    }
    */

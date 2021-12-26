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
#include "set/set.hpp"
#include <set>

template <typename T, typename U>
void print_map(ft::map<T, U> &mp, char const *label)
{
    std::cout << "\nmap Size: " << mp.size();
    std::cout << "\nmap [" << label << "] contains: ";
    if (!mp.size())
        std::cout << "nothing";
    else
        std::cout << "\n\n";
    for (typename ft::map<T, U>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        std::cout << "[" << it->first << "]"
                  << " = " << it->second << std::endl;
    }
    std::cout << std::endl;
}

void print_vector(ft::vector<int> &vect, char const *label)
{
    std::cout << "\nvector Size: " << vect.size();
    std::cout << "\nvector [" << label << "] contains:";
    if (!vect.size())
        std::cout << "\tnothing";
    for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << "  [ " << *it << " ]";
    }
    std::cout << std::endl;
}

int main()
{
    // std::cout << "\nrelational operators" << std::endl;
    // std::cout << "=======================================" << std::endl;

    // ft::vector<int> a;
    // a.push_back(10);
    // a.push_back(20);
    // a.push_back(30);
    // print_vector(a, "a");
    // ft::vector<int> b = a;
    // std::cout << "here" << std::endl;
    // b = a;

    // print_vector(b, "b");

    // ft::vector<int> c;
    // c.push_back(30);
    // c.push_back(20);
    // c.push_back(10);
    // print_vector(c, "c");

    // if (a == b)
    //     std::cout << "\na and b are equal\n";
    // if (b != c)
    //     std::cout << "b and c are not equal\n";
    // if (b < c)
    //     std::cout << "b is less than c\n";
    // if (c > b)
    //     std::cout << "c is greater than b\n";
    // if (a <= b)
    //     std::cout << "a is less than or equal to b\n";
    // if (a >= b)
    //     std::cout << "a is greater than or equal to b\n";
    // std::cout << "=======================================" << std::endl;
    // std::cout << "\nerase()" << std::endl;
    // std::cout << "=======================================" << std::endl;

    // ft::vector<int> myvect;
    // ft::vector<int>::iterator it1, it2;

    // // set some values:
    // for (int i = 1; i < 10; ++i)
    //     myvect.push_back(i * 10);

    // print_vector(myvect, "myvect");

    // // 10 20 30 40 50 60 70 80 90
    // it1 = it2 = myvect.begin(); // ^^
    // for (size_t i = 0; i < 6; i++, it2++)
    //     ;  // ^                 ^
    // ++it1; //    ^              ^
    // --it2;
    // it1 = myvect.erase(it1); // 10 30 40 5
    // {
    //     std::cout << "\ncapacity()" << std::endl;
    //     std::cout << "=======================================" << std::endl;
    //     ft::vector<size_t> vec(50, 500);
    //     ft::vector<size_t> myvect(7, 100);
    //     std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
    //     std::cout << "myvect.size() is: " << myvect.size() << '\n';

    //     myvect.push_back(200);
    //     std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
    //     std::cout << "myvect.size() is: " << myvect.size() << '\n';
    //     myvect.insert(myvect.begin(), vec.begin(), vec.end());

    //     std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
    //     std::cout << "myvect.size() is: " << myvect.size() << '\n';

    //     myvect.push_back(200);
    //     std::cout << "myvect.capacity() is: " << myvect.capacity() << '\n';
    //     std::cout << "myvect.size() is: " << myvect.size() << '\n';
    //     std::cout << "=======================================" << std::endl;
    // }
    // std::cout << "\ninsert()" << std::endl;
    // std::cout << "=======================================" << std::endl;
    // ft::vector<int> myvect;
    // ft::vector<int>::iterator ite;
    // // set some initial values:
    // for (int i = 1; i <= 5; ++i)
    // {
    // 	myvect.push_back(i);
    // }
    // ite = myvect.begin();
    // ++ite;
    // myvect.insert(ite++, 10);
    // std::cout << "=======================================" << std::endl;
    // ite = myvect.begin();
    // ite += 2;
    // myvect.insert(ite, 2, 20);
    // for (ft::vector<int>::iterator it = myvect.begin(); it != myvect.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // ite = myvect.begin();
    // ite += 2;
    // myvect.insert(ite, 2, 20);
    // print_vector(myvect, "myvect");

    // ft::stack<int, ft::vector<int> > stk;
    // stk.push(10);
    // ft::stack<int, ft::vector<int> > stk1;
    // stk1.push(11);
    // ft::stack<int, ft::vector<int> > stk2;
    // stk2.push(10);
    // if (stk == stk1)
    //     std::cout << "stk = stk1" << std::endl;
    // if (stk == stk2)
    //     std::cout << "stk = stk2" << std::endl;
    // if (stk != stk1)
    //     std::cout << "stk != stk1" << std::endl;
    // if (stk != stk1)
    //     std::cout << "stk != stk1" << std::endl;
    // test operators overloaded
    // test operator = and copy constructor
    // ft::vector<int> foo(3, 100); // three ints with a value of 100
    // ft::vector<int> bar(foo); // two ints with a value of 200
    // for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
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
    // ft::map<int , int> mymap;
    // mymap.insert(ft::pair<int , int>(10, 10));
    // mymap.insert(ft::pair<int , int>(20, 10));
    // mymap.insert(ft::pair<int , int>(30, 10));
    // mymap.insert(ft::pair<int , int>(0, 10));
    // ft::map<int , int> mymap1(mymap);
    // for (ft::map<int , int>::iterator it = mymap1.begin(); it != mymap1.end(); it++)
    // {
    //     std::cout << it->first  << " ==> "  << it->second << std::endl;
    // }
    // {
    //     std::cout << "\nbegin() & end() " << std::endl;
    //     std::cout << "=======================================" << std::endl;
    //     ft::map<int, int> map1;
    //     map1.insert(ft::make_pair(5, 1));
    //     // map1.insert(ft::make_pair(10, 3));
    //     // map1.insert(ft::make_pair(4, 4));
    //     // map1.insert(ft::make_pair(2, 2));
    //     // ft::map<int, int>::iterator it = map1.begin();
    //     // print_map(map1, "map1");
    //     // std::cout << "map1.begin(): " << (*it).first << std::endl;
    //     std::cout << "=======================================" << std::endl;
    // }
    // {
    //     std::cout << "\nclear()" << std::endl;
    //     std::cout << "=======================================" << std::endl;
    //     ft::map<int, int> map1;
    //     map1.insert(ft::make_pair(5, 1));
    //     map1.insert(ft::make_pair(2, 2));
    //     map1.insert(ft::make_pair(10, 3));
    //     map1.insert(ft::make_pair(4, 4));
    //     print_map(map1, "map1");
    //     map1.clear();
    //     std::cout << "after clearing map1" << std::endl;
    //     print_map(map1, "map1");
    //     std::cout << "=======================================" << std::endl;
    // }
    // {
    // std::cout << "\nlower_bound()" << std::endl;
    // std::cout << "=======================================" << std::endl;
    // ft::map<int, int> map1;
    // map1.insert(ft::make_pair(5, 1));
    // map1.insert(ft::make_pair(2, 2));
    // map1.insert(ft::make_pair(10, 3));
    // map1.insert(ft::make_pair(4, 4));
    // print_map(map1, "map1");
    // ft::map<int, int>::iterator it = map1.lower_bound(3);
    // std::cout << "map1.lower_bound(3): " << (*it).first << std::endl;
    // it = map1.lower_bound(5);
    // std::cout << "map1.lower_bound(5): " << (*it).first << std::endl;
    // it = map1.lower_bound(6);
    // std::cout << "map1.lower_bound(6): " << (*it).first << std::endl;
    // it = map1.upper_bound(10);
    // std::cout << "map1.upper_bound(10): " << (*it).first << std::endl;
    // it = map1.upper_bound(20);
    // std::cout << "map1.upper_bound(20): " << (*it).first << std::endl;
    // std::cout << "=======================================" << std::endl;
    // }
    // std::cout << "\nupper_bound()" << std::endl;
    // std::cout << "=======================================" << std::endl;
    // ft::map<int, int> map1;
    // map1.insert(ft::make_pair(5, 1));
    // map1.insert(ft::make_pair(2, 2));
    // map1.insert(ft::make_pair(10, 3));
    // map1.insert(ft::make_pair(4, 4));
    // print_map(map1, "map1");
    // ft::map<int, int>::iterator it = map1.upper_bound(3);
    // std::cout << "map1.upper_bound(3): " << (*it).first << std::endl;
    // it = map1.upper_bound(5);
    // std::cout << "map1.upper_bound(5): " << (*it).first << std::endl;
    // it = map1.upper_bound(6);
    // std::cout << "map1.upper_bound(6): " << (*it).first << std::endl;
    // std::cout << "=======================================" << std::endl;
    // ft::set<int> myset;
    // ft::set<int> first; // empty set of ints

    // int myints[] = {10, 20, 30, 40, 50};
    // ft::set<int> second(myints, myints + 5); // range

    // ft::set<int> third(second); // a copy of second

    // ft::set<int> fourth(second.begin(), second.end()); // iterator ctor.
    // function pointer as Compare
    // {
    //     int myints[] = {12, 82, 37, 64, 15};
    //     ft::set<int> first(myints, myints + 5); // set with 5 ints
    //     ft::set<int> second;                    // empty set

    //     second = first;          // now second contains the 5 ints
    //     first = ft::set<int>(); // and first is empty

    //     std::cout << "Size of first: " << int(first.size()) << '\n';
    //     std::cout << "Size of second: " << int(second.size()) << '\n';
    //     return 0;
    // }
    // int myints[] = {75, 23, 65, 42, 13};
    // ft::set<int> myset(myints, myints + 5);

    // std::cout << "myset contains:";
    // for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    //     std::cout << ' ' << *it;

    // std::cout << '\n';
    // int myints[] = {21, 64, 17, 78, 49};
    // ft::set<int> myset(myints, myints + 5);

    // ft::set<int>::reverse_iterator rit;

    // std::cout << "myset contains:";
    // for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
    //     std::cout << ' ' << *rit;

    // std::cout << '\n';
    // ft::set<int> myset;

    // myset.insert(20);
    // myset.insert(30);
    // myset.insert(10);

    // std::cout << "myset contains:";
    // while (!myset.empty())
    // {
    //     std::cout << ' ' << *myset.begin();
    //     myset.erase(myset.begin());
    // }
    // std::cout << '\n';
    // ft::set<int> myints;
    // std::cout << "0. size: " << myints.size() << '\n';

    // for (int i = 0; i < 10; ++i)
    //     myints.insert(i);
    // std::cout << "1. size: " << myints.size() << '\n';

    // myints.insert(100);
    // std::cout << "2. size: " << myints.size() << '\n';

    // myints.erase(2);
    // myints.clear();
    // std::cout << "3. size: " << myints.size() << '\n';
    // for (ft::set<int>::iterator it = myints.begin(); it != myints.end(); it++)
    // {
    //     std::cout << "--> " << *it << std::endl;
    // }
    // mymaeints.insert(i);
    // int myints[] = {12, 75, 10, 32, 20, 25};
    // ft::set<int> first(myints, myints + 3);      // 10,12,75
    // ft::set<int> second(myints + 3, myints + 6); // 20,25,32

    // first.swap(second);

    // std::cout << "first contains:";
    // for (ft::set<int>::iterator it = first.begin(); it != first.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // std::cout << "second contains:";
    // for (ft::set<int>::iterator it = second.begin(); it != second.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // ft::set<int> myset;
    // int highest;

    // ft::set<int>::key_compare mycomp = myset.key_comp();

    // for (int i = 0; i <= 5; i++)
    //     myset.insert(i);

    // std::cout << "myset contains:";

    // highest = *myset.rbegin();
    // ft::set<int>::iterator it = myset.begin();
    // do
    // {
    //     std::cout << ' ' << *it;
    // } while (mycomp(*(++it), highest));

    // std::cout << '\n';
    // ft::set<int> myset;

    // ft::set<int>::value_compare mycomp = myset.value_comp();

    // for (int i = 0; i <= 5; i++)
    //     myset.insert(i);

    // std::cout << "myset contains:";

    // int highest = *myset.rbegin();
    // ft::set<int>::iterator it = myset.begin();
    // do
    // {
    //     std::cout << ' ' << *it;
    // } while (mycomp(*(++it), highest));

    // std::cout << '\n';
    //     ft::set<int> myset;
    //     ft::set<int>::iterator it;

    //     // set some initial values:
    //     for (int i = 1; i <= 5; i++)
    //         myset.insert(i * 10); // set: 10 20 30 40 50

    //     it = myset.find(20);
    //     myset.erase(it);
    //     myset.erase(myset.find(40));

    //     std::cout << "myset contains:";
    //     for (it = myset.begin(); it != myset.end(); ++it)
    //         std::cout << ' ' << *it;
    //     std::cout << '\n';
    // ft::set<int> myset;

    // // set some initial values:
    // for (int i = 1; i < 5; ++i)
    //     myset.insert(i * 3); // set: 3 6 9 12

    // for (int i = 0; i < 10; ++i)
    // {
    //     std::cout << i;
    //     if (myset.count(i) != 0)
    //         std::cout << " is an element of myset.\n";
    //     else
    //         std::cout << " is not an element of myset.\n";
    // }
    // ft::set<int> myset;
    // ft::set<int>::iterator itlow, itup;

    // for (int i = 1; i < 10; i++)
    //     myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    // itlow = myset.lower_bound(30); //       ^
    // itup = myset.upper_bound(60);  //                   ^

    // myset.erase(itlow, itup); // 10 20 70 80 90

    // std::cout << "myset contains:";
    // for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // ft::set<int> myset;
    // ft::set<int>::iterator itlow, itup;

    // for (int i = 1; i < 10; i++)
    //     myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    // itlow = myset.lower_bound(30); //       ^
    // itup = myset.upper_bound(60);  //                   ^

    // myset.erase(itlow, itup); // 10 20 70 80 90

    // std::cout << "myset contains:";
    // for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // ft::set<int> myset;

    // for (int i = 1; i <= 5; i++)
    //     myset.insert(i * 10); // myset: 10 20 30 40 50

    // ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ret;
    // ret = myset.equal_range(30);

    // std::cout << "the lower bound points to: " << *ret.first << '\n';
    // std::cout << "the upper bound points to: " << *ret.second << '\n';
    ft::set<int> myset;
    int *p;
    unsigned int i;

    // allocate an array of 5 elements using myset's allocator:
    p = myset.get_allocator().allocate(5);

    // assign some values to array
    for (i = 0; i < 5; i++)
        p[i] = (i + 1) * 10;

    std::cout << "The allocated array contains:";
    for (i = 0; i < 5; i++)
        std::cout << ' ' << p[i];
    std::cout << '\n';

    myset.get_allocator().deallocate(p, 5);
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

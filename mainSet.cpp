/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSet.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:00:58 by amine             #+#    #+#             */
/*   Updated: 2021/12/26 15:37:06 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set/set.hpp"
#include <set>

int main()
{
    std::cout << "=======================================" << std::endl;
    ft::set<int> myset;
    ft::set<int> first; // empty set of ints

    int myints[] = {10, 20, 30, 40, 50};
    ft::set<int> second(myints, myints + 5); // range

    ft::set<int> third(second); // a copy of second

    ft::set<int> fourth(second.begin(), second.end()); // iterator ctor.
    // function pointer as Compare
    {
        int myints[] = {12, 82, 37, 64, 15};
        ft::set<int> first(myints, myints + 5); // set with 5 ints
        ft::set<int> second;                    // empty set

        second = first;         // now second contains the 5 ints
        first = ft::set<int>(); // and first is empty

        std::cout << "Size of first: " << int(first.size()) << '\n';
        std::cout << "Size of second: " << int(second.size()) << '\n';
    }
    std::cout << "=======================================" << std::endl;
    // iterator
    {
        std::cout << "==================== iterator tests ================ " << std::endl;
        int myints[] = {75, 23, 65, 42, 13};
        ft::set<int> myset(myints, myints + 5);

        std::cout << "myset contains:";
        for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;
    //reverse iterator
    {
        std::cout << "========= reverse iterator tests ========== " << std::endl;
        int myints[] = {21, 64, 17, 78, 49};
        ft::set<int> myset(myints, myints + 5);

        ft::set<int>::reverse_iterator rit;

        std::cout << "myset contains:";
        for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
            std::cout << ' ' << *rit;

        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;

    // empty
    {
        std::cout << "=============== empty test ============ " << std::endl;
        ft::set<int> myset;

        myset.insert(20);
        myset.insert(30);
        myset.insert(10);

        std::cout << "myset contains:";
        while (!myset.empty())
        {
            std::cout << ' ' << *myset.begin();
            myset.erase(myset.begin());
        }
        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;
    // erase
    {
        std::cout << "================ erase =============" << std::endl;
        ft::set<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i = 0; i < 10; ++i)
            myints.insert(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert(100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.erase(2);
        std::cout << "3. size: " << myints.size() << '\n';
        for (ft::set<int>::iterator it = myints.begin(); it != myints.end(); it++)
        {
            std::cout << "--> " << *it << std::endl;
        }
        // myints.insert(i);
    }
    std::cout << "=======================================" << std::endl;
    // swap
    {
        std::cout << "================ test swap =============" << std::endl;
        int myints[] = {12, 75, 10, 32, 20, 25};
        ft::set<int> first(myints, myints + 3);      // 10,12,75
        ft::set<int> second(myints + 3, myints + 6); // 20,25,32

        first.swap(second);

        std::cout << "first contains:";
        for (ft::set<int>::iterator it = first.begin(); it != first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "second contains:";
        for (ft::set<int>::iterator it = second.begin(); it != second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;

    // key comp
    {
        std::cout << "============= key comp ==========" << std::endl;
        ft::set<int> myset;
        int highest;

        ft::set<int>::key_compare mycomp = myset.key_comp();

        for (int i = 0; i <= 5; i++)
            myset.insert(i);

        std::cout << "myset contains:";

        highest = *myset.rbegin();
        ft::set<int>::iterator it = myset.begin();
        do
        {
            std::cout << ' ' << *it;
        } while (mycomp(*(++it), highest));

        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;
    // value compare
    {
        std::cout << "============ valiue compare =========== " << std::endl;
        ft::set<int> myset;

        ft::set<int>::value_compare mycomp = myset.value_comp();

        for (int i = 0; i <= 5; i++)
            myset.insert(i);

        std::cout << "myset contains:";

        int highest = *myset.rbegin();
        ft::set<int>::iterator it = myset.begin();
        do
        {
            std::cout << ' ' << *it;
        } while (mycomp(*(++it), highest));

        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;
    // find
    {
        std::cout << "========== find test ===========" << std::endl;
        ft::set<int> myset;
        ft::set<int>::iterator it;

        // set some initial values:
        for (int i = 1; i <= 5; i++)
            myset.insert(i * 10); // set: 10 20 30 40 50

        it = myset.find(20);
        myset.erase(it);
        myset.erase(myset.find(40));

        std::cout << "myset contains:";
        for (it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    std::cout << "=======================================" << std::endl;
    // count
    {
        std::cout << "============ count test ============== " << std::endl;
        ft::set<int> myset;

        // set some initial values:
        for (int i = 1; i < 5; ++i)
            myset.insert(i * 3); // set: 3 6 9 12

        for (int i = 0; i < 10; ++i)
        {
            std::cout << i;
            if (myset.count(i) != 0)
                std::cout << " is an element of myset.\n";
            else
                std::cout << " is not an element of myset.\n";
        }
    }
    std::cout << "============================================ " << std::endl;

    // lower  upper bound
    {
        std::cout << "=============== lower and upper bound test ================ " << std::endl;

        ft::set<int> myset;
        ft::set<int>::iterator itlow, itup;

        for (int i = 1; i < 10; i++)
            myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

        itlow = myset.lower_bound(30); //       ^
        itup = myset.upper_bound(60);  //                   ^

        myset.erase(itlow, itup); // 10 20 70 80 90

        std::cout << "myset contains:";
        for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    std::cout << "============================================ " << std::endl;

    // equal range
    {
        std::cout << "======== equal range test ============== " << std::endl;
        ft::set<int> myset;

        for (int i = 1; i <= 5; i++)
            myset.insert(i * 10); // myset: 10 20 30 40 50

        ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ret;
        ret = myset.equal_range(30);

        std::cout << "the lower bound points to: " << *ret.first << '\n';
        std::cout << "the upper bound points to: " << *ret.second << '\n';
    }
    std::cout << "============================================ " << std::endl;

    // get_Allocator
    {

        std::cout << "get_Allocator test " << std::endl;
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
    std::cout << "======== end of stack tests ============== " << std::endl;
}
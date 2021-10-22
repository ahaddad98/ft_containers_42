/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:40:06 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/22 14:24:14 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <iostream>
#include <iterator>     // std::iterator, std::input_iterator_tag
#include "iterator_traits.hpp"


template <typename T>
class Iterator : public ft::Iterator_Traits<std::input_iterator_tag, T>
{
public:
    typedef typename ft::Iterator_Traits<std::input_iterator_tag, T>::pointer pointer;

    Iterator(/* args */);
    ~Iterator();


private:
  pointer ptr;
};



// class MyIterator : public std::iterator<std::input_iterator_tag, int>
// {
//   int* p;
// public:
//   MyIterator(int* x) :p(x) {}
//   MyIterator(const MyIterator& mit) : p(mit.p) {}
//   MyIterator& operator++() {++p;return *this;}
//   MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
//   bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
//   bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
//   int& operator*() {return *p;}
// };


#endif
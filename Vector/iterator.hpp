/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:40:06 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/28 16:10:04 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include <iterator>
#include "iterator_traits.hpp"

namespace ft
{
    // typedef int size_type;

    // template <typename T>
    // class iterator
    // {
    // public:
    //     typedef iterator self_type;
    //     typedef T value_type;
    //     typedef T &reference;
    //     typedef T *pointer;
    //     typedef std::forward_iterator_tag iterator_category;
    //     typedef int difference_type;
    //     iterator(pointer ptr) : ptr_(ptr) {}
    //     self_type operator++()
    //     {
    //         self_type i = *this;
    //         ptr_++;
    //         return i;
    //     }
    //     self_type operator++(int junk)
    //     {
    //         ptr_++;
    //         return *this;
    //     }
    //     reference operator*() { return *ptr_; }
    //     pointer operator->() { return ptr_; }
    //     bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
    //     bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

    // private:
    //     pointer ptr_;
    // };
    // template <typename T>
    // class const_iterator
    // {
    // public:
    //     typedef const_iterator self_type;
    //     typedef T value_type;
    //     typedef T &reference;
    //     typedef T *pointer;
    //     typedef int difference_type;
    //     typedef std::forward_iterator_tag iterator_category;
    //     const_iterator(pointer ptr) : ptr_(ptr) {}
    //     self_type operator++()
    //     {
    //         self_type i = *this;
    //         ptr_++;
    //         return i;
    //     }
    //     self_type operator++(int junk)
    //     {
    //         ptr_++;
    //         return *this;
    //     }
    //     // const reference operator*() { return *ptr_; }
    //     const pointer operator->() { return ptr_; }
    //     bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
    //     bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

    // private:
    //     pointer ptr_;
    // };
}

// template <typename T>
// class Iterator : public ft::Iterator_Traits<std::input_iterator_tag, T>
// {
// public:
//     typedef typename ft::Iterator_Traits<std::input_iterator_tag, T>::pointer pointer;

//     Iterator(/* args */);
//     ~Iterator();

// private:
//   pointer ptr;
// };

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
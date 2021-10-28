/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:45:39 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/28 16:12:01 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
// #include <iostream>
#include <cassert>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "iterator.hpp"
#include "iterator_traits.hpp"

class iterator;

namespace ft
{
    template <typename T>
    class vector
    {
    public:
        typedef int size_type;

        class iterator
        {
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T &reference;
            typedef T *pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(pointer ptr) : ptr_(ptr) {}
            self_type operator++()
            {
                self_type i = *this;
                ptr_++;
                return i;
            }
            self_type operator++(int junk)
            {
                ptr_++;
                return *this;
            }
            reference operator*() { return *ptr_; }
            pointer operator->() { return ptr_; }
            bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

        private:
            pointer ptr_;
        };

        class const_iterator
        {
        public:
            typedef const_iterator self_type;
            typedef T value_type;
            typedef T &reference;
            typedef T *pointer;
            typedef int difference_type;
            typedef std::forward_iterator_tag iterator_category;
            const_iterator(pointer ptr) : ptr_(ptr) {}
            self_type operator++()
            {
                self_type i = *this;
                ptr_++;
                return i;
            }
            self_type operator++(int junk)
            {
                ptr_++;
                return *this;
            }
            const reference operator*() { return *ptr_; }
            const pointer operator->() { return ptr_; }
            bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

        private:
            pointer ptr_;
        };

        vector(size_type size) : size_(size)
        {
            data_ = new T[size_];
        }

        size_type size() const { return size_; }

        T &operator[](size_type index)
        {
            assert(index < size_);
            return data_[index];
        }

        const T &operator[](size_type index) const
        {
            assert(index < size_);
            return data_[index];
        }

        iterator begin()
        {
            return iterator(data_);
        }

        iterator end()
        {
            return iterator(data_ + size_);
        }

        const_iterator begin() const
        {
            return const_iterator(data_);
        }

        const_iterator end() const
        {
            return const_iterator(data_ + size_);
        }

    private:
        T *data_;
        size_type size_;
    };
    // template <typename T>
    // class vector
    // {
    // public:
    //     typedef const_iterator self_type;
    //     typedef T value_type;
    //     typedef T &reference;
    //     typedef T *pointer;
    //     typedef int difference_type;
    //     typedef std::forward_iterator_tag iterator_category;
    //     typedef int size_type;
    //     // typedef iterator<value_type>                 iterator;
    //     vector(size_type size) : size_(size)
    //     {
    //         data_ = new T[size_];
    //     }

    //     size_type size() const { return size_; }

    //     T &operator[](size_type index)
    //     {
    //         assert(index < size_);
    //         return data_[index];
    //     }

    //     const T &operator[](size_type index) const
    //     {
    //         assert(index < size_);
    //         return data_[index];
    //     }

    // iterator begin()
    // {
    //     return iterator(data_);
    // }

    // iterator end()
    // {
    //     return iterator(data_ + size_);
    // }

    // const_iterator begin() const
    // {
    //     return const_iterator(data_);
    // }

    // const_iterator end() const
    // {
    //     return const_iterator(data_ + size_);
    // }
}
#endif
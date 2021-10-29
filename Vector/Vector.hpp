/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:45:39 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/29 19:27:33 by amine            ###   ########.fr       */
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
        // create our iterator
        class iterator  : public ft::Iterator_Traits<std::random_access_iterator_tag, T>
        {
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T &reference;
            typedef T *pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(pointer ptr) : ptr_(ptr)
            {
            }
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
            reference operator*()
            {
                return *ptr_;
            }
            pointer operator->()
            {
                return ptr_;
            }
            bool operator==(const self_type &rhs)
            {
                return ptr_ == rhs.ptr_;
            }
            bool operator!=(const self_type &rhs)
            {
                return ptr_ != rhs.ptr_;
            }

        private:
            pointer ptr_;
        };
        // create our const iterator
        class const_iterator : public ft::Iterator_Traits<std::random_access_iterator_tag, T>
        {
        public:
            typedef const_iterator self_type;
            typedef T value_type;
            typedef T &reference;
            typedef T *pointer;
            typedef int difference_type;
            typedef std::forward_iterator_tag iterator_category;
            const_iterator(pointer ptr) : ptr_(ptr)
            {
            }
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
            const value_type &operator*()
            {
                return *ptr_;
            }
            const pointer operator->()
            {
                return ptr_;
            }
            bool operator==(const self_type &rhs)
            {
                return ptr_ == rhs.ptr_;
            }
            bool operator!=(const self_type &rhs)
            {
                return ptr_ != rhs.ptr_;
            }

        private:
            pointer ptr_;
        };
        // constructors
        vector(size_type size) : size_(size)
        {
            m_Data = new T[size_];
        }

        // Capacity:
        size_type size() const
        {
            return size_;
        }
        size_type max_size() const
        {
            // pas encore
            return 0;
        }
        // void resize (size_type n, value_type val = value_type())
        // {
        // }
        //
        size_type capacity() const
        {
            // pas encore
            return 0;
        }
        bool empty() const
        {
            // pas encore
        }
        void reserve(size_type n)
        {
            // pas encore
        }

        // Element access:
        T &operator[](size_type index)
        {
            assert(index < size_);
            return m_Data[index];
        }
        const T &operator[](size_type index) const
        {
            assert(index < size_);
            return m_Data[index];
        }
        // reference at (size_type n)
        // {
        //     // pas encore
        // }
        // const_reference at (size_type n) const
        // {
        //     // pas encore
        // }
        // reference front()
        // {
        //     // pas encore
        // }
        // const_reference front() const
        // {
        //     // pas encore
        // }
        // reference back()
        // {
        //     //  pas encore
        // }
        // const_reference back() const
        // {
        //     //  pas encore
        // }

        // Iterators:
        iterator begin()
        {
            return iterator(m_Data);
        }

        iterator end()
        {
            return iterator(m_Data + size_);
        }

        const_iterator begin() const
        {
            return const_iterator(m_Data);
        }

        const_iterator end() const
        {
            return const_iterator(m_Data + size_);
        }
        //reverse_iterator rbegin()
        // {
        // }
        //const_reverse_iterator rbegin() const
        // {
        // }

        // Modifiers:
        // template <class InputIterator>
        // void assign (InputIterator first, InputIterator last)
        // {
        // }
        // void assign (size_type n, const value_type& val)
        // {
        // }
        // void push_back (const value_type& val)
        // {
        // }
        // void pop_back()
        // {
        // }
        // iterator insert (iterator position, const value_type& val);
        // void insert (iterator position, size_type n, const value_type& val);
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last);
        // iterator erase(iterator position);
        // iterator erase(iterator first, iterator last);
        // void swap (vector& x)
        // void clear();

        // allocators
        // allocator_type get_allocator() const

        // Non-member function overloads
        // template <class T, class Alloc>
        // bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

        // template <class T, class Alloc>
        // bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

        // template <class T, class Alloc>
        // bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

        // template <class T, class Alloc>
        // bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

        // template <class T, class Alloc>
        // bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

        // template <class T, class Alloc>
        // bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

        // template <class T, class Alloc>
        // void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)

        // Template specializations
        // template <class T, class Alloc = allocator<T>>
        // class vector; // generic template
        // template <class Alloc>
        // class vector<bool, Alloc>; // bool specialization
    private:
        T *m_Data;
        size_type size_;
    };
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:45:39 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/05 15:22:04 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cassert>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "iterator.hpp"
#include "iterator_traits.hpp"

class iterator;

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef int size_type;
        typedef ::iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
        typedef Alloc alloc_type;
        // call of iterator class

        typedef ft::iterator<value_type> iterator;
        typedef ft::const_iterator<value_type> const_iterator;
        typedef ft::reverse_iterat<value_type> reverse_iterator;
        typedef ft::const_reverse_iterat<value_type> const_reverse_iterator;

        // constructors
            // empty container constructor (default constructor)
        explicit vector (const alloc_type& alloc = alloc_type()) : size_(0), capacity_(0)
        {
        }
            // (2) fill constructor
        explicit vector (size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type())
        {
        }
            // (3) range constructor
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const alloc_type& alloc = alloc_type())
        {
        }
        vector (const vector& x)
        {   
        }
        // destructor
        ~vector()
        {
            if (size_ > 0)
                this->alloc.deallocate(m_Data, size_);
        }

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
            return cosnt_iterator(m_Data + size_);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(m_Data + size_ - 1);
        }
        reverse_iterator rend()
        {
            return reverse_iterator(m_Data - 1);
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(m_Data + size_ - 1);
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(m_Data - 1);
        }
        
        // Capacity:
        size_type size() const
        {
            return size_;
        }
        size_type max_size() const
        {
            return this->alloc.maxsize();
        }
        void resize (size_type n, value_type val = value_type())
        {
            if (n > size_)
            {
                size_type tmp_size = size_;
                pointer tmp = this->alloc.allocate(n);
                size_type i = 0;

                while (i < tmp_size)
                {
                    tmp[i] = m_Data[i];
                    i++;
                }
                while (tmp_size < n)
                {
                    tmp[tmp_size] = val;
                    tmp_size++;
                }
                this->alloc.destroy(this->m_Data);
                this->alloc.deallocate(this->m_Data, this->capacity_);
                this->m_Data = tmp;
                size_ = n;
                this->capacity_ = n;
            }
            else
            {
                size_ = n;
            }
        }
        //
        size_type capacity() const
        {
            return capacity_;
        }
        bool empty() const
        {
            return (this->size_ == 0);
        }
        void reserve(size_type n)
        {
            if (n > this->capacity_)
            {
                pointer tmp = this->alloc.allocate(n);
                size_type i = 0;

                while (i < this->size_)
                {
                    this->alloc.construct(&(tmp[i]), this->m_Data[i]);
                    i++;
                }
                this->alloc.destroy(this->m_Data);
                this->alloc.deallocate(this->m_Data, this->capacity_);
                this->m_Data = tmp;
                this->capacity_ = n;
            }
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
        reference at (size_type n)
        {
            return m_Data[n];
        }
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


        // Modifiers:
        // template <class InputIterator>
        // void assign (InputIterator first, InputIterator last)
        // {
        // }
        // void assign (size_type n, const value_type& val)
        // {
        // }
        void push_back(const value_type &val)
        {
            // insert(end(), val);
            (void)val;
            if (this->size_ >= this->capacity_)
                my_realloc();
            this->alloc.construct(&(this->m_Data[this->size_]), val);
            this->size_ = this->size_ + 1;
        }
        void pop_back()
        {
        }
        iterator insert(iterator position, const value_type &val)
        {
            if (size_ == 0)
            {
                capacity_ = 1;
                m_Data = this->alloc.allocate(capacity_);
                m_Data[size_] = val;
                size_ += 1;
            }
            else if (size_ == capacity_)
            {
                capacity_ = capacity_ * 2;
                T *m_Data1 = this->alloc.allocate(capacity_);
                int i = 0;
                int tmp_size = size_;
                    for (iterator it = begin(); it != end(); it++)
                    {
                        if (position == begin())
                        {
                            std::cout << "im here" << std::endl;
                            m_Data1[i] = val;
                            i++;
                        }
                        m_Data1[i] = *it;
                        i++;
                    }
                    for (int j = 0; j < size_; j++)
                    {
                        this->alloc.destroy(m_Data + j);
                    }
                    this->alloc.deallocate(m_Data, size_);
                    size_++;
                    m_Data = m_Data1;
            }
            else
            {
                T *m_Data1 = this->alloc.allocate(capacity_);
                int i = 0;
                    i = 0;
                    for (iterator it = begin(); it != end(); it++)
                    {
                        if (position == it)
                        {
                            m_Data1[i] = val;
                            i++;
                        }
                        m_Data1[i] = *it;
                        i++;
                    }
                    for (int j = 0; j < size_; j++)
                    {
                        this->alloc.destroy(m_Data + j);
                    }
                    this->alloc.deallocate(m_Data, size_);
                    size_++;
                    m_Data = m_Data1;
            }
            return begin();
        }
        // fill
        void insert(iterator position, size_type n, const value_type &val)
        {
            int i = 0;
            iterator position_tmp = position;
            while (i < n)
            {
                // std::cout << "====================" << std::endl;
                // if (position == begin())
                // std::cout << "==>" << val << std::endl;
                insert(position, val);
                position++;
                i++;
            }
        }
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last)
        // {
        // }
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
        // class vector<bool, Alloc>; // bool specialization\

        // utils
        void my_realloc()
        {
            if (this->empty())
            {
                this->m_Data = this->alloc.allocate(1);
                this->capacity_ = 1;
                return;
            }
            this->reserve(this->capacity_ * 2);
        }

    private:
        T *m_Data;
        size_type size_;
        alloc_type alloc;

    public:
        size_type capacity_;
        // getters
        // size_type Capac()
        // {
        //     return capacity_;
        // }
    };
    }
#endif
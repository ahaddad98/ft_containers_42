/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:45:39 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/26 19:54:30 by amine            ###   ########.fr       */
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
#include "enable_if.hpp"

class iterator;

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
    class vector
    {
    public:
        typedef size_t size_type;
        typedef ::iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T &const_reference;
        typedef T *pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef Alloc alloc_type;
        // call of iterator class

        typedef ft::iterator<value_type> iterator;
        typedef ft::iterator<value_type> const_iterator;
        typedef ft::reverse_iterat<value_type> reverse_iterator;
        typedef ft::reverse_iterat<value_type> const_reverse_iterator;

        // constructors
        // empty container constructor (default constructor)
        explicit vector(const alloc_type &alloc = alloc_type()) : size_(0), capacity_(0)
        {
            this->alloc = alloc;
        }
        // (2) fill constructor
        explicit vector(size_type n, const value_type &val = value_type(), const alloc_type &alloc = alloc_type()) : size_(0), capacity_(0)
        {
            this->alloc = alloc;
            this->assign(n, val);
        }
        // (3) range constructor
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const alloc_type &alloc = alloc_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0)
        {
            capacity_ = 0;
            size_ = 0;
            this->alloc = alloc;
            for (InputIterator it = first; it != last; it++)
            {
                this->push_back(*it);
            }
        }
        vector(const vector &x)
        {
            *this = x;
        }
        vector &operator=(const vector &src)
        {
            if (src.size() > 0)
            {
                capacity_ = 0;
                if (capacity_ > 0)
                    this->alloc.deallocate(m_Data, capacity_);
                size_ = 0;
                capacity_ = 0;
                size_t i = 0;
                while (i < src.size())
                {
                    this->push_back(src[i]);
                    i++;
                }
            }
            return *this;
        }
        // destructor
        ~vector()
        {
            if (capacity_ > 0)
                this->alloc.deallocate(m_Data, capacity_);
        }

        // Iterators:
        iterator begin()
        {
            return iterator(m_Data);
        }
        const_iterator begin() const
        {
            return const_iterator(m_Data);
        }

        iterator end()
        {
            return iterator(m_Data + size_);
        }

        const_iterator end() const
        {
            return const_iterator(m_Data + size_);
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
            return this->alloc.max_size();
        }
        void resize(size_type n, value_type val = value_type())
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
                if (capacity_ <= n)
                    this->capacity_ *= 2;
            }
            else
                size_ = n;
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
                if (capacity_ > 0)
                    this->alloc.deallocate(this->m_Data, this->capacity_);
                this->m_Data = tmp;
                if (capacity_ <= n)
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
        reference at(size_type n)
        {
            return m_Data[n];
        }
        const_reference at(size_type n) const
        {
            return m_Data[n];
        }
        reference front()
        {
            return m_Data[0];
        }
        const_reference front() const
        {
            return m_Data[0];
        }
        reference back()
        {
            return m_Data[size_ - 1];
        }
        const_reference back() const
        {
            return m_Data[size_ - 1];
        }

        // Modifiers:
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0)
        {
            InputIterator it = first;
            size_t i = 0;
            while (it != last)
            {
                it++;
                i++;
            }
            it = first;
            assign(i, i);
            if (i > capacity_)
            {
                reserve(i);
                size_t j = 0;
                while (it != last)
                {
                    m_Data[j] = *it;
                    it++;
                    j++;
                }
                size_ = i;
                capacity_ *= 2;
            }
            else
            {
                size_ = i;
                size_t j = 0;
                while (it != last)
                {
                    m_Data[j] = *it;
                    it++;
                    j++;
                }
            }
        }

        void assign(size_type n, const value_type &val)
        {
            if (n > capacity_)
            {
                reserve(n);
                size_t i = 0;
                while (i < n)
                {
                    m_Data[i] = val;
                    i++;
                }
                size_ = n;
                capacity_ = n;
            }
            else
            {
                size_ = n;
                size_t i = 0;
                while (i < n)
                {
                    m_Data[i] = val;
                    i++;
                }
            }
        }
        void push_back(const value_type &val)
        {
            // (void)val;
            if (this->size_ >= this->capacity_)
                my_realloc();
            this->alloc.construct(&(this->m_Data[this->size_]), val);
            this->size_ = this->size_ + 1;
        }
        void pop_back()
        {
            if (this->size_ > 0)
                this->alloc.destroy(&(this->m_Data[this->size_ - 1]));
            this->size_ = this->size_ - 1;
        }
        iterator insert(iterator position, const value_type &val)
        {
            iterator it_begin = position;
            iterator it_end = this->end();
            value_type value = val;
            value_type next_value;

            iterator it = position;
            size_t i = 0;
            while (i < this->size() && &(*it) != &(this->m_Data[i]))
                i++;
            while (it_begin != it_end)
            {
                next_value = *it_begin;
                *it_begin = value;
                value = next_value;
                it_begin++;
            }
            this->push_back(value);
            return iterator(this->m_Data, i);
        }
        // fill
        void insert(iterator position, size_type n, const value_type &val)
        {
            size_type i = 0;
            while (i < this->size() && &(*position) != &(this->m_Data[i]))
                i++;
            if (this->capacity() < this->size() + n)
            {
                if (this->size() * 2 >= this->size() + n)
                    this->reserve(this->size() * 2);
                else
                    this->reserve(this->size() + n);
            }
            position = iterator(this->m_Data, i);
            i = 0;
            while (i < n)
            {
                position = this->insert(position, val);
                position++;
                i++;
            }
            i++;
        }
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0)
        {
            size_type i = 0;
            while (i < this->size() && &(*position) != &(this->m_Data[i]))
                i++;
            if (this->capacity() < this->size() + (last - first))
            {
                if (this->size() * 2 >= this->size() + (last - first))
                    this->reserve(this->size() * 2);
                else
                    this->reserve(this->size() + (last - first));
            }
            position = iterator(this->m_Data, i);
            while (first != last)
            {
                position = this->insert(position, *first);
                position++;
                first++;
            }
        }
        iterator erase(iterator position)
        {
            size_t j = 0;
            if (capacity_ > 0)
            {
                size_t i = 0;
                for (iterator it = begin(); it != end(); it++)
                {
                    if (position == it)
                        break;
                    i++;
                }
                j = i;
                while (i < size_)
                {
                    if ((i + 1) < size_)
                        m_Data[i] = m_Data[i + 1];
                    i++;
                }
                size_ -= 1;
            }
            return begin() + j;
        }
        iterator erase(iterator first, iterator last)
        {
            iterator it = begin();
            size_t i = 0;
            size_t j = 0;
            for (it = begin(); it != end() + 1; it++)
            {
                if (it >= first && it < last)
                {
                    j++;
                }
                else
                {
                    m_Data[i] = *it;
                    i++;
                }
            }
            size_ -= j;
            return last;
        }
        void swap(vector &x)
        {
            T *m_Data1 = x.m_Data;
            size_type size1 = x.size_;
            size_type capacity1 = x.capacity_;

            x.m_Data = this->m_Data;
            x.capacity_ = this->capacity_;
            x.size_ = this->size_;

            this->m_Data = m_Data1;
            this->size_ = size1;
            this->capacity_ = capacity1;
        }
        void clear()
        {
            this->erase(begin(), end());
        }

        //allocators
        alloc_type get_allocator() const
        {
            return this->alloc;
        }

        // utils
        void my_realloc()
        {
            if (this->empty())
            {
                this->m_Data = this->alloc.allocate(1);
                this->capacity_ = 1;
                return;
            }
            else
                this->reserve(this->capacity_ * 2);
        }

    private:
        T *m_Data;
        size_type size_;
        alloc_type alloc;

    public:
        size_type capacity_;
    };
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2)) // or: if (!pred(*first1,*first2)), for version 2
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(equal(lhs.begin(), lhs.end(), rhs.begin())));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())));
    }

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }

}
#endif
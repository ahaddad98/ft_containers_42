/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:40:06 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/11 18:27:08 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
    typedef int size_type;

    template <typename T>
    class iterator : public ft::Iterator_Traits<std::random_access_iterator_tag, T>
    {
    public:
        typedef iterator self_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::iterator_categorie iterator_category;

        iterator(pointer ptr) : ptr_(ptr)
        {
        }
        iterator(const iterator &it)
        {
            *this = it;
        }
        // iterator(pointer p, int crement = 0)
        // {
        //     this->ptr_ = p;
        //     this->size_ = crement;
        // }
        ~iterator()
        {
        }
        self_type operator++()
        {
            self_type i = *this;
            ptr_++;
            return i;
        }
        self_type operator--()
        {
            self_type i = *this;
            ptr_--;
            return i;
        }
        self_type operator+(int i)
        {
            ptr_ += i;
            return *this;
        }
        self_type operator-(int i)
        {
            ptr_ -= i;
            return *this;
        }
        self_type operator++(int junk)
        {
            ptr_++;
            return *this;
        }
        self_type operator--(int junk)
        {
            ptr_--;
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
        bool operator>=(const self_type &rhs)
        {
            return (ptr_ >= rhs.ptr_);
        }
        bool operator<=(const self_type &rhs)
        {
            return (ptr_ <= rhs.ptr_);
        }
        bool operator>(const self_type &rhs)
        {
            return (ptr_ > rhs.ptr_);
        }
        bool operator<(const self_type &rhs)
        {
            return (ptr_ < rhs.ptr_);
        }

    private:
        pointer ptr_;
        size_t size_;
    };
    template <typename T>
    class const_iterator : public ft::Iterator_Traits<std::random_access_iterator_tag, T>
    {
    public:
        typedef const_iterator self_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::iterator_categorie iterator_category;
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
        reference operator*()
        {
            // std::cout << "amine123" << std::endl;
            return *ptr_;
        }
        // const reference operator*() { return *ptr_; }
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
        size_t size_;
    };
    template <typename T>
    class reverse_iterat : public ft::Iterator_Traits<std::random_access_iterator_tag, T>
    {
    public:
        typedef reverse_iterat self_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::iterator_categorie iterator_category;
        reverse_iterat(pointer ptr) : ptr_(ptr)
        {
        }
        self_type operator++()
        {
            self_type i = *this;
            ptr_--;
            return i;
        }
        self_type operator++(int junk)
        {
            ptr_--;
            return *this;
        }
        reference operator*()
        {
            return *ptr_;
        }
        // const reference operator*() { return *ptr_; }
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
    template <typename T>
    class const_reverse_iterat : public ft::Iterator_Traits<std::random_access_iterator_tag, T>
    {
    public:
        typedef const_reverse_iterat self_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::random_access_iterator_tag, T>::iterator_categorie iterator_category;
        const_reverse_iterat(pointer ptr) : ptr_(ptr)
        {
        }
        self_type operator++()
        {
            self_type i = *this;
            ptr_--;
            return i;
        }
        self_type operator++(int junk)
        {
            ptr_--;
            return *this;
        }
        reference operator*()
        {
            return *ptr_;
        }
        // const reference operator*() { return *ptr_; }
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
        self_type base() const
        {
            return *this;
        }

    private:
        pointer ptr_;
    };
}

#endif
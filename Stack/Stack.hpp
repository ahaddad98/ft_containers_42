/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:44:29 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/14 20:27:11 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <cassert>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <deque>
namespace ft
{
    template <class T, class Container = std::deque<T> >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
        // constructors
        
        explicit stack (const container_type& ctnr = container_type())
        {
            
        }
    
        // destructor
        ~stack()
        {
            
        }
        // Member functions
        bool empty() const
        {
            
        }
        size_type size() const
        {

        }
        value_type& top()
        {
            
        }
        const value_type& top() const
        {
            
        }
        void push (const value_type& val)
        {
            
        }
        void pop()
        {

        }
        
    private:
        
    };
    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {

    }
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {

    }
    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {

    }
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        
    }
    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {

    }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        
    }
    
}


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:44:29 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/15 21:01:43 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <cassert>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <deque>
#include "../Vector/Vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
        // constructors
        
        explicit stack (const container_type& ctnr = container_type())
        {
            stk = ctnr;
        }
    
        // destructor
        ~stack()
        {
            // stk.~();   
        }
        // Member functions
        bool empty() const
        {
            return (stk.size() == 0);
        }
        size_type size() const
        {
            return stk.size();
        }
        value_type& top()
        {
        }
        const value_type& top() const
        {
            
        }
        void push (const value_type& val)
        {
            stk.push_back(val);
        }
        void pop()
        {
            stk.pop_back();
        }
        
    private:
        container_type stk;
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
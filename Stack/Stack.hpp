/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:44:29 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/15 22:18:31 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <cassert>
#include <iostream>
#include <string.h>
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
            // if (size() > 0)
            // {
            //     // stk.~vector();
            //     std::cout << "amine haddad" << std::endl;
            // }
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
            return stk[size()-1];
        }
        const value_type& top() const
        {
            return stk[size()-1];
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
        return (lhs == rhs);
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
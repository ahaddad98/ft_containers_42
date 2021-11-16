/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:44:29 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/16 18:41:00 by amine            ###   ########.fr       */
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
        }
        
        // Member functions

        bool empty() const
        {
            return (stk.empty());
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
        return (lhs != rhs);   
    }
    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs < rhs);
    }
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs <= rhs);
    }
    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs > rhs);
    }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs >= rhs);        
    }
    
}


#endif
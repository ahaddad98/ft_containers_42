/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:21:05 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/13 22:07:08 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP
#include <iostream>


template <class T1, class T2>
// namespace ft
// {
    

    class pair
    {
        public:
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        
        pair() : first(first_type()) , second(second_type())
        {
        }
        template<class U, class V>
        pair (const pair<U,V>& pr)
        {
            this = pr;
        }
        pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
        }
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        }
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first==rhs.first && lhs.second==rhs.second;
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs==rhs); 
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(rhs<lhs); 
    }
    
    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return rhs<lhs; 
    }
    
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs<rhs); 
    }
    
// } // namespace ft
#endif
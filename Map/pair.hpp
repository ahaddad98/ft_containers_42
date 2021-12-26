/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:21:05 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/26 19:23:45 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP
#include <iostream>
#include <string>


namespace ft
{
    

    template <class T1, class T2>
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
        pair (const pair<U,V>& pr) : first(pr.first) , second(pr.second)
        {
        }
        pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
        }
        pair& operator= (const pair& pr)
        {
            new (this) pair<first_type, second_type>(pr);
            return *this;
        }
    };
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }
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
    
} // namespace ft
#endif
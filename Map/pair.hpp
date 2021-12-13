/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:21:05 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/13 20:00:49 by ahaddad          ###   ########.fr       */
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
        typedef T1 fisrt;
        typedef T2 second;
        pair()
        {
        }
        template<class U, class V>
        pair (const pair<U,V>& pr)
        {
        }
        pair (const fisrt& a, const second& b)
        {
        }
    };

// } // namespace ft
#endif
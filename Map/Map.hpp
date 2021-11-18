/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:40:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/17 21:26:55 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
           >

class Map
{
private:
    /* data */
public:
    typedef std::pair<const Key, T> value_type;
    Map(/* args */)
    {
        
    }
    ~Map()
    {
        
    }
};

#endif

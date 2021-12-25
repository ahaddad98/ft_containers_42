/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:17:44 by amine             #+#    #+#             */
/*   Updated: 2021/12/25 23:22:08 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include <iostream>

namespace ft
{
    template <class T,                   // set::key_type/value_type
              class Compare = std::less<T>,   // set::key_compare/value_compare
              class Alloc = std::allocator<T> // set::allocator_type
              >
    class set
    {
    private:
        /* data */
    public:
        set(/* args */)
        {
        }
        ~set()
        {
        }
    };
} // namespace ft

#endif
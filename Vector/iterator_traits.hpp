/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:32:14 by amine             #+#    #+#             */
/*   Updated: 2021/10/29 20:45:20 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
#include <cstddef>

namespace ft {

template <class Category, class T, class Distance = ptrdiff_t,
    class Pointer = T*, class Reference = T&>
class Iterator_Traits
{
private:
    /* data */
public:
    typedef Category iterator_categorie;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Distance difference_type;
    typedef T value_type;
};

}
#endif
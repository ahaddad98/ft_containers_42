/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/26 10:00:09 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "../Vector/iterator_traits.hpp"
namespace ft
{
    enum colors{red, black};
    template <typename T>
    class Red_Blacl_Tree
    {
    private:
        struct NODE
        {
            colors Color;
            NODE *left;
            NODE *right;
            NODE *parents;
            
        }
    public:
        Red_Blacl_Tree(/* args */)
        {
            
        }
        ~Red_Blacl_Tree()
        {
            
        }
    };
    template <typename T>
    class iterator : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
    {
    public:
        typedef iterator self_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

        iterator(/* args */)
        {
            
        }
        ~iterator()
        {
        }

    private:
        pointer ptr_;
    };
}
#endif

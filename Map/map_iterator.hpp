/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/28 19:40:06 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include <iostream>
#include "../Vector/iterator_traits.hpp"
namespace ft
{
    enum colors
    {
        red,
        black
    };

    template <typename T>
    class Red_Blacl_Tree
    {
    private:
        typedef struct s_Node
        {
            colors Color;
            s_Node *left;
            s_Node *right;
            s_Node *parents;
        } t_Node;

    public:
        Red_Blacl_Tree(/* args */)
        {
        }
        ~Red_Blacl_Tree()
        {
        }
        t_Node *min_of_tree()
        {
            t_Node *tmp;
            tmp = this;
            while (tmp->left)
                tmp = tmp->left;
            return tmp;
        }
        t_Node *max_of_tree()
        {
            t_Node *tmp;
            tmp = this;
            while (tmp->right)
                tmp = tmp->right;
            return tmp;
        }
        class iterator_map : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
        {
        public:
            typedef iterator_map self_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

            iterator_map() : ptr_(NULL)
            {
            }
            ~iterator_map()
            {
            }
            t_Node *root_prev() const
            {
                const t_Node *tmp1 = this->ptr_;
                if (ptr_->left)
                {
                    tmp1 = ptr_->left->max_of_tree();
                }
                else
                {
                    t_Node *tmp = this->ptr_->parent;
                    while (tmp && tmp->left == tmp1)
                    {
                        tmp1 = tmp;
                        tmp = tmp->parent;
                    }
                    if (tmp)
                        tmp1 = tmp;
                    else
                        tmp1 = NULL;
                }
                return (tmp1);
            }

            t_Node *root_next() const
            {
                t_Node *next = this->ptr_;
                if (this->ptr_->right != NULL)
                {
                    next = ptr_->right->min_of_tree();
                }
                else
                {
                    t_Node *tmp = this->ptr_->parent;
                    while (tmp && tmp->right == next)
                    {
                        next = tmp;
                        tmp = tmp->parent;
                    }
                    if (tmp)
                        next = tmp;
                    else
                        next = NULL;
                }
                return (next);
            }
            
        private:
            t_Node *ptr_;
            Red_Blacl_Tree *parent;
        };
    };
}
#endif

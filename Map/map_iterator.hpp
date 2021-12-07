/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/07 16:11:33 by ahaddad          ###   ########.fr       */
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
        RED,
        BLACK
    };
    typedef struct s_Node
    {
        int item;
        colors Color;
        s_Node *left;
        s_Node *right;
        s_Node *parents;
    } t_Node;

    template <class Key, typename T, class Compare = std::less<Key> >
    class Red_Blacl_Tree
    {
    private:
        t_Node *root;

    public:
        Red_Blacl_Tree(/* args */)
        {
            root = nullptr;
            // std::cout << "in red black tree constructor" << std::endl;
        }
        ~Red_Blacl_Tree()
        {
        }
        t_Node * create_NODE(int key)
        {

            // std::allocator alloc<t_Node>;
            t_Node *ret = new t_Node;
            ret->item = key;
            ret->Color  = RED;
            ret->left = nullptr;
            ret->right = nullptr;
            ret->parents = nullptr;

            return ret;
        }
        void insert(int key) 
        {
            t_Node *node;
            t_Node *x;
            t_Node *y;
            x = this->root;
            y = nullptr;
            node  = create_NODE(key);
            while (x != NULL)
            {
                y = x;
                if (node->item < x->item)
                    x = x->left;
                else
                    x = x->right;
            }
            node->parents = y;
            if (y == NULL)
                this->root = node;
            else if (node->item < y->item)
                y->left = node;
            else
                y->right = node;
        }
        t_Node *get_minimum(t_Node *root_)
        {
            t_Node *tmp;
            tmp = root_;
            while (tmp->left)
            {
                // std::cout << "im in getsec ==> " << root_->item << std::endl; 
                // std::cout << "im in getmin ==> " << std::endl;
                tmp = tmp->left;
            }
            return tmp;
        }
        t_Node *get_maximum(t_Node *root_)
        {
            // t_Node *tmp;
            // tmp = root_;
            while (root_->right)
                root_ = root_->right;
            return root_;
        }
        t_Node *getSuccessor(t_Node *root_ = nullptr)
        {
            if (root_ == nullptr)
                root_ = this->root;
            t_Node *tmp;
            tmp = root_;
            // if (!tmp->right)
                // std::cout << "im in getsucc ==> " << std::endl; 
            if (tmp->right)
            {
                tmp = get_minimum(tmp->right);
                // std::cout << "im in getsucc ==> " << tmp->item << std::endl; 
            }
            t_Node *y;
            y = tmp->parents;
            while (y != NULL && tmp == y->right)
            {
                tmp = y;
                y = y->parents;
            }
            return tmp;
        }
        t_Node *getpredecessor(t_Node *root_ = nullptr)
        {
            if (root_ == nullptr)
                root_ = this->root;
            // t_Node *tmp;
            // tmp = root_;
            if (root_->left)
                root_ = get_maximum(root_->left);
            t_Node *y;
            y = root_->parents;
            while (y != NULL && root_ == y->left)
            {
                root_ = y;
                y = y->parents;
            }
            return root_;
        }
        t_Node *getroot()
        {
            return root;
        }
        void print_tree_in_ordre_travers(t_Node *root1)
        {
            t_Node *tmp;
            // tmp = root;
            // if (tmp != NULL)
            // {
            //     tmp = most_left(tmp);
            //     while (tmp)
            //     {
            //         std::cout << tmp->item << std::endl;
            //         tmp = tmp->parents;
            //         tmp = tmp->right;

            //         if (!tmp)
            //             std::cout << "tmp->str" << std::endl;
            //         // tmp = most_left(tmp);
            //     }
            tmp = root1;
            if (tmp)
            {
                print_tree_in_ordre_travers(tmp->left);
                std::cout << tmp->item << std::endl;
                print_tree_in_ordre_travers(tmp->right);
            }
            // }
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
        private:
            t_Node *ptr_;
            Red_Blacl_Tree *parent;
        };
    };
}
#endif

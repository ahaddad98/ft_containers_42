/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/14 15:38:56 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include <iostream>
#include "../Vector/iterator_traits.hpp"
#include "pair.hpp"
namespace ft
{
    enum colors
    {
        RED,
        BLACK
    };

    template <typename T, class Compare = std::less<T> >
    class Red_Blacl_Tree
    {
        typedef struct s_Node
        {
            T item;
            colors Color;
            s_Node *left;
            s_Node *right;
            s_Node *parents;
        } t_Node;

    public:
        t_Node *create_NODE(T key)
        {

            // std::allocator alloc<t_Node>;
            t_Node *ret = new t_Node;
            ret->item = key;
            ret->Color = RED;
            ret->left = NULL;
            ret->right = NULL;
            ret->parents = NULL;

            return ret;
        }
        class Node
        {
        private:
        public:
            T item;
            colors Color;
            Node *left;
            Node *right;
            Node *parents;
            // t_Node *rt;
            Node()
            {
                // rt = new t_Node;
                // item = val;
                Color = RED;
                left = NULL;
                right = NULL;
                parents = NULL;
            }
            Node(T val)
            {
                // rt = new t_Node;
                item = val;
                Color = RED;
                left = NULL;
                right = NULL;
                parents = NULL;
            }
            Node(Node &other)
            {
                this = other;
            }
            Node &operator=(Node &other)
            {
                this->T = other.T;
                this->Color = other.Color;
                this->left = other.left;
                this->right = other.right;
                this->parents = other.parents;
                return (*this);
            }
            Node *rightMost()
            {
                Node *tmp = this;

                while (tmp->right)
                {
                    tmp = tmp->right;
                }
                return (tmp);
            }

            Node *leftMost()
            {
                Node *tmp = this;

                while (tmp->left)
                {
                    tmp = tmp->left;
                }
                return (tmp);
            }

            Node *getPrevious()
            {
                Node *previous = this;
                if (this->left)
                {
                    previous = this->left->rightMost();
                }
                else
                {
                    Node *tmp = this->parents;
                    while (tmp && tmp->left == previous)
                    {
                        previous = tmp;
                        tmp = tmp->parents;
                    }
                    if (tmp)
                        previous = tmp;
                    else
                        previous = NULL;
                }
                return (previous);
            }

            Node *getNext()
            {
                Node *next;
                next = this;
                if (this->right != NULL)
                {
                    next = right->leftMost();
                }
                else
                {
                    Node *tmp = this->parents;
                    while (tmp && tmp->right == next)
                    {
                        next = tmp;
                        tmp = tmp->parents;
                    }
                    if (tmp)
                    {
                        next = tmp;
                    }
                    else
                    {
                        next = NULL;
                    }
                }
                return (next);
            }
        };
        typedef size_t size_type;
        Red_Blacl_Tree(/* args */)
        {
            end_ = new Node(0);
            size_ = 0;
            root = end_;
        }
        ~Red_Blacl_Tree()
        {
        }

        t_Node *get_minimum(t_Node *root_)
        {
            // t_Node *tmp;
            // tmp = root_;
            // while (tmp->left)
            // {
            //     // std::cout << "im in getsec ==> " << root_->item << std::endl;
            //     // std::cout << "im in getmin ==> " << std::endl;
            //     tmp = tmp->left;
            // }
            // return tmp;
        }
        t_Node *get_maximum(t_Node *root_)
        {
            // t_Node *tmp;
            // // tmp = root_;
            // while (root_->right)
            //     root_ = root_->right;
            // return root_;
        }
        t_Node *getSuccessor(t_Node *root_ = NULL)
        {
            // if (root_ == NULL)
            //     root_ = this->root;
            // t_Node *tmp;
            // tmp = root_;
            // // if (!tmp->right)
            // // std::cout << "im in getsucc ==> " << std::endl;
            // if (tmp->right)
            // {
            //     tmp = get_minimum(tmp->right);
            //     // std::cout << "im in getsucc ==> " << tmp->item << std::endl;
            // }
            // t_Node *y;
            // y = tmp->parents;
            // while (y != NULL && tmp == y->right)
            // {
            //     tmp = y;
            //     y = y->parents;
            // }
            // return tmp;
        }
        // t_Node *getpredecessor(t_Node *root_ = NULL)
        // {
        //     if (root_ == NULL)
        //         root_ = this->root;
        //     // t_Node *tmp;
        //     // tmp = root_;
        //     if (root_->left)
        //         root_ = get_maximum(root_->left);
        //     t_Node *y;
        //     y = root_->parents;
        //     while (y != NULL && root_ == y->left)
        //     {
        //         root_ = y;
        //         y = y->parents;
        //     }
        //     return root_;
        // }
        Node *getroot()
        {
            return root;
        }
        void print_tree_in_ordre_travers(Node *root1)
        {
            Node *tmp;
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
            if (tmp && tmp != end_)
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

            iterator_map()
            {
                _ptr = NULL;
            };

            // iterator_map(const iterator_map &it)
            // {
            //     *this = it;
            // };

            iterator_map(Node *ptr, Red_Blacl_Tree *parent)
            {
                // if (ptr = )
                // {
                _ptr = ptr;
                // if (_parent != parent->end_)
                _parent = parent;
                // }
                // else
                // {
                //     _ptr = NULL;
                //     // _parent = NULL;
                // }
                // _ptr = ptr;
                // std::cout << "hnaaaa" << std::endl;
                // this->_parent = _parent;
            }
            // } : _ptr(ptr), _parent(parent){};
            iterator_map &operator=(iterator_map const &other)
            {
                _ptr = other._ptr;
                _parent = other._parent;
                return (*this);
            }

            reference operator*()
            {
                return _ptr->item;
            }
            iterator_map operator++()
            {
                _ptr = _ptr->getNext();
                return (*this);
            }
            iterator_map operator++(int n)
            {
                if (!_ptr->getNext())
                {
                    _ptr = _parent->end_;
                }
                else
                    _ptr = _ptr->getNext();
                return (*this);
                // if (!(_ptr = _ptr->getNext()))
                //     _ptr = _parent->end_;
                // std::cout << "im in ++ " << std::endl;

                return (*this);
            }
            iterator_map operator--()
            {
                if ((_ptr = _ptr->getPrevious()))
                    std::cout << "im in -- " << std::endl;
                return (*this);
            }
            bool operator==(iterator_map const &other)
            {
                // std::cout << "in operstor ++ int n" << std::endl;
                return (_ptr == other._ptr);
            }
            bool operator!=(iterator_map const &other)
            {
                // if (other._ptr)
                // {
                    // if (!(_ptr != other._ptr))
                        // std::cout << "in !=" << std::endl;
                    return (_ptr != other._ptr);
                // }
                // return false;
            }

        protected:
            Node *_ptr;
            Red_Blacl_Tree *_parent;
        };
        iterator_map begin()
        {
            return (iterator_map(root->leftMost(), this));
        }
        iterator_map end()
        {
            // return (iterator_map(root->rightMost()/*, this*/));
            // std::cout << "im in end" << std::endl;
            return (iterator_map(end_, this));
        }

        pair<iterator_map ,bool> insert(T key)
        {
            pair<iterator_map , bool> mypair;
            
            Node *node;
            Node *x;
            Node *y;
            if (this->root == end_)
            {
                root = new Node(key);
                end_->left = root;
                size_++;
                return mypair;
            }
            x = root;
            y = NULL;
            node = new Node(key);
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
            size_++;
            return mypair;
        }
        size_type size()
        {
            return (size_);
        }
    private:
        Node *root;
        Node *end_;
        size_type size_;
    };
}
#endif

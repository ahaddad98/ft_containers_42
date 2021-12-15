/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/15 16:19:00 by ahaddad          ###   ########.fr       */
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

    template <typename T, class allocator_type, class Compare = std::less<T> >
    class Red_Blacl_Tree
    {
    public:
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
                Color = RED;
                left = NULL;
                right = NULL;
                parents = NULL;
            }
            Node(T val) : item(val)
            {
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
        typedef typename allocator_type::template rebind<Node>::other _allocator_type;
        Red_Blacl_Tree(/* args */)
        {
            end_ = this->alloc.allocate(1);
            // end_ = new Node();
            size_ = 0;
            root = end_;
        }
        ~Red_Blacl_Tree()
        {
        }
        Node *getroot()
        {
            return root;
        }
        void print_tree_in_ordre_travers(Node *root1)
        {
            Node *tmp;
            tmp = root1;
            if (tmp && tmp != end_)
            {
                print_tree_in_ordre_travers(tmp->left);
                std::cout << tmp->item << std::endl;
                print_tree_in_ordre_travers(tmp->right);
            }
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

            iterator_map(const iterator_map &it)
            {
                *this = it;
            };

            iterator_map(Node *ptr, Red_Blacl_Tree *parent)
            {
                _ptr = ptr;
                _parent = parent;
            }
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
            pointer operator->()
            {
                return &operator*();
            }
            iterator_map operator++()
            {
                _ptr = _ptr->getNext();
                return (*this);
            }
            iterator_map operator++(int n)
            {
                if (!_ptr->getNext())
                    _ptr = _parent->end_;
                else
                    _ptr = _ptr->getNext();
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
                return (_ptr == other._ptr);
            }
            bool operator!=(iterator_map const &other)
            {
                return (_ptr != other._ptr);
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
            return (iterator_map(end_, this));
        }
        iterator_map search_tree_in_ordre_travers(T root1)
        {
            iterator_map it;
            for ( it = this->begin(); it != this->end(); it++)
            {
                if (root1.first == it->first)
                {
                    return it;
                }
            }
            return it;
            
        }
        pair<iterator_map ,bool> insert(T key)
        {
            pair<iterator_map , bool> mypair;
            iterator_map it;
            Node *node;
            Node *x;
            Node *y;
            if (this->root == end_)
            {
                root = this->alloc.allocate(1);
                this->alloc.construct(root, key);
                // root = new Node(key);
                end_->left = root;
                size_++;
                return make_pair(this->begin(), true);
            }
            it = this->search_tree_in_ordre_travers(key);
            if (it == end())
            {
                x = root;
                y = NULL;
                node = this->alloc.allocate(1);
                this->alloc.construct(node, key);
                // node = new Node(key);
                while (x != NULL)
                {
                    y = x;
                    if (node->item.first < x->item.first)
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
                it = this->search_tree_in_ordre_travers(key);
                return make_pair(it , true);
            }
            return make_pair(it ,false);
        }
        size_type size() const
        {
            return (size_);
        }
    private:
        Node *root;
        Node *end_;
        size_type size_;
        _allocator_type alloc; 
    };
}
#endif

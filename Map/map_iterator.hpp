/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/22 01:39:53 by ahaddad          ###   ########.fr       */
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
            Node(T val) : item(val), Color(RED)
            {
                left = NULL;
                right = NULL;
                parents = NULL;
            }
            Node(const Node &other)
            {
                // this->item = other.item;
                // this->Color = other.Color;
                // this->left = other.left;
                // this->right = other.right;
                // this->parents = other.parents;
                *this = other;
            }
            Node &operator=(const Node &other)
            {
                // const_cast<typename T::first_type&>(this->item.first) = other.item.first;
                // this->item = make_pair(other.item.first, other.item.second);
                // new (&(this->item)) pair<typename T::first_type, typename T::second_type>(other.item);
                // this->item.setfirst(other.item.first);
                this->item = other.item;
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
                while (tmp && (tmp->left != NULL))
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
                // std::cout << "heeee" << std::endl;
                return (next);
            }
        };
        typedef size_t size_type;
        typedef typename allocator_type::template rebind<Node>::other _allocator_type;
        typedef Compare value_compare;
        Red_Blacl_Tree()
        {
            end_ = this->alloc.allocate(1);
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
        void Left_Rotate(Node *x)
        {
            Node *y;
            y = x->right;
            x->right = y->left;
            if (y->left)
            {
                y->left->parents = x;
            }
            y->parents = x->parents;
            if (!x->parents)
                this->root = y;
            else
            {
                if (x == x->parents->left)
                    x->parents->left = y;
                else
                    x->parents->right = y;
            }
            y->left = x;
            x->parents = y;
        }
        void Right_Rotate(Node *x)
        {
            Node *y;
            y = x->left;
            x->left = y->right;
            if (y->right)
            {
                y->right->parents = x;
            }
            y->parents = x->parents;
            if (!x->parents)
                this->root = y;
            else
            {
                if (x == x->parents->right)
                    x->parents->right = y;
                else
                    x->parents->left = y;
            }
            y->right = x;
            x->parents = y;
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
            iterator_map(Node *p) : _ptr(p)
            {
            };

            iterator_map(const iterator_map &it)
            {
                *this = it;
            };
            ~iterator_map()
            {
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
                if (!_ptr->getNext())
                    _ptr = _parent->end_;
                else
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
                if (!_ptr->getPrevious())
                    _ptr = NULL;
                else
                    _ptr = _ptr->getPrevious();
                return (*this);
            }
            iterator_map operator--(int n)
            {
                if (!_ptr->getPrevious())
                    _ptr = NULL;
                else
                    _ptr = _ptr->getPrevious();        
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
        class const_iterator_map : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
        {
        public:
            typedef const_iterator_map self_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

            const_iterator_map()
            {
                _ptr = NULL;
            };
            const_iterator_map(Node *p) : _ptr(p)
            {
            };

            const_iterator_map(const const_iterator_map &it)
            {
                *this = it;
            };
            ~const_iterator_map()
            {
            };

            const_iterator_map(Node *ptr, Red_Blacl_Tree *parent)
            {
                _ptr = ptr;
                _parent = parent;
            }
            const_iterator_map &operator=(const_iterator_map const &other)
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
            const_iterator_map operator++()
            {
                if (!_ptr->getNext())
                    _ptr = _parent->end_;
                else
                    _ptr = _ptr->getNext();
                return (*this);
            }
            const_iterator_map operator++(int n)
            {
                if (!_ptr->getNext())
                    _ptr = _parent->end_;
                else
                    _ptr = _ptr->getNext();
                return (*this);
            }
            const_iterator_map operator--()
            {
                if (!_ptr->getPrevious())
                    _ptr = NULL;
                else
                    _ptr = _ptr->getPrevious();
                return (*this);
            }
            const_iterator_map operator--(int n)
            {
                if (!_ptr->getPrevious())
                    _ptr = NULL;
                else
                    _ptr = _ptr->getPrevious();        
                return (*this);
            }
            bool operator==(const_iterator_map const &other)
            {
                return (_ptr == other._ptr);
            }
            bool operator!=(const_iterator_map const &other)
            {
                return (_ptr != other._ptr);
            }

        protected:
            Node *_ptr;
            Red_Blacl_Tree *_parent;
        };
        class reverse_iterator_map : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
        {
        public:
            typedef reverse_iterator_map self_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

            reverse_iterator_map()
            {
                _ptr = NULL;
            };
            reverse_iterator_map(Node *p) : _ptr(p)
            {
            };

            reverse_iterator_map(const reverse_iterator_map &it)
            {
                *this = it;
            };
            ~reverse_iterator_map()
            {
            };

            reverse_iterator_map(Node *ptr, Red_Blacl_Tree *parent)
            {
                _ptr = ptr;
                _parent = parent;
            }
            reverse_iterator_map &operator=(reverse_iterator_map const &other)
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
            reverse_iterator_map operator++()
            {
                // _ptr = _ptr->getNext();
                // return (*this);
                if (!_ptr->getPrevious())
                    _ptr = NULL;
                else
                    _ptr = _ptr->getPrevious();
                return (*this);
            }
            reverse_iterator_map operator++(int n)
            {
                // if (!_ptr->getNext())
                //     _ptr = _parent->end_;
                // else
                //     _ptr = _ptr->getNext();
                // return (*this);
                if (!_ptr->getPrevious())
                    _ptr = NULL;
                else
                    _ptr = _ptr->getPrevious();
                return (*this);
            }
            reverse_iterator_map operator--()
            {
                if (!_ptr->getNext())
                    _ptr = _parent->end_;
                else
                    _ptr = _ptr->getNext();
                return (*this);
                // if (!_ptr->getPrevious())
                //     _ptr = NULL;
                // else
                //     _ptr = _ptr->getPrevious();
                // return (*this);
            }
            reverse_iterator_map operator--(int n)
            {
                if (!_ptr->getNext())
                    _ptr = _parent->end_;
                else
                    _ptr = _ptr->getNext();
                return (*this);
                // if (!_ptr->getPrevious())
                //     _ptr = NULL;
                // else
                //     _ptr = _ptr->getPrevious();        
                // return (*this);
            }
            bool operator==(reverse_iterator_map const &other)
            {
                return (_ptr == other._ptr);
            }
            bool operator!=(reverse_iterator_map const &other)
            {
                return (_ptr != other._ptr);
            }

        protected:
            Node *_ptr;
            Red_Blacl_Tree *_parent;
        };
        iterator_map begin()
        {
            if (size_ == 0)
            {   
                return (iterator_map(end_, this));
            }
            std::cout << size_ << std::endl;
            return (iterator_map(root->leftMost(), this));
        }
        iterator_map end()
        {
            return (iterator_map(end_, this));
        }
        const_iterator_map begin() const
        {
            if (size_ == 0)
            {   
                return (const_iterator_map(end_, this));
            }
            std::cout << size_ << std::endl;
            return (const_iterator_map(root->leftMost(), this));
        }
        const_iterator_map end() const
        {
            return (const_iterator_map(end_, this));
        }
        reverse_iterator_map rbegin()
        {
            if (size_ == 0)
            {   
                // std::cout << size_ << std::endl;
                return (reverse_iterator_map(end_, this));
            }
            return (reverse_iterator_map(root->rightMost(), this));
        }
        reverse_iterator_map rend()
        {
            if (size_ == 0)
            {   
                // std::cout << size_ << std::endl;
                return (reverse_iterator_map(end_, this));
            }
            // std::cout << "size_" << std::endl;
            return (reverse_iterator_map(root->leftMost()->left, this));
            // return 
        }
        Node* search_tree_in_ordre_travers(T root1)
        {
            Node *tmp;
            tmp = this->root;
            if (root == end_)
                return NULL;
            while (tmp != NULL)
            {
                if (comp(root1.first, tmp->item.first))
                    tmp = tmp->left;
                else if (comp(tmp->item.first, root1.first))
                    tmp = tmp->right;
                else
                    return tmp;
            }
            return NULL;
        }
        void swap_node(Node *n1, Node *n2)
        {
            n1->item = n2->item;
        }
        void rbTransplant(Node *u, Node *v) 
        {
            if (u && u->parents == NULL) 
            {
                root = v;
            } 
            else if (u && u == u->parents->left) 
            {
                    u->parents->left = v;
            } 
            else 
            {
                u->parents->right = v;
            }
            if (v)
            {
                v->parents = u->parents;
            }
        }

        void delete_(T to_delete)
        {
            Node *z = search_tree_in_ordre_travers(to_delete);
            Node *y;
            Node *x;
            colors y_color = y->Color;
            y = z;
            if (z->left == NULL) 
            {
                x = z->right;
                rbTransplant(z, z->right);
            } 
            else if (z->right == NULL) 
            {
                x = z->left;
                rbTransplant(z, z->left);
            } 
            else 
            {
                y = (z->right)->getPrevious();
                y_color = y->Color;
                x = y->right;
                if (y->parents == z) 
                {
                    x->parents = y;
                } 
                else 
                {
                    rbTransplant(y, y->right);
                    y->right = z->right;
                    y->right->parents = y;
                }
                rbTransplant(z, y);
                y->left = z->left;
                y->left->parents = y;
                y->Color = z->Color;
            }
            size_--;
            this->alloc.deallocate(z, 1);
            // Node *x;
            // Node *y;
            // y = z;
            // colors y_color = y->Color;
            // if (z == root)
            // {
            //     size_--;
            //     root = NULL;
            //     this->alloc.deallocate(root , 1);
            //     return ;
            // }
            // if (z && z->left == NULL)
            // {
            //     // std::cout << "-- 1 --" <<std::endl;
            //     x = z->right;
            //     rbTransplant(z, z->right);
            //     size_--;
            //     // std::cout << "-- 1,5 --" <<std::endl;
            // }
            // else if (z->right == NULL)
            // {
            //     size_--;
            //     // std::cout << "-- 2 --" <<std::endl;
            //     x = z->left;
            //     rbTransplant(z, z->left);
            // }
            // else
            // {
            //     size_--;
            //     // std::cout << "-- 3 --" <<std::endl;
            //     y = (z->right)->getPrevious();
            //     y_color = y->Color;
            //     x = y->right;
            //     if (y->parents == z)
            //         x->parents = z;
            //     else
            //     {
            //         rbTransplant(y , y->right);
            //         y->right = z->right;
            //         y->right->parents = y;
            //         y->Color = z->Color;
            //     }
            // }
            // if (tmp->left == NULL) 
            // {
            //     x = tmp->right;
            //     rbTransplant(tmp, tmp->right);
            // } 
            // if (tmp == NULL)
            //     return ;
            // if ((tmp->left == NULL) && (tmp->right == NULL))
            // {
            //     if (tmp == root)
            //     {
            //         std::cout << "here 1" << std::endl;
            //         end_->left = NULL;
            //         end_->left = NULL;
            //         this->alloc.deallocate(root,1);
            //     }
            //     else if (tmp && tmp ==  tmp->parents->left)
            //     {
            //         tmp->parents->left = NULL;
            //         this->alloc.deallocate(tmp,1);
            //     }
            //     else
            //     {
            //         if ( tmp && tmp->parents->right != NULL)
            //         {   
            //             tmp->parents->right = NULL;
            //             this->alloc.deallocate(tmp,1);
            //         }
            //     }
            //     this->size_--;
            //     return ;
            // }
            // if ((tmp->right != NULL) && (tmp->left == NULL))
            // {
            //     std::cout << "amine 2" << std::endl;
            //     tmp->parents->left = NULL;
            //     // swap_node(tmp, tmp->left);
            //     this->alloc.deallocate(tmp->left,1);
            //     this->size_--;
            //     return ;
            // }
            // if ((tmp->left != NULL) && (tmp->right == NULL))
            // {
            //     swap_node(tmp, tmp->left);
            //     tmp->left = NULL;
            //     this->alloc.deallocate(tmp->left,1);
            //     this->size_--;
            //     return ;
            // }
            // else if ((tmp->left != NULL) && (tmp->right != NULL))
            // {
            //     std::cout << "amine 3" << std::endl;
            // }
            // else
            //     std::cout << "root = " << root->item.first << std::endl;
        }
        void insertFix(Node *k)
        {
            Node *u;
            while (k->parents->Color == RED)
            {
                if (k->parents == k->parents->parents->right)
                {
                    u = k->parents->parents->left;
                    if (u && u->Color == RED)
                    {
                        // std::cout << "im here in if" << std::endl;
                        u->Color = BLACK;
                        k->parents->Color = BLACK;
                        k->parents->parents->Color = RED;
                        k = k->parents->parents;
                    }
                    else
                    {
                        // std::cout << "im here in end" << std::endl;
                        if (k == k->parents->left)
                        {
                            k = k->parents;
                            Right_Rotate(k);
                        }
                        k->parents->Color = BLACK;
                        k->parents->parents->Color = RED;
                        Left_Rotate(k->parents->parents);
                    }
                }
                else
                {
                    u = k->parents->parents->right;
                    if (u && u->Color == RED)
                    {
                        k->parents->Color = BLACK;
                        u->Color = BLACK;
                        k->parents->parents->Color = RED;
                        k = k->parents->parents;
                    }
                    else
                    {
                        if (k == k->parents->right)
                        {
                            k = k->parents;
                            Left_Rotate(k);
                        }
                        k->parents->Color = BLACK;
                        k->parents->parents->Color = RED;
                        Right_Rotate(k->parents->parents);
                    }
                }
                if (k == this->root)
                {
                    break;
                }
            }
            root->Color = BLACK;
        }

        pair<iterator_map, bool> insert(T key)
        {
            iterator_map it = end();
            Node *node;
            Node *x;
            Node *y;
            if (this->root == end_)
            {
                root = this->alloc.allocate(1);
                this->alloc.construct(root, Node(key));
                end_->left = root;
                size_++;
                root->Color = BLACK;
                return make_pair(iterator_map(root), true);
            }
            Node *test = this->search_tree_in_ordre_travers(key);
            if (test == NULL)
            {
                x = root;
                y = NULL;
                node = this->alloc.allocate(1);
                this->alloc.construct(node, Node(key));
                while (x != NULL)
                {
                    y = x;
                    if (comp(node->item.first , x->item.first))
                        x = x->left;
                    else
                        x = x->right;
                }
                node->parents = y;
                if (y == NULL)
                    this->root = node;
                else if (comp(node->item.first , y->item.first))
                    y->left = node;
                else
                    y->right = node;
                size_++;
                if (node->parents == NULL)
                {
                    node->Color = BLACK;
                    return make_pair(node, false);
                }
                if (node->parents->parents == NULL)
                {
                    return make_pair(node, false);
                }
                insertFix(node);
                return make_pair(node, true);
            }
            return make_pair(node, false);
        }
        size_type size() const
        {
            return (size_);
        }
        _allocator_type get_alloc()
        {
            return this->alloc;
        }
        value_compare getcompare()
        {
            return this->comp;
        }
    private:
        Node *root;
        Node *end_;
        size_type size_;
        _allocator_type alloc;
        value_compare comp;
    };
}
#endif

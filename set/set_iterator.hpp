/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:43:44 by amine             #+#    #+#             */
/*   Updated: 2021/12/26 19:26:08 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP
#include <iostream>
#include "../Vector/iterator_traits.hpp"
#include "../Map/pair.hpp"

enum colors
{
    RED,
    BLACK
};

template <class key_type, typename T, class allocator_type, class Compare = std::less<T> >
class Red_Blacl_Tree_set
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
            *this = other;
        }
        Node &operator=(const Node &other)
        {
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
            return (next);
        }
        Node *getNext() const
        {
            Node *next;
            next = const_cast<Node *>(this);
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
    typedef Compare value_compare;
    Red_Blacl_Tree_set()
    {
        end_ = this->alloc.allocate(1);
        size_ = 0;
        root = end_;
    }
    Red_Blacl_Tree_set(const Red_Blacl_Tree_set &src)
    {
        *this = src;
    }
    Red_Blacl_Tree_set &operator=(const Red_Blacl_Tree_set &src)
    {
        const_iterator_set it = src.begin();
        for (it = src.begin(); it != src.end(); it++)
        {
            this->insert(*it);
        }
        return *this;
    }
    ~Red_Blacl_Tree_set()
    {
        this->alloc.deallocate(end_, 1);
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
        if (y && y->left)
        {
            y->left->parents = x;
        }
        y->parents = x->parents;
        if (!x->parents)
            this->root = y;
        else
        {
            if (x && x == x->parents->left)
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
        if (x->left)
            x->left = y->right;
        if (y && y->right)
        {
            y->right->parents = x;
        }
        y->parents = x->parents;
        if (!x->parents)
            this->root = y;
        else
        {
            if (x && x == x->parents->right)
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

    class iterator_set : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
    {
    public:
        typedef iterator_set self_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

        iterator_set()
        {
            _ptr = NULL;
        };
        iterator_set(Node *p) : _ptr(p){};

        iterator_set(const iterator_set &it)
        {
            *this = it;
        };
        ~iterator_set(){};

        iterator_set(Node *ptr, Red_Blacl_Tree_set *parent)
        {
            _ptr = ptr;
            _parent = parent;
        }
        iterator_set &operator=(iterator_set const &other)
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
        iterator_set operator++()
        {
            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        iterator_set operator++(int n)
        {
            (void)n;
            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        iterator_set operator--()
        {
            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        iterator_set operator--(int n)
        {
            (void)n;
            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        bool operator==(iterator_set const &other)
        {
            return (_ptr == other._ptr);
        }
        bool operator!=(iterator_set const &other)
        {
            return (_ptr != other._ptr);
        }

    protected:
        Node *_ptr;
        Red_Blacl_Tree_set *_parent;
    };
    class const_iterator_set : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
    {
    public:
        typedef const_iterator_set self_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

        const_iterator_set()
        {
            _ptr = NULL;
        };
        const_iterator_set(Node *p) : _ptr(p){};

        const_iterator_set(const const_iterator_set &it)
        {
            *this = it;
        };
        ~const_iterator_set(){};

        const_iterator_set(const Node *ptr, const Red_Blacl_Tree_set *parent)
        {
            _ptr = ptr;
            _parent = parent;
        }
        const_iterator_set &operator=(const_iterator_set const &other)
        {
            _ptr = other._ptr;
            _parent = other._parent;
            return (*this);
        }
        reference operator*() const
        {
            return const_cast<reference>(_ptr->item);
        }
        pointer operator->()
        {
            return &operator*();
        }
        const_iterator_set operator++()
        {
            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        const_iterator_set operator++(int n)
        {
            (void)n;

            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        const_iterator_set operator--()
        {
            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        const_iterator_set operator--(int n)
        {
            (void)n;

            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        bool operator==(const_iterator_set const &other)
        {
            return (_ptr == other._ptr);
        }
        bool operator!=(const_iterator_set const &other)
        {
            return (_ptr != other._ptr);
        }

    protected:
        const Node *_ptr;
        const Red_Blacl_Tree_set *_parent;
    };
    class reverse_iterator_set : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
    {
    public:
        typedef reverse_iterator_set self_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

        reverse_iterator_set()
        {
            _ptr = NULL;
        };
        reverse_iterator_set(Node *p) : _ptr(p){};

        reverse_iterator_set(const reverse_iterator_set &it)
        {
            *this = it;
        };
        ~reverse_iterator_set(){};

        reverse_iterator_set(Node *ptr, Red_Blacl_Tree_set *parent)
        {
            _ptr = ptr;
            _parent = parent;
        }
        reverse_iterator_set &operator=(reverse_iterator_set const &other)
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
        reverse_iterator_set operator++()
        {
            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        reverse_iterator_set operator++(int n)
        {
            (void)n;

            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        reverse_iterator_set operator--()
        {
            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        reverse_iterator_set operator--(int n)
        {
            (void)n;

            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        bool operator==(reverse_iterator_set const &other)
        {
            return (_ptr == other._ptr);
        }
        bool operator!=(reverse_iterator_set const &other)
        {
            return (_ptr != other._ptr);
        }

    protected:
        Node *_ptr;
        Red_Blacl_Tree_set *_parent;
    };
    class const_reverse_iterator_set : public ft::Iterator_Traits<std::bidirectional_iterator_tag, T>
    {
    public:
        typedef const_reverse_iterator_set self_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::value_type value_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::pointer pointer;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::reference reference;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::Iterator_Traits<std::bidirectional_iterator_tag, T>::iterator_categorie iterator_category;

        const_reverse_iterator_set()
        {
            _ptr = NULL;
        };
        const_reverse_iterator_set(Node *p) : _ptr(p){};

        const_reverse_iterator_set(const const_reverse_iterator_set &it)
        {
            *this = it;
        };
        ~const_reverse_iterator_set(){};

        const_reverse_iterator_set(Node *ptr, Red_Blacl_Tree_set *parent)
        {
            _ptr = ptr;
            _parent = parent;
        }
        const_reverse_iterator_set &operator=(const_reverse_iterator_set const &other)
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
        const_reverse_iterator_set operator++()
        {
            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        const_reverse_iterator_set operator++(int n)
        {
            (void)n;

            if (!_ptr->getPrevious())
                _ptr = NULL;
            else
                _ptr = _ptr->getPrevious();
            return (*this);
        }
        const_reverse_iterator_set operator--()
        {
            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        const_reverse_iterator_set operator--(int n)
        {
            (void)n;
            if (!_ptr->getNext())
                _ptr = _parent->end_;
            else
                _ptr = _ptr->getNext();
            return (*this);
        }
        bool operator==(const_reverse_iterator_set const &other)
        {
            return (_ptr == other._ptr);
        }
        bool operator!=(const_reverse_iterator_set const &other)
        {
            return (_ptr != other._ptr);
        }

    protected:
        Node *_ptr;
        Red_Blacl_Tree_set *_parent;
    };
    iterator_set begin()
    {
        if (size_ == 0)
        {
            return (iterator_set(end_, this));
        }
        return (iterator_set(root->leftMost(), this));
    }
    iterator_set end()
    {
        return (iterator_set(end_, this));
    }
    const_iterator_set begin() const
    {
        if (size_ == 0)
        {
            return (const_iterator_set(end_, this));
        }
        return (const_iterator_set(root->leftMost(), this));
    }
    const_iterator_set end() const
    {
        return (const_iterator_set(end_, this));
    }
    reverse_iterator_set rbegin()
    {
        if (size_ == 0)
        {
            return (reverse_iterator_set(end_, this));
        }
        return (reverse_iterator_set(root->rightMost(), this));
    }
    reverse_iterator_set rend()
    {
        if (size_ == 0)
        {
            return (reverse_iterator_set(end_, this));
        }
        return (reverse_iterator_set(root->leftMost()->left, this));
    }
    const_reverse_iterator_set rbegin() const
    {
        if (size_ == 0)
        {
            return (const_reverse_iterator_set(end_, this));
        }
        return (const_reverse_iterator_set(root->rightMost(), this));
    }
    const_reverse_iterator_set rend() const
    {
        if (size_ == 0)
        {
            return (reverse_iterator_set(end_, this));
        }
        return (reverse_iterator_set(root->leftMost()->left, this));
    }
    Node *search_tree_in_ordre_travers(T root1)
    {
        Node *tmp;
        tmp = this->root;
        if (root == end_)
            return NULL;
        while (tmp != NULL)
        {
            if (comp(root1, tmp->item))
                tmp = tmp->left;
            else if (comp(tmp->item, root1))
                tmp = tmp->right;
            else
                return tmp;
        }
        return NULL;
    }
    Node *search_tree_with_key(const key_type &k) const
    {
        Node *tmp;
        tmp = this->root;
        if (root == end_)
            return NULL;
        while (tmp != NULL)
        {
            if (comp(k, tmp->item))
                tmp = tmp->left;
            else if (comp(tmp->item, k))
                tmp = tmp->right;
            else
                return tmp;
        }
        return NULL;
    }
    Node *search_tree_with_key_to_use_lower(const key_type &k) const
    {
        Node *tmp;
        tmp = this->root;
        if (root == end_)
            return NULL;
        while (tmp != NULL)
        {
            if (comp(k, tmp->item))
            {
                if (tmp->left == NULL)
                    return tmp;
                tmp = tmp->left;
            }
            else if (comp(tmp->item, k))
            {
                if (tmp->right == NULL)
                    return tmp;
                tmp = tmp->right;
            }
            else
                return tmp;
        }
        return NULL;
    }
    Node *search_tree_with_key_to_use_upper(const key_type &k) const
    {
        Node *tmp;
        tmp = this->root;
        if (root == end_)
            return NULL;
        while (tmp != NULL)
        {
            if (comp(k, tmp->item))
            {
                if (tmp->left == NULL)
                {
                    if (tmp->getNext() == NULL && tmp->getNext() == end_)
                        return end_;
                    return tmp;
                }
                tmp = tmp->left;
            }
            else if (comp(tmp->item, k))
            {
                if (tmp->right == NULL)
                {
                    if (tmp->getNext() == NULL && tmp->getNext() == end_)
                        return end_;
                    return tmp;
                }
                tmp = tmp->right;
            }
            else
            {
                if (tmp->getNext() == NULL && tmp->getNext() == end_)
                    return end_;
                return tmp->getNext();
            }
        }
        return NULL;
    }
    iterator_set lower_bound(const key_type &k)
    {
        Node *tmp = search_tree_with_key_to_use_lower(k);
        return iterator_set(tmp, this);
    }
    const_iterator_set lower_bound(const key_type &k) const
    {
        Node *tmp = search_tree_with_key_to_use_lower(k);
        return iterator_set(tmp, this);
    }
    iterator_set upper_bound(const key_type &k)
    {
        Node *tmp = search_tree_with_key_to_use_upper(k);
        return iterator_set(tmp, this);
    }
    const_iterator_set upper_bound(const key_type &k) const
    {
        Node *tmp = search_tree_with_key_to_use_upper(k);
        return iterator_set(tmp, this);
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
    void deleteFix(Node *x)
    {
        Node *s;
        while (x && x != root && x->Color == BLACK)
        {
            if (x && x == x->parents->left)
            {
                if (s && x->parents->right)
                    s = x->parents->right;
                if (s && s->Color == RED)
                {
                    s->Color = BLACK;
                    x->parents->Color = RED;
                    Left_Rotate(x->parents);
                    s = x->parents->right;
                }
                if (s && s->right && s->left && s->left->Color == BLACK && s->right->Color == BLACK)
                {
                    if (s)
                        s->Color = RED;
                    x = x->parents;
                }
                else
                {
                    if (s && s->right->Color == BLACK)
                    {
                        if (s->left)
                            s->left->Color = BLACK;
                        s->Color = RED;
                        Right_Rotate(s);
                        s = x->parents->right;
                    }
                    s->Color = x->parents->Color;
                    x->parents->Color = BLACK;
                    s->right->Color = BLACK;
                    Left_Rotate(x->parents);
                    x = root;
                }
            }
            else
            {
                s = x->parents->left;
                if (s && s->Color == RED)
                {
                    s->Color = BLACK;
                    x->parents->Color = RED;
                    Right_Rotate(x->parents);
                    s = x->parents->left;
                }

                if (s && s->right->Color == BLACK && s->right->Color == BLACK)
                {
                    s->Color = RED;
                    x = x->parents;
                }
                else
                {
                    if (s && s->left->Color == BLACK)
                    {
                        s->right->Color = BLACK;
                        s->Color = RED;
                        Left_Rotate(s);
                        s = x->parents->left;
                    }
                    s->Color = x->parents->Color;
                    x->parents->Color = BLACK;
                    s->left->Color = BLACK;
                    Right_Rotate(x->parents);
                    x = root;
                }
            }
        }
        if (x)
            x->Color = BLACK;
    }

    void delete_(T to_delete)
    {
        Node *z = search_tree_in_ordre_travers(to_delete);
        Node *y;
        Node *x;
        y = z;
        colors y_color = y->Color;
        if (z && z->left == NULL)
        {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z && z->right == NULL)
        {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else
        {
            y = (z->right)->getPrevious();
            y_color = y->Color;
            x = y->right;
            if (y && y->parents == z)
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
        if (y && y_color == BLACK)
        {
            deleteFix(x);
        }
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
                    u->Color = BLACK;
                    k->parents->Color = BLACK;
                    k->parents->parents->Color = RED;
                    k = k->parents->parents;
                }
                else
                {
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

    ft::pair<iterator_set, bool> insert(T key)
    {
        iterator_set it = end();
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
            return ft::make_pair(root, true);
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
                if (comp(node->item, x->item))
                    x = x->left;
                else
                    x = x->right;
            }
            node->parents = y;
            if (y == NULL)
                this->root = node;
            else if (comp(node->item, y->item))
                y->left = node;
            else
                y->right = node;
            size_++;
            if (node->parents == NULL)
            {
                node->Color = BLACK;
                return ft::make_pair(node, false);
            }
            if (node->parents->parents == NULL)
            {
                return ft::make_pair(node, false);
            }
            insertFix(node);
            return ft::make_pair(node, true);
        }
        return ft::make_pair(test, false);
    }
    size_type size() const
    {
        return (size_);
    }
    size_type max__size() const
    {
        return this->alloc.max_size();
    }
    _allocator_type get_alloc() const
    {
        return this->alloc;
    }
    size_type count(const key_type &k) const
    {
        Node *tmp = search_tree_with_key(k);
        if (tmp == NULL)
            return 0;
        return 1;
    }
    value_compare getcompare() const
    {
        return this->comp;
    }
    void swap(Red_Blacl_Tree_set &x)
    {
        Node *tmp_root = x.root;
        Node *tmp_end = x.end_;
        size_t tmp_size = x.size_;
        x.root = this->root;
        x.end_ = this->end_;
        x.size_ = this->size_;
        root = tmp_root;
        end_ = tmp_end;
        size_ = tmp_size;
    }

private:
    Node *root;
    Node *end_;
    size_type size_;
    _allocator_type alloc;
    value_compare comp;
};
#endif

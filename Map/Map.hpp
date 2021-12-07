/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:40:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/07 18:27:24 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "map_iterator.hpp"
namespace ft
{

    template <class Key,                                            // map::key_type
              class T,                                              // map::mapped_type
              class Compare = std::less<Key>,                       // map::key_compare
              class Alloc = std::allocator<std::pair<const Key, T> > // map::allocator_type
              >

    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type;
        typedef Compare key_compare;
        // typedef Comp value_compare;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        // miss iterator here
        typedef typename ft::Red_Blacl_Tree<Key, T ,Compare>::iterator_map iterator;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;
        // constructor
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            // ft::Red_Blacl_Tree<Key, T ,Compare> *test = new ft::Red_Blacl_Tree<Key, T ,Compare>;
            test = new ft::Red_Blacl_Tree<Key, T ,Compare>;
            test->insert(5);
            test->insert(15);
            test->insert(25);
            test->insert(85);
            test->insert(75);
            test->insert(65);
            test->insert(95);
            test->insert(55);
            test->print_tree_in_ordre_travers(test->getroot());
        }
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
        {
        }
        map(const map &x)
        {
        }
        ~map()
        {
        }
        map &operator=(const map &x)
        {
        }

        // iterators;
        // iterator begin()
        // {
        // }
        // const_iterator begin() const
        // {
        // }
        // iterator end()
        // {
        // }
        // const_iterator end() const
        // {
        // }
        // reverse_iterator rbegin()
        // {
        // }
        // const_reverse_iterator rbegin() const
        // {
        // }
        // reverse_iterator rend()
        // {
        // }
        // const_reverse_iterator rend() const
        // {
        // }

        // Capacity:
        bool empty() const
        {
        }
        size_type size() const
        {
        }
        size_type max_size() const
        {
        }
        // Element access:
        mapped_type &operator[](const key_type &k) {}
        // Modifiers:
        // pair<iterator, bool> insert(const value_type &val)
        // {
        // }
        // iterator insert (iterator position, const value_type& val)
        // {
        // }
        // template <class InputIterator>
        // void insert(InputIterator first, InputIterator last)
        // {
        // }
        // void erase(iterator position)
        // {
        // }
        // size_type erase(const key_type &k)
        // {
        // }
        // void erase(iterator first, iterator last)
        // {
        // }
        void swap(map &x)
        {
        }
        void clear()
        {
        }
        // Observers:
        key_compare key_comp() const
        {
        }
        // value compare ?? 
        // value_compare value_comp() const
        // {
        // }
        
        // operations
        // iterator find (const key_type& k)
        // {
        // }
        // const_iterator find (const key_type& k) const
        // {
        // }
        size_type count (const key_type& k) const
        {
        }
        // iterator lower_bound (const key_type& k)
        // {
        // }
        // const_iterator lower_bound (const key_type& k) const
        // {            
        // }
        // iterator upper_bound (const key_type& k)
        // {
        // }
        // const_iterator upper_bound (const key_type& k) const
        // {
        // }
        // pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        // {
        // }
        // pair<iterator,iterator>             equal_range (const key_type& k)
        // {
        // }
        
        // Allocator:
        allocator_type get_allocator() const
        {
        }
    private:
        allocator_type alloc;
        value_type cc;
        size_type size_;
        ft::Red_Blacl_Tree<Key, T ,Compare> *test;
    };

}
#endif

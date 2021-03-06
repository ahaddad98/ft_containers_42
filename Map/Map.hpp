/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:40:33 by ahaddad           #+#    #+#             */
/*   Updated: 2021/12/26 19:21:26 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "map_iterator.hpp"
#include "pair.hpp"
namespace ft
{

    template <class Key,                                           // map::key_type
              class T,                                             // map::mapped_type
              class Compare = std::less<Key>,                      // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
              >

    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const Key, T> value_type;
        typedef Compare key_compare;
        // typedef Comp value_compare;
        typedef Alloc allocator_type;
        // typedef typename  Alloc::template rebind<typename ft::Red_Blacl_Tree<value_type , Alloc,Compare>::Node>::other allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        // miss iterator here
        typedef typename ft::Red_Blacl_Tree<key_type, value_type, allocator_type, Compare>::iterator_map iterator;
        typedef typename ft::Red_Blacl_Tree<key_type, value_type, allocator_type, Compare>::iterator_map const_iterator;
        typedef typename ft::Red_Blacl_Tree<key_type, value_type, allocator_type, Compare>::reverse_iterator_map reverse_iterator;
        typedef typename ft::Red_Blacl_Tree<key_type, value_type, allocator_type, Compare>::const_reverse_iterator_map const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;
        // compare class
        class value_compare : std::binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };
        // constructor
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            cmp = comp;
            this->alloc = alloc;
            this->size_ = mymap.size();
        }
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
        {
            cmp = comp;
            this->alloc = alloc;
            this->size_ = mymap.size();
            for (InputIterator it = first; it != last; it++)
            {
                this->insert(*it);
            }
        }
        map(const map &x)
        {
            *this = x;
        }
        ~map()
        {
            clear();
        }
        map &operator=(const map &x)
        {
            this->clear();
            this->mymap = x.mymap;
            return *this;
        }

        // iterators;
        iterator begin()
        {
            return mymap.begin();
        }
        const_iterator begin() const
        {
            return this->mymap.begin();
        }
        iterator end()
        {
            return mymap.end();
        }
        const_iterator end() const
        {
            return this->mymap.end();
        }
        reverse_iterator rbegin()
        {
            return mymap.rbegin();
        }
        const_reverse_iterator rbegin() const
        {
            return mymap.rbegin();
        }
        reverse_iterator rend()
        {
            return mymap.rend();
        }
        const_reverse_iterator rend() const
        {
            return mymap.rend();
        }

        // Capacity:
        bool empty() const
        {
            return (mymap.size() == 0);
        }
        size_type size() const
        {
            return mymap.size();
        }
        size_type max_size() const
        {
            return this->mymap.max__size();
        }
        // Element access:
        mapped_type &operator[](const key_type &k)
        {
            if (this->count(k) == 0)
                this->insert(ft::pair<int, int>(k, mapped_type()));
            iterator it = this->find(k);
            return ((*it).second);
        }
        // Modifiers:
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            return mymap.insert(val);
        }
        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            mymap.insert(val);
            return (this->find(val.first));
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            InputIterator it;
            for (it = first; it != last; it++)
            {
                insert(*it);
            }
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last) const
        {
            InputIterator it;
            for (it = first; it != last; it++)
            {
                insert(*it);
            }
        }
        void erase(iterator position)
        {
            iterator it;
            for (it = begin(); it != end(); it++)
            {
                if (it == position)
                    this->mymap.delete_(*it);
            }
        }
        size_type erase(const key_type &k)
        {
            iterator it;
            it = find(k);
            if (it == end())
                return 0;
            this->mymap.delete_(*it);
            return 1;
        }
        void erase(iterator first, iterator last)
        {
            iterator it;
            for (it = first; it != last; it++)
            {
                // std::cout << "asd" << std::endl;
                this->mymap.delete_(*it);
            }
        }
        void swap(map &x)
        {
            this->mymap.swap(x.mymap);
        }
        void clear()
        {
            this->erase(begin(), end());
        }
        // Observers:
        key_compare key_comp() const
        {
            return mymap.getcompare();
        }
        // value compare ??
        value_compare value_comp() const
        {
            return this->mymap.getcompare();
        }

        // operations
        iterator find(const key_type &k)
        {
            iterator it;
            for (it = begin(); it != end(); it++)
            {
                if (it->first == k)
                    return it;
            }
            return end();
        }
        const_iterator find(const key_type &k) const
        {
            const_iterator it;
            for (it = begin(); it != end(); it++)
            {
                if (it->first == k)
                    return it;
            }
            return end();
        }
        size_type count(const key_type &k) const
        {
            return this->mymap.count(k);
        }
        iterator lower_bound(const key_type &k)
        {
            return this->mymap.lower_bound(k);
        }
        const_iterator lower_bound(const key_type &k) const
        {
            return this->mymap.const_lower_bound(k);
        }
        iterator upper_bound(const key_type &k)
        {
            return this->mymap.upper_bound(k);
        }
        const_iterator upper_bound(const key_type &k) const
        {
            return this->mymap.upper_bound(k);
        }
        ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return make_pair(lower_bound(k), upper_bound(k));
        }
        ft::pair<iterator, iterator> equal_range(const key_type &k)
        {
            return make_pair(lower_bound(k), upper_bound(k));
        }

        // Allocator:
        allocator_type get_allocator() const
        {
            return mymap.get_alloc();
        }

    private:
        allocator_type alloc;
        value_type cc;
        size_type size_;
        Compare cmp;
        ft::Red_Blacl_Tree<key_type, value_type, allocator_type, Compare> mymap;
    };

}
#endif

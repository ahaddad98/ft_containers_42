/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:17:44 by amine             #+#    #+#             */
/*   Updated: 2021/12/26 19:26:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include <iostream>
// #include "../Map/map_iterator.hpp"
#include "set_iterator.hpp"
#include "../Map/pair.hpp"


namespace ft
{
    template <class T,                        // set::key_type/value_type
              class Compare = std::less<T>,   // set::key_compare/value_compare
              class Alloc = std::allocator<T> // set::allocator_type
              >
    class set
    {
    public:
        typedef T key_type;
        // typedef T mapped_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        // typedef Comp value_compare;
        typedef Alloc allocator_type;
        // typedef typename  Alloc::template rebind<typename ft::Red_Blacl_Tree<value_type , Alloc,Compare>::Node>::other allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        // miss iterator here
        typedef typename Red_Blacl_Tree_set<key_type, value_type, allocator_type, Compare>::iterator_set iterator;
        typedef typename Red_Blacl_Tree_set<key_type, value_type, allocator_type, Compare>::const_iterator_set const_iterator;
        typedef typename Red_Blacl_Tree_set<key_type, value_type, allocator_type, Compare>::reverse_iterator_set reverse_iterator;
        typedef typename Red_Blacl_Tree_set<key_type, value_type, allocator_type, Compare>::const_reverse_iterator_set const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;
        // constructor
        explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            cmp = comp;
            this->alloc = alloc;
            this->size_ = myset.size();
        }
        template <class InputIterator>
        set(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
        {
            cmp = comp;
            this->alloc = alloc;
            this->size_ = myset.size();
            for (InputIterator it = first; it != last; it++)
            {
                this->insert(*it);
            }
        }
        set(const set &x)
        {
            *this = x;
        }
        ~set()
        {
            clear();
        }
        set &operator=(const set &x)
        {
            this->clear();
            this->size_ = myset.size();
            for (const_iterator it = x.begin(); it != x.end(); it++)
            {
                this->insert(*it);
            }
            // this->myset = x.set;
            return *this;
        }

        // iterators;
        iterator begin()
        {
            return myset.begin();
        }
        const_iterator begin() const
        {
            return this->myset.begin();
        }
        iterator end()
        {
            return myset.end();
        }
        const_iterator end() const
        {
            return this->myset.end();
        }
        reverse_iterator rbegin()
        {
            return myset.rbegin();
        }
        const_reverse_iterator rbegin() const
        {
            return myset.rbegin();
        }
        reverse_iterator rend()
        {
            return myset.rend();
        }
        const_reverse_iterator rend() const
        {
            return myset.rend();
        }

        // Capacity:
        bool empty() const
        {
            return (myset.size() == 0);
        }
        size_type size() const
        {
            return myset.size();
        }
        size_type max_size() const
        {
            return this->myset.max__size();
        }
        // Modifiers:
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            return myset.insert(val);
        }
        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            myset.insert(val);
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
                    this->myset.delete_(*it);
            }
        }
        size_type erase(const key_type &k)
        {
            iterator it;
            it = find(k);
            if (it == end())
                return 0;
            this->myset.delete_(*it);
            return 1;
        }
        void erase(iterator first, iterator last)
        {
            iterator it;
            for (it = first; it != last; it++)
            {
                this->myset.delete_(*it);
            }
        }
        void swap (set &x)
        {
            this->myset.swap(x.myset);
        }
        void clear()
        {
            this->erase(begin(), end());
        }
        // Observers:
        key_compare key_comp() const
        {
            return myset.getcompare();
        }
        // value compare ??
        value_compare value_comp() const
        {
            // value_compare compare(key_comp());
            return myset.getcompare();;
        }

        // operations
        iterator find(const key_type &k)
        {
            iterator it;
            for (it = begin(); it != end(); it++)
            {
                if (*it == k)
                    return it;
            }
            return end();
        }
        const_iterator find(const key_type &k) const
        {
            const_iterator it;
            for (it = begin(); it != end(); it++)
            {
                if (it == k)
                    return it;
            }
            return end();
        }
        size_type count(const key_type &k) const
        {
            return this->myset.count(k);
        }
        iterator lower_bound(const key_type &k)
        {
            return this->myset.lower_bound(k);
        }
        const_iterator lower_bound(const key_type &k) const
        {
            return this->myset.const_lower_bound(k);
        }
        iterator upper_bound(const key_type &k)
        {
            return this->myset.upper_bound(k);
        }
        const_iterator upper_bound(const key_type &k) const
        {
            return this->myset.upper_bound(k);
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
            return myset.get_alloc();
        }

    private:
        allocator_type alloc;
        value_type cc;
        size_type size_;
        Compare cmp;
        Red_Blacl_Tree_set<key_type, value_type, allocator_type, Compare> myset;
    };
} // namespace ft

#endif
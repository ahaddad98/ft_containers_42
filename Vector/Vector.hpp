/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:45:39 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/20 16:09:59 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <string.h>
#include <stdio.h>

namespace ft
{
    template <typename T>
    class Vector
    {
        private:
            T *m_Data;
            size_t m_Size;
            size_t m_Capacity; // how mush memory we will allocated
        private:
            void ReAlloc(size_t newCapacity)
            {
                T *newBlock = new T[newCapacity]; 
                if (newCapacity < m_Size)
                    m_Size = newCapacity;
                
                for (size_t i = 0; i < m_Size; i++)
                    newBlock[i] = m_Data[i];
                delete[] m_Data;
                m_Data = newBlock;
                m_Capacity = newCapacity;
            }
        public:
        Vector<T>()
        {
            ReAlloc(2);
        }
        // ===================== algorithms for vector ============================
        void PushBack(const T &value)
        {
            if (m_Size > m_Capacity)
                ReAlloc(m_Capacity + m_Capacity /2);
            m_Data[m_Size] = value;
            m_Size++; 
        }
        void PopBack()
        {
            if (m_Size > 0)
            {
                m_Size--;
                m_Data[m_Size].~T(); 
            }  
        }
        void clear()
        {
            for (int i = m_Size - 1; i >= 0; i--)
            {
                m_Data[i].~T();
            }
            m_Data->~T();
            m_Size = 0;
        }
        size_t Size() const
        {
            return m_Size;
        }
        // ================= operators ========================
        const T& operator[](size_t index) const
        {
            if (index > m_Size)
            {
            }
            return m_Data[index];
        }
        T& operator[](size_t index)
        {
            return m_Data[index];
        }
        // ==================== constructors and desructor ==========
        Vector<T>(int n)
        {
        }
        Vector<T>(int n, int i)
        {
        }
        ~Vector()
        {
        }
    };
}
#endif
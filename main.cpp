/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/04 14:09:26 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>
#include "Vector/iterator.hpp"

int main()
{
    ft::vector<int> vect;
    vect.push_back(2);
    vect.push_back(23);
    vect.push_back(4);
    vect.push_back(4);
    vect.push_back(42);
    vect.push_back(43);
    vect.push_back(44);


    for (ft::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    {
        std::cout << *i << " ";
    }
    vect.insert(vect.begin() , 6);
    std::cout << "after insert" << std::endl;
    for (ft::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    {
        std::cout << *i << " ";
    }
    return 0;
}
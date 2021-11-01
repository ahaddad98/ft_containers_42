/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/01 17:42:19 by ahaddad          ###   ########.fr       */
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
    // vect.push_back(4);
    // // vect[1] = 3;
    // // vect[2] = 4;

    for (ft::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    {
        std::cout << *i << " ";
    }
    // // ft::vector<int>::iterator i = vect.begin();
    // // std::cout << std::endl;
    // vect.insert(vect.begin()+2 , 6);
    // std::cout << "after insert" << std::endl;
    // for (ft::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    // {
    //     std::cout << *i << " ";
    // }
    return 0;
}
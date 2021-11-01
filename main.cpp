/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/01 11:21:10 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>
#include "Vector/iterator.hpp"

int main()
{
    ft::vector<int> vect(3);
    vect[0] = 2;
    vect[1] = 3;
    vect[2] = 4;

    for (ft::vector<int>::reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}

// int main()
// {

//     return 0;
// }
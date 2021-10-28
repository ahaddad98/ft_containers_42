/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/28 18:41:59 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>
#include "Vector/iterator.hpp"

int main()
{
    ft::vector<std::string> vect(3);
    vect[0] = "2";
    vect[1] = "3";
    vect[2] = "4";

    for (ft::vector<std::string>::iterator i = vect.begin(); i != vect.end(); i++)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:32 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/18 19:47:17 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/Map.hpp"
#include "Vector/Vector.hpp"
#include "Stack/Stack.hpp"
#include <vector>


int main()
{
    std::vector<int> vect(10, 0);
    vect.clear();
    std::allocator<int> alloc;
    int *p = alloc.allocate(1);
    p[4] = 4;
    // vect.
    // alloc.deallocate(); 
    return 0;
}
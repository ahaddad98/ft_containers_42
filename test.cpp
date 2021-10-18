/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:55:41 by ahaddad           #+#    #+#             */
/*   Updated: 2021/10/18 20:11:07 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>
#include <string>
 
int main(){
  
  std::cout << std::endl;

  std::allocator<int> intAlloc; 

  std::cout << "intAlloc.max_size(): " << intAlloc.max_size() << std::endl;
  int* intArray = intAlloc.allocate(100);

  std::cout << "intArray[4]: " << intArray[4] << std::endl;
 
  intArray[4] = 2011;

  std::cout << "intArray[4]: " << intArray[4] << std::endl;
 
  intAlloc.deallocate(intArray, 100);

  std::cout << std::endl;
 
  std::allocator<double> doubleAlloc;
  std::cout << "doubleAlloc.max_size(): " << doubleAlloc.max_size() << std::endl;
  
  std::cout << std::endl;

  std::allocator<std::string> stringAlloc;
  std::cout << "stringAlloc.max_size(): " << stringAlloc.max_size() << std::endl;
 
  std::string* myString = stringAlloc.allocate(3); 
 
  stringAlloc.construct(myString, "Hello");
  stringAlloc.construct(myString + 1, "World");
  stringAlloc.construct(myString + 2, "!");
 
  std::cout << myString[0] << " " << myString[1] << " " << myString[2] << std::endl;
 
  stringAlloc.destroy(myString);
  stringAlloc.destroy(myString + 1);
  stringAlloc.destroy(myString + 2);
  stringAlloc.deallocate(myString, 3);
  
  std::cout << std::endl;
  
}


// #include <iostream>
// #include <vector>
// int main()
// {
//     std::cout << "amine haddad is here" << std::endl;

//     std::vector<std::string> vect;
//     // vect.
//     return 0;
// }
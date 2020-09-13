#include <iostream>
#include <iterator>
#include "../include/search_complexity.hpp"

int minimum_in_an_array(int *first, int *last){

  auto medium = std::distance(first, last);

  while(first != last){
    medium = std::distance(first, last) / 2;
    std::cout <<"O: " << first[medium] << std::endl;
    if(first[medium] < first[medium - 1] && first[medium] < first[medium + 1]){
      return first[medium];
    }
    else{
      if(first[medium - 1] < first[medium + 1]){
        last = &last[-medium];
      }
      else{
        first = &first[medium];
      }
    }
    std::cout << "first: " << first[medium] <<"\nlast: " << last[medium] << std::endl;
    std::cout << *first << std::endl;
    std::cout << *last << std::endl;
  }
  return -1;

}

int identity(int *first, int *last){

  auto medium = std::distance(first, last);
  int aux = 0;
  std::cout << medium << std::endl;

  while(first != last){
    medium = std::distance(first, last) / 2;
    aux = aux + medium-1;
    std::cout << "aux: " << aux << std::endl;
    std::cout << "medium: " << medium << std::endl;
    std::cout << "first[m]:" << first[medium] << std::endl;
    if(first[medium - 1] == aux){
      return medium;
    }else{
      if(medium-1 < first[medium - 1]){
        last = &last[-medium];
      }else{// medium-1 > first[medium-1]
        first = &first[medium];
      }
    }
  }
  return 0;
}

#include <iostream>
#include "include/search_complexity.hpp"
void print_vector(int *first, int *last);

int main(){

  int vet[]{8, 7, 9, 10, 11, 12, 13, 14, 15, 16};
//  int vet[]{1, 2, 3, 4, 5, 6, 6, 7, 8, 9};
//  int vet[]{-2, -1, 0, 1, 2, 3, 4, 7, 9, 10};
  int aux{0};
  size_t max_size{sizeof(vet) / sizeof(vet[0])};

  print_vector(&vet[0], &vet[max_size]);
  
  aux = minimum_in_an_array(&vet[0], &vet[max_size]);

  //identity(&vet[0], &vet[max_size]);
  //std::cout << "aux: " << aux << std::endl;

  return 0;
}

void print_vector(int *first, int *last){
  std::cout << "V [ ";

  while(first != last){
    std::cout << *first <<" ";
    first++;
  }
  std::cout <<"]" << std::endl;
}

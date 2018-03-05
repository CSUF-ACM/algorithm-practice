// Created by Roy Redman IV
#include <iostream>

int add_ary(int[], int);

int main() { 
  int ary[] = {1,2,3,4,5,6};
  std::cout << "Count of the array is " << add_ary(ary, 6) << std::endl;
}

//Input: A filled array to be counted, and the size of the array
//Output: The total of all the elements in the array added together
//Assumptions: The size is not negative; The size is not larger than the array size
int add_ary(int ary[], int size) {
  if (size <= 0)
    return 0;

  return ary[size-1] + add_ary(ary, size-1);
}


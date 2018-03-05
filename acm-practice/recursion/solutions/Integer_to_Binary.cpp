// Created by Roy Redman IV
#include <iostream>

void Integer_to_Binary(int);

int main() { 
  std::cout << "The Integer_to_Binary of \"6\" is: " << std::endl;
  Integer_to_Binary(6);
  std::cout << std::endl;
}

//Input: An integer
//Output: The binary equivalent to the integer passed as an argument.
//Assumptions: The integer is not a negative number 
void Integer_to_Binary (int num) {
  if (num > 0) {
    Integer_to_Binary(num/2);
    std::cout << num %2;
  }

}

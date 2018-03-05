// Created by Roy Redman IV
#include <iostream>

int factorial(int);

int main() { 
  std::cout << "Factorial of 4 is: " << factorial(4) << std::endl; 
}

//Input: A number that we will calculate the Factorial of
//Output: The value of the Factorial
//Assumptions: The number passed is not negative
int factorial (int number) {
  if (number == 1 || number == 0) {
   return 1;
  }
  return number * factorial(number-1);
}

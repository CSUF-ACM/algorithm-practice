// Created by Roy Redman IV
#include <iostream>

int exponent_calc(int, int);

int main() { 
  std::cout << "10^5 is :" << exponent_calc(10, 5) << std::endl;
}

//Input: A base number and the exponent value
//Output: The value of the base number to the exponential power
//Assumptions: The power variable is not negative
int exponent_calc(int number, int power) {
  if (power == 1)
    return number;

  return number * exponent_calc(number, power-1);
}

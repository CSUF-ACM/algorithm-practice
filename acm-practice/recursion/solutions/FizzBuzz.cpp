// Created by Roy Redman IV
#include <iostream>

void FizzBuzz(int);

int main() { 
  std::cout << "FizBuz at 40 is" << std::endl;
  FizzBuzz(40);
}

//Input: An integer
//Output: Either a number, "Fizz", "Buzz" or "FizzBuzz" depending on the scenarios
//Assumptions: The number passed is not negative
void FizzBuzz(int num) {
  if (num == 0) {
   std::cout << "0:" << std::endl;
   return;
  }

  if (num % 3 == 0)
   std::cout << "Fizz";

  if (num % 5 == 0)
   std::cout << "Buzz";

  if (num % 5 != 0 && num %3 != 0)
   std::cout << num;

  std::cout << std::endl;
  FizzBuzz(num-1);
}

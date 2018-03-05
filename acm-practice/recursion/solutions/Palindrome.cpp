// Created by Roy Redman IV
#include <iostream>

bool Palindrome(std::string, int=0);

int main() { 
  std::cout << "tacocat Palindrome check is: " << Palindrome("tacocat") << std::endl;
}

//Input: A string that contains a possible Palindrome, and a counter (that doesn't need to be passed in the function call)
//Output: A bool value. True(1) means that it is a Palindrome, and False(0), if it is not.
//Assumptions: The string does not have any spaces in it.
bool Palindrome(std::string word, int index) {
  if ((word.size()-1)-index <= index) {
    return true;
  }
  else if (tolower(word[(word.size()-1)-index]) == tolower(word[index])) {
    return Palindrome(word, index+1);
  }
  else
    return false;
}

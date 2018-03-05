// Created by Roy Redman IV
#include <iostream>

std::string remove_x(std::string);

int main() { 
  std::cout << " \"xesxtxerxx\" without the x is:" << remove_x("xesxtxerxx") << std::endl;
}

//Input: A string that contains x's in it
//Output: The same string without any x's in it
//Assumptions: None
std::string remove_x(std::string word) {
  if (word.size() == 0)
    return word;
  char letter = word[0];
  if (letter == 'x')
    return remove_x(word.substr(1));

  return letter + remove_x(word.substr(1));
}

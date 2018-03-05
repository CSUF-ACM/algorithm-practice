// Created by Roy Redman IV
#include <iostream>

bool elfish(std::string, int=0, std::string="elf");

int main() { 
  std::cout << "Elfish check on \"whiteleaf\"is " << elfish("whiteleaf") << std::endl;
}

//Input: A string that is posibly "elfish", a default index, and a default string "elf"
//Output: A bool value. True(1) if the string is "elfish" and False(0) if not.
//Assumptions: The user is not going to pass any second or third arguments, to mess up the results.
bool elfish(std::string word, int index, std::string elf) {
  if (index == 3)
    return true;

  else if (word.find(elf[index]) != std::string::npos)
    return elfish(word, index+1, elf);

  else
    return false;
}

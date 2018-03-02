# ICPC Theme: Recursion  
The following problems all involve recursion will be ranked in terms of difficulty. You are welcome to use any programming language you would like, but my solutions will be based off of C++. You are allowed to use any library you would like, but the libraries that I used for these problems were `iostream` and `ctime`. You are allowed to use as many parameters as you need to complete the task. The only main requirement is that you use recursion to solve the problem.  


### Easy:
1. Factorial: Create a recursive function that will return the factorial of a passed argument. This program will assume that you are not passing a negative value. The following are examples of the input and output.  

```c++
	Factorial(5);	// 120  
	Factorial(3);	// 6  
	Factorial(1);	// 1  
	Factorial(0);	//1  
```

2. exponent_calculator: This is also known and finding the value of something raised to a power. Your function needs to be able to receive the base number, and to what power you are raising it to. The following are examples of the input and output.  

```c++
	exponent_calc(2, 3);	// 8  
	exponent_calc(1, 5);	// 1  
	exponent_calc(3, 3);	// 27  
```

3. array_counter: Create a function that will add up all the values inside a specific array. For example, if I passed an array with the values [1, 2, 3, 4, 5], the returned value should be 15. This recursive function should be able to work with an array of any size.  

4. remove_x: Create a function that will remove all occurrences of the letter 'x' inside of a string value. The following are examples of the input and output.  

```c++
	remove_x("xxnoobSlayerxx");	// noobSlayer  
	remove_x("existence");	// eistence  
	remove_x("pancakes");	// pancakes  
```

### Medium:

5. FizzBuzz: Create a function that will count down from the parameter that was passed, to 0. While it counts down, it will check if the number is divisible by 3. If it is, it would output "Fizz" to the screen. If the number is divisible by 5, it would output "Buzz" to the screen. If the number is divisible by both 3 and 5, it will output "FizzBuzz" to the screen. Finally, if it is not divisible by either of the two values, it will output the number that it is at. This program will assume you are not passing in a negative value.  


6. Palindrome: A palindrome is when a word is spelled exactly the same backwards and forwards. For example, "mom" is "mom" spelled backwards and "racecar" is "racecar" spelled backwards. This function will receive a string, and check if it is a Palindrome or not. The return value of the function will be a bool value to indicate if it is a palindrome or not. The function assumes that there are no spaces in the string. For an added bonus (optional), allow your program to ignore case-sensitive letters, for example "Mom" will still be considered a Palindrome.  

7. saveAndDelete: If a programmer has a linked list, but wants to have all of its elements data saved into an array and delete its linked list, they should be able to do that. Create a function that will accept an empty array and a pointer to a linked list of your choice, fill up the array with the contents of the linked list, then delete the linked list. This function should be able to work with a linked list of any size. The order in which the elements are saved into the array do not matter. Once the function is completed, the pointer to the linked list should be empty.  

This function will require a basic amount of knowledge with linked lists and pointers. Normally, linked lists should ALWAYS be used inside of classes for security purposes, but since this theme is more based on recursion rather than classes, a stuct can be used to create the linked list. I have supplied some code that will fulfill the requirements of creating a linked list, and printing the linked list, to save time.  

```c++
struct Node{
  int data;
  Node* next; 
  Node(int d, Node* nxt) {
    data = d;
    next = nxt;
  }
};  

```

```c++
Node* Create_LL(int size, Node* current) {
  if (size == 0)
    return NULL;

  current = new Node(rand() % 100 + 1, NULL);
  current->next = Create_LL(size-1, NULL);
  return current;
}  
```

```c++
void Print_LL(Node* current) {
  if (current == NULL) {
   return;
                        }
  std::cout << current->data << std::endl;
  Print_LL(current->next);
}   
```

The following will create the linked list of size 10 in the main to the pointer "Head":  
```c++
int main() {
	Node* Head = NULL;
	Head = Create_LL(10, Head); 
}
```

### Hard:

8.  elfish: A string is considered "elfish" if it contains the letters 'e', 'l' and 'f' inside a string and in any order. The function should return a bool statement (true or false) if the string is "elfish" or not. This function will assume that all letters in the string are lower-case. As said in the beginning of the document, you are allowed to use any library and its functions as you wish, but make sure there is still some form of recursion occurring on in this problem. Example: If I were to pass "Beautiful" into the function, it should return true. If I were to pass "penguin" into the function, it should return false.  

9. reverse_list: This function should allow a user to pass in a singly-linked list, and have it returned in reverse order. For example, a linked list looking like this:  

```
4 -> 10 -> 39 -> 94 -> NULL  
```

should be returned in this format:  
```
94 -> 39 -> 10 -> 4 -> NULL  
```

the code used to create the linked list and print out the linked list are supplied in problem #7. As a reminder, typically linked lists should almost ALWAYS be used inside classes for security purposes, but to try to avoid the complication of working with classes in this problem, we will use a struct. This reversed list should have no missing values from the original list passed in.   

### Interview Questions:  

10. Integer_to_Binary: This interview question will ask you to pass an Integer to a function, and have the function output the binary(base 2) value onto the screen. This function should not have a function return datatype and would use cout (or any other type of output) in order to show the binary value. The decimal passed is expected to be a non-negative number.  For example, here are the following inputs and outputs:  

```c++
	Integer_to_Binary(128);	// 10000000  
	Integer_to_Binary(6);	// 110  
```

11. This last problem requires no coding. As you will see in your future interviews, creating/explaining programs is not the only way you can be tested on your knowledge of a concept. One of the hardest things programmers can do is to explain programming concepts to people that have have no prior programming knowledge. This leads to the final interview question:  

Explain the general concept of recursion, as if you were telling a child about it.   

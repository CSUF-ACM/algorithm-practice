// Created by Roy Redman IV
#include <iostream>
#include <ctime>

struct Node{
  int data;
  Node* next;
  Node(int d, Node* nxt) {
    data = d;
    next = nxt;
  }
};

Node* Create_LL(int, Node*);
void Print_LL(Node*);
void SaveAndDelete(int[], int, Node*);

int main() { 
  srand(time(NULL));
  Node* Head = NULL;
  int ary_size = 10;
  Head = Create_LL(ary_size, Head);
  int new_ary[ary_size];

  std::cout << "The linked list before saving to array:" << std::endl;
  Print_LL(Head);
  
  SaveAndDelete(new_ary, ary_size, Head);
  
  std::cout << "All the values in the array" << std::endl;
  for (int i = 0; i < ary_size; ++i) {
    std::cout << i+1 << ": " << new_ary[i] << std::endl;
  }

  std::cout << "The linked list after deleting it" << std::endl;
  
  // This should break the program if run on Visual Studio, since the pointer is not pointing to anything anymore
  Print_LL(Head);
  


}

//Input: A size of how big the Linked List will be and an empty pointer
//Output: The pointer to a linked list with random values in each Node
//Assumptions: the size is not negative.
Node* Create_LL(int size, Node* current) {
  if (size == 0)
    return NULL;

  current = new Node(rand() % 100 + 1, NULL);
  current->next = Create_LL(size-1, NULL);
  return current;
}

//Input: A pointer to a linked list
//Output: The value of each node in the linked list
//Assumptions: None
void Print_LL(Node* root) {
  if (root == NULL) {
   return;
                        }
  std::cout << root->data << std::endl;
  Print_LL(root->next);
}

//Input: An empty array, the size of the array, and the pointer to a linked list
//Output: A full array with all the values of the linked list, and a deleted linked list. The values in the array are backwards in order to show the usefulness of recursion moving forward, and also moving back towards the main.
//Assumptions: The size of the array is not larger than the actual array.
void SaveAndDelete(int ary[], int index, Node* current) {
  if (current == NULL)
    return;

  ary[index-1] = current->data;
  SaveAndDelete(ary, index-1, current->next);
  delete current;
}

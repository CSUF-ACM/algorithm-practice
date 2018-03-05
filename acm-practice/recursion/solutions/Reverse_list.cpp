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
Node* Reverse_list(Node*);
void Delete_LL(Node*);

int main() { 
  srand(time(NULL));
  Node* Head = NULL;
  int LL_size = 10;
  Head = Create_LL(LL_size, Head);

  std::cout << "The linked list before reversing it:" << std::endl;
  Print_LL(Head);
  
  Head = Reverse_list(Head);

  std::cout << "The linked list after reversing it:" << std::endl;
  Print_LL(Head);
  Delete_LL(Head);

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

//Input: A linked list
//Output: A linked list in its reverse order
//Assumptions: None
Node* Reverse_list(Node* current) {
  if (current == NULL || current->next == NULL)
    return current;

  Node* swapped_current = Reverse_list(current->next);
  current->next->next = current;
  current->next = NULL;
  return swapped_current;
}

//Input: A linked list
//Output: A deleted linked list
//Assumptions: the pointer is pointing to a linked list
void Delete_LL(Node* temp) {
  if (temp == NULL) {
    return;
  }

  Delete_LL(temp->next);
  delete temp;
}


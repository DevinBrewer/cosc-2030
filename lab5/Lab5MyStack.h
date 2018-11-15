/*
  Date: 10/21/18
  Name: Devin Brewer
  Desc: COSC_2030 Lab #5; Stacks and Queues
        Lab5MyStack.h

  Header file to create a stack from a vector
*/

#ifndef LAB5MYSTACK_h_
#define LAB5MYSTACK_h_

#include <vector>

class MyStack {
public:
  bool isEmpty() const;
  void push(char& c);
  char pull();
  std::vector<char> v;
};



#endif

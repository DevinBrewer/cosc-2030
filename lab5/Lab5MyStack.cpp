/*
  Date: 10/21/18
  Name: Devin Brewer
  Desc: COSC_2030 Lab #5; Stacks and Queues
        Lab5MyStack.cpp
*/

#include "Lab5MyStack.h"

/* --- Methods --- */
bool MyStack::isEmpty() const {
  return v.empty();
}

void MyStack::push(char& c) {
  v.push_back(c);
}

char MyStack::pull() {
  char c = v.back();
  v.pop_back();
  return c;
}

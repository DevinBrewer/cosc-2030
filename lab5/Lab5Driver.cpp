/*
  Date: 10/21/18
  Name: Devin Brewer
  Desc: COSC_2030 Lab #5; Stacks and Queues
        Lab5Driver.cpp
*/

// File change, ignore

// Add the necesary files and imports
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <list>
using namespace std;

#include "Lab5MyStack.h"

// Lab5.2
string stringReversal1(string input) {
  // Create a string to hold the result of the reversal
  string outputString = "";

  // Create a stack to hold the data
  stack<char> s;

  // Fill the stack with the data from the string left to right
  for (int i = 0; i < input.length(); i++) {
    s.push(input[i]);
  }

  // Pop the data out of the stack to reverse the order
  while (!s.empty()) {
    outputString += s.top();
    s.pop();
  }

  // Return the new string
  return outputString;
}

// Lab 5.3
string stringReversal2(string input) {
  // Create a string to hold the result of the reversal
  string outputString = "";

  // Create a vector to hold the data
  vector<char> v;

  // Fill the vecotr with data from the string
  for (int i = 0; i < input.length(); i++) {
    v.push_back(input[i]);
  }

  // Pop the data in reverse order
  while (!v.empty()) {
    outputString += v.back();
    v.pop_back();
  }

  // Return the new string
  return outputString;
}

// Lab 5.4
string stringReversal3(string input) {
  // Create a string to hold the result of the reversal
  string outputString = "";

  // Create a list to hold the data
  list<char> l;

  // Fill the list with the data from the string
  for (int i = 0; i < input.length(); i++) {
    l.push_back(input[i]);
  }

  // Pop the data to reverse the order
  while(!l.empty()) {
    outputString += l.back();
    l.pop_back();
  }

  // Return the result
  return outputString;
}

// Lab5.5
string stringReversal4(string input) {
  // Create a string to hold the returning value
  string outputString = "";

  // Create a MyStack to hold the data
  MyStack ms;

  // Fill the vecotr with data from the string
  for (int i = 0; i < input.length(); i++) {
    ms.push(input[i]);
  }

  // Pop the data in reverse order
  while (!ms.isEmpty()) {
    outputString += ms.pull();
  }

  // Return the result
  return outputString;
}

int main() {

  // Test Lab5.2
  cout << "This is a test!" << endl;
  cout << stringReversal1("This is a test!") << endl << endl;

  // Test Lab5.3
  cout << "Does Lab5.3 work?" << endl;
  cout << stringReversal2("Does Lab5.3 work?") << endl << endl;

  // Test Lab5.4
  cout << "Things are looking well..." << endl;
  cout << stringReversal3("Things are looking well...") << endl << endl;

  // Test Lab5.5
  cout << "This is a final test." << endl;
  cout << stringReversal4("This is a final test.") << endl << endl;

  return 0;
}

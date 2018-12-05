#include "TrackingTree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// RANDOM STRING GENERATOR
static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

char getRandomChar() {
  return alphanum[rand() % (sizeof(alphanum)-1)];
}

int main() {

  // Create a single node to test its functionality
  Node snode = Node("acb123");

  snode.printData();

  snode.setEvent("This is a system test.");

  cout << "test" << endl;

  snode.printData();

  return 0;
}

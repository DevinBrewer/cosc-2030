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

string getRandomString(int size) {
  string randString;
  for (int i = 0; i < size; i++) {
    randString += getRandomChar();
  }
  return randString;
}

int main() {

  // Initialize the random seed
  cout << "Enter a seed: ";
  int seed;
  cin >> seed;
  srand(seed);

  // Create a single node to test its functionality
  Node snode = Node(getRandomString(8));

  snode.printData();

  snode.setEvent("This is a system test.");

  cout << "test" << endl;

  snode.printData();

  return 0;
}

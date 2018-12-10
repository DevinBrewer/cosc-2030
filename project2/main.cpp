#include "TrackingTree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



int main() {

  // Initialize the random seed
  cout << "Enter a seed: ";
  int seed;
  cin >> seed;
  srand(seed);

  // // Create a single node to test its functionality
  // Node snode = Node(getRandomString(8));
  //
  // snode.printData();
  //
  // snode.setEvent("This is a system test.");
  //
  // cout << "test" << endl;
  //
  // snode.printData();

  // Create a tracking tree to test its functionality
  TrackingTree tree = TrackingTree();

  tree.viewTree();

  cout << "Constructing layer...\n";
  tree.newLayer();

  tree.viewTree();

  cout << "Constructing layer...\n";
  tree.newLayer();

  tree.viewTree();

  cout << "Constructing layer...\n";
  tree.newLayer();

  tree.viewTree();

  return 0;
}

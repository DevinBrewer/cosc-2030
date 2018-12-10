#include <math.h>
#include <iostream>
#include "TrackingTree.h"



// Constructor
TrackingTree::TrackingTree() {
  // Create a node with the new information
  TrackingTree_.push_back(Node(getRandomString(8), getRandomString(64)));
  // TrackingTree_.at(0).setEvent(getRandomString(1024));

  // Update the information about the tree
  totNodes_ = 1;
}

void TrackingTree::newLayer() {
  for (int i = 0; i < (totNodes_ + 1); i++) {
    int pInd = floor((totNodes_ + i + 1) / 2.0) - 1;
    TrackingTree_.push_back(Node(TrackingTree_.at(pInd).getID(), getRandomString(64)));

    updateParent(TrackingTree_.size()-1);
  }

  totNodes_ = TrackingTree_.size();
}

void TrackingTree::updateNode(std::string ID, std::string rawEvent) {

}

void TrackingTree::viewTree() {
  for (int i = 0; i < TrackingTree_.size(); i++) {
    std::cout << "-------------------\n";
    TrackingTree_.at(i).printData();
  }
  std::cout << "-------------------\n";
}

void TrackingTree::updateParent(int ind) {
  if (ind != 0) {

    Node cNode = TrackingTree_.at(ind);
    int pInd = floor((ind+1)/2.0)-1;
    Node * pNode = &TrackingTree_.at(pInd);
    std::string contents = ::hash(cNode.getData());

    if (ind % 2 == 0) {
      // Current node is left child
      pNode->updateLeftHash(contents);
      updateParent(pInd);
    } else {
      // Current node is right child
      pNode->updateRightHash(contents);
      updateParent(pInd);
    }

  }
}

// RANDOM STRING GENERATOR
static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

char TrackingTree::getRandomChar() {
  return alphanum[rand() % (sizeof(alphanum)-1)];
}

std::string TrackingTree::getRandomString(int size) {
  std::string randString;
  for (int i = 0; i < size; i++) {
    randString += getRandomChar();
  }
  return randString;
}

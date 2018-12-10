#include <math.h>
#include <iostream>
#include "TrackingTree.h"



// Constructor
TrackingTree::TrackingTree() {
  // Create a node with the new information
  TrackingTree_.push_back(Node(getRandomString(8), getRandomString(64)));
  // TrackingTree_.at(0).setEvent(getRandomString(1024));

  // Update the information about the tree
  layerCount_ = 1;
  index_ = 0;
  totNodes_ = 1;
}

void TrackingTree::newLayer() {
  // Using add a new layer to the tree with 2^layerCount nodes
  for (int i = 1; i <= (totNodes_ + 1); i++) {
    TrackingTree_.push_back(Node(TrackingTree_.at(floor((totNodes_ + i)/2) - 1).getID(), getRandomString(64)));
  }
  layerCount_ += 1;
  totNodes_ = pow(2, layerCount_) - 1;
}

void TrackingTree::updateNode(std::string ID, std::string rawEvent) {

}

void TrackingTree::viewTree() {
  for (int i = 0; i < totNodes_; i++) {
    std::cout << "-------------------\n";
    TrackingTree_.at(i).printData();
  }
  std::cout << "-------------------\n";
}

void TrackingTree::updateParent() {

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

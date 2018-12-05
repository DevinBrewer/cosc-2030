#include "TrackingTree.h"

// Constructor
TrackingTree::TrackingTree() {
  TrackingTree_.push_back(Node("12345678"));
  layerCount_ = 1;
  index_ = 0;
}

void TrackingTree::newLayer() {
  // Using add a new layer to the tree with 2^layerCount nodes
  for (int i = 0; i < (2^layerCount); i++) {
    TrackingTree_.push_back()
  }
}

void TrackingTree::updateNode(std::string ID, std::string rawEvent) {

}

void TrackingTree::viewTree() {

}

void TrackingTree::updateParent() {

}

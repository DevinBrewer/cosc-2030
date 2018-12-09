#include "TrackingTree.h"

// Constructor
TrackingTree::TrackingTree(std::string rootNodeID) {
  TrackingTree_.push_back(Node(rootNodeID));
  layerCount_ = 1;
  index_ = 0;
}

void TrackingTree::newLayer() {
  // Using add a new layer to the tree with 2^layerCount nodes
  // for (int i = 0; i < (2^layerCount_); i++) {
  //   TrackingTree_.push_back();
  // }
}

void TrackingTree::updateNode(std::string ID, std::string rawEvent) {

}

void TrackingTree::viewTree() {

}

void TrackingTree::updateParent() {

}

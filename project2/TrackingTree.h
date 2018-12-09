#ifndef TRACKING_TREE_H
#define TRACKING_TREE_H

#include "Node.h"

class TrackingTree {
public:
  // Constructors
  TrackingTree(std::string rootNodeID);

  // Accessable functions
  void newLayer();
  void updateNode(std::string ID, std::string rawEvent);
  void viewTree();

private:
  // Inaccessable functions
  void updateParent();

  // Inaccessable variables
  std::vector<Node> TrackingTree_;
  int layerCount_;
  int index_;
};

#endif

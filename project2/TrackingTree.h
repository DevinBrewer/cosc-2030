#ifndef TRACKING_TREE_H
#define TRACKING_TREE_H

#include "Node.h"

class TrackingTree {
public:
  // Constructors
  TrackingTree();

  // Accessable functions
  void newLayer();
  void updateNode(string ID, string rawEvent);

private:
  // Inaccessable functions
  void updateParent();

  // Inaccessable variables
  Node TrackingTree_[];
  int layerCount_;
  int index_;
  
}

#endif

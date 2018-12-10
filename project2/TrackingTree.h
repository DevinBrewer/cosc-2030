#ifndef TRACKING_TREE_H
#define TRACKING_TREE_H

#include "Node.h"

class TrackingTree {
public:
  // Constructors
  TrackingTree();

  // Accessable functions
  void newLayer();
  void updateNode(std::string ID, std::string rawEvent);
  void viewTree();

private:
  // Inaccessable functions
  void updateParent();
  char getRandomChar();
  std::string getRandomString(int size);

  // Inaccessable variables
  std::vector<Node> TrackingTree_;
  int layerCount_;
  int index_;
  int totNodes_;
};

#endif

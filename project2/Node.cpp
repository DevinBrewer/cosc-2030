#include "Node.h"

// Constructor
Node::Node(string parentID) {
  // Set the parentID
  parentID_ = parentID;

  // Initialize all other values to NULL
  ID_ = NULL;
  rawEvent_ = NULL;
  RHASH_ = NULL;
  LHASH_ = NULL;
}

void Node::updateRightHash(string RHASH) {
  RHASH_ = RHASH;
  RHISTH_.push_back(RHASH_);
}

void Node::updateLeftHash(string LHASH) {
  LHASH_ = LHASH;
  LHISTH_.push_back(LHASH_);
}

void Node::setEvent(string rawEvent) {
  // Set the event
  rawEvent_ = rawEvent;

  // Update the ID of the node
  setID(hash(rawEvent_ + parentID_));
}

void Node::setID(string ID) {
  ID_ = ID;
}

#include "Node.h"

// Constructor
Node::Node(std::string parentID) {
  // Set the parentID
  parentID_ = parentID;

  // Initialize all other values to NULL
  ID_ = "";
  rawEvent_ = "";
  RHASH_ = "";
  LHASH_ = "";
}

void Node::updateRightHash(std::string RHASH) {
  RHASH_ = RHASH;
  RHISTH_.push_back(RHASH_);
}

void Node::updateLeftHash(std::string LHASH) {
  LHASH_ = LHASH;
  LHISTH_.push_back(LHASH_);
}

void Node::setEvent(std::string rawEvent) {
  // Set the event
  rawEvent_ = rawEvent;

  // Update the ID of the node
  setID(hash(rawEvent_ + parentID_));
}

// ostream& operator << (ostream& os) {
//   return os << "This is a test: " << ID_ << endl;
// }

void Node::setID(std::string ID) {
  ID_ = ID;
}

#include "Node.h"
#include <iostream>

// Constructor
Node::Node(std::string parentID, std::string rawEvent) {
  // Set the parentID
  parentID_ = parentID;
  setEvent(rawEvent);

  // Initialize all other values to NULL
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
  setID(::hash(rawEvent_ + parentID_));
}

void Node::printData() {
  std::cout << "ID: " << ID_ << "\n";
  std::cout << "Parent: " << parentID_ << "\n";
  std::cout << "RawE: " << rawEvent_ << "\n";
  std::cout << "LHASH: " << LHASH_ << "\n";
  std::cout << "RHASH: " << RHASH_ << "\n";
  if (!LHISTH_.empty()) { std::cout << "LHIST: " << LHISTH_.back() << "\n"; }
  if (!RHISTH_.empty()) { std::cout << "RHIST: " << RHISTH_.back() << "\n"; }
}

std::string Node::getID() {
  return ID_;
}

std::string Node::getData() {
  return ID_ + parentID_ + rawEvent_ + RHASH_ + LHASH_;
}

void Node::setID(std::string ID) {
  ID_ = ID;
}

#ifndef NODE_H
#define NODE_H

#include <vector>
#include "hash.h"

class Node {
public:
  // Constructors
  Node(std::string parentID); // Upon construction a node will receive only a parentID

  // Accessable functions
  void updateRightHash(std::string RHASH);
  void updateLeftHash(std::string LHASH);
  void setEvent(std::string rawEvent);
  void printData();

private:
  // Inaccessable functions
  void setID(std::string ID);

  // Inaccessable variables
  std::string ID_;
  std::string parentID_;
  std::string rawEvent_;
  std::string RHASH_;
  std::string LHASH_;
  std::vector<std::string> RHISTH_;
  std::vector<std::string> LHISTH_;
};

#endif

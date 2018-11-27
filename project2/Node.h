#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Node {
public:
  // Constructors
  Node(string parentID); // Upon construction a node will receive only a parentID

  // Accessable functions
  void updateRightHash(string RHASH);
  void updateLeftHash(string LHASH);
  void setEvent(string rawEvent);

private:
  // Inaccessable functions
  void setID(string ID);

  // Inaccessable variables
  string ID_;
  string parentID_;
  srting rawEvent_;
  string RHASH_;
  string LHASH_;
  vector<string> RHISTH_;
  vector<string> LHISTH_;
}







#endif

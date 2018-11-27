#include "hash.h"
#include <string>
#include <unordered_map>

/* PRECONDITION: length of unhashedString >= 8 */
/* POSTCONDITION: hashed string of length 8 returned */
std::string hash(std::string unhashedString) {
  return std::hash<std::string>{}(unhashedString);
  // return unhashedString.substr(0, 8);
}

#include "hash.h"
#include <string>
#include <unordered_map>

/* PRECONDITION: length of unhashedString > 0 */
/* POSTCONDITION: hashed string of length 8 returned */
std::string hash(std::string unhashedString) {
  char buffer[9];
  itoa(std::hash<std::string>{}(unhashedString), buffer, 16);
  return std::string(buffer);
}

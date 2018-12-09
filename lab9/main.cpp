#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main() {
  // Open the file and read it word by word
  ifstream fin;
  fin.open("example.txt");

  if (!fin.is_open()) {
    cout << "Error opening file..." << endl;
    return 0;
  }

  // Create a map to hold the word and its number of repetitions
  map<string, int> tally;
  string word;
  while (fin >> word) {
    ++tally[word];  // Increase count of word inside map
  }

  // Write to an output file
  ofstream fout;
  fout.open("output.txt");

  if (!fout.is_open()) {
    cout << "Error opening file..." << endl;
    return 0;
  }

  // Create an iterator to read through the map inorder
  for (map<string, int>::iterator itr = tally.begin(); itr != tally.end(); ++itr) {
    // cout << itr->first << ":" << itr->second << endl;
    string word = itr->first;
    int count = itr->second;
    for (int i = 0; i < count; i++) {
      fout << word << "\n";
    }
  }

  fin.close();
  fout.close();
  return 0;
}

/*
  Date: 10/13/18
  Name: Devin Brewer
  Desc: COSC_2030 Lab #4; Vectors and Iterators
*/

#include <algorithm>  // Sort

#include "VectorDriver.h"

int main() {
  // cout << "  ..:: B E G I N  S A M P L E  C O D E  ::.." << endl << endl;
  // vector<short> sample_vector(5);
  //
  // cout << "new vector: ";
  // print(sample_vector);
  // cout << endl;
  //
  // fill_vector(sample_vector);
  //
  // cout << "filled vector: ";
  // print(sample_vector);
  // cout << endl;
  //
  // cout << "sum of vector's elements: " << compute_sum(sample_vector) << endl;
  // cout << endl << "   ..::  E N D   S A M P L E  C O D E  ::.." << endl;

  /*   ~L4.P1~   */
  cout << "*L4.P1*" << endl;
  vector<short> a;

  cout << "new vector a: ";
  print(a);
  cout << endl;

  // Call add_numbers once then twice and compare the results
  add_numbers(a);
  cout << "a: ";
  print(a);
  cout << endl;

  add_numbers(a);
  cout << "a: ";
  print(a);
  cout << endl;

  cout << endl;
  /*   ~L4.P2~   */
  cout << "*L4.P2*" << endl;
  vector<short> b;

  // Fill vector b with random numbers
  add_numbers(b);

  // Output the normal vector
  cout << "b: ";
  print(b);
  cout << endl;

  // Output the even indecies
  cout << "even b: ";
  print_even(b);
  cout << endl;

  cout << endl;
  /*   ~L4.P3~   */
  cout << "*L4.P3*" << endl;
  vector<short> c;

  // Fill the vector with random numbers
  add_numbers(c);

  // Test the function
  cout << is_present(c, c.at(2)) << endl;
  cout << is_present(c, -1) << endl;  // The minumum value of rand is > 0 so -1 shouldnt ever be in the vector

  cout << endl;
  /*   ~L4.P4~   */
  cout << "*L4.P4*" << endl;
  vector<short> d;
  d.push_back(213);
  d.push_back(654);
  d.push_back(123);
  d.push_back(678);
  d.push_back(124);

  cout << "unsorted: ";
  print(d);
  cout << endl;

  std::sort(d.begin(), d.end());

  cout << "sorted: ";
  print(d);
  cout << endl;

  return 0;
}

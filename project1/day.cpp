/*
  Date: 10/24/18
  Name: Devin Brewer
  Desc: COSC_2030 Project #1; Blood Sugar
        day.cpp

  This is the driver class for day.h
*/

#include "day.h"

/* --- Methods --- */
Day::Day() {
  sum = 0;
  overflowCounter = 0;
  max = INT_MIN;
  min = INT_MAX;
  count = 0;
}

void Day::summary() {
  cout << "The daily sum so far is: " << sum << endl;
  cout << "The daily max so far is: " << max << endl;
  cout << "The daily min so far is: " << min  << endl;
  cout << "The number of readings so far is: " << count << endl;
}

void Day::update(int data) {
  // Update the daily readings
  // Make sure sum doesnt overflow
  if (sum > (INT_MAX - data)) {
    // Dont add to sum, it will overflow
    overflowCounter++;
    sum = data - (INT_MAX - sum);
  }


  if (max < data) max = data;
  if (min > data) min = data;
  count++;
}

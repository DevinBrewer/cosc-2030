/*
  Date: 10/24/18
  Name: Devin Brewer
  Desc: COSC_2030 Project #1; Blood Sugar
        day.cpp

  This is the driver class for week.h
*/

#include "week.h"

/* --- Methods --- */
Week::Week() {
  sum = 0;
  overflowCounter = 0;
  max = INT_MIN;
  min = INT_MAX;
  count = 0;
  delta = 0;
  dayIndex = 0;
}

void Week::summary() {
  cout << "The weekly sum so far is: " << sum << endl;
  cout << "The weekly max so far is: " << max << endl;
  cout << "The weekly min so far is: " << min << endl;
  cout << "The number of readings so far is: " << count << endl;
  cout << "The biggest delta so far is: " << delta << endl;
}

void Week::update(int data) {
  dayArray[dayIndex].update(data);  // Update the dataArray

  // Update the value for the weekly readings
  // Make sure sum doesnt overflow
  if (sum > (INT_MAX - data)) {
    // Dont add to sum, it will overflow
    overflowCounter++;
    sum = data - (INT_MAX - sum);
  }


  if (max < data) max = data;
  if (min > data) min = data;
  count++;

  // Find the biggest delta
  if (dayIndex > 0) {
    if (delta < abs(dayArray[dayIndex].sum - dayArray[dayIndex-1].sum)) {
      delta = abs(dayArray[dayIndex].sum - dayArray[dayIndex-1].sum);
    }
  }
}

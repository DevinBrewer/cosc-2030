/*
  Date: 10/24/18
  Name: Devin Brewer
  Desc: COSC_2030 Project #1; Blood Sugar
        week.h

  Header file to create a data structure for a weeks worth of information
*/

#ifndef WEEK_h_
#define WEEK_h_

#include "day.h"

// Create the class
class Week {
// NOTE: Security is currently not a concern, thus all variables and methods will be defined publicly instead of using getters and setters
public:
  /* --- Methods --- */
  Week(); // Default constructor
  void summary(); // Outputs a weekly summary
  void update(int data);  // Updates the weekly summary based off data

  /* --- Variables --- */
  int sum;  // Stores the sum of the 7 days in a week
  int overflowCounter;  //Stores the amount of times sum overflows
  int max;  // Stores the largest number of all readings
  int min;  // Stores the smallest number of all readings
  int count;  // Stores the total count of blood sugar readings
  int delta;  // Stores the largest change of readings; int as day of week

  Day dayArray[7];  // Holds every day for a week
  short dayIndex; // Holds the index to iterate over the dayArray
};

#endif

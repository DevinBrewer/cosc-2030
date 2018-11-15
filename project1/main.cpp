
/*
  Date: 10/24/18
  Name: Devin Brewer
  Desc: COSC_2030 Project #1; Blood Sugar
        main.cpp

  This file will contain the main function and handle all subprograms
*/

// Add the necessary imports
#include <string>

// Include the day class
#include "week.h"

int main() {
  // Define the main variables to be used
  Week weekArray[2];
  short weekIndex = 0;

  // Output relevant information to the user
  cout << "Controls:" << endl;
  cout << "D - Show current daily summary" << endl;
  cout << "W - Show current weekly summary" << endl;
  cout << "N - Move onto the next day (NOTE: Limited to 14 days)" << endl;
  cout << "Q - Prematurely quit (NOTE: All data will be lost)" << endl;

  // Continuously gather input from the user
  string input = "a";
  while (input != "Q" && input != "q" && weekIndex != 2) {
    // Get input from the user
    cout << "Week: " << (weekIndex+1) << " Day: " << (weekArray[weekIndex].dayIndex+1) << " data: ";
    cin >> input;

    // Parse the input based on character or numeric interaction
    char* sz;
    long convInput = strtol(input.c_str(), &sz, 10);

    if (!*sz) {
      // Input is an integer
      if (convInput > 0) {
        weekArray[weekIndex].update(convInput);
      }

    } else if (input.compare("D") == 0 || input.compare("d") == 0) {
      // Daily summary
      weekArray[weekIndex].dayArray[weekArray[weekIndex].dayIndex].summary();

    } else if (input.compare("W") == 0 || input.compare("w") == 0) {
      // Weekly summary
      weekArray[weekIndex].summary();

    } else if (input.compare("N") == 0 || input.compare("n") == 0) {
      // Update the dayIndex
      weekArray[weekIndex].dayIndex++;

      // If the current weeks dayIndex = 7 switch to the next week
      if (weekArray[weekIndex].dayIndex == 7) {
        weekIndex++;
      }
    } else {
      // No catch case, invalid input
      cout << "Invalid input..." << endl;
    }
  }

  cout << "Completed successfully" << endl;
  return 0;
}

# Lab3
Lab 3 - Numeric Errors; UWYO COSC 2030

Part 2:
  In order to detect an overflow you can watch the value before and after the calculation, because you are always adding positive numbers if the new value if less than the previous an overflow mustve occurred
  The short value overflows when n > 255

Part 3:
  The same idea to test for an overflow in part 2 applies here
  The long value overflows when n > 8965506

Part 4:
  An overflow can be tested when the result of the calculation comes out as inf
  An overflow for float occurs when n > 34

Part 5:
  An overflow for a double occurs when n > 170

Part 6:
  If the computations are exact, the expected value should be 1. The double type seems to return the correct value but the float value breaks at 100 and doesnt return 1.

Part 7:
  The issue in this example is that it prints out 4.4 when it should stop at 4.2. This occurs because floating points occur as a repeating decimal and dont work nicely with being represented as a true binary number

Part 8:
  When doubles are used the issue no longer occurs. It calculates the way you would expect it to.

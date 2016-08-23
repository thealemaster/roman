# roman calculator

This is my attempt to complete the Roman Numeral Calculator
Programming Exercise for Pillar. Some caveats to throw out there:
- My initial check-in to github is a minimal set of files
  that compile and create a library with no logic, just to
  set up the structure of the project (and to learn git)
- My first handful of tests were done to give me some
  familiarity with the check testing framework, which is
  new to me. So when you see a deviation of the solution
  after the first tests, that's why. My intent was always
  to solve the problem by doing string-to-integer-and-back
- My other goal was to be minimalistic. There are a lot of
  other things I could have done to explore all the nuances
  of roman arithmetic. Instead, I tried to stick to the
  rules of the exercise and not go too far off script
- Once the test for > 3999 was added, I realized that
  I hadn't added enough logic for that test to fail
  normally (the code didn't handle all the numbers yet).
  This is why you will notice a jump in logic in the
  convertRomanToDecimal for that test
- After a peer review, I discovered there is a difference
  between installing check using apt-get and if it had
  been built in the VM. I added some logic to the Makefiles
  to detect this and include the right libs
- Subtraction was an obvious extension to what had already
  been implemented for addition. The result is there is less
  test coverage around subtraction. As to-do, more specific
  subtraction tests could be added
- After a second peer review, did some clean-up of the tests
  and library code for readability and organization

The solution implements the following user stories:

User Story: Addition
As a Roman bookkeeper, I want to be able to add two numbers together.
 So that I can do my work faster with fewer mathematical errors.

User Story: Subtraction
As a Roman bookkeeper, I want to be able to subtract one number from
 another. So that I can do my work faster and with fewer mathematical errors.


# roman

This is my attempt to complete the Programming Exercise for
the Falcon project. A couple of caveats to throw out there:
- My initial check-in to github is a minimal set of files
  that compile and create a library with no logic, just to
  set up the structure of the project
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

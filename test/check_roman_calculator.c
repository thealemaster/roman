#include <stdlib.h>
#include <check.h>

extern int add_roman_numerals ();

START_TEST (first_test_case)
{
  int statusReturned;

  statusReturned = add_roman_numerals ();
  ck_assert_int_eq (statusReturned, 1);
}
END_TEST

Suite * roman_calculator_test_suite(void)
{
    Suite *testSuite;
    TCase *testCase;

    testSuite = suite_create("RomanCalculator");

    /* Core test case */
    testCase = tcase_create("Main");

    tcase_add_test(testCase, first_test_case);
    suite_add_tcase(testSuite, testCase);

    return testSuite;
}

int main (void)
{
  int numberOfTestsFailed;
  Suite *testSuite;
  SRunner *sRunnerInstance;

  testSuite = roman_calculator_test_suite ();
  sRunnerInstance = srunner_create(testSuite);

  srunner_run_all(sRunnerInstance, CK_NORMAL);
  numberOfTestsFailed = srunner_ntests_failed(sRunnerInstance);
  srunner_free(sRunnerInstance);

  return (numberOfTestsFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

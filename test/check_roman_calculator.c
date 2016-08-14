#include <stdlib.h>
#include <check.h>

extern int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral);

START_TEST (adding_I_and_I_equals_II)
{
  int statusReturned;
  char firstNumeral [2] = "I", secondNumeral [2] = "I", resultNumeral [2];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "II");
}
END_TEST

START_TEST (check_lower_case_by_adding_i_and_i_to_equal_II)
{
  int statusReturned;
  char firstNumeral [2] = "i\0", secondNumeral [2] = "i\0", resultNumeral [2];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "II");
}
END_TEST

Suite * roman_calculator_test_suite(void)
{
    Suite *testSuite;
    TCase *testCase;

    testSuite = suite_create("RomanCalculator");

    /* Core test case */
    testCase = tcase_create("Main");

    tcase_add_test(testCase, adding_I_and_I_equals_II);
    tcase_add_test(testCase, check_lower_case_by_adding_i_and_i_to_equal_II);
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

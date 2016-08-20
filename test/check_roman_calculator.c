#include <stdlib.h>
#include <check.h>

#include "calculate_roman.h"

/* extern int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral);
 */

START_TEST (adding_I_and_I_equals_II)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "II");
}
END_TEST

START_TEST (check_lower_case_by_adding_i_and_i_to_equal_II)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "i\0", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "i\0", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "II");
}
END_TEST

START_TEST (adding_I_and_II_equals_III)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "II", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "III");
}
END_TEST

START_TEST (adding_II_and_I_equals_III)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "II", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "III");
}
END_TEST

START_TEST (passing_invalid_roman_numeral_returns_error)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "A", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_int_eq (statusReturned, 0);
}
END_TEST

START_TEST (lesser_numeral_before_greater_numeral_means_subtraction)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "IV", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "V");
}
END_TEST

START_TEST (passing_roman_numeral_greater_than_3999_returns_error)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "MMMM", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "I", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_int_eq (statusReturned, 0);
}
END_TEST

START_TEST (adding_M_and_M_equals_MM)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "M", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "M", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "MM");

}
END_TEST

START_TEST (adding_CCC_and_CC_equals_D)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "CCC", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "CC", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "D");

}
END_TEST

START_TEST (adding_C_and_C_equals_CC)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "C", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "C", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "CC");

}
END_TEST

START_TEST (adding_XXX_and_XX_equals_L)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "XXX", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "XX", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "L");

}
END_TEST

START_TEST (adding_X_and_X_equals_XX)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "X", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "X", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "XX");

}
END_TEST

START_TEST (adding_II_and_II_equals_IV)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "II", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "II", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "IV");

}
END_TEST

START_TEST (adding_VI_and_III_equals_IX)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "VI", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "III", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "IX");

}
END_TEST

START_TEST (adding_XX_and_XX_equals_XL)
{
  int statusReturned;
  char firstNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "XX", secondNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE] = "XX", resultNumeral [MAX_ROMAN_NUMERAL_STRING_SIZE];

  statusReturned = add_roman_numerals (firstNumeral, secondNumeral, resultNumeral);
  ck_assert_str_eq (resultNumeral, "XL");

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
    tcase_add_test(testCase, adding_I_and_II_equals_III);
    tcase_add_test(testCase, adding_II_and_I_equals_III);
    tcase_add_test(testCase, passing_invalid_roman_numeral_returns_error);
    tcase_add_test(testCase, lesser_numeral_before_greater_numeral_means_subtraction);
    tcase_add_test(testCase, passing_roman_numeral_greater_than_3999_returns_error);
    tcase_add_test(testCase, adding_M_and_M_equals_MM);
    tcase_add_test(testCase, adding_CCC_and_CC_equals_D);
    tcase_add_test(testCase, adding_C_and_C_equals_CC);
    tcase_add_test(testCase, adding_XXX_and_XX_equals_L);
    tcase_add_test(testCase, adding_X_and_X_equals_XX);
    tcase_add_test(testCase, adding_II_and_II_equals_IV);
    tcase_add_test(testCase, adding_VI_and_III_equals_IX);
    tcase_add_test(testCase, adding_XX_and_XX_equals_XL);

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

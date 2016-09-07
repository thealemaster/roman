/* libmoney - a library to add and subtract roman numerals
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "calculate_roman.h"

int convertRomanNumeralToDecimal (char romanNumeralToConvert) 
{
  int convertedRomanNumeral;

  switch (romanNumeralToConvert) {
  case ('I') :
    convertedRomanNumeral = 1;
    break;
  case ('V') :
    convertedRomanNumeral = 5;
    break;
  case ('X') :
    convertedRomanNumeral = 10;
    break;
  case ('L') :
    convertedRomanNumeral = 50;
    break;
  case ('C') :
    convertedRomanNumeral = 100;
    break;
  case ('D') :
    convertedRomanNumeral = 500;
    break;
  case ('M') :
    convertedRomanNumeral = 1000;
    break;
  default:
    /* If it's not already one of the numbers above, or a NULL, it's an error */
    convertedRomanNumeral = 0;
    break;
  }

  return (convertedRomanNumeral);
}

void convertDecimalToRomanNumeral (int decimalToConvert, char *convertedNumeral)
{
  int remainingDecimalToConvert = decimalToConvert;
  int convertedNumeralArrayIndex = 0;

  struct NumeralsMap {
    char roman_value[3];
    int decimal_value;
  } romanToDecimalMap [] = {{"M", 1000},
                            {"CM", 900},
                            {"D", 500},
                            {"CD", 400},
                            {"C", 100},
                            {"XC", 90},
                            {"L", 50},
                            {"XL", 40},
                            {"X", 10},
                            {"IX",9},
                            {"V", 5},
                            {"IV", 4},
                            {"I", 1}};


    while (remainingDecimalToConvert > 0 &&
	   convertedNumeralArrayIndex < MAX_ROMAN_NUMERAL_STRING_SIZE)
    {

      while (remainingDecimalToConvert >= romanToDecimalMap[convertedNumeralArrayIndex].decimal_value) {
        strcat (convertedNumeral, romanToDecimalMap[convertedNumeralArrayIndex].roman_value);
        remainingDecimalToConvert -= romanToDecimalMap[convertedNumeralArrayIndex].decimal_value;
      }

      convertedNumeralArrayIndex++;

    }

}

int parseDecimalFromRoman (const char *romanStringToConvert)
{
  int convertedNumeral = 0;
  int numeralArrayIndex = 0;
  int currentNumeral = 0, priorNumeral = 0;

  /*
    Start at the end and work back. This allows us to make only one call to
     toupper and simplifies the logic to only add or subtract, based on what
     the prior numeral was
  */

  numeralArrayIndex = strlen (romanStringToConvert);

  while (numeralArrayIndex > 0) {

    currentNumeral = convertRomanNumeralToDecimal(toupper(romanStringToConvert[numeralArrayIndex-1]));

    /* If the number we get back is a 0, we have an invalid number */

    if (currentNumeral  == 0) {
      return (FAILURE);
    }

    /* If our current number is less than our last one, we need to subtract */

    if (currentNumeral < priorNumeral) {
      convertedNumeral -= currentNumeral;
    }
    else {
      convertedNumeral += currentNumeral;
    }

    priorNumeral = currentNumeral;
    numeralArrayIndex--;
  }

  /* If the number we parsed is larger than the MAX, it's an error */
  if (convertedNumeral > MAX_ROMAN_NUMERAL_VALUE) {
    return (FAILURE);
  }

  return (convertedNumeral);

}
 
int add_roman_numerals (const char *firstNumeral, const char *secondNumeral, char*resultNumeral)
{

  int firstConvertedNumeral = 0, secondConvertedNumeral = 0;

  if (firstNumeral == '\0' ||
      secondNumeral  == '\0' ||
      resultNumeral == '\0') {
    return (FAILURE);
  }

  if ((firstConvertedNumeral = parseDecimalFromRoman (firstNumeral)) == FAILURE ||
      (secondConvertedNumeral = parseDecimalFromRoman (secondNumeral)) == FAILURE) {
      return (FAILURE);
  }

  /* If both numbers added are greater than the MAX, return an error */

  if ((firstConvertedNumeral+secondConvertedNumeral) > MAX_ROMAN_NUMERAL_VALUE) {
    return (FAILURE);
  }

  /* Initialize the output string to NULLs */

  memset (resultNumeral, '\0', MAX_ROMAN_NUMERAL_STRING_SIZE);

  convertDecimalToRomanNumeral (firstConvertedNumeral + secondConvertedNumeral, resultNumeral);

  return (SUCCESS);
}

int subtract_roman_numerals (const char *firstNumeral, const char *secondNumeral, char*resultNumeral)
{

  int firstConvertedNumeral = 0, secondConvertedNumeral = 0;

  if (firstNumeral == '\0' ||
      secondNumeral  == '\0' ||
      resultNumeral == '\0') {
    return (FAILURE);
  }

  if ((firstConvertedNumeral = parseDecimalFromRoman (firstNumeral)) == FAILURE ||
      (secondConvertedNumeral = parseDecimalFromRoman (secondNumeral)) == FAILURE) {
      return (FAILURE);
  }

  /* If the resulting subtraction is less that or equal to 0, 
     we have an invalid number and should return an error */
  if ((firstConvertedNumeral-secondConvertedNumeral) <= 0) {
    return (FAILURE);
  }

  /* Initialize the output string to NULLs */
  memset (resultNumeral, '\0', MAX_ROMAN_NUMERAL_STRING_SIZE);

  convertDecimalToRomanNumeral (firstConvertedNumeral - secondConvertedNumeral, resultNumeral);

  return (SUCCESS);
}

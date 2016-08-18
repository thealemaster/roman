/* libmoney - a library to add and subtract roman numerals
 */

#include <stdio.h>
#include <string.h>

int convertRomanNumeralToDecimal (char romanNumeralToConvert) 
{
  int convertedRomanNumeral = 0;

  if (romanNumeralToConvert = 'I') {
    convertedRomanNumeral = 1;
  }

  return (convertedRomanNumeral);
}

void convertDecimalToRomanNumeral (int decimalToConvert, char *convertedNumeral)
{
  int remainingDecimalToConvert = decimalToConvert;
  int convertedNumeralArrayIndex = 0;

  while (remainingDecimalToConvert > 0) {
    /* If the number is less than 4, we're just dealing with I's */
    if (remainingDecimalToConvert < 4) {
      convertedNumeral [convertedNumeralArrayIndex] = 'I';
      remainingDecimalToConvert = remainingDecimalToConvert - 1;
      convertedNumeralArrayIndex++;
    }
  }

}

int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral)
{

  int firstConvertedNumeral = 0, secondConvertedNumeral = 0;
  int numeralArrayIndex = 0;

  while (toupper(firstNumeral[numeralArrayIndex])) {
    firstConvertedNumeral = firstConvertedNumeral + convertRomanNumeralToDecimal (toupper(firstNumeral[numeralArrayIndex]));
    numeralArrayIndex++;
  }

  numeralArrayIndex = 0;

  while (toupper(secondNumeral[numeralArrayIndex])) {
    secondConvertedNumeral = secondConvertedNumeral + convertRomanNumeralToDecimal (toupper(secondNumeral[numeralArrayIndex]));
    numeralArrayIndex++;
  }

  /* Initialize the output string to NULLs */
  numeralArrayIndex = 0;

  while (numeralArrayIndex < 10) {
    resultNumeral [numeralArrayIndex] = '\0';
    numeralArrayIndex++;
  }
  convertDecimalToRomanNumeral (firstConvertedNumeral + secondConvertedNumeral, resultNumeral);

  return (1);
}

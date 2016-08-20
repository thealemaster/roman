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
    /* If it's not already one of the numbers above, it's an error */
    convertedRomanNumeral = 0;
    break;
  }

  return (convertedRomanNumeral);
}

void convertDecimalToRomanNumeral (int decimalToConvert, char *convertedNumeral)
{
  int remainingDecimalToConvert = decimalToConvert;
  int convertedNumeralArrayIndex = 0;

  while (remainingDecimalToConvert > 0 && 
	 convertedNumeralArrayIndex < MAX_ROMAN_NUMERAL_STRING_SIZE) {

    if (remainingDecimalToConvert >= 1000) {
      convertedNumeral [convertedNumeralArrayIndex] = 'M';
      remainingDecimalToConvert -= 1000;
    }
    else if (remainingDecimalToConvert >= 500 && remainingDecimalToConvert < 1000) {
      convertedNumeral [convertedNumeralArrayIndex] = 'D';
      remainingDecimalToConvert -= 500;
    }
    else if (remainingDecimalToConvert >= 400 && remainingDecimalToConvert < 500) {
      convertedNumeral [convertedNumeralArrayIndex] = 'C';
      convertedNumeral [convertedNumeralArrayIndex+1] = 'D';
      convertedNumeralArrayIndex++;
      remainingDecimalToConvert -= 400;
    }
    else if (remainingDecimalToConvert >= 100 && remainingDecimalToConvert < 400) {
      convertedNumeral [convertedNumeralArrayIndex] = 'C';
      remainingDecimalToConvert -= 100;
    }
    else if (remainingDecimalToConvert >= 90 && remainingDecimalToConvert < 100) {
      convertedNumeral [convertedNumeralArrayIndex] = 'X';
      convertedNumeral [convertedNumeralArrayIndex+1] = 'C';
      convertedNumeralArrayIndex++;
      remainingDecimalToConvert -= 90;
    }
    else if (remainingDecimalToConvert >= 50 && remainingDecimalToConvert < 90) {
      convertedNumeral [convertedNumeralArrayIndex] = 'L';
      remainingDecimalToConvert -= 50;
    }
    else if (remainingDecimalToConvert >= 40 && remainingDecimalToConvert < 50) {
      convertedNumeral [convertedNumeralArrayIndex] = 'X';
      convertedNumeral [convertedNumeralArrayIndex+1] = 'L';
      convertedNumeralArrayIndex++;
      remainingDecimalToConvert -= 40;
    }
    else if (remainingDecimalToConvert >= 10 && remainingDecimalToConvert < 40) {
      convertedNumeral [convertedNumeralArrayIndex] = 'X';
      remainingDecimalToConvert -= 10;
    }
    else if (remainingDecimalToConvert == 9) {
      convertedNumeral [convertedNumeralArrayIndex] = 'I';
      convertedNumeral [convertedNumeralArrayIndex+1] = 'X';
      convertedNumeralArrayIndex++;
      remainingDecimalToConvert -= 9;
    }
    else if (remainingDecimalToConvert >= 5 && remainingDecimalToConvert < 9) {
      convertedNumeral [convertedNumeralArrayIndex] = 'V';
      remainingDecimalToConvert -= 5;
    }
    else if (remainingDecimalToConvert == 4) {
      convertedNumeral [convertedNumeralArrayIndex] = 'I';
      convertedNumeral [convertedNumeralArrayIndex+1] = 'V';
      convertedNumeralArrayIndex++;
      remainingDecimalToConvert -= 4;
    }
    else if (remainingDecimalToConvert < 4) {
      convertedNumeral [convertedNumeralArrayIndex] = 'I';
      remainingDecimalToConvert -= 1;
    }

    convertedNumeralArrayIndex++;

  }

}

int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral)
{

  int firstConvertedNumeral = 0, secondConvertedNumeral = 0;
  int numeralArrayIndex = 0;
  int currentNumeral = 0, nextNumeral = 0;

  while (toupper(firstNumeral[numeralArrayIndex])) {
    currentNumeral = convertRomanNumeralToDecimal (toupper(firstNumeral[numeralArrayIndex]));

    /* If the number we get back is a 0, we have an invalid number */

    if (currentNumeral  == 0) {
      return (0);
    }

    nextNumeral = convertRomanNumeralToDecimal (toupper(firstNumeral[numeralArrayIndex+1]));

    if (currentNumeral < nextNumeral) {
      firstConvertedNumeral = firstConvertedNumeral + nextNumeral - currentNumeral; 

      /* If we've just used 2 roman digits, update the index accordingly */
      numeralArrayIndex = numeralArrayIndex + 2;
    }
    else {
      firstConvertedNumeral = firstConvertedNumeral + currentNumeral;
      numeralArrayIndex++;
    }

  }

  numeralArrayIndex = 0;

  while (toupper(secondNumeral[numeralArrayIndex])) {

    currentNumeral = convertRomanNumeralToDecimal (toupper(secondNumeral[numeralArrayIndex]));

    /* If the number we get back is a 0, we have an invalid number */
    if (currentNumeral  == 0) {
      return (0);
    }

    nextNumeral = convertRomanNumeralToDecimal (toupper(secondNumeral[numeralArrayIndex+1]));

   if (currentNumeral < nextNumeral) {
      secondConvertedNumeral = secondConvertedNumeral + nextNumeral - currentNumeral; 

      /* If we've just used 2 roman digits, update the index accordingly */
      numeralArrayIndex = numeralArrayIndex + 2;
   }
   else {
      secondConvertedNumeral = secondConvertedNumeral + currentNumeral;
      numeralArrayIndex++;
   }
  }

  if (firstConvertedNumeral > MAX_ROMAN_NUMERAL_VALUE || 
      secondConvertedNumeral > MAX_ROMAN_NUMERAL_VALUE ) {
    return (0);
  }

  /* Initialize the output string to NULLs */
  numeralArrayIndex = 0;

  while (numeralArrayIndex < MAX_ROMAN_NUMERAL_STRING_SIZE) {
    resultNumeral [numeralArrayIndex] = '\0';
    numeralArrayIndex++;
  }
  convertDecimalToRomanNumeral (firstConvertedNumeral + secondConvertedNumeral, resultNumeral);

  return (1);
}

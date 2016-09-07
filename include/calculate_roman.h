/*
  Header file to hold common roman numeral coding exercise goodness
*/

#ifndef CHECK_ROMAN_H
#define CHECK_ROMAN_H

#define MAX_ROMAN_NUMERAL_VALUE 3999
#define MAX_ROMAN_NUMERAL_STRING_SIZE 20

#define SUCCESS 0
#define FAILURE -1

extern int add_roman_numerals (const char *firstNumeral, const char *secondNumeral, char*resultNumeral, const int maxResultNumeralBufferSize);

extern int subtract_roman_numerals (const char *firstNumeral, const char *secondNumeral, char*resultNumeral, const int maxResultNumeralBufferSize);

#endif /*CHECK_ROMAN_H */

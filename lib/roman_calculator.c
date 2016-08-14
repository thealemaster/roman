/* libmoney - a library to add and subtract roman numerals
 */

#include <stdio.h>
#include <string.h>

int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral)
{
  char *stringPointer;

  /* Make sure the input strings are in all UPPER case 
  for (stringPointer = firstNumeral; stringPointer != '\0'; ++stringPointer) {
    *stringPointer = toupper(*stringPointer);
  }

  for (stringPointer = secondNumeral; stringPointer != '\0'; ++stringPointer) {
    *stringPointer = toupper(*stringPointer);
  }
  */

  if (toupper(firstNumeral [0]) == 'I' && toupper(secondNumeral [0]) == 'I') {
    strcpy (resultNumeral, "II");
  }

  return (1);
}

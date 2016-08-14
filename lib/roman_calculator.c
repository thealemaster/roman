/* libmoney - a library to add and subtract roman numerals
 */

#include <stdio.h>
#include <string.h>

int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral)
{
  if (firstNumeral [0] == 'I' && secondNumeral [0] == 'I') {
    strcpy (resultNumeral, "II");
  }

  return (1);
}

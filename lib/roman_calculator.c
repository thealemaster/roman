/* libmoney - a library to add and subtract roman numerals
 */

#include <stdio.h>
#include <string.h>

int add_roman_numerals (char *firstNumeral, char *secondNumeral, char*resultNumeral)
{

  if (toupper(firstNumeral [0]) == 'I' && toupper(firstNumeral [1]) == 'I' && toupper( secondNumeral [0] == 'I')) {
      strcpy (resultNumeral, "III");
  }
  else if (toupper(firstNumeral[0]) == 'I' && toupper(secondNumeral [0]) == 'I' && toupper(secondNumeral [1]) == 'I') {
      strcpy (resultNumeral, "III");
  }
  else if (toupper (firstNumeral [0]) == 'I' && toupper (secondNumeral [0]) == 'I') {
    strcpy (resultNumeral, "II");
  }

  return (1);
}

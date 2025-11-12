/* Algorithm: Brute-force substring search */

#include <stdio.h>
#include <string.h>

#define Max_size 1024

int main()
{
      char string[Max_size], pattern[Max_size];
      printf("Enter String : ");
      fgets(string, sizeof(string), stdin);

      printf("Enter pattern : ");
      fgets(pattern, sizeof(pattern), stdin);

      string[strcspn(string, "\n")] = 0;
      pattern[strcspn(pattern, "\n")] = 0;

      int Slen = strlen(string);
      int Plen = strlen(pattern);
      int found = 0;
      int counter = -1;

      for (int i = 0; i <= Slen - Plen; i++)
      {
            if (found == Plen)
            {
                  counter = i - 1;
                  break;
            }

            for (int j = 0; j < Plen; j++)
            {
                  found = string[i + j] == pattern[j] ? found + 1 : 0;
            }
      }

      printf("found at %d \n", counter);
      printf("String : ");
      for (int i = counter; i < counter + Plen; i++)
      {
            printf("%c", string[i]);
      }

      return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

char text[MAX_SIZE], pattern[MAX_SIZE];
int LPS[MAX_SIZE];

int LPSTable(int M);

int KMPSearch();

int main()
{
      printf("Enter Text : ");
      fgets(text, MAX_SIZE, stdin);
      printf("\nEnter Pattern : ");
      fgets(pattern, MAX_SIZE, stdin);

      text[strcspn(text, "\n")] = '\0';
      pattern[strcspn(pattern, "\n")] = '\0';
      KMPSearch();
      return 0;
}

int LPSTable(int M)
{
      LPS[0] = 0;
      int i = 1, len = 0;
      while (i < M)
      {
            if (pattern[i] == pattern[i + len])
            {
                  len++;
                  LPS[i] = len;
                  i++;
            }
            else
            {
                  if (len != 0)
                  {
                        len = LPS[len - 1];
                        i++;
                  }
                  else
                  {
                        LPS[i] = 0;
                        i++;
                  }
            }
      }
}

int KMPSearch()
{
      int Tlen = strlen(text), Plen = strlen(pattern);
      LPSTable(Plen);
      int i = 0, j = 0;
      while (i < Tlen)
      {
            if (pattern[j] == text[i])
            {
                  i++;
                  j++;
            }
            if (j == Plen)
            {
                  printf("\nPattern found at index %d\n", i - j);
                  j = LPS[j - 1];
            }
            else if (i < Tlen && pattern[j] != text[i])
            {
                  if (j != 0)
                        j = LPS[j - 1];
                  else
                        i++;
            }
      }
}

#include <stdio.h>
#define n 1024
int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

int main()
{
      int ary[n], max;
      max = inputInt("Enter number of elements: ");
      for (int i = 0; i < max; i++)
      {
            ary[i] = inputInt("Enter element: ");
      }

      for (int i = 0; i < max - 1; i++)
      {
            for (int j = 0; j < max - i - 1; j++)
            {
                  if (ary[j] > ary[j + 1])
                  {
                        int temp = ary[j + 1];
                        ary[j + 1] = ary[j];
                        ary[j] = temp;
                  }
            }
      }
      printf("Output : ");
      for (int i = 0; i < max; i++)
      {
            printf("%d ", ary[i]);
      }
}

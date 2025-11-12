#include <stdio.h>

int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

#define MAX 1024

int a[MAX], size;

void scanElements()
{
      size = inputInt("Enter number of elements: ");
      for (int i = 0; i < size; i++)
      {
            a[i] = inputInt("Enter element: ");
      }
}

void insertionSort()
{
      int i, j, t;
      for (i = 1; i < size; i++)
      {
            t = a[i];
            for (j = i - 1; j >= 0 && a[j] > t; j--)
            {

                  if (a[j] > t)
                  {
                        a[j + 1] = a[j];
                  }
                  else
                  {
                        break;
                  }
            }
            a[j + 1] = t;
      }
}

void displayElements()
{
      for (int i = 0; i < size; i++)
      {
            printf("%d ", a[i]);
      }
}

int main()
{
      scanElements();
      insertionSort();
      displayElements();
      return 0;
}
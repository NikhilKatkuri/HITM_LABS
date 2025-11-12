#include <stdio.h>

int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

#define MAX 1024

int arr[MAX], size;

void FillZero()
{
      for (int i = 0; i < MAX; i++)
      {
            arr[i] = 0;
      }
}

void selectionSort();

int main()
{
      FillZero();
      size = inputInt("Enter size : ");
      int i = 0;
      while (i < size)
      {
            arr[i++] = inputInt("Enter Element : ");
      }
      selectionSort();
}

void selectionSort()
{
      int index = 0;
      for (int i = 0; i < size - 1; i++)
      {
            for (int j = i + 1; j < size; j++)
            {
                  if (arr[j] < arr[index])
                  {
                        index = j;
                  }
            }

            arr[i] += arr[index];
            arr[index] = arr[i] - arr[index];
            arr[i] -= arr[index];
      }

      for (int i = 0; i < size; i++)
      {
            printf("%d ", arr[i]);
      }
}
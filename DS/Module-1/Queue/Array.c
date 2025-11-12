#include <stdio.h>

int queue[30], size, f = -1, r = -1, i;

void nqueue();
void dqueue();
void display();
int main()
{
      printf("enter the size of queue: ");
      scanf("%d", &size);

      printf("\nqueue operations\n");
      int ch;
      while (1)
      {
            printf("\nEnter 1 for mqueue\nEnter 2 for dqueue\n");
            printf("Enter 3 for display\nEnter 4 for exit\n");
            printf("Enter your choice: ");
            scanf("%d", &ch);
            if (ch == 1)
                  nqueue();
            else if (ch == 2)
                  dqueue();
            else if (ch == 3)
                  display();
            else if (ch == 4)
                  break;
            else
                  printf("\nEnter correct operation\n");
      }
}
void nqueue()
{
      int val;
      printf("enter value: ");
      scanf("%d", &val);
      if (r == size - 1)
      {
            printf("overflow");
      }
      else if (r == -1)
      {
            f = 0;
            r = f;
            queue[r] = val;
            printf("inserted");
      }
      else
      {
            r++;
            queue[r] = val;
            printf("inserted");
      }
}
void dqueue()
{
      if (f == -1)
      {
            printf("underflow");
      }
      else if (r == f && f == -1)
      {
            r = -1;
            f = r;
            printf("value deleted");
      }
      else
      {
            f++;
            printf("value deleted");
      }
}
void display()
{
      if (r < 0 || f < 0)
      {
            printf("underflow");
      }
      else
      {
            printf("queue is : ");
            for (i = f; i <= r; i++)
            {
                  printf("%d ", queue[i]);
            }
      }
}
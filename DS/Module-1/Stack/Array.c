#include <stdio.h>

int ary[20], size, i, top = -1;

void push()
{
      int value;
      printf("\nEnter the value:");
      scanf("%d", &value);
      if (top == size - 1)
      {
            printf("\noverflow\n");
      }
      else
      {
            top = top + 1;
            ary[top] = value;
            printf("\nvalue inserted");
      }
}

void pop()
{
      if (top == -1)
            printf("underflow");
      else
      {
            top = top - 1;
            printf("value deleted");
      }
}

void display()
{
      if (top == -1)
      {
            printf("empty");
      }
      else
      {
            printf("The stack is : ");
            for (i = 0; i <= top; i++)
            {
                  printf("%d ", ary[i]);
            }
      }
}

int main()
{
      printf("Name : KATKURI NIKHIL\n");
      printf("ROLL NUMBER : 24E51A6774\n");

      printf("enter the size of stack: ");
      scanf("%d", &size);

      printf("\nStack operations\n");
      int ch;
      while (1)
      {
            printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 for display\nEnter 4 for exit\n");
            printf("choose an option: ");
            scanf("%d", &ch);
            if (ch == 1)
                  push();
            else if (ch == 2)
                  pop();
            else if (ch == 3)
                  display();
            else if (ch == 4)
                  break;
            else
                  printf("\nEnter correct operation");
      }
}
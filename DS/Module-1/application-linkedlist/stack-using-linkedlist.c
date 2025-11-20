#include <stdio.h>
#include <stdlib.h>

struct node
{
     int value;
     struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void display();

int main()
{
     printf("Name : KATKURI NIKHIL\n");
     printf("ROLL NUMBER : 24E51A6774\n");
     int ch;
     printf("\nStack using linked list\n");
     while (1)
     {
          printf("\nChoose Options\n");
          printf("\n1.push\n");
          printf("2.pop\n");
          printf("3.display\n");
          printf("4.exit\n");
          printf("ENTER : ");
          scanf("%d", &ch);

          switch (ch)
          {
          case 1:
               push();
               break;
          case 2:
               pop();
               break;
          case 3:
               display();
               break;
          case 4:
               exit(0);
               break;

          default:
               printf("\nchoose 1,2,3,4 options");
               break;
          }
     }

     return 0;
}

void push()
{
     int value;
     printf("Enter value : ");
     scanf("%d", &value);
     struct node *new = malloc(sizeof(struct node));

     new->value = value;
     new->next = NULL;
     if (top == NULL)
     {
          top = new;
     }
     else
     {
          new->next = top;
          top = new;
     }
     printf("pushed\n");
}

void pop()
{
     struct node *new = top;

     if (top == NULL)
     {
          printf("underflow\n");
     }
     else
     {
          new = top->next;
          top = new;
     }
     printf("Poped\n");
}

void display()
{
     if (top == NULL)
     {
          printf("\nStack is empty\n");
     }
     else
     {
          struct node *new = top;
          printf("Stack is : ");
          while (new != NULL)
          {
               printf("%d ", new->value);
               new = new->next;
          }
          printf("\n");
     }
}
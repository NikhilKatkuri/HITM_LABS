#include <stdio.h>
#include <stdlib.h>

struct node
{
     int value;
     struct node *next;
};

struct node *top = NULL;

void nqueue();
void dqueue();
void display();

int main()
{
     int ch;
     printf("\nqueue using linked list\n");
     while (1)
     {
          printf("\nChoose Options\n");
          printf("\n1.nqueue\n");
          printf("2.dqueue\n");
          printf("3.display\n");
          printf("4.exit\n");
          printf("ENTER : ");
          scanf("%d", &ch);

          switch (ch)
          {
          case 1:
               nqueue();
               break;
          case 2:
               dqueue();
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

void nqueue()
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
          struct node *curr = top;
          while (curr->next != NULL)
          {
               curr = curr->next;
          }
          curr->next = new;
     }
     printf("inserted\n");
}

void dqueue()
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
     printf("deleted\n");
}

void display()
{
     if (top == NULL)
     {
          printf("\nQueue is empty\n");
     }
     else
     {
          struct node *new = top;
          printf("Queue is : ");
          while (new != NULL)
          {
               printf("%d ", new->value);
               new = new->next;
          }
          printf("\n");
     }
}
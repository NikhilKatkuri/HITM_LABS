#include <stdio.h>
#include <stdlib.h>

struct node
{
      int value;
      struct node *next;
};

struct node *head = NULL;

void insertAtBegin();
void insertAtEnd();
void insertAtRandom();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtRandom();
void display();

int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

int main()
{
      int ch;
      while (1)
      {
            printf("\nchoose options :\n");
            printf("1.Insert at begin\n");
            printf("2.Insert at end\n");
            printf("3.Insert at random\n");
            printf("4.delete at begin\n");
            printf("5.delete at end\n");
            printf("6.delete at random\n");
            printf("7.display linked list\n");
            printf("8.exit...\n");

            ch = inputInt("Enter option : ");

            switch (ch)
            {
            case 1:
                  insertAtBegin();
                  break;
            case 2:
                  insertAtEnd();
                  break;
            case 3:
                  insertAtRandom();
                  break;
            case 4:
                  deleteAtBegin();
                  break;
            case 5:
                  deleteAtEnd();
                  break;
            case 6:
                  deleteAtRandom();
                  break;
            case 7:
                  display();
                  break;
            case 8:
                  exit(0);

            default:
                  printf("\nPlease enter correct option \n");
                  break;
            }
      }
      return 0;
}

void insertAtBegin()
{

      int value;
      value = inputInt("Enter value : ");
      struct node *new = malloc(sizeof(struct node));
      new->value = value;
      if (head == NULL)
      {
            head = new;
            new->next = head;
      }
      else
      {
            struct node *curr = head;
            while (curr->next != head)
            {
                  curr = curr->next;
            }
            new->next = head;
            head = new;
            curr->next = head;
      }
      printf("inserted");
}

void insertAtEnd()
{
      if (head == NULL)
            insertAtBegin();
      else
      {
            int value;
            value = inputInt("Enter value : ");
            struct node *curr = head;
            while (curr->next != head)
            {
                  curr = curr->next;
            }
            struct node *new = malloc(sizeof(struct node));
            new->value = value;
            new->next = head;
            curr->next = new;
      }
}

void insertAtRandom()
{
      if (head == NULL)
            insertAtBegin();
      else
      {

            int x;
            x = inputInt("Enter position : ");
            int i = 0;
            struct node *curr = head;
            while (i < x - 1)
            {
                  curr = curr->next;
            }
            int value;
            value = inputInt("Enter value : ");
            struct node *new = malloc(sizeof(struct node));
            new->value = value;
            new->next = curr->next;
            curr->next = new;
      }
}

void deleteAtBegin()
{
      if (head == NULL)
      {
            printf("NULL");
            return;
      }
      else
      {

            struct node *temp = head;
            if (head->next == head)
            {
                  head = NULL;
                  free(temp);
                  return;
            }
            struct node *curr = head;
            while (curr->next != head)
            {
                  curr = curr->next;
            }
            head = head->next;
            curr->next = head;
            free(temp);
            return;
      }
};
void deleteAtEnd()
{
      if (head == NULL)
      {
            printf("NULL");
            return;
      }
      else
      {
            struct node *curr = head;
            struct node *prev = NULL;
            if (head->next == head)
            {
                  head = NULL;
                  free(curr);
                  return;
            }
            while (curr->next != head)
            {
                  prev = curr;
                  curr = curr->next;
            }
            prev->next = head;
            free(curr);
            return;
      }
};
void deleteAtRandom()
{
      if (head == NULL)
      {
            printf("NULL");
            return;
      }
      else
      {
            int x;
            x = inputInt("Enter position : ");
            struct node *curr = head;
            struct node *prev = NULL;
            if (x == 0)
            {
                  deleteAtBegin();
                  return;
            }
            int i = 0;
            while (i < x)
            {
                  prev = curr;
                  curr = curr->next;
                  i++;
            }
            prev->next = curr->next;
            free(curr);
            return;
      }
};

void display()
{

      if (head == NULL)
      {
            printf("List is empty\n");
            return;
      }
      else
      {
            struct node *curr = head;

            printf("\nLinked List : ");
            do
            {
                  printf("%d ", curr->value);
                  curr = curr->next;
            } while (curr != head);
      }
}

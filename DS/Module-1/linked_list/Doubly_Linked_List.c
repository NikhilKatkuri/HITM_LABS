#include <stdio.h>
#include <stdlib.h>
struct node
{
      struct node *prev;
      int value;
      struct node *next;
};

struct node *head = NULL;

int PrintAndScan(const char *message, int *ch)
{
      printf("%s", message);
      return scanf("%d", ch);
}

void insertAtBegin();
void insertAtEnd();
int insertAtRandom();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtRandom();
int display();

int main()
{
      printf("Name : KATKURI NIKHIL\n");
      printf("ROLL NUMBER : 24E51A6774\n");
      int ch;
      printf("Doubly linkedlist\n");
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

            PrintAndScan("choose  : ", &ch);

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
      PrintAndScan("Enter value : ", &value);
      struct node *new = malloc(sizeof(struct node));
      new->value = value;
      new->next = NULL;
      new->prev = NULL;
      if (head == NULL)
      {
            head = new;
      }
      else
      {
            head->prev = new;
            new->next = head;
            new->prev = NULL;
            head = new;
      }
      printf("inserted");
};
void insertAtEnd()
{
      int value;
      PrintAndScan("Enter value : ", &value);
      struct node *new = malloc(sizeof(struct node));
      new->value = value;
      new->next = NULL;
      struct node *curr = head;
      while (curr->next != NULL)
      {
            curr = curr->next;
      }
      curr->next = new;
      new->prev = curr;
};
int insertAtRandom()
{

      int x;
      PrintAndScan("Enter position from 0-n : ", &x);
      struct node *curr = head;
      if (x == 0 || head == NULL)
      {
            insertAtBegin();
      }
      else
      {

            int i = 0;
            while (i < x && curr->next != NULL)
            {
                  i++;
                  curr = curr->next;
            }

            int value;
            PrintAndScan("Enter value : ", &value);
            struct node *new = malloc(sizeof(struct node));
            new->value = value;
            new->next = curr;
            new->prev = curr->prev;
            if (curr->prev != NULL)
            {
                  curr->prev->next = new;
            }
            else
            {
                  head = new;
            }
            curr->prev = new;

            printf("Inserted at position %d\n", i);
      }
      return 0;
};

void deleteAtBegin()
{
      if (head == NULL)
      {
            printf("Linked List is empty\n");
      }
      else
      {
            head = head->next;
            if (head != NULL)
            {
                  head->prev = NULL;
            }
            printf("Deleted at beginning\n");
      }
};

void deleteAtEnd()
{

      if (head == NULL)
      {
            printf("Linked List is empty\n");
      }
      else if (head->next == NULL)
      {
            free(head);
            head = NULL;
      }
      else
      {
            struct node *curr = head;
            while (curr->next != NULL)
            {
                  curr = curr->next;
            }
            curr->prev->next = NULL;
            free(curr);
      }
};

void deleteAtRandom()
{
      if (head == NULL)
      {
            printf("Linked List is empty\n");
      }
      else if (head->next == NULL)
      {
            free(head);
            head = NULL;
      }
      else
      {
            int x;
            PrintAndScan("Enter position : ", &x);
            int i = 0;
            struct node *curr = head;
            while (i < x && curr->next != NULL)
            {
                  i++;
                  curr = curr->next;
            }
            if (curr->next != NULL)
            {
                  curr->prev->next = curr->next;
                  curr->next->prev = curr->prev;
            }
            else
            {
                  curr->prev->next = NULL;
            }
            free(curr);
            printf("%d should be deleted", curr->value);
      }
};
int display()
{
      struct node *currNode = head;
      if (currNode == NULL)
      {
            printf("\nLinkedList is NULL\n");
            return 0;
      }
      printf("\nLinked List : ");
      while (currNode != NULL)
      {
            printf("%d<-> ", currNode->value);
            currNode = currNode->next;
      }
};

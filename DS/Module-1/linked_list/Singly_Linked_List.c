#include <stdio.h>
#include <stdlib.h>

struct node
{
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
void insertAtRandom();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtRandom();
int display();
void length();
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
            printf("8.lenght of linked list\n");
            printf("9.exit...\n");

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
                  length();
                  break;
            case 9:
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
      int x;
      PrintAndScan("\nEnter value of Node : ", &x);
      struct node *copyNode = malloc(sizeof(struct node));
      copyNode->value = x;
      copyNode->next = NULL;

      if (head == NULL)
      {
            head = copyNode;
      }
      else
      {
            copyNode->next = head;
            head = copyNode;
      }
      printf("\nInserted value at beggining\n");
};

void insertAtEnd()
{
      int value;
      PrintAndScan("\nEnter value : ", &value);
      struct node *new = (struct node *)malloc(sizeof(struct node));
      new->value = value;
      new->next = NULL;

      if (head == NULL)
      {
            head = new;
      }
      else
      {
            struct node *curr = head;
            while (curr->next != NULL)
            {
                  curr = curr->next;
            }
            curr->next = new;
      }
      printf("\nInserted at end\n");
};
void insertAtRandom()
{
      if (head == NULL)
      {
            printf("\nLinkedList is NULL\n");
      }
      else
      {
            int x;
            x = PrintAndScan("\nEnter position (from 0-n) : ", &x);
            int value;
            value = PrintAndScan("\nEnter value : ", &value);
            int i = 0;
            struct node *curr = NULL, *new = (struct node *)malloc(sizeof(struct node)), *n = NULL;
            new->value = value;
            new->next = NULL;
            n = head;
            while (i < x)
            {
                  if (n->next == NULL)
                  {
                        printf("\nAt %d is last postion. \n", i + 1);
                        break;
                  }
                  i++;
                  curr = n;
                  n = curr->next;
            }
            new->next = n;
            curr->next = new;
            printf("\nInserted at %d\n", i + 1);
      }
};

void deleteAtBegin()
{
      if (head == NULL)
      {
            printf("\nLinkedList is NULL\n");
      }
      else
      {
            struct node *copyNode = head->next;
            head = copyNode;
      }
};
void deleteAtEnd()
{
      if (head == NULL)
      {
            printf("\nLinkedList is NULL\n");
      }
      else
      {
            struct node *curr = head;
            while (curr->next->next != NULL)
            {
                  curr = curr->next;
            }
            free(curr->next);
            curr->next = NULL;
            printf("\nDeleted At End\n");
      }
};
void deleteAtRandom()
{
      if (head == NULL)
      {
            printf("\nLinkedList is NULL\n");
      }
      else
      {
            int x = PrintAndScan("\nEnter position (from 0-n) : ", &x);
            int i = 0;
            struct node *curr = malloc(sizeof(struct node)), *n = NULL;
            n = head;
            while (i < x)
            {
                  if (n->next == NULL)
                  {
                        printf("\nAt %d is last postion. \n", i + 1);
                        break;
                  }
                  i++;
                  curr = n;
                  n = curr->next;
            }
            curr->next = n->next;
            printf("\nDeleted at %d\n", i + 1);
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
            printf("%d ", currNode->value);
            currNode = currNode->next;
      }
};

void length()
{

      if (head == NULL)
      {
            printf("head is null");
      }
      else
      {

            int l = 0;

            struct node *curr = head;
            while (curr != NULL)
            {
                  l++;
                  curr = curr->next;
            }
            printf("Lenght of linkedlist is %d", l);
      }
}
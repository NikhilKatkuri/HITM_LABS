#include <stdio.h>
#include <stdlib.h>

int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

struct node
{
      int key;
      int value;
      struct node *next;
};

struct node *head = NULL;

void Insert();
void Delete();
int searchKey(int key);
void Search();
void Display();

int main()
{

      printf("-- Dictionary --");

      int option;
      while (1)
      {
            printf("\n--- Options ---\n");
            printf("1.Insert \n");
            printf("2.Delete \n");
            printf("3.Search \n");
            printf("4.Display \n");
            printf("5.Exit \n");
            option = inputInt("Enter an Option : ");
            printf("\n");
            switch (option)
            {
            case 1:
                  Insert();
                  break;
            case 2:
                  Delete();
                  break;
            case 3:
                  Search();
                  break;
            case 4:
                  Display();
                  break;
            case 5:
                  exit(0);
                  break;

            default:
                  printf("\n--- choose correct option --\n\n");
                  break;
            }
      }

      return 0;
}

int searchKey(int key)
{
      if (head == NULL)
            return -1;
      struct node *curr = head;
      int p = 0;
      while (curr != NULL)
      {
            if (curr->key == key)
            {
                  return p;
            }
            curr = curr->next;
            p++;
      }
      return -1;
}

void Insert()
{

      int key;
      key = inputInt("Enter Key : ");
      int p = 0;
      while (1)
      {
            p = searchKey(key);
            if (p == -1)
                  break;
            key = inputInt("Enter Key : ");
      }

      int value;
      value = inputInt("Enter value : ");
      struct node *new = malloc(sizeof(struct node));
      new->key = key;
      new->value = value;
      new->next = NULL;
      if (head == NULL || key < head->key)
      {
            new->next = head;
            head = new;
      }
      else
      {
            struct node *curr = head;
            while (curr->next != NULL && curr->next->key < key)
            {
                  curr = curr->next;
            }
            new->next = curr->next;
            curr->next = new;
      }
      printf("\n- Inserted -");
};
void Delete()
{

      if (head == NULL)
      {
            printf("- Empty -");
      }
      else
      {

            int key;
            key = inputInt("Enter Key : ");
            int p = 0;
            p = searchKey(key);
            if (p == -1)
            {
                  printf("Key not found");
            }
            else
            {
                  if (head->key == key)
                  {
                        struct node *temp = head;
                        head = head->next;
                        free(temp);
                  }
                  else
                  {
                        struct node *curr = head;
                        while (curr->next != NULL && curr->next->key != key)
                        {
                              curr = curr->next;
                        }
                        if (curr->next == NULL)
                        {
                              printf("Key not found");
                        }
                        else
                        {
                              struct node *temp = curr->next;
                              curr->next = curr->next->next;
                              free(temp);
                        }
                  }
                  printf("- Deleted -");
            }
      }
};
void Search()
{
      if (head == NULL)
            printf("- empty -");
      else
      {
            int key;
            key = inputInt("Enter an Key : ");
            int pos = searchKey(key);
            if (pos == -1)
                  printf(" not found");
            else
            {
                  printf("%d found at %d position", key, pos);
            }
      }
};
void Display()
{
      if (head == NULL)
            printf("- empty -");
      else
      {
            struct node *curr = head;
            printf("key:value = ");
            while (curr != NULL)
            {
                  printf("%d:%d  ", curr->key, curr->value);
                  curr = curr->next;
            }
            printf("\n");
      }
};
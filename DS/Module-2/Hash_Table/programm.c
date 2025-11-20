#include <stdio.h>
#include <stdlib.h>

int inputInt(char *prompt)
{
     int value;
     printf("%s", prompt);
     scanf("%d", &value);
     return value;
}

#define SIZE_ 100
static int hashTable[SIZE_], size = -1;

int hashKey(int key)
{
     return key % size;
}

void insert();
void delete();
void display();
void search();

int main()
{
     printf("Name : KATKURI NIKHIL\n");
     printf("ROLL NUMBER : 24E51A6774\n");
     printf("-- hash table --\n");
     size = inputInt("Enter size of has table : ");

     for (int i = 0; i < SIZE_; i++)
          hashTable[i] = -1;

     int ch;
     while (1)
     {
          printf("\nChoose option \n");
          printf("1.Insert \n");
          printf("2.Delete \n");
          printf("3.Search \n");
          printf("4.Display \n");
          printf("5.Exit \n");
          ch = inputInt("Enter Option : ");
          switch (ch)
          {
          case 1:
               insert();
               break;
          case 2:
               delete();
               break;
          case 3:
               search();
               break;
          case 4:
               display();
               break;
          case 5:
               exit(0);
               break;

          default:
               break;
          }
     }

     return 0;
}

void insert()
{
     int value = inputInt("Enter value to insert : ");
     int key = hashKey(value);
     int i = 0;
     while (hashTable[hashKey(key + i)] != -1 && i < size)
     {
          i++;
     }
     if (i >= size)
     {
          printf("Hash table full");
          return;
     }

     hashTable[hashKey(key + i)] = value;
}

void delete()
{
     int value = inputInt("Enter value to delete : ");
     int key = hashKey(value);
     int i = 0;
     while (hashTable[hashKey(key + i)] != value && i < size)
     {
          i++;
     }

     if (hashTable[hashKey(key + i)] == value && i < size)
     {
          hashTable[hashKey(key + i)] = -1;
     }
     else
          printf("value not found");
}

void search()
{
     int value = inputInt("Enter value to search : ");
     int key = hashKey(value);
     int i = 0;
     while (hashTable[hashKey(key + i)] != value && i < size)
          i++;
     int pos = hashKey(key + i);
     if (i >= size)
     {
          printf("value not found");
          return;
     }
     printf("value = %d , pos = %d", value, pos);
}

void display()
{
     printf("\ndisplay \n");
     for (int i = 0; i < size; i++)
     {
          printf("%d ", i);
     }
     printf("\n");
     for (int i = 0; i < size; i++)
     {
          printf("%d ", hashTable[i]);
     }
}

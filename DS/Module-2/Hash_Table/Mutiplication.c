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
double A = 0.200720082022;

static int hashTable[SIZE_], size = -1;

int hashKey(int key)
{
     double fac = (key * A) - (int)(key * A);
     return (int)(size * (fac));
}

void init()
{
     printf("-- hash table --\n");
     size = inputInt("Enter size of has table : ");

     for (int i = 0; i < SIZE_; i++)
          hashTable[i] = -1;
}

void insert();
void delete();
void display();
void search();

int main()
{
     printf("Name : KATKURI NIKHIL\n");
     printf("ROLL NUMBER : 24E51A6774\n");
     init();
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
     int i = 0;
     while (hashTable[hashKey(value + i)] != -1 && i < size)
          i++;

     if (i >= size)
     {
          printf("value already exist in it or hash table size is full");
          return;
     }

     hashTable[hashKey(value + i)] = value;
}

void delete()
{
     int value = inputInt("Enter value to delete : ");
     int i = 0;
     while (hashTable[hashKey(value + i)] != value && i < size)
          i++;

     if (i >= size)
     {
          printf("value does'nt exist");
          return;
     }
     hashTable[hashKey(value + i)] = -1;
}

void search()
{
     int value = inputInt("Enter value to search : ");
     int i = 0;
     while (hashTable[hashKey(value + i)] != value && i < size)
          i++;
     if (i >= size)
     {
          printf("value not found");
          return;
     }

     printf("value = %d , pos = %d", value, hashKey(value + i));
}

void display()
{
     printf("Hash Table : \n");
     printf("Index : ");
     for (int i = 0; i < size; i++)
     {
          printf("%d ", i);
     }
     printf("\nvalues : ");
     for (int i = 0; i < size; i++)
     {
          printf("%d ", hashTable[i]);
     }
}
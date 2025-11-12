#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE_ 100

int inputInt(char *prompt)
{
     int value;
     printf("%s", prompt);
     scanf("%d", &value);
     return value;
}
static int hashTable[SIZE_], size = -1;

int Count(int key)
{
     return (int)(log10(key) + 1);
}

long long square(int key)
{
     return (long long)(key * key);
}

int midSquareHash(int key);

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
     int key = midSquareHash(value);
     int i = 0;
     while (hashTable[(key + i) % size] != -1 && i < size)
          i++;
     if (i >= size)
     {
          printf("value already exist in it or hash table size is full");
          return;
     }
     hashTable[(key + i) % size] = value;
}

void delete()
{
     int value = inputInt("Enter value to delete : ");
     int key = midSquareHash(value);
     int i = 0;
     while (hashTable[(key + i) % size] != value && i < size)
          i++;
     if (i >= size)
     {
          printf("value does'nt exist");
          return;
     }
     hashTable[(key + i) % size] = -1;
}

void search()
{
     int value = inputInt("Enter value to Search : ");
     int key = midSquareHash(value);
     int i = 0;
     while (i < size)
     {
          int index = (key + i) % size;
          if (hashTable[index] == value)
          {
               printf("value = %d , pos = %d ", hashTable[index], index);
               return;
          }
          i++;
     }

     printf("value not found\n");
}

void display()
{
     printf("hashtable\n");
     printf("Index : ");
     for (int i = 0; i < size; i++)
     {
          printf("%d  ", i);
     }
     printf("\nValue : ");
     for (int i = 0; i < size; i++)
          printf("%d  ", hashTable[i]);
}
int midSquareHash(int key)
{
     char ch[SIZE_];
     sprintf(ch, "%lld", square(key));
     int len = 0;
     while (ch[len] != '\0')
          len++;

     int digits = Count(size - 1);
     int start = (int)((len / 2) - (digits / 2));
     start = start < 0 ? 0 : start;
     char mid[size / 2];
     strncpy(mid, ch + start, digits);
     mid[digits] = '\0';
     int num = atoi(mid);
     return num % size;
}
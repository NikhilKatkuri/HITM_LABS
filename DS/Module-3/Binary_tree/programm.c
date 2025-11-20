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
      struct node *left;
      int value;
      struct node *right;
};

struct node *root = NULL;

struct node *createNewNode(int value)
{
      struct node *new = malloc(sizeof(struct node));
      new->left = NULL;
      new->value = value;
      new->right = NULL;

      return new;
}

// note : left < parent < right
struct node *updateNode(struct node *curr, int value)
{
      if (curr == NULL)
            return createNewNode(value);

      if (curr->value > value)
      {

            curr->left = updateNode(curr->left, value);
      }
      else if (curr->value < value)
      {

            curr->right = updateNode(curr->right, value);
      }
      return curr;
}

void insert();
void inorder(struct node *curr);
void postorder(struct node *curr);
void preorder(struct node *curr);

int main()
{
      printf("Name : KATKURI NIKHIL\n");
      printf("ROLL NUMBER : 24E51A6774\n");
      printf("-- binary tree --\n");
      int ch;
      while (1)
      {
            printf("-- Options --\n");
            printf("1. Insert --\n");
            printf("2. Inorder --\n");
            printf("3. Postorder --\n");
            printf("4. Preorder --\n");
            printf("5. Exist --\n");
            ch = inputInt("-- choose option : ");
            switch (ch)
            {
            case 1:
                  insert();
                  break;
            case 2:
                  inorder(root);
                  break;
            case 3:
                  postorder(root);
                  break;
            case 4:
                  preorder(root);
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

      int values[100];
      for (int i = 0; i < 100; i++)
            values[i] = -1;

      int value = 0, i = 0;
      printf("enter -1 for stop entering values\n");
      while (value != -1 && i < 100)
      {
            value = inputInt("enter value : ");
            if (value == -1)
            {
                  break;
            }
            values[i] = value;
            i++;
      }

      for (int j = 0; j < i; j++)
      {
            root = updateNode(root, values[j]);
      }
};

void inorder(struct node *curr)
{
      if (curr == NULL)
            return;
      inorder(curr->left);
      printf("value : %d\n", curr->value);
      inorder(curr->right);
};
void postorder(struct node *curr)
{
      if (curr == NULL)
            return;
      postorder(curr->left);
      postorder(curr->right);
      printf("value : %d\n", curr->value);
};
void preorder(struct node *curr)
{
      if (curr == NULL)
            return;
      printf("value : %d\n", curr->value);
      preorder(curr->left);
      preorder(curr->right);
};

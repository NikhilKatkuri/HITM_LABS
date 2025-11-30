#include <stdio.h>
#include <stdlib.h>

// Function for input
int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

// AVL Tree Node
typedef struct Node
{
      int key;
      struct Node *left;
      struct Node *right;
      int height;
} Node;

// Helper function to get node height
int height(Node *N)
{
      if (N == NULL)
            return 0;
      return N->height;
}

// Helper function to get max of two integers
int max(int a, int b)
{
      return (a > b) ? a : b;
}

// Create a new node
Node *newNode(int key)
{
      Node *node = (Node *)malloc(sizeof(Node));
      node->key = key;
      node->left = NULL;
      node->right = NULL;
      node->height = 1; // new node is initially added at leaf
      return (node);
}

// Right rotate subtree rooted with y
Node *rightRotate(Node *y)
{
      Node *x = y->left;
      Node *T2 = x->right;

      // Perform rotation
      x->right = y;
      y->left = T2;

      // Update heights
      y->height = max(height(y->left), height(y->right)) + 1;
      x->height = max(height(x->left), height(x->right)) + 1;

      // Return new root
      return x;
}

// Left rotate subtree rooted with x
Node *leftRotate(Node *x)
{
      Node *y = x->right;
      Node *T2 = y->left;

      // Perform rotation
      y->left = x;
      x->right = T2;

      // Update heights
      x->height = max(height(x->left), height(x->right)) + 1;
      y->height = max(height(y->left), height(y->right)) + 1;

      // Return new root
      return y;
}

// Get balance factor of node N
int getBalance(Node *N)
{
      if (N == NULL)
            return 0;
      return height(N->left) - height(N->right);
}

// Insert a key in the subtree rooted with node and returns the new root
Node *insert(Node *node, int key)
{
      if (node == NULL)
            return (newNode(key));

      if (key < node->key)
            node->left = insert(node->left, key);
      else if (key > node->key)
            node->right = insert(node->right, key);
      else // Equal keys not allowed
            return node;

      // Update height
      node->height = 1 + max(height(node->left), height(node->right));

      // Get balance factor
      int balance = getBalance(node);

      // Balance the tree with 4 cases

      // Left Left Case
      if (balance > 1 && key < node->left->key)
            return rightRotate(node);

      // Right Right Case
      if (balance < -1 && key > node->right->key)
            return leftRotate(node);

      // Left Right Case
      if (balance > 1 && key > node->left->key)
      {
            node->left = leftRotate(node->left);
            return rightRotate(node);
      }

      // Right Left Case
      if (balance < -1 && key < node->right->key)
      {
            node->right = rightRotate(node->right);
            return leftRotate(node);
      }

      return node;
}

// Find node with minimum key value
Node *minValueNode(Node *node)
{
      Node *current = node;
      while (current->left != NULL)
            current = current->left;
      return current;
}

// Delete a node with given key
Node *deleteNode(Node *root, int key)
{
      if (root == NULL)
            return root;

      if (key < root->key)
            root->left = deleteNode(root->left, key);
      else if (key > root->key)
            root->right = deleteNode(root->right, key);
      else
      {
            if ((root->left == NULL) || (root->right == NULL))
            {
                  Node *temp = root->left ? root->left : root->right;

                  if (temp == NULL)
                  {
                        temp = root;
                        root = NULL;
                  }
                  else
                        *root = *temp;
                  free(temp);
            }
            else
            {
                  Node *temp = minValueNode(root->right);
                  root->key = temp->key;
                  root->right = deleteNode(root->right, temp->key);
            }
      }

      if (root == NULL)
            return root;

      root->height = 1 + max(height(root->left), height(root->right));

      int balance = getBalance(root);

      // Balance tree
      if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

      if (balance > 1 && getBalance(root->left) < 0)
      {
            root->left = leftRotate(root->left);
            return rightRotate(root);
      }

      if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

      if (balance < -1 && getBalance(root->right) > 0)
      {
            root->right = rightRotate(root->right);
            return leftRotate(root);
      }

      return root;
}

// Search for a key in AVL Tree
int search(Node *root, int key)
{
      if (root == NULL)
            return 0; // Not found
      if (root->key == key)
            return 1; // Found
      if (key < root->key)
            return search(root->left, key);
      else
            return search(root->right, key);
}

// Inorder traversal
void inorder(Node *root)
{
      if (root != NULL)
      {
            inorder(root->left);
            printf("%d ", root->key);
            inorder(root->right);
      }
}

// Preorder traversal
void preorder(Node *root)
{
      if (root != NULL)
      {
            printf("%d ", root->key);
            preorder(root->left);
            preorder(root->right);
      }
}

// Postorder traversal
void postorder(Node *root)
{
      if (root != NULL)
      {
            postorder(root->left);
            postorder(root->right);
            printf("%d ", root->key);
      }
}

int main()
{
      printf("Name : KATKURI NIKHIL\n");
      printf("ROLL NUMBER : 24E51A6774\n");
      Node *root = NULL;
      int choice, key;

      while (1)
      {
            printf("\nAVL Tree Operations:\n");
            printf("1. Insert\n2. Delete\n3. Search\n4. Inorder traversal\n5. Preorder traversal\n6. Postorder traversal\n7. Exit\n");
            choice = inputInt("Enter choice: ");

            switch (choice)
            {
            case 1:
                  key = inputInt("Enter key to insert: ");
                  root = insert(root, key);
                  printf("Inserted %d\n", key);
                  break;
            case 2:
                  key = inputInt("Enter key to delete: ");
                  root = deleteNode(root, key);
                  printf("Deleted %d\n", key);
                  break;
            case 3:
                  key = inputInt("Enter key to search: ");
                  if (search(root, key))
                        printf("Key %d found in AVL Tree\n", key);
                  else
                        printf("Key %d not found in AVL Tree\n", key);
                  break;
            case 4:
                  printf("Inorder traversal: ");
                  inorder(root);
                  printf("\n");
                  break;
            case 5:
                  printf("Preorder traversal: ");
                  preorder(root);
                  printf("\n");
                  break;
            case 6:
                  printf("Postorder traversal: ");
                  postorder(root);
                  printf("\n");
                  break;
            case 7:
                  exit(0);
            default:
                  printf("Invalid choice\n");
            }
      }
      return 0;
}

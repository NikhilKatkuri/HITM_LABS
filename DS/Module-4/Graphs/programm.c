#include <stdio.h>

int inputInt(char *prompt)
{
      int value;
      printf("%s", prompt);
      scanf("%d", &value);
      return value;
}

/**
 * program : BFS and DFS
 * BFS - queue
 * DFS - stack
 * using Adjacent matrix
 *
 */

#define MAX 1024
int size, graph[MAX][MAX], visited[MAX];
// stack
int stack[MAX], top = -1;
// queue
int queue[MAX];
int front = -1, rear = -1;

void fillZero()
{

      for (int i = 0; i < MAX; i++)
      {
            visited[i] = 0;
      }
}

void BFS(int start, int n);

void DFS(int start, int n);

int main()
{
      printf("Name : KATKURI NIKHIL\n");
      printf("ROLL NUMBER : 24E51A6774\n");
      size = inputInt("Enter size : ");

      int index = inputInt("Start from 0 or 1 : ");
      for (int i = index; i < size; i++)
      {
            for (int j = index; j < size; j++)
            {
                  printf("Enter number a[%d][%d] =  ", i, j);
                  graph[i][j] = inputInt("");
            }
      }
      int vertexStart = inputInt("Enter starting vertex : ");
      printf("BFS : ");
      DFS(vertexStart, size);
      printf("\nDFS : ");
      BFS(vertexStart, size);

      return 0;
}

void BFS(int start, int n)
{
      fillZero();

      visited[start] = 1;
      queue[rear++] = start;

      while (front < rear)
      {
            int node = queue[front++];
            printf("%d ", node);

            for (int i = 0; i < n; i++)
            {
                  if (graph[node][i] && !visited[i])
                  {
                        queue[rear++] = i;
                        visited[i] = 1;
                  }
            }
      }
}

void DFS(int start, int n)
{
      fillZero();
      int stack[n];
      int top = -1;

      stack[++top] = start;

      while (top != -1)
      {
            int node = stack[top--];
            if (!visited[node])
            {
                  visited[node] = 1;
                  printf("%d ", node);

                  for (int j = 0; j < n; j++)
                  {
                        if (graph[node][j] != 0 && !visited[j])
                        {
                              stack[++top] = j;
                        }
                  }
            }
      }
}

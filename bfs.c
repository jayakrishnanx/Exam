#include <stdio.h>
#define Max 30

int graph[Max][Max], vertex, visited[Max], Queue[Max], front = -1, rear = -1;
void Bfs(int v);
void enqueue(int v);
int dequeue(void);

int main()
{
    int start;
    printf("\nEnter Number Of Vertixes");
    scanf("%d", &vertex);
    printf("\nEnter Adjacency Matrix\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nEnter Starting Vertex");
    scanf("%d", &start);
    printf("\n *********BFS Starting*********\n");
    Bfs(start);
    return 1;
}

void Bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
    while (front != -1)
    {
       int v = dequeue();
        printf("\t%d", v);
        for (int i = 0; i < vertex; i++)
        {

            if (graph[v][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void enqueue(int v)
{
    if (rear == Max - 1)
    {
        printf("\nQueue is full");
        return;
    }

    if (front == -1)
        front = 0;

    Queue[++rear] = v;
}

int dequeue()
{
    int v = Queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return v;
}
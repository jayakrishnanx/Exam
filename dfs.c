#include <stdio.h>
#define Max 30
int top = -1, stack[Max], visited[Max], a[Max][Max], vert;

void push(int v)
{
    stack[++top] = v;
}

int pop()
{
    return(stack[top--]);
}

void DFS(int start)
{
    push(start);
    visited[start] = 1;
    while (top != -1)
    {
        int v=pop();
        printf("\t%d", v);
        
        for(int i=0;i<vert;i++)
        {
            if(a[v][i]==1 && !visited[i])
            {
                push(i);
                visited[i]=1;
            }
        }
    }
}
void main()
{
    int start;
    printf("\nEnter Number Of Vertixes:");
    scanf("%d", &vert);
    printf("\n Enter the Adjacency Matrix\n");
    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter Starting Vertex:");
    scanf("%d", &start);
    DFS(start);
}
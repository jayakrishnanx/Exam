#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *Createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void InsertFront(int data)
{
    struct node *newnode = Createnode(data);
    if (head == NULL)
    {
        head = newnode;
        tail = head;
        printf("\n%d->data Entered\n", data);
        return;
    }
    newnode->next = head;
    head = newnode;
    printf("\n%d->data Entered\n", data);
}

void InsertLast(int data)
{
    if (head == NULL)
    {
        InsertFront(data);
        return;
    }
    struct node *newnode = Createnode(data);
    tail->next = newnode;
    tail = newnode;
}

void InsertPos(int data, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        InsertFront(data);
        return;
    }
    struct node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    struct node *newnode = Createnode(data);
    newnode->next = ptr->next;
    ptr->next = newnode;
}

void DeleteFront()
{
    if (head == NULL)
    {
        printf("\n List Empty");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);
}

void DeleteLast()
{
    if (head == NULL)
    {
        printf("\nList Is Empty");
        return;
    }
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
        printf("\nDeleted Last Node");
        return;
    }

    struct node *ptr = head;
    while (ptr->next != tail)
    {
        ptr = ptr->next;
    }
    free(tail);
    ptr->next = NULL;
    tail = ptr;
}
void display()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }
    printf("\n**********Displaying Linked List*******\n");
    while (ptr != NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

void main()
{
    int choice, data, pos;
    while (1)
    {
        printf("\n\n");
        printf("\nEnter your choice");
        printf("\n1.Insert At Beggining");
        printf("\n2.Insert At End ");
        printf("\n3.Insert At Pos");
        printf("\n4.Delete At Front");
        printf("\n5.Delete At Last");
        printf("\n6.Delete At Pos");
        printf("\n7.Search An Element");
        printf("\n8.Display");
        printf("\n9.Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Data To Insert\n");
            scanf("%d", &data);
            InsertFront(data);
            break;

        case 2:
            printf("\nEnter Data To Insert\n");
            scanf("%d", &data);
            InsertLast(data);
            printf("\n%d data Entered\n", data);
            break;

        case 3:
            printf("\nEnter Data:");
            scanf("%d", &data);
            printf("\nEnter Position:");
            scanf("%d", &pos);
            InsertPos(data, pos);
            printf("\n%d data Entered", data);
            break;

        case 4:
            DeleteFront();
            break;

        case 5:
            DeleteLast();
            break;

        case 8:
            display();
            break;

        case 9:
            printf("\n*******Exiting*****\n");
            return;
        }
    }
}
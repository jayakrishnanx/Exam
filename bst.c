#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;

struct node *CreateNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *Insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = Insert(root->left, data);
    }
    return root;
}

struct node *Search(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }

    if (data > root->data)
    {
        return Search(root->right, data);
    }
    else if (data < root->data)
    {
        return Search(root->left, data);
    }
}

struct node *MinVal(struct node *ptr)
{
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

struct node *Delete(struct node *root, int data)
{

    if (root == NULL)
    {
        return root;
    }
    if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = MinVal(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}
struct node *Preorder(struct node *root)
{
    if (root == NULL)
    {
        return root;
    }
    printf("\t%d", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

struct node *Inorder(struct node *root)
{
    if (root == NULL)
    {
        return root;
    }
    Inorder(root->left);
    printf("\t%d", root->data);
    Inorder(root->right);
}

struct node *Postorder(struct node *root)
{
    if (root == NULL)
    {
        return root;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("\t%d", root->data);
}
void main()
{
    int choice, data;

    while (1)
    {
        printf("\n1.Insert");
        printf("\n2.Search");
        printf("\n3.Delete");
        printf("\n4.Display");
        printf("\nEnter Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Data:");
            scanf("%d", &data);
            root = Insert(root, data);
            printf("\n%d Inserted", data);
            break;

        case 2:
            printf("\nEnter Data:");
            scanf("%d", &data);
            if (Search(root, data))
            {
                printf("\n%d Found ", data);
            }
            else
            {
                printf("\n %d Not Found");
            }
            break;

        case 3:
            printf("\nEnter Data");
            scanf("%d", &data);
            if (Search(root, data))
            {
                root = Delete(root, data);
                printf("%d Deleted", data);
            }
            else
            {
                printf("%d Not Found", data);
            }
            break;

        case 4:
            printf("\nEnter Your Choice");
            printf("\n1.Inorder");
            printf("\n2.Preorder");
            printf("\n3.Postorder");

            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\n******Inorder Traversal *******\n");
                Inorder(root);
                break;

            case 2:
                printf("\n******Preorder Traversal *******\n");
                Preorder(root);
                break;

            case 3:
                printf("\n******Postorder Traversal *******\n");
                Postorder(root);
                break;
            }
        }
    }
}

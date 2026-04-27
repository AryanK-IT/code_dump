#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *convert(struct treenode *root)
{
    struct treenode *curr = root;
    struct node *head = NULL;
    struct node *temp = head;

    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            struct node *newNode = createNewNode();
            temp->next = newNode;
            newNode->prev = temp;
            newNode->data = curr->data;

            curr = curr->right;
        }
        else
        {
            struct treenode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;

                struct node *newNode = createNewNode();
                temp->next = newNode;
                newNode->prev = temp;
                newNode->data = curr->data;

                curr = curr->right;
            }
        }
    }
    return head;
}

struct node *createNewNode()
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct node
{
    int val;
    struct node *next;
    struct node *random;
};

struct node *createNewNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = NULL;
    newNode->random = NULL;

    return newNode;
}

struct node *clone(struct node *head)
{
    if (head == NULL)
        return NULL;

    struct node *temp = head;
    struct node **address_array[MAX_SIZE];

    int i = 0;
    int length = 0;

    // traverse the original list first and store all node addresses
    while (temp != NULL)
    {
        address_array[i++] = &temp;
        temp = temp->next;
        length++;
    }

    // create a cloned list
    temp = head;

    while (temp != NULL)
    {
        struct node *newNode = createNewNode(temp->val);
        newNode->next = temp->next;
        newNode->random = address_array[rand() % (length + 1)];
        temp = temp->next;
    }

    return head;
}
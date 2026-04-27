#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHARS 256

typedef struct trienode
{
    struct trienode *children[NUM_CHARS];
    bool terminal;
} trienode;

trienode *createNode()
{
    trienode *newNode = malloc(sizeof *newNode);
    // trienode *newNode = (trienode*)malloc(sizeof(trienode));

    for (int i = 0; i < NUM_CHARS; i++)
    {
        newNode->children[i] = NULL;
    }
    newNode->terminal = false;
    return newNode;
}

bool treiInsert(trienode **root, char *signedText)
{
    if (*root == NULL)
    {
        *root = createNode();
    }

    unsigned char *text = (unsigned char *)signedText;
    trienode *temp = *root;
    int length = strlen(signedText);

    for (int i = 0; i < length; i++)
    {
        if (temp->children[text[i]] == NULL)
        {
            // create a new node
            temp->children[text[i]] = createNode();
        }
        temp = temp->children[text[i]];
    }
    if (temp->terminal)
    {
        return false;
    }
    else
    {
        temp->terminal = true;
        return true;
    }
}

void printTrie_rec(trienode *node, unsigned char *prefix, int length)
{
    unsigned char *newprefix = (unsigned char *)malloc(length + 2);
    memcpy(newprefix, prefix, length);
    newprefix[length + 1] = 0;

    if (node->terminal)
    {
        printf("WORD: %s\n", prefix);
    }

    for (int i = 0; i < NUM_CHARS; i++)
    {
        if (node->children[i] != NULL)
        {
            newprefix[length] = i;
            printTrie_rec(node->children[i], newprefix, length + 1);
        }
    }
}

void printTrie(trienode *root)
{
    if (root == NULL)
    {
        printf("Trie empty!\n");
        return;
    }
    printTrie_rec(root, NULL, 0);
}

bool searchtrie(trienode *root, char *signedtext)
{
    unsigned char *text = (unsigned char *)signedtext;
    int length = strlen(signedtext);
    trienode *temp = root;

    for (int i = 0; i < length; i++)
    {
        if (temp->children[text[i]] == NULL)
        {
            return false;
        }
        temp = temp->children[text[i]];
    }
    return temp->terminal;
}

int main()
{
    trienode *root = NULL;

    treiInsert(&root, "KIT");
    treiInsert(&root, "CATTLE");
    treiInsert(&root, "KIN");
    treiInsert(&root, "CAT");
    treiInsert(&root, "HAPPY");

    printTrie(root);

    printf("search for CATTLE: %d\n", searchtrie(root, "CATTLE"));
    printf("search for CAT: %d\n", searchtrie(root, "CAT"));
    printf("search for KITTEN: %d\n", searchtrie(root, "KITTEN"));
}
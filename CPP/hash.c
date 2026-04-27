#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10000

typedef struct node
{
    char *key;
    char *value;
    struct node *next;
} node;

typedef struct
{
    node **entries;
} hashtable;

unsigned int hash(const char *key)
{
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i)
    {
        value = value * 37 + key[i];
    }

    value = value % TABLE_SIZE;

    return value;
}

hashtable *create_hashtable(void)
{
    /// allocate table
    hashtable *newHashT = (hashtable *)malloc(sizeof(hashtable) * 1);

    /// allocate table entries
    newHashT->entries = malloc(sizeof(node *) * TABLE_SIZE);

    /// set them all to NULL
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        newHashT->entries[i] = NULL;
    }

    return newHashT;
}

node *hashtable_pair(const char *key, const char *value)
{
    /// allocate the entry
    node *entry = malloc(sizeof(node));
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    /// copy the key value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    /// next is NULL for now
    entry->next = NULL;

    return entry;
}

void hashtable_set(hashtable *hashT, const char *key, const char *value)
{
    unsigned int slot = hash(key);
    node *entry = hashT->entries[slot];

    if (entry == NULL)
    {
        hashT->entries[slot] = hashtable_pair(key, value);
        return;
    }

    node *prev;
    /// traverse the entire chain untill the matching value is found or we reach the end

    while (entry != NULL)
    {
        /// check key
        if (strcmp(entry->key, key) == 0)
        {
            /// match found
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        prev = entry;
        entry = prev->next;
    }

    /// at this point the end of the chain is reached without a match
    prev->next = hashtable_pair(key, value);
}

char *hashtable_get(hashtable *hashT, const char *key)
{
    unsigned int slot = hash(key);
    /// try to find a valid slot
    node *entry = hashT->entries[slot];

    /// no slot means no entry
    if (entry == NULL)
    {
        return NULL;
    }

    /// walk through each entry in the slot, which could just be a single thing
    while (entry != NULL)
    {
        /// return value if found
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

void hashtable_dump(hashtable *hashT)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        node *entry = hashT->entries[i];

        if (entry == NULL)
        {
            continue;
        }

        printf("slot[%4d]: ", i);

        for (;;)
        {
            printf("%s=%s ", entry->key, entry->value);

            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{
    hashtable *hashT = create_hashtable();

    hashtable_set(hashT, "name1", "bruh");
    hashtable_set(hashT, "name2", "india");
    hashtable_set(hashT, "name3", "nigger");
    hashtable_set(hashT, "name4", "cortisol");
    hashtable_set(hashT, "name5", "speed");
    hashtable_set(hashT, "name6", "partick");
    hashtable_set(hashT, "name7", "duncan");

    hashtable_dump(hashT);
    return 0;
}
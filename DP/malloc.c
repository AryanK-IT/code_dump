#define SIZE 1024
char memory[SIZE];

struct Block
{
    int size;
    int free;
    struct Block *next;
};

struct Block *freeList = (struct Block *)memory;

void init()
{
    freeList->size = SIZE - sizeof(struct Block);
    freeList->free = 1;
}

void *my_malloc(int size)
{
    struct Block *curr = freeList;
    while (curr)
    {
        if (curr->free && curr->size >= size)
        {
            curr->free = 0;
            return (void *)(curr + 1);
        }
        curr = curr->next;
    }
}

void my_free(void *ptr)
{
    if (!ptr)
        return;
    struct Block *block = (struct Block *)ptr - 1;
    block->free = 1;
}
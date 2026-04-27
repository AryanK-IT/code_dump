// DATA STRUCTURES IN C — Complete Reference Implementation
// Covers: Array, Linked List, Stack, Queue, Binary Search, Tree, Min-Heap, Hash Table, Graph (Adjacency List)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 1. ARRAY
//    Static array with insert, delete, search, sort (bubble)
#define ARRAY_MAX 100

typedef struct
{
    int data[ARRAY_MAX];
    int size;
} Array;

void array_init(Array *a)
{
    a->size = 0;
}

/// Insert at end — O(1)
bool array_insert(Array *a, int value)
{
    if (a->size >= ARRAY_MAX)
    {
        printf("[Array] Overflow\n");
        return false;
    }
    a->data[a->size++] = value;
    return true;
}

/// Insert at index — O(n)
bool array_insert_at(Array *a, int index, int value)
{
    if (a->size >= ARRAY_MAX || index < 0 || index > a->size)
        return false;
    for (int i = a->size; i > index; i--)
        a->data[i] = a->data[i - 1];
    a->data[index] = value;
    a->size++;
    return true;
}

/// Delete at index — O(n)
bool array_delete(Array *a, int index)
{
    if (index < 0 || index >= a->size)
    {
        printf("[Array] Index out of bounds\n");
        return false;
    }
    for (int i = index; i < a->size - 1; i++)
        a->data[i] = a->data[i + 1];
    a->size--;
    return true;
}

/// Linear search — O(n)
int array_search(Array *a, int value)
{
    for (int i = 0; i < a->size; i++)
        if (a->data[i] == value)
            return i;
    return -1;
}

/// Binary search (array must be sorted) — O(log n)
int array_binary_search(Array *a, int value)
{
    int lo = 0, hi = a->size - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (a->data[mid] == value)
            return mid;
        else if (a->data[mid] < value)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

/// Bubble sort — O(n²)
void array_sort(Array *a)
{
    for (int i = 0; i < a->size - 1; i++)
        for (int j = 0; j < a->size - 1 - i; j++)
            if (a->data[j] > a->data[j + 1])
            {
                int tmp = a->data[j];
                a->data[j] = a->data[j + 1];
                a->data[j + 1] = tmp;
            }
}

void array_print(Array *a)
{
    printf("[Array] ");
    for (int i = 0; i < a->size; i++)
        printf("%d ", a->data[i]);
    printf("\n");
}

// 2. SINGLY LINKED LIST
//    insert (head/tail/position), delete, search, sort

typedef struct LLNode
{
    int data;
    struct LLNode *next;
} LLNode;

typedef struct
{
    LLNode *head;
    int size;
} LinkedList;

void ll_init(LinkedList *l)
{
    l->head = NULL;
    l->size = 0;
}

LLNode *ll_new_node(int value)
{
    LLNode *n = malloc(sizeof(LLNode));
    n->data = value;
    n->next = NULL;
    return n;
}

/// Insert at head — O(1)
void ll_insert_head(LinkedList *l, int value)
{
    LLNode *n = ll_new_node(value);
    n->next = l->head;
    l->head = n;
    l->size++;
}

/// Insert at tail — O(n)
void ll_insert_tail(LinkedList *l, int value)
{
    LLNode *n = ll_new_node(value);
    if (!l->head)
    {
        l->head = n;
        l->size++;
        return;
    }
    LLNode *cur = l->head;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
    l->size++;
}

/// Insert at position (0-indexed) — O(n)
bool ll_insert_at(LinkedList *l, int pos, int value)
{
    if (pos < 0 || pos > l->size)
        return false;
    if (pos == 0)
    {
        ll_insert_head(l, value);
        return true;
    }
    LLNode *cur = l->head;
    for (int i = 0; i < pos - 1; i++)
        cur = cur->next;
    LLNode *n = ll_new_node(value);
    n->next = cur->next;
    cur->next = n;
    l->size++;
    return true;
}

/// Delete by value (first occurrence) — O(n)
bool ll_delete(LinkedList *l, int value)
{
    if (!l->head)
        return false;
    if (l->head->data == value)
    {
        LLNode *tmp = l->head;
        l->head = l->head->next;
        free(tmp);
        l->size--;
        return true;
    }
    LLNode *cur = l->head;
    while (cur->next && cur->next->data != value)
        cur = cur->next;
    if (!cur->next)
        return false;
    LLNode *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    l->size--;
    return true;
}

/// Search by value — O(n), returns position or -1
int ll_search(LinkedList *l, int value)
{
    LLNode *cur = l->head;
    int pos = 0;
    while (cur)
    {
        if (cur->data == value)
            return pos;
        cur = cur->next;
        pos++;
    }
    return -1;
}

/// Sort using bubble sort on nodes — O(n²)
void ll_sort(LinkedList *l)
{
    if (!l->head)
        return;
    bool swapped;
    do
    {
        swapped = false;
        LLNode *cur = l->head;
        while (cur->next)
        {
            if (cur->data > cur->next->data)
            {
                int tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}

void ll_print(LinkedList *l)
{
    printf("[LinkedList] ");
    LLNode *cur = l->head;
    while (cur)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void ll_free(LinkedList *l)
{
    LLNode *cur = l->head;
    while (cur)
    {
        LLNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    l->head = NULL;
    l->size = 0;
}

// 3. STACK  (array-based)
//    push, pop, peek, search

#define STACK_MAX 100

typedef struct
{
    int data[STACK_MAX];
    int top;
} Stack;

void stack_init(Stack *s) { s->top = -1; }
bool stack_is_empty(Stack *s) { return s->top == -1; }
bool stack_is_full(Stack *s) { return s->top == STACK_MAX - 1; }

bool stack_push(Stack *s, int value)
{
    if (stack_is_full(s))
    {
        printf("[Stack] Overflow\n");
        return false;
    }
    s->data[++s->top] = value;
    return true;
}

int stack_pop(Stack *s)
{
    if (stack_is_empty(s))
    {
        printf("[Stack] Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int stack_peek(Stack *s)
{
    if (stack_is_empty(s))
    {
        printf("[Stack] Empty\n");
        return -1;
    }
    return s->data[s->top];
}

/// Search from top — O(n), returns depth from top (0 = top)
int stack_search(Stack *s, int value)
{
    for (int i = s->top; i >= 0; i--)
        if (s->data[i] == value)
            return s->top - i;
    return -1;
}

void stack_print(Stack *s)
{
    printf("[Stack] top -> ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->data[i]);
    printf("\n");
}

// 4. QUEUE  (circular array-based)
//    enqueue, dequeue, peek, search

#define QUEUE_MAX 100

typedef struct
{
    int data[QUEUE_MAX];
    int front, rear, size;
} Queue;

void queue_init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
bool queue_is_empty(Queue *q) { return q->size == 0; }
bool queue_is_full(Queue *q) { return q->size == QUEUE_MAX; }

bool queue_enqueue(Queue *q, int value)
{
    if (queue_is_full(q))
    {
        printf("[Queue] Overflow\n");
        return false;
    }
    q->rear = (q->rear + 1) % QUEUE_MAX;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

int queue_dequeue(Queue *q)
{
    if (queue_is_empty(q))
    {
        printf("[Queue] Underflow\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_MAX;
    q->size--;
    return val;
}

int queue_peek(Queue *q)
{
    if (queue_is_empty(q))
        return -1;
    return q->data[q->front];
}

/// Linear search — O(n)
int queue_search(Queue *q, int value)
{
    for (int i = 0; i < q->size; i++)
    {
        int idx = (q->front + i) % QUEUE_MAX;
        if (q->data[idx] == value)
            return i; /// position from front
    }
    return -1;
}

void queue_print(Queue *q)
{
    printf("[Queue] front -> ");
    for (int i = 0; i < q->size; i++)
        printf("%d ", q->data[(q->front + i) % QUEUE_MAX]);
    printf("<- rear\n");
}

//5. BINARY SEARCH TREE (BST)
//   insert, delete, search, inorder/preorder/postorder

typedef struct BSTNode
{
    int data;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode *bst_new_node(int value)
{
    BSTNode *n = malloc(sizeof(BSTNode));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

/// Insert — O(log n) average
BSTNode *bst_insert(BSTNode *root, int value)
{
    if (!root)
        return bst_new_node(value);
    if (value < root->data)
        root->left = bst_insert(root->left, value);
    else if (value > root->data)
        root->right = bst_insert(root->right, value);
    return root; /// duplicate ignored
}

/// Find minimum node in a subtree
BSTNode *bst_min_node(BSTNode *root)
{
    while (root->left)
        root = root->left;
    return root;
}

/// Delete — O(log n) average
BSTNode *bst_delete(BSTNode *root, int value)
{
    if (!root)
        return NULL;
    if (value < root->data)
        root->left = bst_delete(root->left, value);
    else if (value > root->data)
        root->right = bst_delete(root->right, value);
    else
    {
        if (!root->left)
        {
            BSTNode *tmp = root->right;
            free(root);
            return tmp;
        }
        if (!root->right)
        {
            BSTNode *tmp = root->left;
            free(root);
            return tmp;
        }
        BSTNode *succ = bst_min_node(root->right);
        root->data = succ->data;
        root->right = bst_delete(root->right, succ->data);
    }
    return root;
}

/// Search — O(log n) average
BSTNode *bst_search(BSTNode *root, int value)
{
    if (!root || root->data == value)
        return root;
    if (value < root->data)
        return bst_search(root->left, value);
    else
        return bst_search(root->right, value);
}

void bst_inorder(BSTNode *root)
{
    if (!root)
        return;
    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}
void bst_preorder(BSTNode *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}
void bst_postorder(BSTNode *root)
{
    if (!root)
        return;
    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->data);
}

void bst_free(BSTNode *root)
{
    if (!root)
        return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

//6. MIN-HEAP  (array-based priority queue)
//   insert, delete-min, search, heapify / sort

#define HEAP_MAX 100

typedef struct
{
    int data[HEAP_MAX];
    int size;
} MinHeap;

void heap_init(MinHeap *h) { h->size = 0; }

static void heap_swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/// Bubble up after insert
static void heap_bubble_up(MinHeap *h, int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (h->data[parent] > h->data[i])
        {
            heap_swap(&h->data[parent], &h->data[i]);
            i = parent;
        }
        else
            break;
    }
}

/// Bubble down after delete
static void heap_bubble_down(MinHeap *h, int i)
{
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < h->size && h->data[left] < h->data[smallest])
        smallest = left;
    if (right < h->size && h->data[right] < h->data[smallest])
        smallest = right;
    if (smallest != i)
    {
        heap_swap(&h->data[i], &h->data[smallest]);
        heap_bubble_down(h, smallest);
    }
}

/// Insert — O(log n)
bool heap_insert(MinHeap *h, int value)
{
    if (h->size >= HEAP_MAX)
    {
        printf("[Heap] Overflow\n");
        return false;
    }
    h->data[h->size++] = value;
    heap_bubble_up(h, h->size - 1);
    return true;
}

/// Delete minimum — O(log n)
int heap_delete_min(MinHeap *h)
{
    if (h->size == 0)
    {
        printf("[Heap] Empty\n");
        return -1;
    }
    int min = h->data[0];
    h->data[0] = h->data[--h->size];
    heap_bubble_down(h, 0);
    return min;
}

int heap_peek_min(MinHeap *h)
{
    return h->size ? h->data[0] : -1;
}

/// Linear search — O(n)
int heap_search(MinHeap *h, int value)
{
    for (int i = 0; i < h->size; i++)
        if (h->data[i] == value)
            return i;
    return -1;
}

/// Heap sort — O(n log n): drains a copy of the heap
void heap_sort(int *arr, int n)
{
    MinHeap h;
    heap_init(&h);
    for (int i = 0; i < n; i++)
        heap_insert(&h, arr[i]);
    for (int i = 0; i < n; i++)
        arr[i] = heap_delete_min(&h);
}

void heap_print(MinHeap *h)
{
    printf("[MinHeap] ");
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->data[i]);
    printf("\n");
}

// 7. HASH TABLE  (chaining with linked lists)
//    insert, delete, search

#define HT_CAPACITY 16

typedef struct HTNode
{
    int key;
    int value;
    struct HTNode *next;
} HTNode;

typedef struct
{
    HTNode *buckets[HT_CAPACITY];
} HashTable;

void ht_init(HashTable *ht)
{
    for (int i = 0; i < HT_CAPACITY; i++)
        ht->buckets[i] = NULL;
}

static int ht_hash(int key)
{
    return abs(key) % HT_CAPACITY;
}

/// Insert or update — O(1) average
void ht_insert(HashTable *ht, int key, int value)
{
    int h = ht_hash(key);
    HTNode *cur = ht->buckets[h];
    while (cur)
    {
        if (cur->key == key)
        {
            cur->value = value;
            return;
        } /// update
        cur = cur->next;
    }
    HTNode *n = malloc(sizeof(HTNode));
    n->key = key;
    n->value = value;
    n->next = ht->buckets[h];
    ht->buckets[h] = n;
}

/// Search — O(1) average, returns pointer or NULL
HTNode *ht_search(HashTable *ht, int key)
{
    int h = ht_hash(key);
    HTNode *cur = ht->buckets[h];
    while (cur)
    {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

/// Delete — O(1) average
bool ht_delete(HashTable *ht, int key)
{
    int h = ht_hash(key);
    HTNode *cur = ht->buckets[h], *prev = NULL;
    while (cur)
    {
        if (cur->key == key)
        {
            if (prev)
                prev->next = cur->next;
            else
                ht->buckets[h] = cur->next;
            free(cur);
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void ht_print(HashTable *ht)
{
    printf("[HashTable]\n");
    for (int i = 0; i < HT_CAPACITY; i++)
    {
        if (!ht->buckets[i])
            continue;
        printf("  [%2d] ", i);
        HTNode *cur = ht->buckets[i];
        while (cur)
        {
            printf("(%d:%d) -> ", cur->key, cur->value);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void ht_free(HashTable *ht)
{
    for (int i = 0; i < HT_CAPACITY; i++)
    {
        HTNode *cur = ht->buckets[i];
        while (cur)
        {
            HTNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        ht->buckets[i] = NULL;
    }
}

//8. GRAPH  (adjacency list, undirected, unweighted)
//   add/remove vertex & edge, BFS, DFS

#define GRAPH_MAX_V 20

typedef struct AdjNode
{
    int dest;
    struct AdjNode *next;
} AdjNode;

typedef struct
{
    AdjNode *adj[GRAPH_MAX_V];
    int num_vertices;
} Graph;

void graph_init(Graph *g, int vertices)
{
    g->num_vertices = vertices;
    for (int i = 0; i < vertices; i++)
        g->adj[i] = NULL;
}

/// Add undirected edge — O(1)
void graph_add_edge(Graph *g, int u, int v)
{
    AdjNode *nu = malloc(sizeof(AdjNode));
    nu->dest = v;
    nu->next = g->adj[u];
    g->adj[u] = nu;
    AdjNode *nv = malloc(sizeof(AdjNode));
    nv->dest = u;
    nv->next = g->adj[v];
    g->adj[v] = nv;
}

/// Remove undirected edge — O(degree)
void graph_remove_edge(Graph *g, int u, int v)
{
    AdjNode **cur = &g->adj[u];
    while (*cur)
    {
        if ((*cur)->dest == v)
        {
            AdjNode *tmp = *cur;
            *cur = tmp->next;
            free(tmp);
            break;
        }
        cur = &(*cur)->next;
    }
    cur = &g->adj[v];
    while (*cur)
    {
        if ((*cur)->dest == u)
        {
            AdjNode *tmp = *cur;
            *cur = tmp->next;
            free(tmp);
            break;
        }
        cur = &(*cur)->next;
    }
}

/// BFS from source — O(V + E)
void graph_bfs(Graph *g, int src)
{
    bool visited[GRAPH_MAX_V] = {false};
    int q[GRAPH_MAX_V], front = 0, rear = 0;
    visited[src] = true;
    q[rear++] = src;
    printf("[Graph BFS from %d] ", src);
    while (front < rear)
    {
        int u = q[front++];
        printf("%d ", u);
        for (AdjNode *n = g->adj[u]; n; n = n->next)
        {
            if (!visited[n->dest])
            {
                visited[n->dest] = true;
                q[rear++] = n->dest;
            }
        }
    }
    printf("\n");
}

static void dfs_util(Graph *g, int u, bool *visited)
{
    visited[u] = true;
    printf("%d ", u);
    for (AdjNode *n = g->adj[u]; n; n = n->next)
        if (!visited[n->dest])
            dfs_util(g, n->dest, visited);
}

/// DFS from source — O(V + E)
void graph_dfs(Graph *g, int src)
{
    bool visited[GRAPH_MAX_V] = {false};
    printf("[Graph DFS from %d] ", src);
    dfs_util(g, src, visited);
    printf("\n");
}

/// Search: check if a vertex exists — O(V + E) via BFS reachability
bool graph_search(Graph *g, int src, int target)
{
    bool visited[GRAPH_MAX_V] = {false};
    int q[GRAPH_MAX_V], front = 0, rear = 0;
    visited[src] = true;
    q[rear++] = src;
    while (front < rear)
    {
        int u = q[front++];
        if (u == target)
            return true;
        for (AdjNode *n = g->adj[u]; n; n = n->next)
            if (!visited[n->dest])
            {
                visited[n->dest] = true;
                q[rear++] = n->dest;
            }
    }
    return false;
}

void graph_print(Graph *g)
{
    printf("[Graph Adjacency List]\n");
    for (int i = 0; i < g->num_vertices; i++)
    {
        printf("  %d: ", i);
        for (AdjNode *n = g->adj[i]; n; n = n->next)
            printf("%d -> ", n->dest);
        printf("NULL\n");
    }
}

void graph_free(Graph *g)
{
    for (int i = 0; i < g->num_vertices; i++)
    {
        AdjNode *cur = g->adj[i];
        while (cur)
        {
            AdjNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        g->adj[i] = NULL;
    }
}

// MAIN — demonstration of every structure

int main(void)
{

    /// --- 1. Array ---
    printf("\n====== 1. ARRAY ======\n");
    Array arr;
    array_init(&arr);
    array_insert(&arr, 5);
    array_insert(&arr, 2);
    array_insert(&arr, 8);
    array_insert(&arr, 1);
    array_insert(&arr, 9);
    array_print(&arr);
    array_insert_at(&arr, 2, 42);
    printf("After insert 42 at index 2: ");
    array_print(&arr);
    array_delete(&arr, 2);
    printf("After delete at index 2:    ");
    array_print(&arr);
    printf("Linear search 8: index %d\n", array_search(&arr, 8));
    array_sort(&arr);
    printf("After sort: ");
    array_print(&arr);
    printf("Binary search 8 (sorted): index %d\n", array_binary_search(&arr, 8));

    /// --- 2. Linked List ---
    printf("\n====== 2. LINKED LIST ======\n");
    LinkedList ll;
    ll_init(&ll);
    ll_insert_tail(&ll, 3);
    ll_insert_tail(&ll, 7);
    ll_insert_tail(&ll, 1);
    ll_insert_head(&ll, 0);
    ll_print(&ll);
    ll_insert_at(&ll, 2, 99);
    printf("After insert 99 at pos 2: ");
    ll_print(&ll);
    ll_delete(&ll, 99);
    printf("After delete 99:          ");
    ll_print(&ll);
    printf("Search 7: position %d\n", ll_search(&ll, 7));
    ll_sort(&ll);
    printf("After sort: ");
    ll_print(&ll);
    ll_free(&ll);

    /// --- 3. Stack ---
    printf("\n====== 3. STACK ======\n");
    Stack stk;
    stack_init(&stk);
    stack_push(&stk, 10);
    stack_push(&stk, 20);
    stack_push(&stk, 30);
    stack_print(&stk);
    printf("Peek: %d\n", stack_peek(&stk));
    printf("Search 10 (depth from top): %d\n", stack_search(&stk, 10));
    printf("Pop: %d\n", stack_pop(&stk));
    stack_print(&stk);

    /// --- 4. Queue ---
    printf("\n====== 4. QUEUE ======\n");
    Queue q;
    queue_init(&q);
    queue_enqueue(&q, 100);
    queue_enqueue(&q, 200);
    queue_enqueue(&q, 300);
    queue_print(&q);
    printf("Peek: %d\n", queue_peek(&q));
    printf("Search 200 (pos from front): %d\n", queue_search(&q, 200));
    printf("Dequeue: %d\n", queue_dequeue(&q));
    queue_print(&q);

    /// --- 5. BST ---
    printf("\n====== 5. BINARY SEARCH TREE ======\n");
    BSTNode *bst = NULL;
    int bst_vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        bst = bst_insert(bst, bst_vals[i]);
    printf("Inorder   (sorted): ");
    bst_inorder(bst);
    printf("\n");
    printf("Preorder           : ");
    bst_preorder(bst);
    printf("\n");
    printf("Postorder          : ");
    bst_postorder(bst);
    printf("\n");
    printf("Search 40: %s\n", bst_search(bst, 40) ? "Found" : "Not found");
    printf("Search 99: %s\n", bst_search(bst, 99) ? "Found" : "Not found");
    bst = bst_delete(bst, 50);
    printf("After deleting root 50, inorder: ");
    bst_inorder(bst);
    printf("\n");
    bst_free(bst);

    /// --- 6. Min-Heap ---
    printf("\n====== 6. MIN-HEAP ======\n");
    MinHeap heap;
    heap_init(&heap);
    int hvals[] = {15, 10, 5, 20, 3};
    for (int i = 0; i < 5; i++)
        heap_insert(&heap, hvals[i]);
    heap_print(&heap);
    printf("Peek min: %d\n", heap_peek_min(&heap));
    printf("Search 20: index %d\n", heap_search(&heap, 20));
    printf("Delete min: %d\n", heap_delete_min(&heap));
    heap_print(&heap);
    int to_sort[] = {9, 4, 7, 2, 6};
    heap_sort(to_sort, 5);
    printf("Heap sort result: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", to_sort[i]);
    printf("\n");

    /// --- 7. Hash Table ---
    printf("\n====== 7. HASH TABLE ======\n");
    HashTable ht;
    ht_init(&ht);
    ht_insert(&ht, 1, 100);
    ht_insert(&ht, 17, 200);
    ht_insert(&ht, 33, 300);
    ht_insert(&ht, 5, 500);
    ht_print(&ht);
    HTNode *found = ht_search(&ht, 17);
    printf("Search key 17: %s (value=%d)\n", found ? "Found" : "Not found", found ? found->value : -1);
    ht_delete(&ht, 17);
    printf("After deleting key 17:\n");
    ht_print(&ht);
    ht_free(&ht);

    /// --- 8. Graph ---
    printf("\n====== 8. GRAPH (Adjacency List) ======\n");
    Graph g;
    graph_init(&g, 6);
    graph_add_edge(&g, 0, 1);
    graph_add_edge(&g, 0, 2);
    graph_add_edge(&g, 1, 3);
    graph_add_edge(&g, 2, 4);
    graph_add_edge(&g, 3, 5);
    graph_print(&g);
    graph_bfs(&g, 0);
    graph_dfs(&g, 0);
    printf("Can reach 5 from 0? %s\n", graph_search(&g, 0, 5) ? "Yes" : "No");
    printf("Can reach 5 from 4? %s\n", graph_search(&g, 4, 5) ? "Yes" : "No");
    graph_remove_edge(&g, 3, 5);
    printf("After removing edge 3-5:\n");
    graph_print(&g);
    printf("Can reach 5 from 0 now? %s\n", graph_search(&g, 0, 5) ? "Yes" : "No");
    graph_free(&g);

    printf("\nAll done.\n");
    return 0;
}
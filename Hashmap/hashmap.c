#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


// STRUCTURES
typedef struct Node
{
    int key;
    int value;
    struct Node* nextnode;
} Node;

typedef struct Hashmap
{
    Node* arr[SIZE];
} Hashmap;


// FUNCTIONS
int hash(int key)
{
    return key % SIZE;
}

Hashmap* initHashmap()
{
    Hashmap* map = (Hashmap*)malloc(sizeof(Hashmap));
    for (int i=0; i<SIZE; i++) {
        map->arr[i] = NULL;
    }
    return map;
}

Node* createNode(int key, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->value = value;
    newnode->nextnode = NULL;
    return newnode;
}

void addNode(int key, int value, Hashmap* map)
{
    int index = hash(key);
    Node* newnode = createNode(key, value);
    if (map->arr[index] == NULL) {
        map->arr[index] = newnode;
    }
    else {
        Node* currentNode = map->arr[index];
        while (currentNode->nextnode != NULL) {
            currentNode = currentNode->nextnode;
        }
        currentNode->nextnode = newnode;
    }
}

void getNodes(int key, Hashmap* map)
{
    int index = hash(key);
    Node* curr = map->arr[index];
    printf("%d [", index);
    while (curr != NULL) {
        printf("-> (%d %d)", curr->key, curr->value);
        curr = curr->nextnode;
    }
    printf("-> NULL ]\n");
}

void printHashMap(Hashmap* map)
{
    for (int i=0; i<SIZE; i++) {
        printf("%d [", i);
        Node* curr = map->arr[i];
        while (curr != NULL) {
            printf(" -> (%d %d)", curr->key, curr->value);
            curr = curr->nextnode;
        }
        printf(" -> NULL  ]\n");
    }
}


// DRIVER CODE
int main()
{
    Hashmap* map = initHashmap();
    addNode(0, 100, map);
    addNode(0, 101, map);
    addNode(2, 200, map);
    addNode(3, 300, map);
    addNode(7, 700, map);
    addNode(7, 701, map);
    addNode(7, 102, map);
    printHashMap(map);
    getNodes(7, map);
    return 0;
}


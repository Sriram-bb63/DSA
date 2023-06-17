#include <stdio.h>
#include <stdlib.h>

#define SIZE 56


// STRUCTURES
typedef struct Node
{
    // int key;
    char key;
    int value;
    struct Node* nextnode;
} Node;

typedef struct Hashmap
{
    Node* arr[SIZE];
} Hashmap;


// FUNCTIONS
int hash(char key)
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

Node* createNode(char key, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->value = value;
    newnode->nextnode = NULL;
    return newnode;
}

void addNode(char key, int value, Hashmap* map)
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

void getNodes(char key, Hashmap* map)
{
    int index = hash(key);
    Node* curr = map->arr[index];
    printf("%d [", index);
    while (curr != NULL) {
        printf("-> (%c %d)", curr->key, curr->value);
        curr = curr->nextnode;
    }
    printf("-> NULL ]\n");
}

void printHashMap(Hashmap* map)
{
    printf("Index Nodes\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d [ ", i);
        Node* curr = map->arr[i];
        while (curr != NULL) {
            printf("-> (%c %d) ", curr->key, curr->value);
            curr = curr->nextnode;
        }
        printf(" -> NULL  ]\n");
    }
}


// DRIVER CODE
int main()
{
    Hashmap* map = initHashmap();
    addNode('a', 100, map);
    addNode('b', 101, map);
    addNode('b', 200, map);
    addNode('z', 300, map);
    addNode('z', 700, map);
    addNode('a', 701, map);
    addNode('z', 102, map);
    printHashMap(map);
    printf("\n");
    getNodes('z', map);
    return 0;
}


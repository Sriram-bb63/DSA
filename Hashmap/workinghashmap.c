#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node* array[SIZE];
} HashMap;

int hash(int key) {
    return key % SIZE;
}

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < SIZE; i++) {
        map->array[i] = NULL;
    }
    return map;
}

void put(HashMap* map, int key, int value) {
    int index = hash(key);
    Node* newNode = createNode(key, value);

    if (map->array[index] == NULL) {
        map->array[index] = newNode;
    } else {
        Node* currentNode = map->array[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

int get(HashMap* map, int key) {
    int index = hash(key);
    Node* currentNode = map->array[index];

    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }

    return -1;  // Key not found
}

void removeKey(HashMap* map, int key) {
    int index = hash(key);
    Node* currentNode = map->array[index];
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->key == key) {
            if (prevNode == NULL) {
                map->array[index] = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
}

void printHashMap(HashMap* map) {
    for (int i = 0; i < SIZE; i++) {
        Node* currentNode = map->array[i];
        printf("Bucket %d: ", i);
        while (currentNode != NULL) {
            printf("(%d, %d) -> ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashMap* map = createHashMap();

    put(map, 0, 100);
    put(map, 0, 101);
    put(map, 2, 200);
    put(map, 3, 300);
    put(map, 7, 700);
    put(map, 7, 701);
    put(map, 7, 102);

    // printf("Value for key 5: %d\n", get(map, 5));
    // printf("Value for key 15: %d\n", get(map, 15));
    // printf("Value for key 20: %d\n", get(map, 20));
    // printf("Value for key 25: %d\n", get(map, 25));

    // removeKey(map, 15);

    // printf("Value for key 15: %d\n", get(map, 15));

    printHashMap(map);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int print_linked_list(struct Node* head)
{
    struct Node* curr = head;
    printf("%d %p %p\n\n", head->data, (void*)&head, (void*)head->next);
    while (curr != NULL) {
        printf("Val: %d   Addr: %p   Next: %p\n", curr->data, (void*)curr, (void*)curr->next);
        curr = curr->next;
    }
    printf("Over");
    return 0;
    
}

int main()
{
    struct Node* head = NULL;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<len; i++) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = arr[i];
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        }
        else {
            struct Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newnode;
        }
        printf("%d inserted\n", arr[i]);
    }
    printf("--- --- ---\n");
    print_linked_list(head);
    return 0;
}
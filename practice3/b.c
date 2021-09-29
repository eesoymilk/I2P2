#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
} Node;

Node *createList(int);
void freeList(Node*);
int solveJosephus(Node**, int);

// TEMPLATE CODE STARTS HERE

#include<stdio.h>
#include<stdlib.h>

Node* createList(int n)
{
    Node *head, *cursor, *new_node;

    head = (Node*)malloc(sizeof(Node));
    head->number = 1;
    cursor = head;

    for (int i = 2; i <= n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->number = i;
        cursor->next = new_node;
        cursor = cursor->next;
    }
    cursor->next = head;

    return head;
}

void freeList(Node* head)
{
    free(head);
    return;
}

int solveJosephus(Node **head, int step)
{
    Node *cursor = *head, *prev;
    int n, i;

    for (n = 1; cursor->next != *head; n++)
        cursor = cursor->next;
    prev = cursor;
    cursor = cursor->next;

    while (cursor != cursor->next) {
        for (i = (step - 1) % (n--); i; i--) {
            prev = cursor;
            cursor = cursor->next;
        }
        if (cursor == *head)
            *head = cursor->next;
        prev->next = cursor->next;
        free(cursor);
        cursor = prev->next;
    }

    return cursor->number;
}

// TEMPLATE CODE ENDS HERE

int main() {
    Node *head;
    int n, k;

    while (scanf("%d%d", &n, &k) != EOF) {
        head = createList(n);
        printf("%d\n", solveJosephus(&head, k));
        freeList(head);
    }

    return 0;
}
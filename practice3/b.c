#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
} Node;

Node *createList(int);
void freeList(Node*);
int solveJosephus(Node**, int);

//****************************//
// TEMPLATE CODE STARTS HERE! //
//****************************//

#include<stdio.h>
#include<stdlib.h>

Node* createList(int n)
{
    Node *head, *cursor, *new_node;

    // CREATE INDEX 1 FIRST
    head = (Node*)malloc(sizeof(Node));
    head->number = 1;
    cursor = head;

    for (int i = 2; i <= n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->number = i;
        cursor->next = new_node;
        cursor = cursor->next;
    }
    // CIRCULAR LIST
    cursor->next = head;

    return head;
}

void freeList(Node* head)
{
    free(head);
    return;
}

// The input "step" here is "k" from testcases
int solveJosephus(Node **head, int step)
{
    Node *cursor = *head, *prev;
    int n, i;

    // traverse through the list to find the number "n"
    for (n = 1; cursor->next != *head; n++)
        cursor = cursor->next;
    prev = cursor;
    cursor = cursor->next;

    // (cursor != cursor->next) means there is only one node in the list;
    // in that case, we have our chosen index.
    while (cursor != cursor->next) {
        // (step - 1) because we already counted the cursor in
        // "MOD n, or % (n--)" to avoid TLE
        // This for loop finds the index to be deleted
        for (i = (step - 1) % (n--); i; i--) {
            prev = cursor;
            cursor = cursor->next;
        }
        // UPDATE head IF NEEDED
        if (cursor == *head)
            *head = cursor->next;
        // delete the node
        prev->next = cursor->next;
        free(cursor);
        // the next starting node
        cursor = prev->next;
    }

    return cursor->number;
}

//****************************//
//  TEMPLATE CODE ENDS HERE!  //
//****************************//

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
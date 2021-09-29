#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NODE
{
    int val;
    struct _NODE *next;
    struct _NODE *prev;
} Node;

int sqn_size = 1;

void insert(Node** cur_ptr, int val1, int val2)
{
    Node *cursor = *cur_ptr;
    Node *return_node = (*cur_ptr)->next;
    Node* new_node;

    for (int i = 0; i < val2; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->val = val1;
        sqn_size++;

        new_node->prev = cursor;
        cursor->next = new_node;

        cursor = cursor->next;
    }

    cursor->next = return_node;
    return_node->prev = cursor;

    return;
}

void erase(Node** cur_ptr, int val)
{
    Node *start_node = *cur_ptr;
    Node *cursor = start_node->next;
    Node *next;

    for (int i = 0; i < val; i++) {
        next = cursor->next;
        free(cursor);
        sqn_size--;
        cursor = next;
    }

    cursor->prev = start_node;
    start_node->next = cursor;

    return;
}

Node* move(Node** cur_ptr, int val)
{   
    Node *cursor = *cur_ptr;
    int i;

    if (val > 0) {
        i = val % sqn_size;
        while (i--) cursor = cursor->next;
    } else if (val < 0) {
        i = (-val) % sqn_size;
        while (i--) cursor = cursor->prev;
    }

    return cursor;
}

void show(Node** cur_ptr)
{
    Node *cursor = *cur_ptr;

    do {
        printf("%d", cursor->val);
        if (cursor->next != *cur_ptr)
            putchar(' ');
        cursor = cursor->next;
    } while (cursor != *cur_ptr);
    putchar('\n');

    return;
}

int main() {
    Node *cursor;
    char buf[10]; 
    int n, val1, val2;

    cursor = (Node*)malloc(sizeof(Node));
    cursor->next = cursor;
    cursor->prev = cursor;
    scanf("%d %d", &(cursor->val), &n);

    while(n--) {
        scanf("%s", buf);
        if (!strcmp (buf, "insert")) {
            scanf("%d%d", &val1, &val2);
            insert(&cursor, val1, val2);
        } else if (!strcmp(buf, "erase")) {
            scanf("%d", &val1);
            erase(&cursor, val1);
        } else if (!strcmp(buf, "move")) {
            scanf("%d", &val1);
            cursor = move(&cursor, val1);
        } else if(!strcmp(buf, "show")) {
            show(&cursor);
        }
    }

    return 0;
}
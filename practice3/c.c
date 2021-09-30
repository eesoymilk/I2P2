#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NODE
{
    char character;
    struct _NODE *ptr_to_next_node;
    struct _NODE *ptr_to_prev_node;
} Node;

Node *head, *tail;

//****************************//
// TEMPLATE CODE STARTS HERE! //
//****************************//

// There are BUGS in the OJ
// You can fix them by defining those 3 lines
#define prev ptr_to_prev_node
#define ch character
#define next ptr_to_next_node

void insert(Node** cur, char c)
{
    Node *new_node, *cursor = *cur, *nxt;

    new_node = (Node*)malloc(sizeof(Node));
    new_node->character = c;
    new_node->ptr_to_prev_node = cursor;

    nxt = cursor->ptr_to_next_node;
    nxt->ptr_to_prev_node = new_node;
    new_node->ptr_to_next_node = nxt;
    cursor->ptr_to_next_node = new_node;

    // UPDATE tail
    if (cursor == tail)
        tail = new_node;

    return;
}

void deletion(Node** cur)
{
    if (*cur == tail)
        return;

    // for deletion, we have to delete the next one on the *cur
    // cursor is the node we're deleting
    Node *cursor = (*cur)->ptr_to_next_node, *prv = *cur, *nxt;

    nxt = cursor->ptr_to_next_node;
    nxt->ptr_to_prev_node = prv;
    prv->ptr_to_next_node = nxt;

    // UPDATE tail IF NEEDED
    if (cursor == tail)
        tail = prv;
    free(cursor);

    return;
}

void backspace(Node** cur)
{
    if (*cur == head)
        return;

    Node *cursor = *cur, *prv = (*cur)->ptr_to_prev_node, *nxt;

    nxt = cursor->ptr_to_next_node;
    nxt->ptr_to_prev_node = prv;
    prv->ptr_to_next_node = nxt;
    *cur = prv;

    // UPDATE tail IF NEEDED
    if (cursor == tail)
        tail = prv;
    free(cursor);

    return;
}

void go_left(Node** cur, int m)
{
    while (m--)
        *cur = (*cur)->ptr_to_prev_node;
    return;
}

void go_right(Node** cur, int m)
{
    while (m--)
        *cur = (*cur)->ptr_to_next_node;
    return;
}

void go_home(Node **cur)
{
    *cur = head;
    return;
}

void go_end(Node **cur)
{
    *cur = tail;
    return;
}
//****************************//
//  TEMPLATE CODE ENDS HERE!  //
//****************************//

// show function is provided in the append code, no need to turn in.
void show()
{
    Node *now = head->next;

    while (now != head) {
        printf("%c", now->ch);
        if (now != tail)
            putchar(' ');
        now = now->next;
    }
    putchar('\n');

    return;
}

int main(int arg, char *argv[]) {
    char buf[20], input_char;
    int n, input_num;
    Node *cursor;

    // first node, head, is a sentinel
    // it contains nothing
    head = (Node*)malloc(sizeof(Node));
    head->character = '\0';
    head->ptr_to_next_node = head;
    head->ptr_to_prev_node = head;
    tail = head;
    cursor = head;

    scanf("%d",&n);
    while(n--) {
        scanf("%s", buf);
        if (!strcmp (buf, "insert")) {
            scanf(" %c", &input_char);
            insert(&cursor, input_char);
        } else if (!strcmp (buf, "deletion")) {
            deletion(&cursor);
        } else if (!strcmp (buf, "backspace")) {
            backspace(&cursor);
        } else if (!strcmp(buf, "go_left")) {
            scanf("%d", &input_num);
            go_left(&cursor, input_num);
        } else if (!strcmp(buf, "go_right")) {
            scanf("%d", &input_num);
            go_right(&cursor, input_num);
        } else if (!strcmp(buf, "go_home")) {
            go_home(&cursor);
        } else if (!strcmp(buf, "go_end")) {
            go_end(&cursor);
        } else if(!strcmp(buf, "show")) {
            show();
        }
    }
    
    return 0;
}
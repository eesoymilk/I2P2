#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left, *right;
} Node;

int idx;

Node* NewNode(int val)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* BuildTree(int* in, int* post, int l, int r)
{
    int nxt;
    Node *root;

    if (l > r) return NULL;

    for (nxt = l; nxt <= r && in[nxt] != post[idx]; nxt++) ;
    root = NewNode(post[idx--]);

    if (l == r) return root;

    root->right = BuildTree(in, post, nxt + 1, r);
    root->left  = BuildTree(in, post, l, nxt - 1);
    return root;
}

void PrintPreorder(Node* root)
{
    if (root == NULL)   return;

    printf("%d ", root->val);
    PrintPreorder(root->left);
    PrintPreorder(root->right);
    free(root);
}

int main()
{
    int n, t = 0, in[101], post[101];
    Node *root;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &in[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);
        idx = n - 1;
        root = BuildTree(in, post, 0, n - 1);
        printf("testcase%d: ", ++t);
        PrintPreorder(root);
        putchar('\n');
    }

    return 0;
}
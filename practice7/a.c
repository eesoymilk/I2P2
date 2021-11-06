#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

int idx;

Node* BuildTree(int* in, int* post, int start, int end)
{

    if (start > end)
        return NULL;

    int root_idx;
    for (root_idx = start; root_idx <= end; root_idx++)
        if (in[root_idx] == post[idx])  break;

    Node *root = (Node*)malloc(sizeof(Node));
    root->val = post[idx--];
    root->right = BuildTree(in, post, root_idx + 1, end);
    root->left = BuildTree(in, post, start, root_idx - 1);
    return root;
}

void PrintPre(Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    PrintPre(root->left);
    PrintPre(root->right);
    free(root);
}

int main()
{
    int n, testcases = 0;
    int in[101], post[101];

    while (scanf("%d", &n) != EOF)  
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &in[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);

        idx = n - 1;
        printf("testcase%d: ", ++testcases);
        PrintPre(BuildTree(in, post, 0, n - 1));
        putchar('\n');
    }

    return 0;
}
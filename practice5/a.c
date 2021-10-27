#include <stdio.h>
#include <stdlib.h>
#define VAL number
#define RT ptr_to_right_node
#define LT ptr_to_left_node

int n;

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

Node* buildTree(int* In, int* Pre, int instart, int inend)
{
    static int preidx = 0;
    int inidx;

    if (instart > inend)
        return NULL;

    Node *root = (Node*)malloc(sizeof(Node));
    root->VAL = Pre             [preidx++];
    root->RT = NULL;
    root->LT = NULL;

    if (instart == inend)
        return root;

    for (int i = instart; i <= inend; i++) {
        if (In[i] == root->VAL) {
            inidx = i;
            break;
        }
    }

    root->LT = buildTree(In, Pre, instart, inidx - 1);
    root->RT = buildTree(In, Pre, inidx + 1, inend);

    if (preidx == n)
        preidx = 0;

    return root;
}

void showPostorder(Node* root)
{
    if (root == NULL)   return;
    showPostorder(root->LT);
    showPostorder(root->RT);
    printf("%d ", root->VAL);
}

void freeTree(Node *root)
{
    if (root == NULL)   return;

    freeTree(root->LT);
    freeTree(root->RT);
    free(root);
}

int main(void)
{
    int id = 1;
    while(~scanf("%d", &n))
    {
        int inorder[100], preorder[100];
        for(int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
        Node *root = buildTree(inorder, preorder, 0, n - 1);
        printf("testcase%d: ", id++);
        showPostorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}
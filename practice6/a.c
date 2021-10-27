#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
    char c;
    struct _NODE *right;
    struct _NODE *left;
} Node;

Node* New_Node(char ch)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->c = ch;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* Build_Syntax_Tree()
{
    char buf;
    scanf(" %c", &buf);
    Node *new = New_Node(buf);
    if (buf == '+' || buf == '-' || buf == '*' || buf == '/') {
        new->left   = Build_Syntax_Tree();
        new->right  = Build_Syntax_Tree();
    }
    return new;
}

int Cal_Inorder(Node* root, int x, int y, int z)
{
    if (root == NULL)
        return 0;

    int left, ans, right;
    left = Cal_Inorder(root->left, x, y, z);
    putchar(root->c);
    right = Cal_Inorder(root->right, x, y, z);

    switch (root->c) {
        case '+':   return left + right;
        case '-':   return left - right;
        case '*':   return left * right;
        case '/':   return left / right;
        case 'x':   return x;
        case 'y':   return y;
        case 'z':   return z;
        default:    return root->c - '0';
    }
}

int main()
{
    int i, x, y, z;
    Node *root = Build_Syntax_Tree();
    scanf("%d%d%d", &x, &y, &z);
    printf("\n%d\n", Cal_Inorder(root, x, y, z));
    return 0;
}
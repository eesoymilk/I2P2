#include <stdio.h>
#include <stdlib.h>

typedef enum {
    OP_VAR = 0,
    CONST
} token_type;

typedef union {
    int val;
    char ch;
} token_data;

typedef struct {
    token_type type;
    token_data data;
} token;

typedef struct Node Node;
struct Node {
    Node *right, *left;
    token tkn;
};

Node* New_Node(int type, int val, char ch)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->tkn.type = type;
    if (type == OP || type == VAR)
        new_node->tkn.data = ch;
    if (type == CONST)
        new_node->tkn.data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* Build_Syntax_Tree()
{
    int buf_int;
    char buf_ch;
    scanf(" %c", &buf_ch);
    switch (buf_ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case 'x':
        case 'y':
        case 'z':
            break;
        default:
            break;
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
    int x, y, z;
    Node *root = Build_Syntax_Tree();
    scanf("%d%d%d", &x, &y, &z);
    printf("\n%d\n", Cal_Inorder(root, x, y, z));
    return 0;
}
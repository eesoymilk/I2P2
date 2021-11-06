#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    Node *new = (Node*)malloc(sizeof(Node));
    new->tkn.type = type;
    new->left = NULL;
    new->right = NULL;
    if (type == OP_VAR) {
        new->tkn.data.ch = ch;
    }
    if (type == CONST) {
        new->tkn.data.val = val;
    }
    return new;
}

Node* Build_Syntax_Tree()
{
    int val;
    char buf;
    Node *root;

    scanf(" %c", &buf);
    if (buf == '+' || buf == '-' || buf == '*' || buf == '/') {
        root = New_Node(OP_VAR, -1, buf);
        root->left = Build_Syntax_Tree();
        root->right = Build_Syntax_Tree();
    }
    if (buf == 'x' || buf == 'y' || buf == 'z') {
        root = New_Node(OP_VAR, -1, buf);
    }
    if (buf >= '0' && buf <= '9') {
        val = buf - '0';
        while ((buf = getchar()) != ' ' && buf != '\n') {
            if (buf >= '0' && buf <= '9')
                val = val * 10 + buf - '0';
        }
        root = New_Node(CONST, val, '\0');
    }
    return root;
}

int PrintCal_Inorder(Node* root, int x, int y, int z)
{
    if (root == NULL)
        return 0;

    int left, right;
    left = PrintCal_Inorder(root->left, x, y, z);
    if (root->tkn.type == OP_VAR)
        putchar(root->tkn.data.ch);
    if (root->tkn.type == CONST)
        printf("%d", root->tkn.data.val);
    right = PrintCal_Inorder(root->right, x, y, z);

    if (root->tkn.type == OP_VAR) {
        switch (root->tkn.data.ch) {
            case '+':   return left + right;
            case '-':   return left - right;
            case '*':   return left * right;
            case '/':   return left / right;
            case 'x':   return x;
            case 'y':   return y;
            case 'z':   return z;
        }
    }
    return root->tkn.data.val;
    return 0;
}

// void Print_Inorder(Node* root, int x, int y, int z)
// {
//     if (root == NULL)
//         return;

//     Print_Inorder(root->left, x, y, z);
//     if (root->tkn.type == OP_VAR)
//         putchar(root->tkn.data.ch);
//     if (root->tkn.type == CONST)
//         printf("%d", root->tkn.data.val);
//     Print_Inorder(root->right, x, y, z);
// }

int main()
{
    int x, y, z;
    Node *root = Build_Syntax_Tree();
    assert(root != NULL);
    scanf("%d%d%d", &x, &y, &z);
    // Print_Inorder(root, x, y, z);
    printf("\n%d\n", PrintCal_Inorder(root, x, y, z));
    return 0;
}
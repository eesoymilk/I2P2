#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {
	OP_ADD = 0,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	VAR_X,
	VAR_Y,
	VAR_Z,
	INT
} token_e;

typedef union {
	int i;
	char c;
} token_u;

typedef struct {
	token_e type;
	token_u data;
} token_t;

typedef struct Node Node;
struct Node {
	Node *lch, *rch;
	token_t token;
};

char expr[512]; // preorder expression
int idx; // global index to access expression
int x, y, z, N;
Node *st;

inline int is_operator(token_t t)
{
	return t.type == OP_ADD || t.type == OP_SUB || t.type == OP_MUL || t.type == OP_DIV; 
}

// modifies global index to parse expression
token_t next_token()
{
	int value;
	token_t t;
	while (idx < N && expr[idx]==' ')
		idx++;
	switch (expr[idx]) {
		case '+': t.type = OP_ADD; t.data.c = '+'; idx++; break;
		case '-': t.type = OP_SUB; t.data.c = '-'; idx++; break;
		case '*': t.type = OP_MUL; t.data.c = '*'; idx++; break;
		case '/': t.type = OP_DIV; t.data.c = '/'; idx++; break;
		case 'x': t.type = VAR_X; t.data.c = 'x'; idx++; break;
		case 'y': t.type = VAR_Y; t.data.c = 'y'; idx++; break;
		case 'z': t.type = VAR_Z; t.data.c = 'z'; idx++; break;
		default: // read int from string
			t.type = INT;
			value = 0;
			while (idx < N && '0' <= expr[idx] && expr[idx] <= '9') {
				value *= 10;
				value += expr[idx++] - '0';
			}
			t.data.i = value;
			break;
	}
	/*
	printf("next_token(): ");
	if (t.type == INT)
		printf("%d\n", t.data.i);
	else
		printf("%c\n", t.data.c);
		*/
	return t;
}

Node *new_node()
{
	Node *node = malloc(sizeof(Node));
	node->lch = node->rch = NULL;
	node->token = next_token();
	return node;
}

void build_syntax_tree(Node **root)
{
	/* puts("build_syntax_tree"); */
	*root = new_node();
	if (is_operator((*root)->token)) { // not leaf node, build recursively
		build_syntax_tree(&(*root)->lch);
		build_syntax_tree(&(*root)->rch);
	}
}

void print_inorder(Node *root)
{
	if (!root)
		return;
	print_inorder(root->lch);
	if (root->token.type == INT)
		printf("%d", root->token.data.i);
	else // operands and var x, y, z
		printf("%c", root->token.data.c);
	print_inorder(root->rch);
}

int eval(Node *root)
{
	assert(root);
	token_t t = root->token;
	if (is_operator(t))
		switch (t.type) {
			case OP_ADD:
				return eval(root->lch) + eval(root->rch);
			case OP_SUB:
				return eval(root->lch) - eval(root->rch);
			case OP_MUL:
				return eval(root->lch) * eval(root->rch);
			case OP_DIV:
				return eval(root->lch) / eval(root->rch);
			default:
				assert(0);
		}
	else // return a value directly
		switch (t.type) {
			case VAR_X:
				return x;
			case VAR_Y:
				return y;
			case VAR_Z:
				return z;
			case INT:
				return t.data.i;
			default:
				assert(0);
		}
}

int main(int argc, char *argv[])
{
	char c;
	idx = 0;
	while ((c = getchar()) != '\n')
		expr[idx++] = c;
	expr[idx] = '\0';
	N = strlen(expr);
	scanf(" %d %d %d", &x, &y, &z);
	//
	idx = 0;
	build_syntax_tree(&st);
	print_inorder(st); putchar('\n');
	printf("%d\n", eval(st));
	return 0;
}

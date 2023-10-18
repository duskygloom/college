#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	// types: i, f, d, c
	char type;
	void *content;
} Node;

Node *init_node(char type);
void delete_node(Node *node);
void print_node(Node *node);
void get_node(Node *node);

int main()
{
	printf("Integer: ");
	Node *nodei = init_node('i');
	get_node(nodei);
	printf("Float: ");
	Node *nodef = init_node('f');
	get_node(nodef);
	printf("Character: ");
	Node *nodec = init_node('c');
	get_node(nodec);
	printf("String: ");
	Node *nodes = init_node('s');
	get_node(nodes);

	fputs("Integer node: ", stdout);
	print_node(nodei);
	putchar('\n');
	fputs("Float node: ", stdout);
	print_node(nodef);
	putchar('\n');
	fputs("Character node: ", stdout);
	print_node(nodec);
	putchar('\n');
	fputs("String node: ", stdout);
	print_node(nodes);
	putchar('\n');
	return 0;
}

Node *init_node(char type)
{
	// node.type = 0 in case of incompatible type
	Node *node = malloc(sizeof(Node));
	switch (type) {
		case 'i':
			node->content = malloc(sizeof(int));
			node->type = 'i';
			break;
		case 'f':
			node->content = malloc(sizeof(float));
			node->type = 'f';
			break;
		case 'c':
			node->content = malloc(sizeof(char));
			node->type = 'c';
			break;
		default:
			printf("Incompatible node type.\n");
			node->type = '\0';
			break;
	}
	return node;
}

void delete_node(Node *node)
{
	switch (node->type) {
		case 'i':
			free((int*)(node->content));
			free(node);
			break;
		case 'f':
			free((float*)(node->content));
			free(node);
			break;
		case 'c':
			free((char*)(node->content));
			free(node);
			break;
		default:
			free(node);
			break;
	}
}

void print_node(Node *node)
{
	switch (node->type) {
		case 'i':
			printf("%d", *((int*)node->content));
			break;
		case 'f':
			printf("%f", *((float*)node->content));
			break;
		case 'c':
			printf("%c", *((char*)node->content));
			break;
		case 's':
			printf("%s", *((char*)node->content));
			break;
		default:
			printf("Incompatible node type.\n");
			break;
	}
}

void get_node(Node *node)
{
	switch (node->type) {
		case 'i':
			scanf("%d", node->content);
			getchar();
			break;
		case 'f':
			scanf("%f", node->content);
			getchar();
			break;
		case 'c':
			scanf("%c", node->content);
			break;
		case 's':
			scanf("%s", node->content);
			break;
		default:
			printf("Incompatible node type.\n");
			break;
	}
}

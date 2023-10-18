// linked list operations

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
};
typedef struct Node Node;

int get_response();
Node *init_list();
void destroy_list(Node *head);
void print_list(Node *head);
void fill_list(Node *head);
void append_to_tail(Node *head, int value);
void concatenate_lists(Node *head_to, Node *head_from);
void reverse_list(Node *head);
void insert_node(Node *head, int index, Node *node_to_insert);
void copy_list(Node *head_from, Node *head_to);
int count_nodes(Node *head);
void delete_even_nodes(Node *head);
void interchange_nodes(Node *head, int index_smaller, int index_bigger);

int main()
{
	Node *node, *main_list = init_list();
	int element, index;
	while (1) {
		switch (get_response()) {
			case 0:
				return 0;
			case 1:
				printf("Element: ");
				scanf("%d", &element);
				append_to_tail(main_list, element);
				printf("List after appending:");
				print_list(main_list);
				putchar('\n');
				break;
			case 2:
				node = init_list();
				printf("Elements for new list: ");
				fill_list(node);
				concatenate_lists(main_list, node);
				printf("List after concatenating:");
				print_list(main_list);
				putchar('\n');
				destroy_list(node);
				break;
			case 3:
				reverse_list(main_list);
				printf("List after reversing:");
				print_list(main_list);
				putchar('\n');
				break;
			case 4:
				printf("n: ");
				scanf("%d", &index);
				node = malloc(sizeof(Node));
				printf("Node value: ");
				scanf("%d", &(node->value));
				insert_node(main_list, index, node);
				printf("List after insertion:");
				print_list(main_list);
				putchar('\n');
				break;
			case 5:
				node = init_list();
				copy_list(main_list, node);
				printf("Copy of list:");
				print_list(node);
				putchar('\n');
				destroy_list(node);
				break;
			case 6:
				printf("Number of nodes: %d\n", count_nodes(main_list));
				break;
			case 7:
				delete_even_nodes(main_list);
				printf("List after deleting all even nodes:");
				print_list(main_list);
				putchar('\n');
				break;
			case 8:
				// storing n and k in index and element resp
				printf("n k: ");
				scanf("%d %d", &index, &element);
				interchange_nodes(main_list, index, element);
				printf("List after interchanging:");
				print_list(main_list);
				putchar('\n');
				break;
		}
		putchar('\n');
	}
	destroy_list(main_list);
	return 0;
}

int get_response()
{
	printf("1. Append an element to the tail of the list.\n");
	printf("2. Concatenate two lists.\n");
	printf("3. Reverse a list.\n");
	printf("4. Insert a node as the nth node of the list.\n");
	printf("5. Copy a list into another.\n");
	printf("6. Count the number of nodes in a list.\n");
	printf("7. Delete all even nodes in the list.\n");
	printf("8. Interchange the nth and kth nodes of a list.\n");
	printf("0. Quit.\n");
	int response;
	printf("Response: ");
	scanf("%d", &response);
	getchar();
	return response;
}

Node *init_list()
{
	// the value of head contains length of list
	Node *nodehead = malloc(sizeof(Node));
	nodehead->value = 0;
	nodehead->next = NULL;
	return nodehead;
}

void destroy_list(Node *head)
{
	Node *current, *next;
	for (current=head; current; current=next) {
		next = current->next;
		free(current);
	}
}

int count_nodes(Node *head)
{
	int length = 0;
	for (head=head->next; head; head=head->next)
		++length;
	return length;
}

void print_list(Node *head)
{
	// prints only the elements, no staring or endline
	for (head=head->next; head; head=head->next)
		printf(" %d", head->value);
}

void fill_list(Node *head)
{
	Node *current, *newnode;
	// going to the end of the list
	for (current=head; current->next; current=current->next);
	// getting elements and pushing at the end
	while (1) {
		newnode = malloc(sizeof(Node));
		newnode->next = NULL;
		scanf("%d", &(newnode->value));
		current->next = newnode;
		current = newnode;
		++(head->value);
		if (getchar() == '\n') break;
	}
}

void append_to_tail(Node *head, int value)
{
	Node *current;
	// moving to the last node
	for (current=head; current->next; current=current->next);
	// creating new node
	Node *newnode = malloc(sizeof(Node));
	newnode->value = value;
	newnode->next = NULL;
	current->next = newnode;
	++(head->value);
}

void concatenate_lists(Node *head_to, Node *head_from)
{
	Node *current, *node;
	// moving to last node of list 1
	for (current=head_to; current->next; current=current->next);
	// creating new nodes for each value in list 2
	for (head_from=head_from->next; head_from; head_from=head_from->next) {
		node = malloc(sizeof(Node));
		node->value = head_from->value;
		node->next = NULL;
		current->next = node;
		current = node;
		++(head_to->value);
	}
}

void reverse_list(Node *head)
{
	Node *current, *prev = NULL, *next;
	for (current=head->next; current; current=next) {
		next = current->next;
		// setting the previous node as next
		if (prev) current->next = prev;
		// setting next of first element to NULL
		else current->next = NULL;
		// setting the current node as previous
		prev = current;
	}
	// setting last node as head->next
	head->next = prev;
}

void insert_node(Node *head, int index, Node *node_to_insert)
{
	Node *current;
	for (current=head; index>0 && current->next; --index)
		current = current->next;
	node_to_insert->next = current->next;
	current->next = node_to_insert;
	++(head->value);
}

void copy_list(Node *head_from, Node *head_to)
{
	// copies the elements from head_from and 
	// pastes them to the end of head_to
	Node *current, *newnode;
	for (current=head_to; current->next; current=current->next);
	for (head_from=head_from->next; head_from; 
			head_from=head_from->next) {
		newnode = malloc(sizeof(Node));
		newnode->value = head_from->value;
		newnode->next = NULL;
		current->next = newnode;
		current = newnode;
		++(head_to->value);
	}
}

void delete_even_nodes(Node *head)
{
	Node *current, *evennode;
	for (current=head->next; current && current->next; current=current->next) {
		evennode = current->next;
		current->next = evennode->next;
		free(evennode);
		--(head->value);
	}
}

void interchange_nodes(Node *head, int index_smaller, int index_bigger)
{
	int temp, index_counter = 0;
	if (index_smaller > index_bigger) {
		temp = index_smaller;
		index_smaller = index_bigger;
		index_bigger = temp;
	}
	Node *current, *node_smaller = NULL, *node_bigger = NULL;
	for (current=head->next; current; current=current->next) {
		if (index_counter == index_smaller)
			node_smaller = current;
		if (index_counter == index_bigger) {
			node_bigger = current;
			break;
		}
		++index_counter;
	}
	if (node_smaller && node_bigger) {
		temp = node_smaller->value;
		node_smaller->value = node_bigger->value;
		node_bigger->value = temp;
	}
}


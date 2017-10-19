#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie *trie_create_node () 
{
	struct trie *node;
	node = malloc(sizeof(node));
	if (node == NULL)
		return NULL;
	//node->parent = NULL;
	node->value = NULL;
	node->end = NULL;
	return node;
}

struct trie *trie_insert (struct trie *root, char *value)
{
		struct trie *node = root;

		if (node == NULL) {
			node = trie_create_node();
			if (node == NULL) 
				return NULL;
		}

		for (int i = 0; i < strlen(value); i++) {
			struct set_siblin *node_value_parent = NULL, *n_value = NULL;

			if (node->value != NULL) {
				n_value = node->value;
			}

			while (n_value != NULL && n_value->key != value[i]) {
				node_value_parent = n_value;
				n_value = node->value->next;
			}

			if (n_value == NULL) {
				n_value = malloc(sizeof(n_value));
				n_value->key = value[i];

				if (node_value_parent != NULL) {
					node_value_parent->next = n_value;
					n_value->parent = node_value_parent;
				}

				n_value->node_siblin = trie_create_node();
				if (n_value->node_siblin == NULL)
					return NULL;

				n_value->node_siblin->key = n_value->key;
				//n_value->node_siblin->parent = node;
			}
			if (root == NULL)
				root = node;

			if (node->value == NULL)
				node->value = n_value;
			
			node = n_value->node_siblin;
		}

		node->end = malloc(sizeof(node->end));
		node->end->parent = node;
		node->end->value_string = 10;

		if (root == NULL) {
			root = node;
			//root->parent = NULL;
		}

		return root;
}

/*
struct trie *trie_delete()
{
	
	return NULL;
}

struct trie *trie_lookup ()
{

	return NULL;
}*/

void trie_print (struct trie *root)
{
	struct trie *node = root;
	struct set_siblin *n_value = NULL;

	if (node->value != NULL) {
		n_value = node->value;
	}

	printf("Node: %p\n", node);
	printf("Node key: %c\n", node->key);
	if (node->end != NULL) {
		printf("End: %d\n", node->end->value_string);
	} else {
		printf("End: not\n");
	}
	printf("Set value: \n");
	printf("Value\t\tNext\t\tSiblin\t\tKey\tEnd\n");
	while (n_value != NULL) {
		printf("%p\t", n_value);
		printf("%p\t", n_value->next);
		if (n_value->next == NULL)
			printf("\t");
		printf("%p\t", n_value->node_siblin);
		printf("%c\t", n_value->node_siblin->key);
		if (n_value->node_siblin->end != NULL) {
			printf("%d\n", n_value->node_siblin->end->value_string);
		} else {
			printf("Not\n");
		}
		n_value = n_value->next;
	}

	if (node->value != NULL) {
		n_value = node->value;
	}

	while (n_value != NULL) {
		printf("\n");
		trie_print(n_value->node_siblin);
		n_value = n_value->next;
	}
}
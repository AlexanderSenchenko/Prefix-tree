#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

trie *trie_create_node () 
{
	trie *node;
	node = malloc(sizeof(node));
	if (node == NULL)
		return NULL;
	node->value = NULL;
	node->end = NULL;
	return node;
}

trie *trie_insert (trie *root, char *value, int key)
{
	struct trie *node = root;

	if (node == NULL) {
		node = trie_create_node();
		if (node == NULL) 
			return NULL;
	}

	for (int i = 0; i < strlen(value); i++) {
		set_siblin *node_value_parent = NULL, *n_value = NULL;

		if (node->value != NULL)
			n_value = node->value;

		while (n_value != NULL && n_value->key != value[i]) {
			node_value_parent = n_value;
			n_value = n_value->next;
		}

		if (n_value == NULL) {
			n_value = malloc(sizeof(n_value));
			n_value->key = value[i];

			if (node_value_parent != NULL) {
				node_value_parent->next = n_value;
			}

			n_value->node_siblin = trie_create_node();
			if (n_value->node_siblin == NULL)
				return NULL;

			n_value->node_siblin->key = n_value->key;
		}
		if (root == NULL)
			root = node;

		if (node->value == NULL)
			node->value = n_value;
		
		node = n_value->node_siblin;
	}

	node->end = malloc(sizeof(node->end));
	node->end->parent = node;
	node->end->value_string = key;

	if (root == NULL)
		root = node;

	return root;
}

/*
trie *trie_delete()
{
	
	return NULL;
}*/

int trie_lookup (trie *root, char *key)
{
	trie *node = root;

	for (int i = 0; i < strlen(key); i++) {
		set_siblin *n_value = NULL;

		if (node->value != NULL)
			n_value = node->value;

		while (n_value != NULL && n_value->key != key[i]) {
			n_value = n_value->next;
		}

		if (n_value == NULL) {
			return -1;
		} else {
			node = n_value->node_siblin;
		}
		if (i + 1 == strlen(key) && node->end != NULL)
			return node->end->value_string;
	}

	return -1;
}

void trie_print (trie *root)
{
	trie *node = root;
	set_siblin *n_value = NULL;

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

	if (n_value != NULL) {
		printf("Set value: \n");
		printf("Value\t\tNext\t\tSiblin\t\tKey\tEnd\n");
	}
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
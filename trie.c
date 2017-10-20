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

trie *trie_insert (trie *root, char *key, int value)
{
	struct trie *node = root;

	if (node == NULL) {
		node = trie_create_node();
		if (node == NULL) 
			return NULL;
	}

	for (int i = 0; i < strlen(key); i++) {
		set_sibling *node_value_parent = NULL, *n_value = NULL;

		if (node->value != NULL)
			n_value = node->value;

		while (n_value != NULL && n_value->node_sibling->key != key[i]) {
			node_value_parent = n_value;
			n_value = n_value->next;
		}

		if (n_value == NULL) {
			n_value = malloc(sizeof(n_value));
			n_value->parent = node_value_parent;

			if (node_value_parent != NULL) {
				node_value_parent->next = n_value;
			}

			n_value->node_sibling = trie_create_node();
			if (n_value->node_sibling == NULL)
				return NULL;

			n_value->node_sibling->key = key[i];
		}
		if (root == NULL)
			root = node;

		if (node->value == NULL)
			node->value = n_value;
		
		node = n_value->node_sibling;
	}

	node->end = malloc(sizeof(node->end));
	node->end->parent = node;
	node->end->value_string = value;

	if (root == NULL)
		root = node;

	return root;
}

trie *trie_delete(trie *root, char* key)
{
	trie *node = root, *node_del = NULL, *node_del_next = NULL;
	set_sibling *node_in_set = NULL;

	if (trie_lookup(root, key) == -1) {
		printf("Error not element\n");
		return root;
	}
	
	for (int i = 0; i < strlen(key); i++) {
		set_sibling *n_value = NULL;

		if (node->value != NULL)
			n_value = node->value;

		while (n_value != NULL && n_value->node_sibling->key != key[i]) {
			n_value = n_value->next;
		}

		if (node->value->next == NULL && node->end == NULL && node_del == NULL) {
			node_del = node;
		} else {
			node_del = NULL;
			node_in_set = n_value;
		}

		if (n_value != NULL)
			node = n_value->node_sibling;
	}

	node_in_set->node_sibling = NULL;
	if (node_in_set->parent != NULL)
		node_in_set->parent->next = node_in_set->next;
	if (node_in_set->next != NULL)
	node_in_set->next->parent = node_in_set->parent;


	while (node_del_next != NULL) {
		if (node->value != NULL)
			node_del_next = node->value->node_sibling;

		free(node_del->value);
		if (node_del->end != NULL)
			free(node_del->end);
		free(node_del);
	}

	return root;
}

int trie_lookup (trie *root, char *key)
{
	trie *node = root;

	for (int i = 0; i < strlen(key); i++) {
		set_sibling *n_value = NULL;

		if (node->value != NULL)
			n_value = node->value;

		while (n_value != NULL && n_value->node_sibling->key != key[i]) {
			n_value = n_value->next;
		}

		if (n_value == NULL) {
			return -1;
		} else {
			node = n_value->node_sibling;
		}
		if (i + 1 == strlen(key) && node->end != NULL)
			return node->end->value_string;
	}

	return -1;
}

void trie_print (trie *root)
{
	trie *node = root;
	set_sibling *n_value = NULL;

	if (node->value != NULL) {
		n_value = node->value;
	}

	printf("Node: %p\n", node);
	if (node != NULL)
		printf("Node key: %c\n", node->key);
	if (node->end != NULL) {
		printf("End: %d\n", node->end->value_string);
	} else {
		printf("End: not\n");
	}

	if (n_value != NULL) {
		printf("Set sibling: \n");
		printf("Value\t\tNext\t\tParent\t\tSibling\t\tKey\tEnd\n");
	}
	while (n_value != NULL) {
		printf("%p\t", n_value);
		printf("%p\t", n_value->next);
		if (n_value->next == NULL)
			printf("\t");
		printf("%p\t", n_value->parent);
		if (n_value->parent == NULL)
			printf("\t");
		printf("%p\t", n_value->node_sibling);
		printf("%c\t", n_value->node_sibling->key);
		if (n_value->node_sibling->end != NULL) {
			printf("%d\n", n_value->node_sibling->end->value_string);
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
		trie_print(n_value->node_sibling);
		n_value = n_value->next;
	}
}
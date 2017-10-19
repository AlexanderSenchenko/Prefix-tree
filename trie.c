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
	node->value = NULL;
	/*node->value = malloc(sizeof(node->value));
	if (node->value == NULL)
		return NULL;
	node->value->next = NULL;
	//node->value->parent = NULL;*/
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
					//n_value->parent = node_value_parent;
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
		node->end->value_string = 10;

		if (root == NULL)
			root = node;

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
	struct set_siblin *n_value;
	//while () {
		printf("%p\t", node);
		printf("%c\t", node->key);
		printf("%p\t", node->value);
		if (node->value != NULL)
			n_value = node->value;
		while (n_value != NULL) {
			trie_print(n_value->node_siblin);
			n_value = n_value->next;
		}






	//}
}

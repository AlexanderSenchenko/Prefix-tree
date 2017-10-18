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
		struct set_siblin *node_value_parent = NULL;

		if (node == NULL) {
			node = trie_create_node();
			if (node == NULL) 
				return NULL;
			if (root == NULL)
				root = node;
		}

		for (int i = 0; i < strlen(value); i++) {
			while (node->value != NULL && node->value->key != value[i]) {
				node_value_parent = node->value;
				node->value = node->value->next;
			}

			if (node->value == NULL) {
				node->value = malloc(sizeof(node->value));
				node->value->key = value[i];

				if (node_value_parent != NULL) {
					node_value_parent->next = node->value;
					node->value->parent = node_value_parent;
					node_value_parent = NULL;
				}

				node->value->node_siblin = trie_create_node();
				if (node->value->node_siblin == NULL)
					return NULL;

				node->value->node_siblin->key = node->value->key;
			}
			
			node = node->value->node_siblin;
		}

		node->end = malloc(sizeof(node->end));
		node->end->parent = node;
		node->end->value_string = 10;

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

}
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main()
{
	struct trie *root = NULL;

	root = trie_insert(root, "test");
	root = trie_insert(root, "time");
	if (root != NULL) {
		while (root!= NULL) {
			printf("%c\n", root->key);
			if (root->value != NULL) {
				//printf("%c\n", root->value->key);
				//printf("%c\n", root->value->next->key);
				root = root->value->node_siblin;
			} else {
				printf("%d\n", root->end->value_string);
				root = NULL;
			}
		}
	} else {
		printf("Error\n");
	}

	return 0;
}
#include <stdio.h>
#include "trie.h"

int main(int argc, char *argv[])
{
	trie *root = NULL;

	root = trie_insert(root, "ab", 10);
	root = trie_insert(root, "cd", 37);
	root = trie_insert(root, "ef", 4);
	root = trie_insert(root, "agf", 83);
	root = trie_insert(root, "ecm", 94);
	root = trie_insert(root, "cdrt", 94);
	
	trie_print(root);

	printf("\nLookup\nString value: %d\n", trie_lookup(root, argv[1]));

	printf("\nDelete\n");
	root = trie_delete(root, argv[1]);

	trie_print(root);

	return 0;
}

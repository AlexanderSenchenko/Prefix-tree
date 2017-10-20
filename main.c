#include <stdio.h>
#include "trie.h"

int main()
{
	trie *root = NULL;

	root = trie_insert(root, "ab", 10);
	root = trie_insert(root, "cd", 37);
	root = trie_insert(root, "ef", 4);
	root = trie_insert(root, "ag", 83);
	root = trie_insert(root, "ec", 94);
	
	trie_print(root);

	return 0;
}

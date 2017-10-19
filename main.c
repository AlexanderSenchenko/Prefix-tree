#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main()
{
	struct trie *root = NULL;

	root = trie_insert(root, "teso");
	root = trie_insert(root, "time");
	root = trie_insert(root, "tine");
	root = trie_insert(root, "rect");
	root = trie_insert(root, "rectum");
	//root = trie_insert(root, "plumbum");
	
	trie_print(root);

	return 0;
}

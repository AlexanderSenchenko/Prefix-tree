#ifndef TRIE_H
#define TRIE_H

typedef struct trie
{
	struct set_sibling *value;
	struct end *end;
	char key;
} trie;

typedef struct set_sibling
{
	struct set_sibling *next;
	struct set_sibling *parent;
	struct trie *node_sibling;
} set_sibling;

typedef struct end
{
	struct trie *parent;
	int value_string;
} end;

trie *trie_create ();
int trie_lookup (trie*, char*);
trie *trie_insert (trie*, char*, int);
trie *trie_delete(trie*, char*);
void trie_print(trie*);

#endif

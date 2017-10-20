#ifndef TRIE_H
#define TRIE_H

typedef struct trie
{
	char key;
	struct set_siblin *value;
	struct end_string *end;
} trie;

typedef struct set_siblin
{
	char key;
	struct trie *node_siblin;
	struct set_siblin *next;
} set_siblin;

typedef struct end_string
{
	int value_string;
	struct trie *parent;
} end_stirng;

trie *trie_create ();
int trie_lookup (trie*, char*);
trie *trie_insert (trie*, char*, int);
//trie *trie_delete();
void trie_print(trie*);

#endif

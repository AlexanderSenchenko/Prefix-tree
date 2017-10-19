#ifndef TRIE_H
#define TRIE_H

typedef struct trie
{
	char key;
	//struct trie *parent;
	struct set_siblin *value;
	struct end_string *end;
} trie;

typedef struct set_siblin
{
	char key;
	struct trie *node_siblin;
	struct set_siblin *next;
	//struct set_siblin *parent;
} set_siblin;

typedef struct end_string
{
	int value_string;
	struct trie *parent;
} end_stirng;

struct trie *trie_create ();
//char *trie_lookup ();
struct trie *trie_insert (struct trie* , char*);
//struct trie *trie_delete();
//void trie_print_tree();

#endif

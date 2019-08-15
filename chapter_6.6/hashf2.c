#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gen2.h"

void printerr(int errcode);

extern struct nlist* hashtab[];

/* hash: form hash value for string s */
unsigned hash(char* s)
{
	unsigned int hashval;
	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist* lookup(char* s)
{
	struct nlist* np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->pnext) {
		if (strcmp(s, np->pname) == 0) {
			return np;			/* found */
		}
	}
	return NULL;				/* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist* install(char* name, char* defn)
{
	struct nlist* np;
	unsigned int hashval;
	if ((np = lookup(name)) == NULL) {				/* not found */
		np = (struct nlist*) malloc(sizeof(*np));
		if (np == NULL || (np->pname = strdup(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);
		np->pnext = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else {											/* already there */
		free((void*)np->pdefn);						/* free previous defn */
	}
	if ((np->pdefn = strdup(defn)) == NULL) {
		return NULL;
	}
	return np;
}

/* undef: remove (name, definition) from hashtab */
void undef(char* name)
{
	struct nlist* np1, * np2, ** pnp;
	unsigned int hashval;
	if ((np1 = lookup(name)) != NULL) {
		pnp = NULL;
		hashval = hash(name);
		if (hashtab[hashval] == np1) {
			pnp = &hashtab[hashval];
		}
		else {
			for (np2 = hashtab[hashval]; np2->pnext != NULL; np2 = np2->pnext) {
				if (np2->pnext == np1) {
					pnp = &np2->pnext;
					break;
				}
			}
		}
		if (pnp == NULL) {
			printerr(ERRNULLPNP);
		}
		else {
			*pnp = np1->pnext;
			free((void*)np1->pname);
			free((void*)np1->pdefn);
			free((void*)np1);
		}
	}
}
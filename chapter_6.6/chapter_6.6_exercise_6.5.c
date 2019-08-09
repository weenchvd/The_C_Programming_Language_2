/** Chapter 6.6 | Exercise 6.5 */

#include <stdio.h>
#include "gen.h"

struct nlist* hashtab[HASHSIZE];			/* pointer table */

int main()
{
	int ngetline(char* ps, int lim, char n);
	struct nlist* install(char* name, char* defn);
	void undef(char* name);
	void printhashtab(struct nlist** hashtab, unsigned int size);
	
	int n;
	char name[MAXLENGTH];
	char defn[MAXLENGTH];
	while (1) {
		printf("Input the name to install: ");
		if ((n = ngetline(name, MAXLENGTH, 11)) <= 0) {
			printf("\n\n");
			break;
		}
		printf("Input the definition to install: ");
		if ((n = ngetline(defn, MAXLENGTH, 3)) <= 0) {
			printf("\n\n");
			break;
		}
		install(name, defn);
		printhashtab(hashtab, HASHSIZE);
	}
	while (1) {
		printf("Input the name to undef: ");
		if ((n = ngetline(name, MAXLENGTH, 11)) <= 0) {
			printf("\n\n");
			break;
		}
		undef(name);
		printhashtab(hashtab, HASHSIZE);
	}
}

void printhashtab(struct nlist** hashtab, unsigned int size)
{
	struct nlist* np;
	int i, n;
	for (i = 0; size-- > 0; i++) {
		for (np = hashtab[i], n = 1; np != NULL; np = np->pnext, n++) {
			printf("\tTable[%2d] Entry #%4d\tName: %s\n\t\t\t\tDefinition: %s\n", i, n, np->pname, np->pdefn);
		}
	}
}
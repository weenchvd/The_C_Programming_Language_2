#include <stdlib.h>
#include <string.h>
#include "gen2.h"

/* talloc: make a tnode */
struct tnode* talloc(void)
{
	return (struct tnode*) malloc(sizeof(struct tnode));
}

struct numstr* nalloc(void)
{
	return (struct numstr*) malloc(sizeof(struct numstr));
}

char* wstrdup(char* s)
{
	char* p;
	p = (char*)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}

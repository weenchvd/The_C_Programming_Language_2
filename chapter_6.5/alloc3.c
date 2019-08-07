#include <stdlib.h>
#include <string.h>
#include "gen3.h"

/* talloc: make a tnode */
struct tnode* talloc(void)
{
	return (struct tnode*) malloc(sizeof(struct tnode));
}

struct llword* walloc(void)
{
	return (struct llword*) malloc(sizeof(struct llword));
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

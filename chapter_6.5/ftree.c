#include <string.h>
#include "gen.h"


struct tnode* naddtree(struct tnode* p, char* w, int n, int* found)
{
	struct tnode* talloc(void);
	char* wstrdup(char* string);
	int nstrcmp(struct tnode* p, char* s, int n, int* found);
	int cond;
	if (p == NULL) {
		p = talloc();
		p->word = wstrdup(w);
		p->ismatch = *found;
		p->left = p->right = NULL;
	}
	else if ((cond = nstrcmp(p, w, n, found)) < 0) {
		p->left = naddtree(p->left, w, n, found);
	}
	else if (cond > 0) {
		p->right = naddtree(p->right, w, n, found);
	}
	return p;
}

int nstrcmp(struct tnode* p, char* s, int n, int* found)
{
	int i;
	char* t = p->word;
	for (i = 0; *s == *t; i++, s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}
	if (i >= n) {
		*found = TRUE;
		p->ismatch = TRUE;
	}
	return *s - *t;
}
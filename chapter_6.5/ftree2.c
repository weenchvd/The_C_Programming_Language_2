#include <string.h>
#include "gen2.h"


struct tnode* addtree(struct tnode* p, char* w, int numstr)
{
	struct tnode* talloc(void);
	struct numstr* nalloc(void);
	char* wstrdup(char* string);

	int cond;
	struct numstr* ptemp;
	if (p == NULL) {
		p = talloc();
		p->pword = wstrdup(w);
		p->pnumstr = nalloc();
		p->pnumstr->pnextnumstr = NULL;
		p->pnumstr->number = numstr;
		p->pleft = p->pright = NULL;
	}
	else if ((cond = strcmp(w, p->pword)) == 0) {
		ptemp = p->pnumstr;
		while (ptemp->pnextnumstr != NULL) {
			ptemp = ptemp->pnextnumstr;
		}
		if (ptemp->number != numstr) {
			ptemp->pnextnumstr = nalloc();
			ptemp = ptemp->pnextnumstr;
			ptemp->pnextnumstr = NULL;
			ptemp->number = numstr;
		}
	}
	else if (cond < 0) {
		p->pleft = addtree(p->pleft, w, numstr);
	}
	else {
		p->pright = addtree(p->pright, w, numstr);
	}
	return p;
}

#include <string.h>
#include "gen3.h"

struct tnode* addtree(struct tnode* p, char* w)
{
	struct tnode* talloc(void);
	char* wstrdup(char* string);

	int cond;
	if (p == NULL) {
		p = talloc();
		p->pword = wstrdup(w);
		p->count = 1;
		p->pnextword = NULL;
		p->pleft = p->pright = NULL;
	}
	else if ((cond = strcmp(w, p->pword)) == 0) {
		p->count++;
	}
	else if (cond < 0) {
		p->pleft = addtree(p->pleft, w);
	}
	else {
		p->pright = addtree(p->pright, w);
	}
	return p;
}

struct tnode* addtreesorted(struct tnode* proot, struct tnode* pnode)
{
	struct tnode* talloc(void);
	struct llword* walloc(void);

	struct llword* pllword;
	int cond;
	if (proot == NULL) {
		proot = talloc();
		proot->pword = pnode->pword;
		proot->count = pnode->count;
		proot->pnextword = NULL;
		proot->pleft = proot->pright = NULL;
	}
	else if ((cond = (pnode->count - proot->count)) == 0) {
		if (proot->pnextword == NULL) {
			proot->pnextword = walloc();
			proot->pnextword->pnextword = NULL;
			proot->pnextword->pword = pnode->pword;
		}
		else {
			for (pllword = proot->pnextword; pllword->pnextword != NULL; pllword = pllword->pnextword);
			pllword->pnextword = walloc();
			pllword->pnextword->pnextword = NULL;
			pllword->pnextword->pword = pnode->pword;
		}
	}
	else if (cond < 0) {
		proot->pleft = addtreesorted(proot->pleft, pnode);
	}
	else {
		proot->pright = addtreesorted(proot->pright, pnode);
	}
	return proot;
}

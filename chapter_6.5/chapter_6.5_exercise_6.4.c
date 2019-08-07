/** Chapter 6.5 | Exercise 6.4 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "gen3.h"

struct tnode* addtree(struct tnode* p, char* w);
struct tnode* addtreesorted(struct tnode* proot, struct tnode* pnode);
void treesort(struct tnode* p, struct tnode** pnewtree);
void treeprint(struct tnode* p);
void freemem(struct tnode* p, int cond);
int getword(char* word, int lim);

int main()
{
	struct tnode* root;
	struct tnode* sroot;
	char word[MAXWORD], lcword[MAXWORD];
	int c, i;
	root = sroot = NULL;
	while ((c = getword(word, MAXWORD)) != EOF) {
		if (isalpha(c)) {
			for (i = 0; (lcword[i] = tolower(word[i])) != '\0'; i++);
			root = addtree(root, lcword);
		}
	}
	treesort(root, &sroot);
	freemem(root, DONTFREEWORD);
	printf("\n\n");
	treeprint(sroot);
	freemem(sroot, FREEWORD);
	return 0;
}

void treeprint(struct tnode* p)
{
	if (p != NULL) {
		struct llword* ptemp;
		treeprint(p->pright);
		printf("%9d  %s\n", p->count, p->pword);
		if (p->pnextword != NULL) {
			ptemp = p->pnextword;
			printf("%9d  %s\n", p->count, ptemp->pword);
			while (ptemp->pnextword != NULL) {
				ptemp = ptemp->pnextword;
				printf("%9d  %s\n", p->count, ptemp->pword);
			}
		}
		treeprint(p->pleft);
	}
}

void treesort(struct tnode* p, struct tnode** pnewtree)
{
	if (p != NULL) {
		treesort(p->pleft, pnewtree);
		*pnewtree = addtreesorted(*pnewtree, p);
		treesort(p->pright, pnewtree);
	}
}

void freemem(struct tnode* p, int cond)
{
	if (p != NULL) {
		struct llword* p1, * p2;
		freemem(p->pleft, cond);
		freemem(p->pright, cond);
		if (cond) {
			while (p->pnextword != NULL) {
				for (p1 = p->pnextword, p2 = NULL; p1->pnextword != NULL; p1 = p1->pnextword) {
					p2 = p1;
				}
				free(p1->pword);
				free(p1);
				if (p2 != NULL) {
					p2->pnextword = NULL;
				}
				else {
					p->pnextword = NULL;
				}
			}
			free(p->pword);
		}
		free(p);
	}
}
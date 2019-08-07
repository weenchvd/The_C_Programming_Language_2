/** Chapter 6.5 | Exercise 6.3 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "gen2.h"

struct tnode* addtree(struct tnode* p, char* w, int numstr);
void treeprint(struct tnode* p);
int getword(char* word, int lim);
int binsearch(char* word, struct key tab[], int n);

struct key {
	char* word;
} keytab[] = {
	"a", "about", "and", "as", "at", "but", "by", "down", "for", "from", "if", "in", "into",
	"nor", "of", "on", "onto", "or", "since", "so", "the", "till", "until", "up", "with", "yet"
};

int numstr;

int main()
{
	struct tnode* root;
	char word[MAXWORD], lcword[MAXWORD];
	int c, i;
	root = NULL;
	numstr = 1;
	while ((c = getword(word, MAXWORD)) != EOF) {
		if (isalpha(c)) {
			for (i = 0; (lcword[i] = tolower(word[i])) != '\0'; i++);
			if (binsearch(lcword, keytab, NKEYS) < 0) {
				root = addtree(root, lcword, numstr);
			}
		}
	}
	printf("\n\n");
	treeprint(root);
	return 0;
}

void treeprint(struct tnode* p)
{
	if (p != NULL) {
		struct numstr* ptemp;
		treeprint(p->pleft);
		printf("%s    ", p->pword);
		ptemp = p->pnumstr;
		do {
			printf(" %d,", ptemp->number);
			ptemp = ptemp->pnextnumstr;
		}
		while (ptemp != NULL);
		printf("\b \n");
		treeprint(p->pright);
	}
}

int binsearch(char* word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0) {
			high = mid - 1;
		}
		else if (cond > 0) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

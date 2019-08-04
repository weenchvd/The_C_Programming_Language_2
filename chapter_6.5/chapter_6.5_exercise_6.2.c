/** Chapter 6.5 | Exercise 6.2 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "gen.h"

struct tnode* naddtree(struct tnode*, char*, int, int*);
void ntreeprint(struct tnode*);
int getword(char*, int);
int binsearch(char*, struct key*, int);

struct key {
	char* word;
} keytab[] = {
	"auto", "break", "case", "char", "const", "continue", "default", "do",
	"double", "else", "enum", "extern", "float", "for", "goto", "if",
	"int", "long", "register", "return", "short", "signed", "sizeof", "static",
	"struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int main(int argc, char* argv[])
{
	struct tnode* root;
	char word[MAXWORD];
	int n;
	int found;
	root = NULL;
	n = DEFAULTQTY;
	if (--argc && **++argv == '-') {
		n = atoi(*argv + 1);
		if (n < 0) {
			n = DEFAULTQTY;
		}
	}
	while (getword(word, MAXWORD) != EOF) {
		if ((isalpha(word[0]) || word[0] == '_') && strlen(word) >= n && binsearch(word, keytab, NKEYS) < 0) {
			found = FALSE;
			root = naddtree(root, word, n, &found);
		}
	}
	ntreeprint(root);
	return 0;
}

void ntreeprint(struct tnode* p)
{
	if (p != NULL) {
		ntreeprint(p->left);
		if (p->ismatch) {
			printf("%s\n", p->word);
		}
		ntreeprint(p->right);
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

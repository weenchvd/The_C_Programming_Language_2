/** Chapter 6.6 | Exercise 6.6 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gen2.h"

void printerr(int errcode);

struct nlist* hashtab[HASHSIZE];			/* pointer table */
char* output;
size_t len, sizeout;

int main()
{
	int getword(char word[], int lim);
	struct nlist* lookup(char* s);
	void addtooutput(char* s);
	
	struct nlist* np;
	char* ps;
	char word[MAXWORD];
	int type;
	output = NULL;
	while ((type = getword(word, MAXWORD)) != EOF) {
		if (type == WORD && (np = lookup(word)) != NULL) {
			ps = np->pdefn;
		}
		else if (type == PREPROCESSOR || type == COMMENT || type == STRINGCONST) {
			continue;
		}
		else ps = word;
		addtooutput(ps);
		if (type == STRINGCONST) {
			free(ps);
		}
	}
	printf("%s", output);
	return 0;
}

void addtooutput(char* s)
{
	len = strlen(s);
	if (output == NULL) {
		sizeout = len + 1;
		if ((output = (char*)malloc(sizeout)) == NULL) {
			printerr(ERRMALLOC);
			return ERROR;
		}
		else if ((output = strcpy(output, s)) == NULL) {
			printerr(ERRSTRCPY);
			return ERROR;
		}
	}
	else {
		sizeout += len;
		if ((output = (char*)realloc(output, sizeout)) == NULL) {
			printerr(ERRREALLOC);
			return ERROR;
		}
		else if ((output = strcat(output, s)) == NULL) {
			printerr(ERRSTRCAT);
			return ERROR;
		}
	}
	return;
}
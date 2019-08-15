#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gen2.h"

void printerr(int errcode);

extern struct nlist* hashtab[];
extern char* output;
extern size_t len, sizeout;

/* getword: get next word or character from input */
int getword(char word[], int lim)
{
	int getch(void);
	void ungetch(int);
	void preprocessor(void);
	void getcharacter(char word[], int lim);
	void getstring(char word[], int lim);
	int iscomment(void);

	int c;
	char* w = word;
	if ((c = getch()) == EOF) {
		return EOF;
	}
	else *w++ = c;
	if (isspace(c)) {
		while (isspace((c = getch()))) {
			*w++ = c;
		}
		ungetch(c);
		*w = '\0';
		return SPACE;
	}
	if (c == '#') {
		preprocessor();
		return PREPROCESSOR;
	}
	if (c == '\'') {
		getcharacter(word, lim);
		return CHARACTERCONST;
	}
	if (c == '"') {
		getstring(word, lim);
		return STRINGCONST;
	}
	if (c == '/') {
		if (iscomment()) {
			return COMMENT;
		}
	}
	if (!isalpha(c) && c != '_') {
		*w = '\0';
		return SYMBOL;
	}
	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return WORD;
}

void preprocessor(void)
{
	int getch(void);
	int getnd(char a[], int lim, int type, int nl);
	struct nlist* install(char* name, char* defn);
	void undef(char* name);

	struct nlist* np;
	char name[MAXNAME];
	char defn[MAXDEFINITION];
	if (getnd(name, MAXNAME, NAME, NLNOTALLOWED) == ERROR) {			/* get directive */
		return;
	}
	if (strcmp(name, "define") == 0) {
		if (getnd(name, MAXNAME, NAME, NLNOTALLOWED) == ERROR) {
			return;
		}
		if (getnd(defn, MAXDEFINITION, DEFN, NLALLOWED) == ERROR) {
			return;
		}
		if ((np = install(name, defn)) == NULL) {
			printerr(ERRPPNOINSTALL);
		}
	}
	else if (strcmp(name, "undef") == 0) {
		if (getnd(name, MAXNAME, NAME, NLALLOWED) == ERROR) {
			return;
		}
		undef(name);
	}
	else {
		while (getch() != '\n');
		return;
	}
	return;
}

int getnd(char a[], int lim, int type, int nl)			/* nl: whether a newline character is allowed */
{
	int getch(void);
	void ungetch(int);
	int iscomment(void);

	int c, i;
	while (isspace(c = getch())) {
		if (c == '\n') {
			printerr(ERRPPNOINPUT);
			return ERROR;
		}
	}
	ungetch(c);
	for (i = 0; i < lim && (nl == NLALLOWED ? (c = getch()) != '\n' : !isspace(c = getch())); ) {
		if (c == '/') {
			if (iscomment()) {
				continue;
			}
		}
		if (type == NAME) {
			if (i > 0 && (isalnum(c) || c == '_')) {
				a[i] = c;
			}
			else if (i == 0 && (isalpha(c) || c == '_')) {
				a[i] = c;
			}
			else {
				printerr(ERRPPUNALLOWSYM);
				while ((c = getch()) != '\n');
				return ERROR;
			}
		}
		else a[i] = c;
		i++;
	}
	if (i >= lim) {
		printerr(ERRPPINPUTGLIM);
		while ((c = getch()) != '\n');
		return ERROR;
	}
	else if (nl == NLNOTALLOWED && c == '\n') {
		printerr(ERRPPNLFOUND);
		return ERROR;
	}
	else a[i] = '\0';
	return i;
}

void getcharacter(char word[], int lim)
{
	int getch(void);
	void ungetch(int);

	int i;
	lim--;
	for (i = 1; i < lim; i++) {
		if ((word[i] = getch()) == '\'') {
			if (word[i - 1] != '\\') {
				i++;
				break;
			}
			else if (i == 3) {
				i++;
				break;
			}
		}
	}
	word[i] = '\0';
	return;
}

void getstring(char word[], int lim)
{
	int getch(void);
	void ungetch(int);
	void addtooutput(char* s);

	int i, cond;
	cond = TRUE;
	lim--;
	while (cond) {
		for (i = 1; i < lim; i++) {
			if ((word[i] = getch()) == '"') {
				if (word[i - 1] != '\\') {
					cond = FALSE;
					i++;
					break;
				}
			}
		}
		word[i] = '\0';
		addtooutput(word);
	}
	return;
}

int iscomment(void)
{
	int getch(void);
	void ungetch(int);

	int c;
	if ((c = getch()) == '/') {
		while (getch() != '\n');
		ungetch('\n');
		return OLCOMMENT;
	}
	else if (c == '*') {
		while (c = getch()) {
			if (c == '*') {
				if ((c = getch()) == '/') {
					break;
				}
				else ungetch(c);
			}
		}
		return MLCOMMENT;
	}
	else {
		ungetch(c);
		return FALSE;
	}
}
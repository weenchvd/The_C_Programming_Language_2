#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gen.h"

extern int iserr;
extern int tokentype;
extern char token[];
extern char datatype[];
char temp[MAXTOKEN];
char keyword[MAXKEYWORD][LENKEYWORD] = { "const", "signed", "unsigned","void", "char",
"short", "int", "long", "float", "double" };

/* return next token */
int gettoken(void)
{
	int getch(void);
	void ungetch(int);
	int gettoken(void);
	int iskeyword(void);
	int c;
	char* p = token;
	char* ptemp = temp;
	if (iserr) {
		return ERROR;
	}
	while ((c = getch()) == ' ' || c == '\t');
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else if (isalpha(c)) {
			*p++ = '(';
			for (*p++ = c; (*p = getch()) != ')'; p++) {
				if (*p == '\n') {
					iserr = TRUE;
					ungetch(*p);
					return ERROR;
				}
			}
			*++p = '\0';
			return tokentype = PARENSARG;
		}
		else {
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[') {
		for (*p++ = c; (*p = getch()) != ']'; p++) {
			if (*p == '\n') {
				iserr = TRUE;
				ungetch(*p);
				return ERROR;
			}
		}
		*++p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c)) {
		for (*ptemp++ = c; isalnum(c = getch()); *ptemp++ = c);
		*ptemp = '\0';
		ungetch(c);
		if (iskeyword()) {
			if (!datatype[0]) {
				strcpy(datatype, temp);
			}
			else {
				strcat(datatype, " ");
				strcat(datatype, temp);
			}
			return gettoken();
		}
		else {
			strcpy(token, temp);
			return tokentype = NAME;
		}
	}
	else {
		return tokentype = c;
	}
}

int iskeyword(void)
{
	int i;
	for (i = 0; i < MAXKEYWORD; i++) {
		if (!strcmp(temp, keyword[i])) {
			return TRUE;
		}
	}
	return FALSE;
}

void getrestline(void)
{
	int getch(void);
	while (getch() != '\n');
	return;
}

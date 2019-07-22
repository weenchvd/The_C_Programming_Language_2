#include <string.h>
#include <ctype.h>
#include "gen.h"

extern int iserr;
extern int tokentype;
extern char token[];

/* return next token */
int gettoken(void)
{
	int getch(void);
	void ungetch(int);
	int c;
	char* p = token;
	if (iserr) {
		return ERROR;
	}
	while ((c = getch()) == ' ' || c == '\t');
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
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
		for (*p++ = c; isalnum(c = getch()); *p++ = c);
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else {
		return tokentype = c;
	}
}

void getrestline(void)
{
	int getch(void);
	while (getch() != '\n');
	return;
}

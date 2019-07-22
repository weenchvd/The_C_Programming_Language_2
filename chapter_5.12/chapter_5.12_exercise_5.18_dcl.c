/** Chapter 5.12 | Exercise 5.18 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gen.h"

int dcl(void);
int dirdcl(void);
int gettoken(void);
void getrestline(void);

int iserr;
int tokentype;							/* type of last token */
char token[MAXTOKEN];					/* last token string */
char name[MAXTOKEN];					/* identifier name */
char datatype[MAXTOKEN];				/* data type = char, int, etc. */
char out[LENGTHOUT];

/* converts declaration to words */
int main()
{
	while (gettoken() != EOF) {			/* 1st token on line */
		strcpy(datatype, token);		/* is the datatype */
		out[0] = '\0';
		if (dcl() == ERROR) {			/* parse rest of line */
			if (tokentype != '\n') {
				getrestline();
			}
			printf("Incorrect input\n");
			iserr = 0;
			tokentype = 0;
			token[0] = '\0';
			name[0] = '\0';
			datatype[0] = '\0';
			out[0] = '\0';
			continue;
		}
		if (tokentype != '\n') {
			printf("syntax error\n");
			getrestline();
			printf("Incorrect input\n");
			iserr = 0;
			tokentype = 0;
			token[0] = '\0';
			name[0] = '\0';
			datatype[0] = '\0';
			out[0] = '\0';
			continue;
		}
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* dcl: parse a declarator */
int dcl(void)
{
	int ns;
	for (ns = 0; gettoken() == '*'; ns++);	/* count *'s */
	if (dirdcl() == ERROR) {
		return ERROR;
	}
	while (ns-- > 0) {
		strcat(out, " pointer to");
	}
	return 0;
}

/* dirdcl: parse a direct declarator */
int dirdcl(void)
{
	int type;
	if (tokentype == '(') {					/* ( dcl ) */
		if (dcl() == ERROR) {
			return ERROR;
		}
		if (tokentype != ')') {
			printf("error: missing )\n");
			iserr = TRUE;
			return ERROR;
		}
	}
	else if (tokentype == NAME) {			/* variable name */
		strcpy(name, token);
	}
	else {
		printf("error: expected name or (dcl)\n");
		iserr = TRUE;
		return ERROR;
	}
	while ((type = gettoken()) == PARENS || type == BRACKETS) {
		if (type == PARENS) {
			strcat(out, " function returning");
		}
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
	if (type == ERROR) {
		return ERROR;
	}
	return 0;
}

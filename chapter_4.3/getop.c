#include "common.h"

int getch(void);
void ungetch(int);
void ungets(char s[]);

int bufp;

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	if (bufp == 0) {
		for (i = 0; i < MAXOP && (c = getchar()) != '\n' && c != EOF; i++) {
			s[i] = c;
		}
		if (i >= MAXOP) {
			while ((c = getchar()) != '\n' && c != EOF);
			printf("Please enter a maximum of %d characters\n", MAXOP - 1);
			return CONTINUE;
		}
		else if (c == '\n' || c == EOF) {
			s[i] = c;
			if (MAXOP <= BUFSIZE) {
				ungets(s);
			}
			else {
				printf("Please enter a maximum of %d characters\n", BUFSIZE - 1);
				return CONTINUE;
			}
		}
	}
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (c == '$') {
		for (i = 0; i < MAXOP && (c = getch()) != '\n'; i++) {
			s[i] = c;
		}
		return COMMAND;
	}
	if (islower(c)) {
		i = 0;
		while (islower(s[++i] = c = getch()));
		if (c == '=') {
			return ASSIGNVAR;
		}
		else if (c != EOF) {
			ungetch(c);
		}
		if (i == 1) {
			return USEVAR;
		}
		if (s[0] == 'l' && s[1] == 'a' && s[2] == 's' && s[3] == 't') {
			return LAST;
		}
		else if (s[0] == 's' && s[1] == 'i' && s[2] == 'n') {
			return SIN;
		}
		else if (s[0] == 'e' && s[1] == 'x' && s[2] == 'p') {
			return EXP;
		}
		else if (s[0] == 'p' && s[1] == 'o' && s[2] == 'w') {
			return POW;
		}
		else return UNKNOWNCOMMAND;
	}
	if (!isdigit(c) && c != '.' && c != '-') {
		return c;		//not a number
	}
	i = 0;
	if (c == '-') {
		if (isdigit(s[++i] = c = getch()));
		else if(c != EOF) {
			ungetch(c);
			return '-';
		}
	}
	if (isdigit(c)) {	//collect integer part
		while (isdigit(s[++i] = c = getch()));
	}
	if (c == '.') {		//collect fraction part
		while (isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

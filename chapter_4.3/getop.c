#include "common.h"

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
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
		else {
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
		else {
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
	ungetch(c);
	return NUMBER;
}

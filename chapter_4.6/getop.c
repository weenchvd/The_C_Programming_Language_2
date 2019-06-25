#include "common.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
	static int buf;
	int i, c;
	if (buf == 0) {
		c = getchar();
	}
	else {
		c = buf;
		buf = 0;
	}
	while ((s[0] = c) == ' ' || c == '\t') {
		c = getchar();
	}
	s[1] = '\0';
	if (c == '$') {
		for (i = 0; i < MAXOP && (c = getchar()) != '\n'; i++) {
			s[i] = c;
		}
		return COMMAND;
	}
	if (islower(c)) {
		i = 0;
		while (islower(s[++i] = c = getchar()));
		if (c == '=') {
			return ASSIGNVAR;
		}
		else {
			buf = c;
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
		if (isdigit(s[++i] = c = getchar()));
		else {
			buf = c;
			return '-';
		}
	}
	if (isdigit(c)) {	//collect integer part
		while (isdigit(s[++i] = c = getchar()));
	}
	if (c == '.') {		//collect fraction part
		while (isdigit(s[++i] = c = getchar()));
	}
	s[i] = '\0';
	buf = c;
	return NUMBER;
}

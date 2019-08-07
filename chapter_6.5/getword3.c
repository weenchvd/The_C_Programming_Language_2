#include <stdio.h>
#include <ctype.h>

#define NOTLETTER ' '

/* getword: get next word or character from input */
int getword(char* word, int lim)
{
	int getch(void);
	void ungetch(int);
	int c, t;
	char* w = word;
	while (isspace(c = getch()));
	if (c != EOF) {
		*w++ = c;
	}
	if (isdigit(c)) {
		while (!isspace(t = getch()) && !ispunct(t));
		ungetch(t);
		*w = '\0';
		return NOTLETTER;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++) {
		if (!isalpha(*w = getch())) {
			if (isspace(*w) || ispunct(*w)) {
				ungetch(*w);
				break;
			}
			else {
				while (!isspace(t = getch()) && !ispunct(t));
				ungetch(t);
				*w = '\0';
				return NOTLETTER;
			}
		}
	}
	*w = '\0';
	return word[0];
}

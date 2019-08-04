#include <stdio.h>
#include <ctype.h>

/* getword: get next word or character from input */
int getword(char* word, int lim)
{
	int getch(void);
	void ungetch(int);
	int c;
	char* w = word;
	while (isspace(c = getch()));
	if (c != EOF) {
		*w++ = c;
	}
	if (c == '#') {
		while ((c = getch()) != '\n');
		*w = '\0';
		return word[0];
	}
	if (c == '"') {
		while ((c = getch()) != '"');
		*w = '\0';
		return c;
	}
	if (c == '/') {
		if ((c = getch()) == '*') {
			while (c = getch()) {
				if (c == '*') {
					if ((c = getch()) == '/') {
						*w = '\0';
						return c;
					}
					else {
						ungetch(c);
					}
				}
			}
		}
		else if (c == '/') {
			while ((c = getch()) != '\n');
			*w = '\0';
			return word[0];
		}
		else {
			ungetch(c);
			*w = '\0';
			return word[0];
		}
	}
	if (!isalpha(c) && c != '_') {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

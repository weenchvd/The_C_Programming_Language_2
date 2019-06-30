#include <stdio.h>

enum boolean { FALSE, TRUE };

int getstr(char str[], int lim)
{
	int i, c;
	short int trig;
	for (i = 0, c = EOF, trig = TRUE; i < lim && trig == TRUE && (c = getchar()) != EOF; i++) {
		str[i] = c;
		if (str[i] == '\n' && i > 1 && str[i - 1] == '`' && str[i - 2] == '`') {
			trig = FALSE;
			i--;
		}
	}
	if (str[0] == '`' && str[1] == '`') {
		return -1;
	}
	else if (i == lim) {
		return -2;
	}
	else if (c == EOF) {
		return -100;
	}
	else {
		str[i - 3] = '\0';
		return i - 3;
	}
}
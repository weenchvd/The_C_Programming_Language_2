#include <stdio.h>
#include <ctype.h>

/* getint: get next integer from input into *pn */
int getint(int* pn)
{
	static int buf;
	int c, sign;
	if (buf == 0) {
		c = getchar();
	}
	else {
		c = buf;
		buf = 0;
	}
	while (isspace(c)) { //skip white space
		c = getchar();
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		buf = c; //it is not a number
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getchar();
	}
	if (isdigit(c)) {
		for (*pn = 0; isdigit(c); c = getchar()) {
			*pn = 10 * *pn + (c - '0');
		}
		*pn *= sign;
		if (c != EOF) {
			buf = c;
		}
		return c;
	}
	else {
		buf = c;
		return 0;
	}
}

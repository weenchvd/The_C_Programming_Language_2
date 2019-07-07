#include <stdio.h>

/* n = 0: common case of ngetline(),
   n = 1: case 1 - ngetline() will delete '\n' in the end of line,
   n = 2: case 2 - ngetline() will receive all characters after the limit is reached.
   Cases can be grouped by adding n, for example:
   n = 3: case 1 + case 2 */
int ngetline(char* ps, int lim, char n)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*(ps + i++) = c;
	}
	if (c == '\n') {
		if (n & 1);
		else *(ps + i++) = c;
	}
	if (n & 2 && lim == 0) {
		while ((c = getchar()) != EOF && c != '\n');
	}
	*(ps + i) = '\0';
	return i;
}
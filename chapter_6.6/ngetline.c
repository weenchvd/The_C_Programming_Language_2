#include <stdio.h>

/* n = 0: common case of ngetline(),
   n = 1: case 1 - ngetline() will delete '\n' in the end of line,
   n = 2: case 2 - ngetline() will receive all characters after the limit is reached.
   n = 4: case 3 - ngetline() will return 0 and erase all stored characters and replaces them with NULL if the limit is reached.
          Case 3 should always be grouped with case 2 (n = 6)!
   n = 8: case 4 - ngetline() will return only first word from input
   Cases can be grouped by adding n, for example:
   n = 3: case 1 + case 2
   n = 7: case 1 + case 2 + case 3 */
int ngetline(char* ps, int lim, char n)
{
	int c, i;
	i = 0;
	if (lim < 1) {
		return -1;
	}
	if (n & 8) {
		while (--lim > 0 && (c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\t') {
			*(ps + i++) = c;
		}
		if (c == ' ' || c == '\t') {
			while ((c = getchar()) != EOF && c != '\n');
		}
	}
	else {
		while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
			*(ps + i++) = c;
		}
	}
	if (c == '\n') {
		if (n & 1);
		else *(ps + i++) = c;
	}
	if (n & 2 && lim == 0) {
		while ((c = getchar()) != EOF && c != '\n');
		if (n & 4) {
			while (i > 0) {
				*(ps + --i) = '\0';
			}
		}
	}
	*(ps + i) = '\0';
	return i;
}
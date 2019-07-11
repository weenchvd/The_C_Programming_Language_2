/** Chapter 5.10 | Exercise 5.13 */

#include <stdio.h>
#include <stdlib.h>

#define STORELENGTH 10000
#define MAXLINES 2000

int ngetline(char* ps, int lim, char n);

int main(int argc, char* argv[])
{
	int n, i, tmp, lenline, flen;
	char* ptrlines[MAXLINES];
	char lines[STORELENGTH];
	n = 10;
	if (argc > 1 && (tmp = atoi(++(*++argv))) > 0) {
		n = tmp;
	}
	printf("   Press ENTER on an empty line to finish typing\n");
	flen = 0;
	i = 0;
	while (i < MAXLINES && (lenline = ngetline(lines + flen, STORELENGTH - flen, 6)) > 1) {
		ptrlines[i++] = lines + flen;
		flen = flen + lenline + 1;
	}
	if ((tmp = i - n) < 0) {
		tmp = 0;
		n = i;
	}
	if (n > 0) {
		printf("\n>>>The last %d lines:\n", n);
	}
	while (n-- > 0) {
		printf("%s", ptrlines[tmp++]);
	}
	return 0;
}
/** Chapter 5.10 | Exercise 5.12 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000			/* the maximum size of the input string */
#define STDLENGTHTAB 8

int ngetline(char* ps, int lim, char n);

int main(int argc, char *argv[])
{
	int lenline, lentab, tmp, i, c, n, start;
	char line[MAXLINE];
	printf("   Enter arguments \'-m\', \'+n\' (tab stops every n columns, starting at column m).\n");
	lentab = tmp = STDLENGTHTAB;
	start = 1;
	while (--argc > 0) {
			switch (**++argv) {
			case '-':
				if ((start = atoi(*argv + 1)) < 1) {
					printf("---Error: the entered number \'m\' must be greater than 0\n");
					return -1;
				}
			case '+':
				if ((tmp = atoi(*argv + 1)) < 1) {
					printf("---Error: the entered number \'n\' must be greater than 0\n");
					return -1;
				}
			}
	}
	start--;
	while ((lenline = ngetline(line, MAXLINE, 2)) > 1) {
		lentab = STDLENGTHTAB;
		for (i = 0, c = 0; i < lenline; i++) {
			if (i == start) {
				lentab = tmp;
			}
			if (line[i] == '\t') {
				n = lentab - (c - (c / lentab * lentab));
				c += n;
				while(n-- > 0) {
					printf(" ");
				}
			}
			else {
				printf("%c", line[i]);
				c++;
			}
		}
	}
	return 0;
}

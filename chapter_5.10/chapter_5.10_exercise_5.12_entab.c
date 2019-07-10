/** Chapter 5.10 | Exercise 5.12 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000			/* the maximum size of the input string */
#define STDLENGTHTAB 8

int ngetline(char* ps, int lim, char n);

int main(int argc, char *argv[])
{
	int lenline, lentab, i, c, s, t, k, tmp, start;
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
	while((lenline = ngetline(line, MAXLINE, 2)) > 1) {
		int nt = 0, ns = 0;
		lentab = STDLENGTHTAB;
		for(i = 0, c = 0; i < lenline; i++) {
			if (i == start) {
				lentab = tmp;
			}
			if(line[i] == ' ' && line[i + 1] == ' ') {
				c++;
			}
			else if(line[i] == ' ' && c > 0) {
				c++;
				if((k = ((i + 1) / lentab) * lentab) > (i + 1 - c)) {
					if((i + 1 - c) - ((i + 1 - c) / lentab) * lentab == 0) {
						t = (k - (i + 1 - c)) / lentab;
					}
					else {
						t = (k - (i + 1 - c)) / lentab + 1;
					}
					s = (i + 1) - k;
					nt = nt + t;
					while(t-- > 0) {
						printf("\t");
					}
				}
				else {
					s = c;
				}
				ns = ns + s;
				while(s-- > 0) {
					printf(" ");
				}
				c = 0;
			}
			else {
				printf("%c", line[i]);
			}
		}
		printf("\nNumbers of TABS: %4d\nNumbers of SPACES (exclude single spaces): %4d\n", nt, ns);
	}
	return 0;
}

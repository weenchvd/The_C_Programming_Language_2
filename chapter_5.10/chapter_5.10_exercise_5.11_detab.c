/** Chapter 5.10 | Exercise 5.11 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000			/* the maximum size of the input string */
#define STDLENGTHTAB 8

int ngetline(char* ps, int lim, char n);

int main(int argc, char *argv[])
{
	int lenline, lentab, i, c, n;
	char line[MAXLINE];
	printf("   Enter the number of tab stops as an argument.\n");
	if (argc < 2) {
		lentab = STDLENGTHTAB;
	}
	else if ((lentab = atoi(*++argv)) < 1) {
		printf("---Error: the entered number must be greater than 0\n");
		return -1;
	}
	while ((lenline = ngetline(line, MAXLINE, 2)) > 1) {
		for(i = 0, c = 0; i < lenline; i++) {
			if(line[i] == '\t') {
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

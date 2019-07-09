/** Chapter 5.10 | Exercise 5.11 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000			/* the maximum size of the input string */
#define STDLENGTHTAB 8

int ngetline(char* ps, int lim, char n);

int main(int argc, char *argv[])
{
	int lenline, lentab, i, c, s, t, k;
	char line[MAXLINE];
	printf("   Enter the number of tab stops as an argument.\n");
	if (argc < 2) {
		lentab = STDLENGTHTAB;
	}
	else if ((lentab = atoi(*++argv)) < 1) {
		printf("---Error: the entered number must be greater than 0\n");
		return -1;
	}
	while((lenline = ngetline(line, MAXLINE, 2)) > 1) {
		int nt = 0, ns = 0;
		for(i = 0, c = 0; i < lenline; i++) {
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
